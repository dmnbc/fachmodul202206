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
	Feld(char, char);
	Figur* get_figur() { return figur; }
	bool get_hell() { return hell; }
};

