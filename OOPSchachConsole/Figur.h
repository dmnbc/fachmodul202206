#pragma once
class Figur
{
	char figurTyp;
	bool figurFarbe;
public:
	Figur();
	Figur(char, bool);
	char get_figurTyp() { return figurTyp; }
};

