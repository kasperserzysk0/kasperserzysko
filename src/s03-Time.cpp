#include <iostream>
#include <sstream>
#include <cstdio>
#include "time.h"



int main()  {
    
    //1 CZAS
    
	Time time(17,50,2);
	std::cout<<time.to_string();
    
    //2 NEXTY
    
	std::cout<<"Dodano godzine"<<std::endl;
	time.next_hour();
	std::cout<<time.to_string();
	std::cout<<"Dodano minute"<<std::endl;
	time.next_minute();
	std::cout<<time.to_string();
	std::cout<<"Dodano sekunde"<<std::endl;
	time.next_second();
	std::cout<<time.to_string();
    
    //3 ENUMY
    
    std::cout<<time.to_string(time.time_of_day());
    
    //OPERATORY
    
    Time time2(10,12,5);
    
    // ++++++++++++++++++++++++
    
    Time time3 = time+time2;
    std::cout<<time3.to_string();
    
    // ------------------------
    
    time3 = time - time2;
    std::cout<<time3.to_string();
    
    // <<<<<<<<<<<<<<<<<<<<<<<<<<
    
    if(time<time2){
        std::cout<< "< - PRAWDA\n";
    }else{
        std::cout<< "< - FALSZ\n";
    }
    
    // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    
    if(time>time2){
        std::cout<< "> - PRAWDA\n";
    }else{
        std::cout<< "> - FALSZ\n";
    }
    
    // =============================
    
    if(time==time2){
        std::cout<< "== - PRAWDA\n";
    }else{
        std::cout<< "== - FALSZ\n";
    }
    
    // !=!=!=!=!=!=!=!=!=!=!=!=!=!=!=

    if(time!=time2){
        std::cout<< "!= - PRAWDA\n";
    }else{
        std::cout<< "!= - FALSZ\n";
    }
    
    // SEKUNDY I MINUTY DO PÓŁNOCY
    
    std::cout << "Sekundy: " << time.count_seconds() << std::endl;
    std::cout << "Minuty: " << time.count_minutes() << std::endl;
    
    // CZAS DO PÓŁNOCY
    
    Time time_to_midnight = time.time_to_midnight();
    std::cout << "Czas do północy: " << time_to_midnight.to_string() << std::endl;
}
