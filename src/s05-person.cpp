#include <iostream>

class Person
{
	protected:
	std::string imie;
	std::string nazwisko;
	
	public:
	Person(std::string name, std::string nazwisko) : imie(imie), nazwisko(nazwisko) 
	{}
	
	virtual std::string to_string() const = 0;
	
	};
class Mr : public Person{
	public:
	Mr(std::string name, std::string nazwisko): Person(name, nazwisko)
	{}
	std::string to_string() const{
		return "Mr " + imie + " " + nazwisko + "\n";
		}
	};
class Mrs : public Person{
	public:
	Mrs(std::string name, std::string nazwisko): Person(name, nazwisko)
	{}
	std::string to_string() const{
		return "Mrs " + imie + " " + nazwisko + "\n";
		}
	};
class King : public Person{
public:
	King(std::string name, std::string nazwisko): Person(name, nazwisko)
	{}
	std::string to_string() const{
		return "King " + imie + " " + nazwisko + "\n";
		}
	};
class Queen : public Person{
	public:
	Queen(std::string name, std::string nazwisko): Person(name, nazwisko)
	{}
	std::string to_string() const{
		return "Queen " + imie + " " + nazwisko + "\n";
		}
	};
	
class Greetings{
	public:
	virtual std::string greet(Person const& a) = 0;
	};
	
class Hello : public Greetings
{
	std::string greet(Person const& a){
		return "Hello " + a.to_string();
		}
	};
class Good_evening : public Greetings
{
	std::string greet(Person const& a){
		return "Good evening " + a.to_string();
		}
	};
class Farawell : public Greetings
{
	std::string greet(Person const& a){
		return "Farawell " + a.to_string();
		}
	};

	
	
	
	
	
//FUNKCJE
std::string who_is_it(Person const& a ){
	return a.to_string();
	}

int main(){
	Person* x = new King("fdsf", "zxcxzc");
	Person* y = new Queen("fdsf", "zxcxzc");
	Person* z = new Mr("fdsf", "zxcxzc");
	Person* v = new Mrs("fdsf", "zxcxzc");
	std::cout << who_is_it(*x) << std::endl;
	std::cout << who_is_it(*y) << std::endl;
	std::cout << who_is_it(*z) << std::endl;
	std::cout << who_is_it(*v) << std::endl;
	Greetings* rano = new Hello();
	Greetings* wieczor = new Good_evening();
	Greetings* czesc = new Farawell();
	std::cout << rano->greet(*x) << std::endl;
	std::cout << czesc->greet(*x) << std::endl;
	std::cout << wieczor->greet(*y) << std::endl;
	std::cout << rano->greet(*z) << std::endl;
	std::cout << wieczor->greet(*z) << std::endl;
	
	}
