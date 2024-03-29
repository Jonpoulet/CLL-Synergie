#include "client.h"
#include <QByteArray>
#include <QDataStream>
#include "serveur.h"
#include "Console/console.h"
#include "Reseau/Paquets/paquetouverturefichier.h"
#include "Reseau/Paquets/basepaquet.h"
#include "Reseau/Paquets/paquetdonnees.h"
#include "Reseau/Paquets/paquetenvoicollegues.h"
#include "Reseau/Paquets/paquetlistefichiers.h"
#include "Reseau/Paquets/paquetconnexioncollegue.h"

// Sert à attribuer automatiquement des ID aux clients.
int Client::GenerateurID = 0;

Client::Client(QTcpSocket* socket, QObject* parent) :
    QObject(parent)
{
    m_ID = GenerateurID;
    m_Connexion = new Connexion(socket, this);
    m_Transfers = new QMap<int, Transfer*>;
    m_FichiersOuverts = new QList<Fichier*>;

    GenerateurID++;
}

void Client::EnvoyerPaquet(BasePaquet* paquet)
{
    m_Connexion->EnvoyerPaquet(paquet);
}

// Attention! Un client connecté n'est pas nécéssairement authentifié!
void Client::Authentifier(QString nom, QColor couleur)
{
    m_Nom = nom;
    m_Couleur = couleur;

    EnvoyerPaquet(new PaquetEnvoiCollegues(this));
    EnvoyerPaquet(new PaquetListeFichiers());

    Console::Instance()->Imprimer(m_Nom + " est en ligne");

    // TODO: Envoyer les 10-15 derniers messages du chat.

    // Indique aux autres clients que ce client est connecté & authentifié
    Serveur::Instance()->getClients()->EnvoyerPaquetATous(new PaquetConnexionCollegue(this), this);
}

void Client::Deconnecter()
{
    m_Connexion->Fermer();

    Fichier* fichier;
    foreach (fichier, *m_FichiersOuverts)
    {
        FermerFichier(fichier);
    }

    emit siDeconnexion(this);

    Console::Instance()->Imprimer(m_Nom + " est déconnecté");
}

void Client::OuvrirFichier(Fichier* fichier)
{
    m_FichiersOuverts->append(fichier);
    fichier->AjouterClient(this);
    EnvoyerFichier(fichier);
}

void Client::FermerFichier(Fichier *fichier)
{
    fichier->EnleverClient(this);
    m_FichiersOuverts->removeOne(fichier);
}

// Le paramètre onglet détermine si l'on ouvre un nouvel onglet du côté client
void Client::EnvoyerFichier(Fichier* fichier, bool onglet)
{
    Transfer* transfer = new Transfer(fichier, this);
    m_Transfers->insert(fichier->getID(), transfer);

    connect (transfer, SIGNAL(siFin(int)), this, SLOT(slFinTransfer(int)));

    if (onglet)
    {
        EnvoyerPaquet(new PaquetOuvertureFichier(this, fichier));
    }
    EnvoyerPaquet(new PaquetDonnees(transfer));
}

QString Client::getNom()
{
    return m_Nom;
}

int Client::getID()
{
    return m_ID;
}

Connexion* Client::getConnexion()
{
    return m_Connexion;
}

Transfer* Client::getTransfer(int id)
{
    return m_Transfers->value(id);
}

QMap<int, Transfer*>* Client::getTransfers()
{
    return m_Transfers;
}

QList<Fichier*>* Client::getFichiers()
{
    return m_FichiersOuverts;
}

int Client::getMauvaisesReponses()
{
    return m_MauvaisesReponses;
}

QColor Client::getCouleur()
{
    return m_Couleur;
}

void Client::setMauvaisesReponses(int valeur)
{
    m_MauvaisesReponses = valeur;
}

void Client::slFinTransfer(int id)
{
    m_Transfers->remove(id);
}
