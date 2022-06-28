#include "Tag.h"
#include <iostream>
#include <array>

std::array<std::string, 7> wochentag
{ "So","Mo","Di","Mi","Do","Fr","Sa" };

void Tag::set_text(std::string t)
{
	text = t;
}
void  Tag::set_nameWochentag(std::string nW)
{
	nameWochentag = nW;
}
void  Tag::set_laufenderTagImMonat(int n)
{
	laufenderTagImMonat = n;
}
std::string Tag::get_text()
{
	return text;
}
std::string Tag::get_nameWochentag()
{
	return nameWochentag;
}
int    Tag::get_laufenderTagImMonat()
{
	return laufenderTagImMonat;
}

void Tag::tag_Anzeige()
{
	std::cout << nameWochentag << ": " 
		      << laufenderTagImMonat << ".\t" 
		      << text << "\n";
}

Tag::Tag()
{
	std::cout << "Ein Tag wird angelegt\n";
}

Tag::Tag(int n)
{
	laufenderTagImMonat = n;
	nameWochentag = wochentag[n % 7];
}
