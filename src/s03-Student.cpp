#include <iostream>
#include <sstream>

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
	 
	 std::string const to_string()
	{
		std::stringstream os;
		os << "imię: " << imie << "\nnazwisko: " << nazwisko << "\nindeks: " << indeks << "\nsemestr: " << semestr << "\nśrednia: "<< srednia << "\n";
    
		return os.str();
		}
	 
	};



int main()
{
	
	Student student("Kasper", "Serzysko", "24222", 1, 5.2);
	std::cout<<student.to_string();
	
	
	}
