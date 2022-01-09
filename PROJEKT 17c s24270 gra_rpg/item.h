//
//  item.h
//  PROJEKT 17c s24270 gra_rpg
//
//  Created by Kasper Serżysko on 21/12/2021.
//

#ifndef item_h
#define item_h
#include"utill.h"

class Item {
    std::string name;
    int power;
    std::string items[9] = {"miecz", "łuk", "różdżka", "topór", "szabla", "pałka", "młot", "kusza", "sztylet"};    
    
public:
    Item(std::string name, int power) : name(name), power(power)
    {}
    Item(){}
    int getPower(){return power;}
    std::string getName(){return name;}

    Item* dropItem(){
            name = items[Utilities::randomNumber(8)];
            int chances = Utilities::randomInt();
        
            if (chances > 0 ){
                name = "zwykły/a " + name;
                power = 5;
            }else if (chances > 65 && chances <= 85)
            {
                name = "unikatowy/a " + name;
                power = 10;
            }else if (chances > 85 && chances <= 95)
            {
                name = "heroiczny/a " + name;
                power = 15;
            }else{
                name = "legendarny/a " + name;
                power = 20;
            }
            
        return new Item(name, power);
    }
};




#endif /* item_h */
