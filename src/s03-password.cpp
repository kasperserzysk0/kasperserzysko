#include <iostream>

int main(){
std::cout<<"Podaj hasło\n";
std::string password;
std::cin>>password;
std::string password_check;
do{
	std::cout<<"Sprawdź hasło:\n";
	std::cin>> password_check;
	if(password_check != password)
	{
		std::cout<<"Złe hasło!";
	}
	}while(password_check!=password);
	std::cout << "Dobre hasło!\n";
	return 0;
}
