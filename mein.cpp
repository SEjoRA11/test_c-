#include <iostream>
#include <string>
#include <fstream>
using namespace std;
template <typename T>
class List{
private:
    class Node{
        public:
        T data;
        Node*next;
        Node(T&value, Node*next=nullptr){
            this ->data = value;
            this ->next = next;
        }
    };
    Node*head;
    int size;

public:
    List();
    ~List();
    void push_back(T value); // добавление в конец списка
    int get_size(){ // получить размер списка
        return size;
    }
    T& operator[](const int index);//перегрузка оператора []
    void pop_front();//удаление первого элемента в списке
    void clear();//очиска всего списка
    void push_front(T value);// добавление в начало списка
    void insert(T value, int index);// добавление в середину по индексу
    void pop_back();// удаление последнего элемента 
    void removeAt(int index);//удаление по индексу 
    
};


template <typename T>
List<T>::List(){
    size = 0;
    head = nullptr;
}
template <typename T>
List<T>::~List(){
    clear();
}

template <typename T>
void List<T>::push_back(T value){
    if(head == nullptr){
        head = new Node(value);
    }
    else{
        Node* current = this->head;
        while(current->next !=nullptr){
            current = current->next;
        }
        current->next = new Node(value);
    }
    size++;
}

template <typename T>
T &List<T>::operator[](const int index){
    if (index < 0 || index >=size){
    throw std::out_of_range("Index out of bounds");
    }
    Node*current = this->head;
    for (int i = 0; i < index; ++i){
        current = current->next;
    }
        return current->data;
}

template <typename T>
void List<T>::pop_front(){
    Node* temp = head;
    head = head->next;
    delete temp;
    size--;
}

template <typename T>
void List<T>::clear(){
    while(size){
        pop_front();
    }   
}
template <typename T>
void List<T>::push_front(T value){
    head = new Node(value,head);
    size++;
}

template <typename T>
void List<T>::insert(T value, int index){
    if (index == 0){
        push_front(value);
    }
    else{
        Node*temp = this -> head;
        for (int i = 0; i < index - 1; i++){
            temp = temp->next;
        }
        Node*newNode = new Node(value, temp->next);
        temp->next = newNode;
        size++;
    }
}

template <typename T>
void List<T>::removeAt(int index){
    if (index == 0){
        pop_front();
    }
    else{
        Node*temp = this->head;
        for (int i = 0; i < index - 1; i++){
            temp = temp->next;
        }
        Node* removeNode = temp->next;
        temp->next = removeNode->next;
        delete removeNode;
        size--;
    }
}

template <typename T>
void List<T>::pop_back(){
    removeAt(size-1);
}


int main(){
    setlocale(0, "ru");
    List<int> list;
    list.push_back(12);
    list.push_back(23);
    list.push_back(11);
    list.push_back(43);
    list.push_back(51);
    cout <<"элементы в нашем списке:\n";
    for (int i = 0; i < list.get_size(); i++){
        cout << i << '\t' << list[i] << endl;
    }

    cout<<"Элемент под индексом 3 = "<<list[3]<<endl;
    cout<<endl;
    cout << "Добавляем 100 по индексу 3:\n\n";
    list.insert(100, 3);
    cout<<"Элемент под индексом 3 = "<<list[3]<<endl<< endl;

    cout << "Наш новый список: \n";
    for (int i = 0; i<list.get_size(); i++){
        cout<< i << '\t' << list[i] << endl;
    }

    cout << "удоляем элеемент под индексом 3: \n\n";

    list.removeAt(3);
    list.pop_back();
    cout << "Наш новый список: \n";
    for (int i = 0; i<list.get_size(); i++){
        cout<< i << '\t' << list[i] << endl;
    }




    return 0;
} 

