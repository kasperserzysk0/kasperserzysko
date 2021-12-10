#include <iostream>
#include "itemz.h"




int main(){
    
    Creature ork("uruk", 100);
    Item* bron = new Weapon();
    Item* misktura = new Potion();
    Item* miecz = new Sword();
    Item* topor = new Axe();
    Item* luk = new Bow();
    Item* hp_mix = new Hp_Potion();
    miecz->use_on(ork);
    ork.get_hp();
    topor->use_on(ork);
    ork.get_hp();
    hp_mix->use_on(ork);
    ork.get_hp();
    luk->use_on(ork);
    ork.get_hp();
    hp_mix->use_on(ork);
    ork.get_hp();
    hp_mix->use_on(ork);
    


   

}
