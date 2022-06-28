// OOPTermine.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
// zum Test
#include "Tag.h"

int main()
{
    for (int tag = 1; tag <= 28; tag++)
    {
        Tag t(tag); // Instanzieren über einen überladenen Konstruktor
        t.tag_Anzeige();
    }
}

