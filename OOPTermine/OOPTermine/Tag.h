#pragma once
#include <string>
class Tag
{   // Attribute
	std::string text;
	std::string nameWochentag;
	int    laufenderTagImMonat;
public: // Deklarationen
	// getter und setter f�r die Attribute
	void  set_text(std::string);
	void  set_nameWochentag(std::string);
	void  set_laufenderTagImMonat(int);
	std::string get_text();
	std::string get_nameWochentag();
	int    get_laufenderTagImMonat();

	void  tag_Anzeige(); 

	// Konstruktor
	Tag();    // Standardkonstruktor
	Tag(int); // weiter �berladungen bei Bedarf



};

