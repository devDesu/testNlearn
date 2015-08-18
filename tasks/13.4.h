#ifndef TASK_13_4_H_INCLUDED
#define TASK_13_4_H_INCLUDED
#include <iostream>
#include <cstring>
using namespace std;
class Port // портвейн
{
private:
    char * brand;
    char style[20]; // например, tawny (золотистый),
// ruby (рубиновый), vintage (марочный)
    int bottles;
public:
    Port(const char * br = "none", const char * st = "none", int b = 0) {
        brand = new char[strlen(br)+1];
        strcpy(brand, br);
        strcpy(style, st);
        bottles = b;
    };
    Port(const Port& p) { // конструктор копирования
        brand = new char[strlen(p.brand)+1];
        strcpy(brand, p.brand);
        strcpy(style, p.style);
        bottles = p.bottles;
    }
    virtual ~Port() {
        delete [] brand;
    }
    Port& operator=(const Port& p){
        if(&p == this)
            return *this;
        delete [] brand;
        brand = new char[strlen(p.brand)+1];
        strcpy(brand, p.brand);
        strcpy(style,p.style);
        bottles = p.bottles;
        return *this;
    }
    Port& operator+=(int b) {
        bottles+=b;
    }; // добавляет b к bottles
    Port& operator-= (int b) {
        if(b<=bottles) bottles-=b;
    }; // вычитает b из bottles, если это возможно
    int BottleCount() const {
        return bottles;
    }
    virtual void Show() const {
        cout<<"Brand: "<<brand<<endl;
        cout<<"Kind: "<<style<<endl;
        cout<<"Bottles: "<<bottles<<endl;
    }
    friend ostream& operator<<(ostream& os, const Port& p) {
        os<<p.brand<<", "<<p.style<<", "<<p.bottles;
        return os;
    }
};

class VintagePort : public Port // style обязательно = "vintage"
{
private:
    char * nickname; // т.е. "The Noble", "Old Velvet" и т.д.
    int year; // год сбора
public:
    VintagePort():Port(){};
    VintagePort(const char * br, int b, const char * nn, int y):Port(br, "vintage", b), year(y){
        nickname = new char[strlen(nn)+1];
        strcpy(nickname, nn);
    }
    VintagePort(const VintagePort & vp):Port(vp){
        year = vp.year;
        nickname = new char[strlen(vp.nickname)+1];
        strcpy(nickname,vp.nickname);
    }
    ~VintagePort() {
        delete [] nickname;
    }
    VintagePort& operator=(const VintagePort & vp){
        if(&vp == this)
            return *this;
        Port::operator=(vp);
        year = vp.year;
        delete [] nickname;
        nickname = new char[strlen(vp.nickname)+1];
        strcpy(nickname, vp.nickname);
        return *this;
    }
    void Show() const{
        Port(*this).Show();
        cout<<"Year: "<<year<<endl;
        cout<<"Nickname: "<<nickname<<endl;
    }
    friend ostream& operator<<(ostream & os, const VintagePort & vp){
        os<<(const Port&) vp<<", "<<vp.year<<", "<<vp.nickname<<endl;
        return os;
    }
};

void test134(){
    Port p("Gallo", "ruby", 10);
    cout<<p<<endl;
    p.Show();
    VintagePort test("G2", 10, "py", 3);
    VintagePort test2("I8", 8, "js", 14);
    test.Show();
    test2+=2;
    cout<<test2;
    test2 = test;
    test2.Show();
}
#endif // TASK_13_4_H_INCLUDED
