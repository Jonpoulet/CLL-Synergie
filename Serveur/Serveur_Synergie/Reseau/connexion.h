#ifndef CONNEXION_H
#define CONNEXION_H

#include <QObject>
#include <QTcpSocket>

#include "../client.h"
#include "Paquets/basepaquet.h"

class Client;

// Cette classe sert à lire et envoyer des paquets au client.

class Connexion : public QObject
{
    Q_OBJECT
public:
    explicit Connexion(QTcpSocket* socket, Client* client);

    void Lire();
    void EnvoyerPaquet(BasePaquet* paquet);
    void EnvoyerBytes(QByteArray donnees);
    void Fermer();

    QString getIP();

private:
    Client* m_Client;
    QTcpSocket* m_Socket;

public slots:
    void slPretALire();
    void slDeconnexion();

};

#endif // CONNEXION_H
