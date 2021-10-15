#include <iostream>

int main(){
	
	int liczba;
	std::cout<<"Podaj liczbe: ";
	std::cin>>liczba;
	
	
	for(int i = 1; i <= liczba; i++){
		std::cout<<i;
		if(i%3==0 && i%5==0){
			std::cout <<" FizzBuzz\n";
			continue;
			}
		if(i%3==0){
			std::cout<< " Fizz";
			}
		if(i%5==0){
			std::cout<<" Buzz";
			}
		
		std::cout<<"\n";
		
		}
	}
