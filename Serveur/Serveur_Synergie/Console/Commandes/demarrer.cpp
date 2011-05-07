#include "demarrer.h"
#include "serveur.h"

Demarrer::Demarrer()
{
    m_MotsCle << "demarrer" << "start";
    m_ArgsMin = 0;
    m_Description = "Démarre le serveur.";
}

QString Demarrer::Executer(const QStringList& arguments)
{

    Serveur::Instance()->Demarrer();
    return "";
}
