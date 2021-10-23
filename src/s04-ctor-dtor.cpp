#include <iostream>


struct Konstruktor{
    
    std::string a;
    Konstruktor(std::string a): a(a){
        std::cout << a<<std::endl;
    }
    
    ~Konstruktor(){
        a = "DESTRUCTION!";
        std::cout << a<<std::endl;
    }
};



int main(){
    Konstruktor a("KONSTRUKTOR");
    
}

