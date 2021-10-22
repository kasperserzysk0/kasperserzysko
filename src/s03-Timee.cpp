#include <iostream>
#include <sstream>
#include <cstdio>
struct Time
{
private:
	int hour;
	int minute;
	int second;
	
public:
	Time(int hour, int minute, int second): hour(hour), minute(minute), second(second){}

	
	std::string const to_string()
	{	
		int a;
		std::string b;
		a = printf("%02d:%02d:%02d",hour, minute, second);
		b = std::to_string(a);
		b.pop_back();
		return b + "\n";
		}
		
		
//NEXT FUNCS

	void next_hour()
	{
		if(hour == 23)
			{
				hour = 0;
			}
		else
			{
				hour++;
			}	
	}
	void next_minute()
	{
		if(minute == 59)
			{
				minute = 0;
			}
		else
			{
				minute++;
			}
		
	}
	void next_second()
	{
		if(second == 59)
		{
			second = 0;
		}
		else
		{
			second++;
		}
	}
		
};


int main()
{
	Time time(23,15,02);
	std::cout<<time.to_string();
	std::cout<<"Dodano godzine"<<std::endl;
	time.next_hour();
	std::cout<<time.to_string();
	std::cout<<"Dodano minute"<<std::endl;
	time.next_minute();
	std::cout<<time.to_string();
	std::cout<<"Dodano sekunde"<<std::endl;
	time.next_second();
	std::cout<<time.to_string();
	}
