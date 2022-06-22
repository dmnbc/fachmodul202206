// chessMuster.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

bool testPhase = false;

#include <iostream> // ein und ausgabe methoden laden 
#include <array>
char hell   = 219;
char dunkel = 176;
int ausdehnung = 10;
int zeile;
int spalte;
int zug = 1;
std::array<std::array<unsigned char, 10>, 10>   spielfeld; 
int vonSpalte, vonZeile, nachSpalte, nachZeile;

void spielstand_anzeigen()
{
	system("CLS");
	std::cout << "Der aktuelle Spielstand\n\n";
	for (std::array<unsigned char,10> zeile : spielfeld)
	{
		for (char spalte : zeile)
		{
			std::cout << spalte;
		}
		std::cout << std::endl;
	}
}

void grundstellung()
{
	for (zeile = 0; zeile < ausdehnung; zeile++)
	{
		for (spalte = 0; spalte < ausdehnung; spalte++)
		{
			switch (zeile) // if ( zeile == 0 || zeile == 9 )
			{
			case 0: case 9: // oberste oder letzte Zeile mit Umrandung
				if ((spalte) == 0 || (spalte) == 9)
				{
					spielfeld[zeile][spalte] = '*';
					// std::cout << '*';   // die vier Ecken 
				}
				else
				{
					spielfeld[zeile][spalte] = char(spalte + 64); // ASCII Buchstaben ab 64 
				}
				break;
			case 2: case 7:  // Zeilen mit Bauern füllen
				if (spalte > 0 && spalte < 9)
				{				
						spielfeld[zeile][spalte] = ((zeile % 2 == 0)?'B': 'b');			
				}
				else
				{
					spielfeld[zeile][spalte] = char(zeile + 48);
				}
				break;
			case 1: case 8:
				switch (spalte)
				{
				case 1: case 8:
					if (zeile % 2 != 0)
					{
						spielfeld[zeile][spalte] = 'T';
					}
					else
					{
						spielfeld[zeile][spalte] = 't';
					}
					break;
				case 2: case 7:
					if (zeile % 2 != 0)
					{
						spielfeld[zeile][spalte] = 'P';
					}
					else
					{
						spielfeld[zeile][spalte] = 'p';
					}
					break;
				case 3: case 6:
					if (zeile % 2 != 0)
					{
						spielfeld[zeile][spalte] = 'L';
					}
					else
					{
						spielfeld[zeile][spalte] = 'l';
					}
					break;
				case 4:
					if (zeile % 2 != 0)
					{
						spielfeld[zeile][spalte] = 'D';
					}
					else
					{
						spielfeld[zeile][spalte] = 'd';
					}
					break;
				case 5:
					if (zeile % 2 != 0)
					{
						spielfeld[zeile][spalte] = 'K';
					}
					else
					{
						spielfeld[zeile][spalte] = 'k';
					}
					break;

				default:
					spielfeld[zeile][spalte] = char(zeile + 48);
				}

				break;
			default:              // auf dem Spielfeld Zeile 1 bis 8
				switch (spalte)
				{
				case 0: case 9:   // erste oder letzte Spalte mit Ziffern
					spielfeld[zeile][spalte] = char(zeile + 48); // ASCII Ziffern ab 48
					break;
				default:
					if ((zeile + spalte) % 2) // 
						spielfeld[zeile][spalte] = hell;
					else
						spielfeld[zeile][spalte] = dunkel;
				}
			}
		}
		// std::cout << std::endl;
	}
}

// Überprüfen der Regeln
bool zugErlaubt() 
{
	bool ok = false;
	// ist der Zug noch auf dem Spielfeld -> indizes müssen zwischen 1 und 8 liegen
	if (vonZeile >= 1 && vonZeile <= 8
		&& vonSpalte >= 1 && vonSpalte <= 8
		&& nachZeile >= 1 && nachZeile <= 8
		&& nachSpalte >= 1 && nachSpalte <= 8)
	{
		ok = true;
	}

	if (spielfeld[vonZeile][vonSpalte] == dunkel 
	|| spielfeld[vonZeile][vonSpalte]  == hell)
	{
		ok = false;
	}

	if (zug % 2 == 0 && isupper(spielfeld[vonZeile][vonSpalte]) == 0
	 || zug % 2 != 0 && isupper(spielfeld[vonZeile][vonSpalte]) != 0)
	{
		ok = true;
	}
	else
	{
		ok = false;
	}

	return ok;
}  

void userEingabe()
{
	std::string vonWo, nachWo;
	if (testPhase) { std::cout << __LINE__ << "\n"; }
	std::cout << "Bitte geben Sie die Startkoordinaten der Figur an :";
	std::cin >> vonWo; if (testPhase) { std::cout << __LINE__ << "\n"; }
	std::cout << "Bitte geben Sie die Zielkoordinaten der Figur an :";
	std::cin >> nachWo; if (testPhase) { std::cout << __LINE__ << "\n"; }
	if (testPhase)
	{
		std::cout << "Es wird der Zug " << vonWo << " nach " << nachWo << " berechnet\n";
	}
	vonZeile = vonWo[1] - 48;
	vonSpalte=    toupper(vonWo[0]) - 64;  // Umrechnung von ASCII in int
	nachZeile =  nachWo[1] - 48;
	nachSpalte = toupper(nachWo[0]) - 64;

	if (testPhase)
	{
		std::cout << "Es wird der Zug spielfeld[" << vonZeile << "][" << vonSpalte << "] nach spielfeld["
			<< nachZeile << "][" << nachSpalte << "] berechnet\n";
		std::cout << "Bewegt wird die Figur " << spielfeld[vonZeile][vonSpalte] << "\n";
	}
}

void ersetzFeld(int vonZeile, int vonSpalte)
{
	if ((vonZeile + vonSpalte) % 2) 
		spielfeld[vonZeile][vonSpalte] = hell;
	else
		spielfeld[vonZeile][vonSpalte] = dunkel;
	
}

void figurBewegen()
{
	spielfeld[nachZeile][nachSpalte] = spielfeld[vonZeile][vonSpalte];
	ersetzFeld(vonZeile, vonSpalte);
}



int main()
{
	grundstellung();
	spielstand_anzeigen();
	if (testPhase) { std::cout << __LINE__ << "\n"; }
	
	for (zug; zug <= 10; )
	{
		std::cout << "Es ist Spieler " << (zug % 2 ?'1':'2') << " am Zug\n";
		userEingabe();
		while (!zugErlaubt())
		{
			std::cout << "Der Zug ist nicht erlaubt ! Bitte einen regelkonformen Zug eingeben\n";
			userEingabe();
		}   // ein gültiger Zug wurde angefordert
		zug++;
		figurBewegen();
		spielstand_anzeigen();
		std::cout << "Es folgt Zugnummer :" << zug << std::endl;
		
	}
}

