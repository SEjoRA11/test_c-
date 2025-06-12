#include <iostream>
#include <string>
using namespace std;


// class Apple;
// class Human{
// public:
//     void takeApple(Apple& apple);
// };
// class Apple{
// private:
//     int weight;
//     string color;
//     int id;
//     static int count;
// public:
//     Apple(int weight, string color){
//         this -> weight = weight;
//         this -> color = color;
//         count++;
//         id += count;
//     }
//     int getId(){
//         return id;
//     }
//     static int getCount(){
//         return count;
//     }
//     static void changeColor(Apple &apple, string color){
//         apple.color = color;
//     }
//     friend void Human::takeApple(Apple &apple);
// };
// class Image{
// private:
//     static const int lenpixel = 5;
//     Pixel pixels[lenpixel]{
//         Pixel(0, 4, 64),
//         Pixel(203, 204, 114),
//         Pixel(210, 124, 224),
//         Pixel(112, 224, 164),
//         Pixel(8, 43, 12)
//     };
// public:
//     void getImageInfo(){
//         for (int i =0; i < lenpixel; i++){
//             cout<< "# "<< i << " " << pixels[i].getInfo() << endl;
//         }
//     }
// };
// class Pixel{
//     private:
//         int r;
//         int g;
//         int b;
//     public:
//         Pixel(){
//             r = g = b = 0;
//         }
//         Pixel(int r, int g, int b){
//             this -> r = r;
//             this -> g = g;
//             this -> b = b;
//         }
//         string getInfo(){
//             return "Pixel r= "+to_string(r)+" g= "+to_string(g)+" b= "+to_string(b);
//         }
// };
// class Cap{
// private:
//     string color = "red";
// public:
//     string getColor(){
//         return color;
//     }
// };
// class Model{
// public:
//     void inspectModel(){
//         cout << "Mоя кепка " << cap.getColor() << " цвета" << endl;
//     }
// private:
//     Cap cap;
// };
// class Human{
// public: 
//     void think(){
//         brain.think();
//     }
//     void inspectTheCap(){
//         cout << "Mоя кепка " << cap.getColor() << " цвета" << endl;
//     }
// private:
//     class Brain{
//     public:
//         void think(){
//             cout << "Я думаю" << endl;
//         }
//     };
//     Brain brain;
//     Cap cap;
// };
// class Human{
// private: 
//     string name ;
// public: 
//     void setName(string name){
//         this -> name = name;
//     }
//     string getName(){
//         return name;
//     }
// };
// class Student : public Human {
// public:
//     string group;
//     void learn(){
//         cout << "Я учусь!" << endl;
//     }
// };
// class Professor : public Human {
//     string subject;
// };
// class ExtramuralStudent : public Student{
// public:
//     void learn(){
//         cout << "Я хожу на пары реже обычного студента!" << endl;
//     }
// };
// class A{
// private:
// string msg;
// public:
//     A(){
//         msg = "Пустое сообщение!" ;
//     }
//     A(string msg){
//         this ->msg = msg;
//     }
//     void printMsg(){
//         cout << msg << endl;
//     }
// };
// class B : public A{
// public:
//     B() : A("Ghhdh") {
//     }
// };
// class Weapon{
// public:
//     virtual void shoot() = 0; 
// };
// class Gun : public Weapon{
// public: 
//     void shoot() override{
//         cout <<"BANG!" <<endl;
//     }
// };
// class SubmachinGun : public Gun{
// public:
//     void shoot() override{
//         cout << "BANG! BANG! BANG!" <<endl;
//     }
// };
// class Knife : public Weapon{
// public:
//     void shoot() override{
//         cout << "wjoohh!"<<endl;
//     }
// };
// class Player{
// public:
//     void shoot(Weapon*gun){
//         gun->shoot();
//     }
// };
// class A{
// public:
//     A(){
//     }
//     virtual ~A() = 0;
// };
// A::~A(){};
// class B : public A{
// public:
//     B(){
//         cout << "выдклкна динамическая память B!" << endl;
//     }
//     ~B() override {
//         cout << "Освобождена динамическая память B!" << endl;
//     }
// };
// class Human{
// public:
//     Human(string name){
//         this ->name = name;
//         this ->age = 0;
//         this ->weight = 0;
//     }
//     Human(string name, int age):Human(name){
//         this ->age = age;
//     }
//     Human(string name, int age, int weight):Human(name, age){
//         this ->weight = weight;
//     }
//     string name;
//     int age;
//     int weight;
// };


class Car{
public:
    void Drive(){
        cout << "Я еду!"  << endl;
    }
};

class Airplain{
public:
    void Fly(){
        cout << "Я лечу!" << endl;
    }
};

class FlyingCar:public Car , public Airplain{

};

int main(){
    FlyingCar fc;
    fc.Drive();
    fc.Fly();

    return 0;
} 

