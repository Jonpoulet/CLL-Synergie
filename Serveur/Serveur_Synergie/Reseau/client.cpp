#include "client.h"
#include <QByteArray>
#include <QDataStream>
#include <QtCore>
#include "serveursynergie.h"
#include "Console/console.h"
#include "Paquets/paquetouverturefichier.h"
#include "Paquets/basepaquetserveur.h"
#include "Paquets/paquetdonnees.h"

Client::Client(int id, QTcpSocket* socket)
{
    m_ID = id;
    m_Socket = socket;
    m_Transfers = new QMap<int, Transfer*>;

    connect(m_Socket, SIGNAL(readyRead()),this,SLOT(slPretALire()));
    connect(m_Socket,SIGNAL(disconnected()),this,SLOT(slOnDeconnection()));
}

void Client::EnvoyerPaquet(BasePaquetServeur* paquet)
{
   m_Socket->write(paquet->getBuffer());
   m_Socket->waitForBytesWritten();
}

void Client::slPretALire()
{
    LirePaquet();
}

void Client::LirePaquet()
{
    QByteArray bufferTaille; // Pourquoi deux buffer et deux datastream ???
    QDataStream streamTaille(&bufferTaille, QIODevice::ReadOnly);

    int taille = 0;
    bufferTaille = m_Socket->read(4);
    streamTaille >> taille;

    QByteArray buffer;
    QDataStream stream(&buffer, QIODevice::ReadOnly);

    buffer = m_Socket->read(taille);

    ServeurSynergie::getInstance()->getMangePaquets()->Interpreter(this, &stream);

    if (m_Socket->bytesAvailable() > 0) {
        LirePaquet();
    }
}

void Client::slOnDeconnection()
{
    m_Socket->close();
    ServeurSynergie::getInstance()->EnleverClient(this);
    Console::getInstance()->Imprimer(m_Nom + " est déconnecté");
}

void Client::EnvoyerFeuille(int id)
{
    EnvoyerPaquet(new PaquetOuvertureFichier(id));
    Transfer* transfer = new Transfer(id);
    m_Transfers->insert(id, transfer);
    EnvoyerPaquet(new PaquetDonnees(transfer));
}

void Client::FinTransfer(int id)
{
    m_Transfers->remove(id);
}

QString Client::getNom()
{
    return m_Nom;
}

int Client::getID()
{
    return m_ID;
}

QString Client::getIP()
{
    return m_Socket->peerAddress().toString();
}

Transfer* Client::getTransfer(int id)
{
    return m_Transfers->value(id);
}

void Client::setNom(QString nom)
{
    m_Nom = nom;
    Console::getInstance()->Imprimer(getIP() + " change de nom pour " + nom);
}
