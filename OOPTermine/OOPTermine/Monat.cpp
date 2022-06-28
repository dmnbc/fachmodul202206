#include "Monat.h"

int                 Monat::get_laufenderMonatImJahr()
{
	return laufenderMonatImJahr;
}
std::string         Monat::get_nameMonat()
{
	return nameMonat;
}
int                 Monat::get_anzahlTage()
{
	return anzahlTage;
}
std::vector<Tag>    Monat::get_tage()
{
	return tage;
}
void    Monat::set_laufenderMonatImJahr(int n)
{
	laufenderMonatImJahr = n;
}
void    Monat::set_nameMonat(std::string s)
{
	nameMonat = s;
}
void    Monat::set_anzahlTage(int n)
{
	anzahlTage = n;
}
void    Monat::set_tage(std::vector<Tag> v)
{
	tage = v;
}

void  monat_Anzeige();

// Konstruktor
Monat();    // Standardkonstruktor
Monat(int); // weiter Überladungen bei Bedarf