#include <iostream>
#include <string>
#include <fstream>

using namespace std;


class Point{
public:


Point(){
    x=y=z=0;
}
Point(int x, int y, int z){
    this ->x = x;
    this ->y = y;
    this ->z = z;
}
void print(){
    cout<<"X: " << x << "\tY: " << y << "\tZ: " << z << endl;
}

int x;
int y;
int z;
public:


};

int main(){
    setlocale(0, "ru");

    string path = "myFile.txt";
    // ifstream fin;
    // fin.open(path);
    // if (!fin.is_open())
    // {
    //     cout << "Ошибка открытия файла!";
    // }
    // else{
    //     cout << "Файл открылся!" <<endl;
    //     string str;
    //     while(!fin.eof()){
    //         str = "";
    //         getline(fin, str);
    //         cout << str << endl;;
    //     }
    // }
    // fin.close();

//fout.open("myFile.txt", ofstream::app);
    // if(!fout.is_open()){
    //     cout << "ошибка открытия файла!" << endl;
    // }
    // else{
    //     fout <<"это наши данные" << endl;
    //     fout<<555<<endl;;;;
    // }
    // fout.close();

    // Point a(23, 12, 1);
    // Point b(12, 3, 2);
    // ofstream fout;
    // fout.open(path, ofstream::app);
    // if (!fout.is_open()){
    //     cout << "Ошибка открытия файла!" << endl;
    //     return 1;
    // }
    // else{
    //     cout<<"Файл открылся!"<< endl;
    //     fout.write((char*)&b, sizeof(b));
    // }
    ifstream fin;
    fin.open(path);

    if (!fin.is_open()){
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }
    else{
         cout<<"Файл открылся!"<< endl;
        Point prt;
        while(fin.read((char*)&prt, sizeof(Point))){
            prt.print();
        }

    }

    fin.close();
    return 0;
} 

