#include <iostream>
#include <sstream>
#include <string>



template <typename T>
class ArrayCircolare{
    private : 
        int capacity;
        int head;
        int tail;

        T* data;
    public :
        ArrayCircolare(int capacity) : capacity(capacity), head(1), tail(0), data(new T[capacity]) {}
        ArrayCircolare() : capacity(10), head(1), tail(0), data(new T[10]) {}
        ~ArrayCircolare(){
            delete[] data;
        }
    
        void pushFront(T const value);
        void pushBack(T const value);
        T popFront();
        T popBack();
        void printList();
        int getSize() const {return (head +abs(tail-capacity))%capacity;}
        bool isEmpty() const {return head == (tail +1)%capacity ;}
        bool isFull()const { return head == tail; }
};

template <typename T>
void ArrayCircolare<T>::pushFront(T value){
    if(!isFull()){
        data[head] = value;
        head = (head + 1) % capacity;
    }
}

template <typename T>
void ArrayCircolare<T>::pushBack(T value){
    if(!isFull()){
        tail = (capacity - 1 - tail) %capacity;
        data[tail] = value;
    }
}

template <typename T>
T ArrayCircolare<T>::popFront(){
    if(!isEmpty()){
        head = (head - 1) % capacity;
        T tmp = data[head];
        return tmp;
    }
}

template <typename T>
T ArrayCircolare<T>::popBack(){
    if(!isEmpty()){
        T tmp = data[tail];
        tail = (tail + 1) % capacity;
        return tmp;
    }
}
template <typename T>
std::string toString(T t){
    std::ostringstream s;

    s << "[" << t << "]";
    return s.str();
}

template <typename T>
void ArrayCircolare<T>::printList(){
    for(int i = 0; i < capacity; i++){
        std::cout << i << ":"<< toString(data[i]) << " ";
    }
    std::cout << std::endl;
    std::cout <<  "Head : " << head << " Tail : " << tail << std::endl;
    
}


template <typename T>
using AC = ArrayCircolare<T>;
int main(){

    AC<int> ac {10};
    int s = ac.getSize();
    ac.pushFront(1);
    ac.pushBack(2);
    ac.printList();
    std::cout << ac.getSize() << std::endl;

    return 0;
}