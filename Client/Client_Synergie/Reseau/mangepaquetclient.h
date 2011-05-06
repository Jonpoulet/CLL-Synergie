#ifndef MANGEPAQUETCLIENT_H
#define MANGEPAQUETCLIENT_H

#include <QObject>
#include <QMap>
#include "collegue.h"

class MangePaquetClient : public QObject
{
    Q_OBJECT
public:
    explicit MangePaquetClient(QObject *parent = 0);
    void Interpreter(QDataStream*);

private:
    void Reception_ListeCollegues(QDataStream* stream);
    void Reception_ListeDesFichiers(QDataStream* stream);
    void Reception_ConnexionCollegue(QDataStream* stream);
    void Reception_DeconnexionCollegue(QDataStream* stream);
    void Reception_OuvertureFichier(QDataStream* stream);
    void Reception_Donnees(QDataStream* stream);
    void Reception_Texte(QDataStream* stream);
    void Reception_EffacementTexte(QDataStream* stream);
    void Reception_TexteChat(QDataStream* stream);

signals:
    void siNouvelleListeCollegues(QStringList* noms);
    void NouvelleListeFichiers(QStringList* noms);
    void siOuvrirFichier(int id);
    void siNouvelleDonnees(int id, QString donnees);
    void siNouveauTexte(int id, int position, QString Texte);
    void siEffacementTexte(int id, int position, int longeur);
    void siNouveauTexteChat(QString Nom,QString Texte);

public slots:
};

#endif // MANGEPAQUETCLIENT_H
