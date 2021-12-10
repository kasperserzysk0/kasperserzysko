#include <iostream>
#include <sstream>
#include "student.h"
/*struct Student
{
	private:
	const std::string imie;
	const std::string nazwisko;
	std::string indeks;
	int semestr;
	float srednia;
	
	public:
	Student(std::string imie, std::string nazwisko,
	 std::string indeks, int semestr, float srednia) : imie(imie), nazwisko(nazwisko), indeks(indeks), semestr(semestr), srednia(srednia)
	 {};
	 std::string to_string() const{
		std::stringstream os;
		os << "imię: " << imie << "\nnazwisko: " << nazwisko << "\nindeks: " << indeks << "\nsemestr: " << semestr << "\nśrednia: "<< srednia << "\n";
    
		return os.str();
		}	
	};
*/


int main()
{
	
	Student student1("Kasper", "Serzysko", "24222", 1, 5.2);
	std::cout<<student1.to_string();
	
	
	}
