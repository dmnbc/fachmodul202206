// BewegungenAufDemSchachbrett.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>

bool isDiagonal(std::string eingabe)
{
    return abs(eingabe[0] - eingabe[2]) 
        == abs(eingabe[1] - eingabe[3]); // Änderung in der Zeile
}

bool isVertical(std::string eingabe) // A4C4
{
    return eingabe[0] == eingabe[2];
}

bool isHorizontal(std::string eingabe)
{
    return eingabe[1] == eingabe[3];
}

bool isPferdBewegung(std::string eingabe)
{
    return abs(eingabe[1] - eingabe[3]) == 1 && abs(eingabe[0] - eingabe[2]) == 2
        || abs(eingabe[1] - eingabe[3]) == 2 && abs(eingabe[0] - eingabe[2]) == 1;
}

int main()
{
    std::cout << "Bitte einen Zug eingeben :";
    std::string eingabe;
    std::cin >> eingabe; // z.B:   A2B3

    // Analyse des Zuges
    if (isDiagonal(eingabe))
        std::cout << "als diagonaler Zug erkannt\n";
    if (isVertical(eingabe))
        std::cout << "als vertikaler Zug erkannt\n";
    if (isHorizontal(eingabe))
        std::cout << "als horizontaler Zug erkannt\n";
    if (isPferdBewegung(eingabe))
        std::cout << "als Springer-Zug erkannt\n";


}

