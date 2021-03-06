#ifndef student
#define student
#include <iostream>

struct Student
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
#endif
