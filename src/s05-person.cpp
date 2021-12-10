#include <iostream>
#include "personz.h"

	
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
