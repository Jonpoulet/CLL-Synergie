#include "paqueteffacementtexte.h"

PaquetEffacementTexte::PaquetEffacementTexte(Fichier* fichier, int position, int longeur) :
    BasePaquetServeur((qint8)7)
{
    *m_Stream << fichier->getID();
    *m_Stream << position;
    *m_Stream << longeur;
}