#ifndef SERVEURSYNERGIE_H
#define SERVEURSYNERGIE_H

#include <QObject>
#include <QTcpServer>
#include <QMap>
#include "Reseau/client.h"
#include "Reseau/mangepaquetsserveur.h"
#include "Reseau/Paquets/basepaquetserveur.h"
#include "fichier.h"

class ServeurSynergie : public QObject
{
    Q_OBJECT
public:
    static ServeurSynergie* getInstance();

    bool Demarrer();
    bool Arreter();
    bool EnleverClient(Client* client);
    bool AjouterClient(Client* client);
    void EnvoyerPaquetATous(BasePaquetServeur* paquet, Client* exception = 0);
    void EnvoyerPaquetAListe(QList<Client*>* clients, BasePaquetServeur* paquet, Client* exception = 0);
    Fichier* ChercherFichierParID(int id);
    MangePaquetsServeur* getMangePaquets();
    QMap<int, Client*>* getClients();
    QMap<int, Fichier*>* getFichiers();
    int getGenerateurIDFichier();
    QString getProjet();
    bool NouveauProjet(QString nom);

private:
    static ServeurSynergie* m_Instance;

    explicit ServeurSynergie(QObject *parent = 0);
    void InitialiserFichiers();

    QString m_Projet;
    QTcpServer* m_Ecouteur;
    MangePaquetsServeur* m_MangePaquets;
    QMap<int, Client*>* m_Clients;
    QMap<int, Fichier*>* m_Fichiers;
    int m_GenerateurIDClient; // Sert à attribuer des nombres d'identification aux clients.
    int m_GenerateurIDFichier;

signals:

public slots:
    void slNouveauClient();
};

#endif // SERVEURSYNERGIE_H
