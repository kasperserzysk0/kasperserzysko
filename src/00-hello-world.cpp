/*
 * The very first program you should write in any new programming language.
 */


#include <iostream>


auto main() -> int
{
	std::string name;
	std::cout << "Podaj imie:\n";
	std::cin >> name;
	std::cout << "Hello, World! " + name + "\n";
	return 0;
}
