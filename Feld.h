#pragma once
#include "Figur.h"
class Feld
{
	char spalte;
	char zeile;
	bool hell;
	Figur* figur;

public:
	Feld();
	Feld(char, char);  // ctor der Zeile und Spalte erh�lt
	Figur* get_figur() { return figur; }
	bool get_hell() { return hell; }
};

