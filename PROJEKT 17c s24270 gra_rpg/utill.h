//
//  Utill.h
//  PROJEKT 17c s24270 gra_rpg
//
//  Created by Kasper Serżysko on 18/12/2021.
//

#ifndef utill_h
#define utill_h
#include <thread>
class Utilities {
    
    
public:
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
    
};

#endif /* Utill_h */
