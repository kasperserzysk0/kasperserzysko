#ifndef itemz
#define itemz

class Creature
{
    std::string name;

public:
    int hp_points;
    Creature(std::string name, int hp_points) : name(name), hp_points(hp_points)
    {}
    void get_hp(){
        std::cout<<"Przeciwnik: "<<name<<" Pozostało "<<hp_points<<"HP"<<std::endl;
    }
};

class Item
{
public:
    virtual void use_on(Creature& creature) = 0;
    
    virtual int strength() const = 0;
};

class Weapon : public Item
{
public:
    void use_on(Creature& creature){
        creature.hp_points = creature.hp_points + strength();
    }
    int strength() const{
        return -10;
    }
    
};
class Sword : public Weapon
{
    void use_on(Creature& creature){
        std::cout<<"Użyto miecza"<<std::endl;
        creature.hp_points = creature.hp_points + strength();
    }
    int strength() const{
        return -20;
    }
};
class Axe : public Weapon
{
    void use_on(Creature& creature){
        std::cout<<"Użyto topora"<<std::endl;
        creature.hp_points = creature.hp_points + strength();
    }
    int strength() const{
        return -30;
    }
};
class Bow : public Weapon
{
    void use_on(Creature& creature){
        std::cout<<"Użyto łuku"<<std::endl;
        creature.hp_points = creature.hp_points + strength();
    }
    int strength() const{
        return -15;
    }
};

class Potion : public Item
{
public:
    void use_on(Creature& creature){
        creature.hp_points = creature.hp_points + strength();
    }
    int strength() const{
        return 10;
    }
};
class Hp_Potion : public Potion
{
public:
    int times_used = 0;
    void use_on(Creature& creature){
        
        if(times_used < 2){
            std::cout<<"Użyto mikstury"<<std::endl;
            creature.hp_points = creature.hp_points + strength();
            this->times_used += 1;
        }else std::cout << "Nie możesz użyć więcej razy" << std::endl;
    }
    int strength() const{
        return 15;
    }
};

#endif
