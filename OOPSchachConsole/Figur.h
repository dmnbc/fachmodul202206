#pragma once
class Figur
{
	char figurTyp;     // B T L usw. b t l 
	bool figurFarbe;   // wei� oder schwarz
public:
	Figur();
	Figur(char, bool);
	char get_figurTyp() { return figurTyp; }
};

