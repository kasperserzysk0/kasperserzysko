#include <iostream>

int main(int argc, char* argv[]){
std::string password_check;
    std::string password = argv[1];
if(argc != 2)
{
    std::cout <<"Błędna ilość argumentów";
    return 1;
}
do{
	std::cout<<"Podaj hasło:\n";
	std::cin>> password_check;
	if(password_check != password)
	{
		std::cout<<"Złe hasło!\n";
	}
	}while(password_check!=password);
	std::cout << "Dobre hasło!\n";
	return 0;
}
