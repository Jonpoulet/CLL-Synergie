#include "vider.h"
#include "Console/console.h"

Vider::Vider()
{
    m_MotsCle << "vider" << "nettoyer" << "clear";
    m_ArgsMin = 0;
    m_Description = "Nettoie la console.";
}

QString Vider::Executer(Arguments* arguments)
{
    Console::Instance()->Vider();
    return "";
}
