#include <iostream>
#include <sstream>
#include <cstdio>

enum class Time_of_day{MORNING,NOON,AFTERNOON,NIGHT};



struct Time{

//*******KONSTRUKTORY********
private:
	int hour;
	int minute;
	int second;
	
public:
	Time(int hour, int minute, int second): hour(hour), minute(minute), second(second){}
    Time(){}
	
	std::string const to_string(){
		int a;
		std::string b;
		a = printf("%02d:%02d:%02d",hour, minute, second);
		b = std::to_string(a);
		b.pop_back();
		return b + "\n";
		}
		
//*******FUNKCJE NEXT********

	void next_hour(){
		if(hour == 23){
				hour = 0;
        }else{
				hour++;
			}}
    
	void next_minute(){
		if(minute == 59){
				minute = 0;
				hour++;
        }else{
				minute++;
			}}
    
	void next_second(){
		if(second == 59){
			second = 0;
			minute++;
        }else{
			second++;
        }}
    
    //*******ENUMY********
    
    Time_of_day const time_of_day(){
        Time_of_day rano = Time_of_day::MORNING;
        Time_of_day dzien = Time_of_day::NOON;
        Time_of_day wieczor = Time_of_day::AFTERNOON;
        Time_of_day noc = Time_of_day::NIGHT;
        
        if (hour>=6 && hour<12) return rano;
        if (hour>=12 && hour<16) return dzien;
        if (hour>=16 && hour<20) return wieczor;
        else return noc;
    }
		std::string to_string(Time_of_day r){
            std::stringstream os;
            std::string pora_dnia = "hihi";
            if(r == Time_of_day::MORNING) pora_dnia = "rano";
            if(r == Time_of_day::NOON) pora_dnia = "dzień";
            if(r == Time_of_day::AFTERNOON) pora_dnia = "wieczór";
            if(r == Time_of_day::NIGHT) pora_dnia = "noc";
            
            os << "Pora dnia: "<< pora_dnia<< std::endl;
            return os.str();
        }
    
    //*******OPERATORY********
    
    Time const operator+ (Time const& time2){
        Time time;
        time.second = second + time2.second;
        time.minute = minute + time2.minute;
        time.hour = hour + time2.hour;
        if(time.second>60){
            time.second = time.second - 60;
            time.minute++;
        }if(time.minute>59){
            time.minute = time.minute - 60;
            time.hour++;
        }if(time.hour >23) time.hour = time.hour-24;
        
        return time;
    }
    Time const operator- (Time const& time2){
        Time time;
        time.second = second - time2.second;
        time.minute = minute - time2.minute;
        time.hour = hour - time2.hour;
        if(time.second<0){
            time.second = time.second + 60;
            time.minute--;
        }if(time.minute<0){
            time.minute = time.minute + 60;
            time.hour--;
        }if(time.hour <0) time.hour = time.hour+24;
        
        return time;
    }
        
    bool const operator< (Time const& time2){
        if(hour < time2.hour) return true;
        if(hour == time2.hour){
            if(minute < time2.minute) return true;
            else if(minute == time2.minute){
                if(second <time2.second) return true;
                else return false;
            }
            else return false;
        }
        else return false;
    }
    
    bool const operator> (Time const& time2){
        if(hour > time2.hour) return true;
        if(hour == time2.hour){
            if(minute > time2.minute) return true;
            else if(minute == time2.minute){
                if(second > time2.second) return true;
                else return false;
            }
            else return false;
        }
        else return false;
    }
    
    bool const operator== (Time const& time2){
        if(hour == time2.hour && minute == time2.minute && second == time2.second) return true;
        else return false;
    }
    
    bool const operator!= (Time const& time2){
        if(hour != time2.hour || minute != time2.minute || second || time2.second) return true;
        else return false;
    }
    
    //SEKUNDY DO PÓŁNOCY
    
    unsigned int const count_seconds(){
        int a = hour * 60 * 60 + minute * 60 + second;
        return a;
    }
    
    unsigned int const count_minutes(){
        int a = hour * 60 + minute * 60;
        return a;
    }
    
    Time const time_to_midnight(){
        int h,min,sec;
        h = 24 - hour;
        min = 60 - minute;
        sec = 60 - second;
        
        Time time(h,min,sec);
        return time;
    }
};


int main()  {
    
    //1 CZAS
    
	Time time(9,50,2);
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
