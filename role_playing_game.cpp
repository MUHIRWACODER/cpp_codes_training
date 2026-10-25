#include<iostream>
using namespace std;
class Character{
    private:
    string name;
    int health;
    public:
    Character(string n, int h){
        name=n;
        health=h;
    }
    virtual ~Character(){

    }
    virtual void useAbility(){
        cout<<"character performs a basic action"<<endl;

    }


    
};
class Warrior : public Character{
    public:
    string name;
    int health;

    public:
    Warrior(string n,int h):Character(n,h){}

    void useAbility() override{
        cout<<"[warrior] swings a massive claymore!"<<"\n";


    }
};
class Mage: public Character{

    public:
    string name;
    int health;
    Mage(string n,int h):Character(n,h){

    }

    void useAbility() override{
        cout<<"[Mage] casts a blazing fireball!"<<"\n";

    }
};
class Rogue: public Character{
    public:
    string name;
    int health;

    public:
    Rogue(string n, int h):Character(n,h){
        name=n;
        health=h;
    }

    void useAbility() override{
        cout <<"[Rogue] executes a stealth backstab!"<<"\n";
    }
};
int main(){
    Character *party[3];
    Warrior w("jules",100);

    Mage m("jacob",87);
    Rogue r("anac",76);
    party[0]=&w;
    party[1]=&m;
    party[2]=&r;
    for(int i=0;i<3;i++){
        party[i]->useAbility();
    }
}
