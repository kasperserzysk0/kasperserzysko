#include <iostream>


int main(){
	std::srand(time(NULL));
	int random_number = rand()%100+1;
	int guessed;
	
	do{
		std::cout<<"Zgadnij liczbę od 1 do 100\n";
		std::cin>>guessed;
		if(guessed < random_number){
				std::cout<<"Liczba jest za mała!\n";
			}
		if(guessed > random_number){
			std::cout<<"Liczba jest za duża!\n";
			}
		}while(guessed != random_number);
	std::cout << "\nZgadłeś, twoja liczba to " << random_number;
	
	}
