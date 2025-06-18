#include <iostream>
#include <string>
#include <fstream>
using namespace std;
template <typename T> 
struct Node
{
    T data;
    Node * next;
    Node(const T&value) : data(value), next(nullptr){}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head; //указатель на начало списка
    Node<T>* tail; //Указатель на конец списка
    int size; // Размер списка
    
public:
    LinkedList() : head(nullptr), tail(nullptr), size(0){}// конструктор по умолчанию
    ~LinkedList(){ // деструктор для освобожления памяти
        Node<T>*current = head;
        while(current!=nullptr){
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
        head=tail=nullptr;
        size = 0;
    }

    //Добовление элемента в начало списка

    void push_front(const T& value){
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    //Добавление элемента в конец списка
    void push_back(const T& value){
        Node<T>*newNode = new Node<T>(value);
        if (tail == nullptr){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    //Удаление элемента из начала списка
    void pop_front(){
        if(head == nullptr){
            return;//список пуст
        }
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr){
            tail = nullptr; //список стал пустым
        }
        size--;
    }

    //Получение значения элемента то индексу
    T get_at(int index){
        if (index < 0 || index >=size){
            throw std::out_of_range("Index out of bounds");
        }
        Node<T>* current = head;
        for (int i = 0; i < index; ++i){
            current = current->next;
        }
        return current->data;
    }
    //Полуяение размера списка
    int get_size() const{
        return size;
    }
};

int main(){
    setlocale(0, "ru");
    LinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_front(5);

    cout<<"list size: " << list.get_size()<<'\n';
    cout << "element at index 1 :" << list.get_at(1) << '\n';

    list.pop_front();
    cout<<"list size: " << list.get_size()<<'\n';
    cout << "element at index 1 :" << list.get_at(1) << '\n';    

    return 0;
} 

