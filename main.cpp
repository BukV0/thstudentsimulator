#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
class Bar{
    int value = 100;
public:
    Bar(int _value = 100){
        value = _value;
    }
    void set(int x){
        value = x;
    }
    int get(){
        return value;
    }
    void add(int x){
        if(value + x <= 100 && value + x > 0){
            value+=x;
        }
        if(value + x > 100){
            value = 100;
        }
        if(value + x < 0){
            value =  0;
        }
    }
    void show(){
        int t = value;
        cout <<'[';
        for(int i = 0; i < 100;i++){
            if(t >= 0){
                cout << '=';
                t--;
            }
            else cout << ' ';
        }
        cout << ']';
        cout << ' ' << value << '/' << 100;
    }
};
class Student {
private:
    char name[51];
    char surname[51];
    Bar hp(100);  // очки здоровья персонажа
    Bar energy(100);
    Bar iq(20);
    Bar sanity(100);
    Bar excitement(50);
    int change_field(int field, int delta){
        if(field + delta <= 100 && field + delta > 0){
            return field + delta;
        }
        if(field + delta > 100){
            return 100;
        }
        if(field + delta < 0){
            return 0;
        }
    }
    void change_params(int _hp, int _energy, int _iq, int _sanity, int _excitement){
        hp = change_field(hp,_hp);
        iq = change_field(iq,_iq);
        energy = change_field(energy,_energy);
        sanity = change_field(sanity,_sanity);
        excitement = change_field(excitement,_excitement);
    }
    void apply_effects(){
        if(energy == 0) {
            change_params(-25, 0, 0, 0, 0);
        }
        if(energy == 100){
            change_params(-10,0,0,0,0);
        }
        if(sanity <= 10){
            int t = 15 - sanity;
            change_params(-t,0,0,0,0);
        }
        if(excitement < 25){
            change_params(0,0,0,-5,0);
        }
    }
public:
    Student(int _hp = 100, int _energy = 100, int _iq = 100, int _sanity = 20, int _excitement = 50){
        hp = _hp;
        energy = _energy;
        iq = _iq;
        sanity = _sanity;
        excitement = _excitement;
    }
    Student(char* name, char* surname,int _hp = 100, int _energy = 100, int _iq = 100, int _sanity = 20, int _excitement = 50){
        strcpy(this->name,name);
        strcpy(this->surname,surname);
        hp = _hp;
        iq = _iq;
        energy = _energy;
        sanity = _sanity;
        excitement = _excitement;

    }


    bool is_alive(){
        if(hp > 0){
            return true;
        }
        return false;
    }


    void show(){
        for(int i = 0; i < strlen(name);i++){
            cout << name[i];
        }
        cout << ' ';
        for(int i = 0; i < strlen(surname);i++){
            cout << surname[i];
        }
        cout << ": HP = " << setw(3) << setfill('0') << hp;
        cout << ", Energy = " << setw(3) << setfill('0') << energy;
        cout << ",  IQ = " << setw(3) << setfill('0') << iq;
        cout << ", Sanity = " << setw(3) << setfill('0') << sanity;
        cout << ", Excitement = " << setw(3) << setfill('0') << excitement << '.';
        if(is_alive() == false){
            cout << " Game over." << endl;
        }
        else
            cout << endl;
    }
    void eat(){
        if(!is_alive()) return;
        change_params(1,7,-1,0,-2);
        apply_effects();
    }
    void wait(){
        if(!is_alive()) return;
        change_params(1,-3,0,0,-3);
        apply_effects();
    }
    void sleep(){
        if(!is_alive()) return;
        change_params(2,-2,0,7,0);
        apply_effects();

    }
    void watch_tv(){
        if(!is_alive()) return;
        change_params(-2,-3,-3,1,5);
        apply_effects();
    }
    void study(){
        if(!is_alive()) return;
        change_params(-2,-4,5,-5,-2);
        apply_effects();
    }

};
int main(){
    char t1[100], t2[100];
    int hp,energy,iq,sanity,excitement;
    cin >> t1 >> t2 >> hp >> energy >> iq >> sanity >> excitement;
    Student player(t1, t2,hp,energy,iq,sanity,excitement);
    int steps = 0;
    cin >> steps;
    char token[100];
    for(int i = 0; i < steps;i++){
        cin >> token;
        if(strncmp(token,"Wait", 4) == 0){
            player.wait();
            player.show();
        }
        if(strncmp(token,"Eat",3) == 0){
            player.eat();
            player.show();
        }
        if(strncmp(token,"Study",5) == 0){
            player.study();
            player.show();
        }
        if(strncmp(token,"Sleep",5) == 0){
            player.sleep();
            player.show();
        }
        if(strncmp(token,"Watch",5) == 0){
            cin >> token;
            player.watch_tv();
            player.show();
        }
    }


    return 0;
}
