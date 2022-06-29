#include "Monat.h"
#include <array>
#include <iostream>

std::array<std::string, 13> monatName
{
	"","Jan","Feb","Mar","Apr","Mai","Jun","Jul","Aug","Sep","Okt","Nov","Dez"
};

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

void  Monat::monat_Anzeige()
{
	std::cout << nameMonat << " mit " << anzahlTage << " Tagen \n";
	for (auto einzelTag : get_tage())
	{
		einzelTag.tag_Anzeige();
	}
}

// Konstruktor
Monat::Monat() {}    // Standardkonstruktor
Monat::Monat(int n) // weiter Überladungen bei Bedarf
{ // n ist die Nummer des Monats
	laufenderMonatImJahr = n;
	set_nameMonat(monatName[n]);
	switch (n)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		set_anzahlTage(31);
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		set_anzahlTage(30);
		break;
	case 2:
		set_anzahlTage(28); // muss noch Schaltjahr untersuchen
		break;
	}

	// Tage des Monats in den vector eintragen
	for (int t = 1; t <= get_anzahlTage(); t++)
	{
		tage.push_back(Tag(t));
	}


}