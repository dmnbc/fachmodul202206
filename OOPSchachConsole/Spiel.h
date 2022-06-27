#pragma once
#include <array>
#include <string>
#include <map>
#include <iostream>

#include "Feld.h"
class Spiel
{
	std::array<std::string, 2> spieler{ "Spieler 1","Spieler 2" };
	int zugnummer{ 0 };

	std::map<std::string, Feld> spielStand; 
public:
	Spiel(); // ctor stellt das Brett  mit den Feldern und Figuren bereit
	void spielstandAnzeigen();
};

