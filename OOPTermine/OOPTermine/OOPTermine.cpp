// OOPTermine.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
// zum Test
#include "Monat.h"

int main()
{
    for (int monat = 1; monat <= 12; monat++)
    {
        Monat m(monat); // Instanzieren über einen überladenen Konstruktor
        m.monat_Anzeige();
    }
}

