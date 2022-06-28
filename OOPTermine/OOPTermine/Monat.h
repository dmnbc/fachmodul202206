#pragma once
#include <string>
#include <vector>

#include "Tag.h"
class Monat
{
    int                 laufenderMonatImJahr;
    std::string         nameMonat;
    int                 anzahlTage;
    std::vector<Tag>    tage;
public: // Deklarationen
    // getter und setter für die Attribute
    int                 get_laufenderMonatImJahr();
    std::string         get_nameMonat();
    int                 get_anzahlTage();
    std::vector<Tag>    get_tage();
    void                set_laufenderMonatImJahr(int);
    void                set_nameMonat(std::string);
    void                set_anzahlTage(int);
    void                set_tage(std::vector<Tag>);
    
    void  monat_Anzeige();

    // Konstruktor
    Monat();    // Standardkonstruktor
    Monat(int); // weiter Überladungen bei Bedarf
};

