#include <iostream>
#include <vector>

struct Student {
	
	//VARS
	private:
	std::string imie;
	std::string nazwisko;
	int wiek;
	int semestr;
	std::string kierunek;
	
	//CONSTRUCTOR
	public:
	Student(std::string imie, std::string nazwisko, int wiek, int semestr, std::string kierunek) : imie(imie), nazwisko(nazwisko), wiek(wiek), semestr(semestr), kierunek(kierunek){}
	
	//FUNCS
	void student_info(){
		std::cout<<" imie: " << imie <<" ,nazwisko: " << this->nazwisko << " ,wiek: " << this->wiek << " ,semestr: " << this->semestr << " ,kierunek: " << this->kierunek << std::endl;}
		
	//GETTERS	
	std::string get_imie(){return this->imie;}
	std::string get_nazwisko(){return this->nazwisko;}
	int get_wiek(){return this->wiek;}
	int get_semestr(){return this->semestr;}
	std::string get_kierunek(){return this->kierunek;}

};

//UTIL FUNCS

std::string imie(){
	std::string imie;
	std::cout<< "Podaj imie: ";
	std::cin>>imie;
	return imie;
	}
std::string nazwisko(){
	std::string nazwisko;
	std::cout << "Podaj nazwisko: ";
	std::cin>>nazwisko;
	return nazwisko;
	}
int wiek(){
	int wiek;
	std::cout <<"Podaj wiek: ";
	std::cin>>wiek;
	return wiek;
	}
int semestr(){
	int semestr;
	std::cout << "Podaj semestr: ";
	std::cin >> semestr;
	return semestr;
	}
std::string kierunek(){
	std::string kierunek;
	std::cout << "Podaj kierunek: ";
	std::cin >> kierunek;
	return kierunek;
	}
void studentList(std::vector<Student*> vectorStudent){
	int i=0;
	for( Student* student : vectorStudent){					
	std::cout << i << " ";
	student->student_info();
	i++;
	}
}


int main(){
	std::vector<Student*> vectorStudent;
	
	//APP WOKRING
	while(true){
		int in;
		
		std::cout<<"\n1) - dodaj studenta\n2) - usun studenta\n3) pokaz liste sudentow\n0) - Exit\n"<<std::endl;
		std::cin>>in;
		switch(in){
			
			//ADDING STUDENT
			case 1:
				vectorStudent.push_back(new Student(imie(),nazwisko(),wiek(),semestr(),kierunek()));
				std::cout << "Dodano studenta!" << std::endl;
				break;
				
			//ERASING STUDENT	
			case 2:
				if (vectorStudent.empty()){
					std::cout << "Brak studentow" << std::endl;
					break;
				}else{
					int del;
					studentList(vectorStudent);
					std::cout << "Podaj nr studenta do usuniecia: ";
					std:: cin >> del;
					if(del < 0 || del > vectorStudent.size()){
						std::cout<<"Zly indeks"<<std::endl;
						break;
						}else{
					vectorStudent.erase(vectorStudent.begin()+(del - 1));
					std::cout << "Student usuniety"<<std::endl;
					break;
				}
			}
			//LIST VIEW	
			case 3:
				studentList(vectorStudent);
				break;
			
			case 0:
				exit(1);
				break;
			default:
				std::cout << "Zly indeks"<<std::endl;
				break;
		}
	
	}
}
