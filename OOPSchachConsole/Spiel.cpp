#include "Spiel.h"

Spiel::Spiel()
{
	// Brett aufbauen, also die map befüllen 
	for (char zeile = '1'; zeile <= '8'; zeile++)	
	{ for (char spalte = 'A'; spalte <= 'H'; spalte++)
	  { // generate the collection of fields
			std::string key; // neuer leerer Index für das nächste Feld
			key += zeile;    // 1. Zeichen des Index Ziffer der Zeile
			key += spalte;   // 2. Zeichen des Index Buchstabe der Spalte
			 //                  generieren des Feldes für Zeile, Spalte
			 //       index      ctor in Feld
			std::cout << key << " "; 
			//spielStand[key] = Feld(zeile,spalte); // einzelne Elemente der map
		}
	}	
}

void Spiel::spielstandAnzeigen()
{
	std::cout<<"   A B C D E F G H \n" ;
	// map ausgeben
	int zeile = 1;
	int lfd_f = 0;
	char hell = 219;
	char dunkel = 176;
	
	for (auto f : spielStand)
	{	
		if (f.first[1] == 'A')
		{
			std::cout << "\n"<<zeile <<" ";
		}
		std::cout << " " << (f.second.get_hell() ? hell : dunkel);
		/*
				if(f.second.get_figur()->get_figurTyp()=='x')
				{std::cout << " " << (f.second.get_hell()?hell:dunkel); }
				else
				{
					std::cout << " " << f.second.get_figur()->get_figurTyp();
				}
				*/
		if (f.first[1] == 'H')
		{
			std::cout << " " <<zeile++ ;
		}
	}
	std::cout << "\n\n   A B C D E F G H \n";

	
}
