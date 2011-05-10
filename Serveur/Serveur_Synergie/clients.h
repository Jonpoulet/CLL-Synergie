#ifndef CLIENTS_H
#define CLIENTS_H

#include <QObject>
#include <QMap>
#include "Reseau/client.h"

class Clients : public QObject
{
    Q_OBJECT
public:
    explicit Clients(QObject *parent = 0);

    void EnleverClient(Client* client);
    void AjouterClient(Client* client);
    void EnvoyerPaquetATous(BasePaquet* paquet, Client* exception = 0);
    static void EnvoyerPaquetAListe(QList<Client*>* clients, BasePaquet* paquet, Client* exception = 0);
    int compte();
    QMap<int, Client*>* getClients();

private:
    QMap<int, Client*>* m_Clients;

signals:

public slots:
    void slDeconnexionClient(Client* client);

};

#endif // CLIENTS_H