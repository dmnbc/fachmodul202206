#include "Feld.h"

Feld::Feld()
{

}
Feld::Feld(char zeile, char spalte) 
{
	hell = ((zeile + spalte) % 2);  // errechnet 0 oder 1, false oder true 
	int caseSelector = ((zeile+1) % 2 * 32);
	int figurFarbe = (zeile + 1) % 2;

	switch (zeile)
	{
	case '2':
	case '7':
		figur = new Figur('B'+(zeile%2*32), zeile%2); // ctor
		break;
	case '1':
	case '8':
		switch (spalte)
		{
		case 'A':
		case 'H':
			figur = new Figur('T' + caseSelector, figurFarbe);
			break;
		case 'B':
		case 'G':
			figur = new Figur('S' + caseSelector, figurFarbe);
			break;
		case 'C':
		case 'F':
			figur = new Figur('L' + caseSelector, figurFarbe);
			break;
		case 'D':
			figur = new Figur('D' + caseSelector, figurFarbe);
			break;
		case 'E':
			figur = new Figur('K' + caseSelector, figurFarbe);
			break;
		default:
			figur = new Figur('x', true);
		 }
		 
		break;
	default:
		figur = new Figur('x', true);
	}
}