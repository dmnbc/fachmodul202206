// Einbinden der notwendigen Header
#include <iostream>    // mit std:: namespace 
using namespace std;   // erspart std:: vor jedem io-Befehl

// globale Variable des Programms

// Funktionen des Programms



int main() // hier startet die Verarbeitung 
{
	// lokale Variable der main 
	int ausdehnung = 10; // breite des spielbrettes
	cout << "Hallo Schachspieler\n";// console out für Ausgaben auf den Bildschirm
	
	// Schleife mit Zähler
	for (int zeile = 0; zeile < ausdehnung; zeile++) // 
	{
		for (int spalte = 0; spalte < ausdehnung; spalte++)
		{
			cout << (char)(spalte+64) << ":" << zeile << "  ";
		}
		cout << endl;
	}
	


	return 0; 
}

