//
//  character.h
//  PROJEKT 17c s24270 gra_rpg
//
//  Created by Kasper Serżysko on 17/12/2021.
//

#ifndef character_h
#define character_h
#include "areas.h"
#include <map>
#include "utill.h"
#include "item.h"

class Hero {
    int posX = 0;
    int posY = 0;
    int lvl = 0;
    int max_hp = 1000;
    int hp = max_hp;
    int exp = 0;
    int exp_to_lvlup = 20;
    bool has_item = false;
    int gold = 0;

    Item* current_item;
    Location* current_location;
    std::string location;
    Areas area;
    Item item;
    
    
    //**************FUNKCJE CHECK*****************
    
    //funkcja sprawdza, czy zdobyliśmy nowy poziom
    void expCheck(){
        if (exp >= exp_to_lvlup){
            exp = exp - exp_to_lvlup;
            lvl = lvl + 1;
            max_hp = 100 + 5 * lvl;
            exp_to_lvlup = 2 * exp_to_lvlup;
            std::cout<<"Zyskałeś poziom "<<lvl<<std::endl;
        }
    }
    //funkcja sprawdza, czy "żyjemy"
    void hpCheck(){
        if(hp<1){
            std::cout<<"Nie żyjesz, koniec gry. Spróbuj ponownie!"<<std::endl;
            std::cout<<"Projekt prostej gry rpg,\nKasper Serżysko styczeń 2022"<<std::endl;
            Utilities::placeHolder();
            std::exit(0);
        }
    }
    
    //**************KONIEC FUNKCJI CHECK*****************
    

public:
    Hero(){
        current_location = area.getArea(0, 0);
        location = current_location->getName();
    }
    
    //Funkcja pokazuje szczegóły naszej postaci
    void statusCheckOption(){
        Utilities::clearScreen();
        std::cout<<"-STATUS-"<<std::endl;
        std::cout<<"Poziom: "<<lvl<<std::endl;
        std::cout<<"EXP: "<<exp<<"/"<<exp_to_lvlup<<std::endl;
        std::cout<<"HP: "<<hp<<"/"<<max_hp<<std::endl;
        std::cout<<"Aktualna lokalizacja: "<<location<<std::endl;
        if (!has_item)std::cout<<"Przedmiot: brak"<<std::endl;
        else std::cout<<"Przedmiot: "<<current_item->getName()<<std::endl;;
        std::cout<<"Złoto: "<<gold<<std::endl;
        std::cout<<"Wpisz cokolwiek, aby wrócić"<<std::endl;
        std::cout<<"->";
        std::string a;
        std::cin >> a;
        Utilities::placeHolder();
    }
    
    
    
private:
    
    //*********OBSŁUGA ZDARZEŃ**************
    void event(){
        
        if (current_location->getEnemy()) { 
            std::array<int,3> array_data = area.enemyEncounter(current_location->getType());
           battle(array_data);
        }

        if (current_location->getEndGame())
        {
            hp = hp - area.trapEncounter(current_location->getType());
        }
        if (current_location->getItem()){
            Item* item_dropped = item.dropItem();
            if (!has_item){
            current_item = item_dropped;
            has_item = true;
            std::cout<<"Zdobyłeś "<<item_dropped->getName()<<" ("<<item_dropped->getPower()<<")"<<std::endl;
            }else{
                char choice;
                bool done = false;
                    while(!done){
                    std::cout<<"Twój aktualny przedmiot: "<<current_item->getName();
                    std::cout<<"Zamienić na: "<<item_dropped->getName()<<" ("<<item_dropped->getPower()<<")"<<std::endl;
                    std::cout<<"y - Tak\nn - Nie"<<std::endl;
                    std::cin>>choice;
                    choice = tolower(choice);
                    switch (choice)
                    {
                        case 'y':
                            current_item = item_dropped;
                            done = true;
                            break;
                        case 'n':
                            done = true;
                            break;
                        default:
                                Utilities::errorMessage;
                            break;
                    }
                }
            }
            current_location->setItem(false);
        }
    }
    
    //**********SYSTEM PODRÓZY************
    
    /*
     Funkcja sprawdza, czy na "sąsiednich polach" istnieje jakaś lokacja, jeli tak,
     to sprawdza, czy wcześniej w niej byliśmy i wyświetla jej nazwe, jeśli nie, wyświetla "-"
     */
    void availableLocations(){
        std::string north,south,east,west;
        
        if (area.existCheck(posX, posY + 1)){
            if(!area.getArea(posX, posY + 1)->getDiscovered()){
                north = "Nieodkryto";
            }else{
                north = area.getArea(posX, posY + 1)->getName();
            }
        }else north = "-";
        if (area.existCheck(posX, posY - 1)){
            if(!area.getArea(posX, posY - 1)->getDiscovered()){
                south = "Nieodkryto";
            }else{
                south = area.getArea(posX, posY - 1)->getName();
            }
        }else south = "-";
        if (area.existCheck(posX + 1, posY)){
            if(!area.getArea(posX + 1, posY)->getDiscovered()){
                east = "Nieodkryto";
            }else{
                east = area.getArea(posX + 1, posY)->getName();
            }
        }else east = "-";
        if (area.existCheck(posX - 1, posY)){
            if(!area.getArea(posX - 1, posY)->getDiscovered()){
                west = "Nieodkryto";
            }else{
                west = area.getArea(posX - 1, posY)->getName();
            }
        }else west = "-";
        
        std::cout<<"Wybierz kierunek podróży:\nn - Północ ("<<north<<")\ns - Południe ("<<south<<")\ne - Wschód ("<<east<<")\nw - Zachód ("<<west<<")\nb - Wróć"<<std::endl;
        std::cout<<"-> ";
    }
    
    
public:
    
    //funkcja podróży
    void travelOption(){
        char choice;
        int end = 0;
        
        while (end == 0) {
            Utilities::clearScreen();
            availableLocations();
            std::cin>>choice;
            choice = tolower(choice);
            /*
             Po każdym wyborze funkcja existCheck sprawdza, czy "nie wyszliśmy" poza mapę, jeślie nie, to zmienia naszą pozycję (posX lub posY), znajduje tą pozycje na mapie (z headera "areas.h") i ustawia ją jako naszą current_location.
             */
            switch (choice) {
                case 'n':
                    if (area.existCheck(posX, posY + 1)) {
                        end = 1;
                        posY = posY + 1;
                        current_location = area.getArea(posX, posY);
                        location = current_location->getName();
                        
                    }else{
                        Utilities::errorWrongWay();
                    }
                    break;
                case 's':
                    if (area.existCheck(posX, posY - 1)) {
                        end = 1;
                        posY = posY - 1;
                        current_location = area.getArea(posX, posY);
                        location = current_location->getName();
                        
                    }else{
                        Utilities::errorWrongWay();
                    }
                    break;
                case 'e':
                    if (area.existCheck(posX + 1, posY)) {
                        end = 1;
                        posX = posX + 1;
                        current_location = area.getArea(posX, posY);
                        location = current_location->getName();
                        
                    }else{
                        Utilities::errorWrongWay();
                    }
                    break;
                case 'w':
                    if (area.existCheck(posX - 1, posY)) {
                        end = 1;
                        posX = posX - 1;;
                        current_location = area.getArea(posX, posY);
                        location = current_location->getName();
                    }else{
                        Utilities::errorWrongWay();
                    }
                    break;
                case 'b':
                    end = 2;
                    break;
                default:
                    Utilities::errorMessage();
                    break;
            }
            if (end == 1) {                                         //Po każdym przejściu do innej lokacji, wykonywany jest konkretny event, oraz sprawdznay jest stan zdrowia oraz punkty doświadczenia
                std::cout<<"Dotarłeś do " <<location<<std::endl;
                area.getArea(posX, posY)->setDiscovered(true);
                Utilities::placeHolder();
                event();
                Utilities::placeHolder();
            }
        }
    }
    //***********KONIEC SYSTEMU PODRÓŻY*************
    
    
    
    
    
    
    /*FUNKCJA ODPOCZYNKU. Podczas odpoczynku istnieje szansa zostania zaatakowanym,
     jeśli znajdujemy się w lokalizacji z przeciwnikiem. Posiadamy również szanse na
    odzyskanie większej ilości zdrowia niż normalnie*/
    
        void restOption(){
            int hp_healed;
            if (hp == max_hp){
                std::cout<<"Nie potrzebujesz odpoczynku, lepiej zrób coś pożytecznego!"<<std::endl;
            }
            else if(current_location->getEnemy()){                               //jeśli jesteśmy w lokalizacji z przeciwnikami
                int random = Utilities::randomInt();
                if (random > 80){                                           //warunek ataku z zaskoczenia
                    std::cout<<"Zostałes zaatakowany podczas odpoczynku"<<std::endl;
                    std::array<int, 3> array_data = area.enemyEncounter(current_location->getType());
                    battle(array_data);
                    
                }else if(random < 20){
                    hp_healed = 40;
                    hp = hp + hp_healed;
                    if (hp>max_hp){
                        hp_healed = hp_healed - (hp - max_hp);
                        hp = max_hp;
                        std::cout<<"Obudziłeś się wypoczęty jak nigdy dotąd, zyskałeś dodatkowe zdrowie.\nOdzyskałeś "<<hp_healed<<" HP"<<std::endl;
                    }else
                        std::cout<<"Obudziłeś się wypoczęty jak nigdy dotąd, zyskałeś dodatkowe zdrowie.\nOdzyskałeś "<<hp_healed<<" HP"<<std::endl;
                }else{
                    hp_healed = 25;
                    hp = hp + hp_healed;
                    if (hp>max_hp){
                        hp_healed = hp_healed - (hp - max_hp);
                        hp = max_hp;
                        std::cout<<"Obudziłeś się wypoczęty.\nOdzyskałeś "<<hp_healed<<" HP"<<std::endl;
                    }else
                        std::cout<<"Obudziłeś się wypoczęty.\nOdzyskałeś "<<hp_healed<<" HP"<<std::endl;
                }
            }else{                                                             //dla lokalizacji bez przeciwników
                int random = Utilities::randomInt();
                if(random < 30){
                    hp_healed = 40;
                    hp = hp + hp_healed;
                    if (hp>max_hp){
                        hp_healed = hp_healed - (hp - max_hp);
                        hp = max_hp;
                        std::cout<<"Obudziłeś się wypoczęty jak nigdy dotąd, zyskałeś dodatkowe zdrowie.\nOdzyskałeś "<<hp_healed<<" HP"<<std::endl;
                    }else
                        std::cout<<"Obudziłeś się wypoczęty jak nigdy dotąd, zyskałeś dodatkowe zdrowie.\nOdzyskałeś "<<hp_healed<<" HP"<<std::endl;
                }else{
                    hp_healed = 25;
                    hp = hp + hp_healed;
                    if (hp>max_hp){
                        hp_healed = hp_healed - (hp - max_hp);
                        hp = max_hp;
                        std::cout<<"Obudziłeś się wypoczęty.\nOdzyskałeś "<<hp_healed<<" HP"<<std::endl;
                    }else
                        std::cout<<"Obudziłeś się wypoczęty.\nOdzyskałeś "<<hp_healed<<" HP"<<std::endl;
                }
            }
            Utilities::placeHolder();
        }



        void enterShop(){
            if( current_location->getType() != shop){
                std::cout<<"W tej lokacji nie ma sklepu, spróbuj gdzieś indziej!"<<std::endl;
                return;
            }else{
                bool enter = false;
                while(!enter){
                    int choice;
                    std::cout<<"Co chciałbyś kupić?\n1 - Losowy przedmiot (100g))\n2 - Losowe doświadczenie (75g)"<<std::endl;
                    std::cin>>choice;
                    choice = tolower(choice);
                    switch (choice)
                    {
                    case 1:
                        if (gold >= 100)
                        {
                            bool enter2 = false;
                            if((gold - 100) >= 0) {
                            gold = gold - 100;
                            }else{
                                gold = 0;
                            }
                            Item* bought_item = item.dropItem();
                            
                            while (!enter2)
                            {
                                char choice2;
                                std::cout<<"Kupiłeś: "<<bought_item->getName()<<"("<<bought_item->getPower()<<")"<<std::endl;
                                std::cout<<"Twój aktualny przedmiot: "<<current_item->getName()<<"("<<current_item->getPower()<<")"<<std::endl;
                                std::cout<<"Zamienić?\ny - Tak\nn - Nie"<<std::endl;
                                std::cin>>choice2;
                                choice2 = tolower(choice2);
                                switch (choice2)
                                {
                                case 'y':
                                    current_item = bought_item;
                                    enter2 = true;
                                    break;
                                case 'n':
                                    enter2 = true;
                                    break;
                                default:
                                    Utilities::errorMessage;
                                    break;
                                }
                            }
                            
                        }else{
                            std::cout<<"Nie masz tyle złota, wróć innym razem!"<<std::endl;
                        }
                        
                        break;
                    case 2:
                        if (gold >= 75)
                        {
                            bool enter2 = false;
                            if((gold - 75) >= 0) {
                            gold = gold - 75;
                            }else{
                                gold = 0;
                            }
                            int bought_exp = Utilities::randomExp(50);
                            
                            while (!enter2)
                            {
                                char choice2;
                                std::cout<<"Kupiłeś: "<<bought_exp<<" EXP'a"<<std::endl;
                                exp = exp + bought_exp;
                                expCheck();
                            }
                            
                        }else{
                            std::cout<<"Nie masz tyle złota, wróć innym razem!"<<std::endl;
                        }

                    default:
                        Utilities::errorMessage;
                        break;
                    }
                }

            }

        }

    private:

        void battle(std::array<int, 3> array_data){
            if (has_item)
            {
                if ((array_data[0] - current_item->getPower()) < 0)
                {
                    std::cout<<"Posiadasz: "<<current_item->getName()<<" więc straciłeś: 0 punktów zdrowia"<<std::endl;
                    exp = exp + array_data[1];
                    gold = gold + array_data[2];
                }else
                    std::cout<<"Posiadasz: "<<current_item->getName()<<" więc straciłeś: "<<(array_data[0] - current_item->getPower())<<std::endl;
                    hp = hp - array_data[0] - current_item->getPower();
                    exp = exp + array_data[1];
                    gold = gold + array_data[2];
                 
            }else{
                hp = hp - array_data[0];
                exp = exp + array_data[1];
                gold = gold + array_data[2];
            }
            hpCheck();
            expCheck();
        }
};

#endif /* character_h */
