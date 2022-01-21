//
//  Utill.h
//  PROJEKT 17c s24270 gra_rpg
//
//  Created by Kasper Serżysko on 18/12/2021.
//

#ifndef utill_h
#define utill_h
#include <thread>
#include <cstring>
class Utilities {
    
    
public:
    static int randomNumber(int x){
        srand((unsigned int)time(NULL));
        int random = rand() % x;
        return random;
    }
    static int randomExp(int x){
        srand((unsigned int)time(NULL));
        int random = rand() % x + 1;
        return random;
    }
    static void sleepFor(int n){
        std::chrono::milliseconds timespan(n);
        std::this_thread::sleep_for(timespan);
    }
    static void placeHolder(){
        sleepFor(500);
        std::cout<<".";
        sleepFor(500);
        std::cout<<".";
        sleepFor(500);
        std::cout<<".";
        sleepFor(1500);
    }
    static void writeText(std::string text){
          char tab[1024];
          strcpy(tab, text.c_str());
          for (char letter : tab){
          std::cout<<letter; 
          sleepFor(200);             
          } 
           std::cout<<std::endl;
}
    static void clearScreen(){
        int n = 3;
           for (n = 0; n < 10; n++)
             printf( "\n\n\n\n\n\n\n\n\n\n" );
    }
    
    static void errorMessage(){
        std::cout<<"Zła komenda, spróbuj jeszcze raz!"<<std::endl;
        std::cout<<".";
        sleepFor(500);
        std::cout<<".";
        sleepFor(500);
        std::cout<<".";
        sleepFor(1500);
    }
    
    static void errorWrongWay(){
        std::cout<<"Nie możesz tam pójść, spróbuj wybrać inną drogę"<<std::endl;
        std::cout<<".";
        sleepFor(500);
        std::cout<<".";
        sleepFor(500);
        std::cout<<".";
        sleepFor(1500);
    }
    static int randomInt(){
        srand((unsigned int)time(NULL));
        int random = rand() % 100 + 1;
        return random;
    }
    static int randomItem(){
        srand((unsigned int)time(NULL));
        int random = rand() % 3;
        return random;
    }

    static char getInput(std::string s){
        char r;

        if ( !getline( std::cin, s ) ){    // reads a whole line
        return '9';

        }else if ( s.size() != 1 ){
        return '9';

        }else{
            r = s[0];
            return tolower(r);
        }
    }
    
};

#endif /* Utill_h */
