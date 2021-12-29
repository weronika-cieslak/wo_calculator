// Calculator.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "Calc.h"
int main()
{
	Calc test = Calc();
	test.set_values("7f4j6");
	test.set_values("twojast+15478fhjf/59");
	std::vector<std::string> ret = test.values;
	
	test.convert_values();
	for (int i = 0; i < test.int_values.size(); i++) {
		std::cout << test.int_values[i] << " ";
	}
	test.set_values("7f4j6");
	test.set_values("twojast+15478fhjf/59");
	std::cout << "after\n";
	test.convert_values();
	for (int i = 0; i < test.int_values.size(); i++) {
		std::cout << test.int_values[i] << " ";
	}
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
