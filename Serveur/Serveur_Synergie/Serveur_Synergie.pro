#-------------------------------------------------
#
# Project created by QtCreator 2011-04-24T12:03:50
#
#-------------------------------------------------

QT       += core gui network

TARGET = Serveur_Synergie
TEMPLATE = app


SOURCES += main.cpp\
        UI/fenetreprincipale.cpp \
    Console/console.cpp \
    Console/Commandes/basecommande.cpp \
    Console/Commandes/aide.cpp \
    Console/Commandes/vider.cpp \
    client.cpp \
    Console/Commandes/demarrer.cpp \
    Reseau/Paquets/paquetenvoicollegues.cpp \
    Console/Commandes/collegues.cpp \
    Reseau/Paquets/paquetlistefichiers.cpp \
    Console/Commandes/fichiers.cpp \
    Reseau/Paquets/paquetconnexioncollegue.cpp \
    Reseau/Paquets/paquetdeconnexioncollegue.cpp \
    Reseau/Paquets/paquetouverturefichier.cpp \
    Reseau/Paquets/paquetdonnees.cpp \
    fichier.cpp \
    Reseau/Paquets/paquetinsertiontexte.cpp \
    Reseau/Paquets/paqueteffacementtexte.cpp \
    projet.cpp \
    Reseau/transfer.cpp \
    clients.cpp \
    serveur.cpp \
    Reseau/Paquets/basepaquet.cpp \
    Reseau/depaqueteur.cpp \
    Reseau/Paquets/paquetmessagechat.cpp \
    Chat/chat.cpp \
    verificateur.cpp \
    Reseau/Paquets/paquetverification.cpp \
    Reseau/Paquets/paquetnettoyerfichier.cpp \
    Chat/message.cpp \
    Reseau/connexion.cpp \
    Chat/archiveur.cpp \
    Reseau/Paquets/paquetouvrirfeuille.cpp \
    curseur.cpp \
    Reseau/Paquets/paquetfermerfeuille.cpp \
    Console/argument.cpp \
    Console/arguments.cpp \
    Console/Commandes/parler.cpp \
    Console/Commandes/projetcommande.cpp \
    Reseau/Paquets/paquetfermetureserveur.cpp \
    Console/Commandes/redemarrer.cpp

HEADERS  += UI/fenetreprincipale.h \
    Console/console.h \
    Console/Commandes/basecommande.h \
    Console/Commandes/aide.h \
    Console/Commandes/vider.h \
    client.h \
    Console/Commandes/demarrer.h \
    Reseau/Paquets/paquetenvoicollegues.h \
    Console/Commandes/collegues.h \
    Reseau/Paquets/paquetlistefichiers.h \
    Console/Commandes/fichiers.h \
    Reseau/Paquets/paquetconnexioncollegue.h \
    Reseau/Paquets/paquetdeconnexioncollegue.h \
    Reseau/Paquets/paquetouverturefichier.h \
    Reseau/Paquets/paquetdonnees.h \
    fichier.h \
    Reseau/Paquets/paquetinsertiontexte.h \
    Reseau/Paquets/paqueteffacementtexte.h \
    projet.h \
    Reseau/transfer.h \
    clients.h \
    serveur.h \
    Reseau/Paquets/basepaquet.h \
    Reseau/depaqueteur.h \
    Reseau/Paquets/paquetmessagechat.h \
    Chat/chat.h \
    verificateur.h \
    Reseau/Paquets/paquetverification.h \
    Reseau/Paquets/paquetnettoyerfichier.h \
    Chat/message.h \
    Reseau/connexion.h \
    Chat/archiveur.h \
    Reseau/Paquets/paquetouvrirfeuille.h \
    curseur.h \
    Reseau/Paquets/paquetfermerfeuille.h \
    Console/argument.h \
    Console/arguments.h \
    Console/Commandes/parler.h \
    Console/Commandes/projetcommande.h \
    Reseau/Paquets/paquetfermetureserveur.h \
    Console/Commandes/redemarrer.h

FORMS    += UI/fenetreprincipale.ui
