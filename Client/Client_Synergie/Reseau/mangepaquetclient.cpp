#include "mangepaquetclient.h"
#include <QDataStream>
#include <QDebug>
#include <QStringList>

MangePaquetClient::MangePaquetClient(QObject *parent) :
    QObject(parent)
{
}

void MangePaquetClient::Interpreter(QDataStream* stream)
{
    quint8 id;

    *stream >> id;

    switch (id) {
    case 1:
        Reception_ListeCollegues(stream);
        break;
    default:
        qDebug() << "Réception d'un paquet inconnu #" << id;
        break;
    }
}

void MangePaquetClient::Reception_ListeCollegues(QDataStream* stream)
{
    QStringList* collegues = new QStringList();
    int nombre;

    *stream >> nombre;

    for(int i = 0; i < nombre; i++) {
        QString nom;
        *stream >> nom;
        collegues->append(nom);
    }
}
