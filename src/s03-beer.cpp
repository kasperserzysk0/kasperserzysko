#include <iostream>

int main()
{
	int n;
	int a;
	std::cout <<"Podaj liczbę: ";
	std::cin>>n;
	a=n;
	for(a; a>=1; a--){
		std::cout<<a<<" bottles of beer on the wall, "<<a<<" bottles of beer.\nTake one down, pass it around, "<<(a-1)<<" bottles of beer on the wall.\n";
		}
	std::cout<<"No more bottles of beer on the wall, no more bottles of beer. Go to the store and buy some more, "<<n<<" bottles of beer on the wall...\n";
	
	
	}
