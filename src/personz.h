#ifndef personz
#define personz

class Person
{
    protected:
    std::string imie;
    std::string nazwisko;
    
    public:
    Person(std::string imie, std::string nazwisko) : imie(imie), nazwisko(nazwisko)
    {}
    
    virtual std::string to_string() const = 0;
    
    };
class Mr : public Person{
    public:
    Mr(std::string name, std::string nazwisko): Person(name, nazwisko)
    {}
    std::string to_string() const{
        return "Mr " + imie + " " + nazwisko + "\n";
        }
    };
class Mrs : public Person{
    public:
    Mrs(std::string name, std::string nazwisko): Person(name, nazwisko)
    {}
    std::string to_string() const{
        return "Mrs " + imie + " " + nazwisko + "\n";
        }
    };
class King : public Person{
public:
    King(std::string name, std::string nazwisko): Person(name, nazwisko)
    {}
    std::string to_string() const{
        return "King " + imie + " " + nazwisko + "\n";
        }
    };
class Queen : public Person{
    public:
    Queen(std::string name, std::string nazwisko): Person(name, nazwisko)
    {}
    std::string to_string() const{
        return "Queen " + imie + " " + nazwisko + "\n";
        }
    };
    
class Greetings{
    public:
    virtual std::string greet(Person const& a) = 0;
    };
    
class Hello : public Greetings
{
    std::string greet(Person const& a){
        return "Hello " + a.to_string();
        }
    };
class Good_evening : public Greetings
{
    std::string greet(Person const& a){
        return "Good evening " + a.to_string();
        }
    };
class Farawell : public Greetings
{
    std::string greet(Person const& a){
        return "Farawell " + a.to_string();
        }
    };



#endif
