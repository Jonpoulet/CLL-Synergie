#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include "Reseau/Paquets/basepaquet.h"
#include "fichier.h"
#include "Reseau/transfer.h"
#include "Reseau/connexion.h"
#include <QMap>
#include <QList>
#include <QColor>

class Transfer;
class Fichier;
class Connexion;

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QTcpSocket* socket, QObject *parent = 0);

    void Authentifier(QString nom, QColor couleur);
    void Deconnecter();
    void EnvoyerPaquet(BasePaquet* paquet);
    void EnvoyerBytes(QByteArray donnees);
    void OuvrirFichier(Fichier* fichier);
    void FermerFichier(Fichier* fichier);
    void EnvoyerFichier(Fichier* fichier, bool onglet = true);
    void FinTransfer(int id);

    QString getNom();
    int getID();
    Connexion* getConnexion();
    Transfer* getTransfer(int index);
    QMap<int, Transfer*>* getTransfers();
    QList<Fichier*>* getFichiers();
    int getMauvaisesReponses();
    QColor getCouleur();

    void setMauvaisesReponses(int valeur);

private:
    static int GenerateurID;

    int m_ID;
    QString m_Nom;
    QColor m_Couleur;
    Connexion* m_Connexion;
    QMap<int, Transfer*>* m_Transfers;
    QList<Fichier*>* m_FichiersOuverts;

    // Le nombre de mauvaises réponses est proportionnel aux chances que le client soit désynchronisé avec le serveur.
    int m_MauvaisesReponses;

signals:
    void siDeconnexion(Client* client);

public slots:
    void slFinTransfer(int id);
};

#endif // CLIENT_H
