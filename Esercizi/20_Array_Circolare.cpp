#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

template <typename T>
class ArrayCircolare {
    private:
        int capacity;
        int head;   // indice del primo elemento
        int tail;   // indice della prima cella libera (in coda)
        int count;  // numero di elementi presenti
        T* data;

    public:
        ArrayCircolare(int capacity)
            : capacity(capacity), head(0), tail(0), count(0), data(new T[capacity]) {}

        ArrayCircolare()
            : capacity(10), head(0), tail(0), count(0), data(new T[10]) {}

        ~ArrayCircolare() { delete[] data; }

        int getSize() const { return count; }
        bool isEmpty() const { return count == 0; }
        bool isFull() const { return count == capacity; }

        void pushBack(const T& value) {
            if (!isFull()){
            data[tail] = value;
            tail = (tail + 1) % capacity;
            ++count;
            }
        }
        void pushFront(const T& value) {
            if (!isFull()){
                head = (head - 1 + capacity) % capacity;
                data[head] = value;
                ++count;
            } 
        }

        T popFront() {
            if (!isEmpty()) {
                T tmp = data[head];
                head = (head + 1) % capacity;
                --count;
            return tmp;
            }
            return T();
        }

        T popBack() {
            if (isEmpty()){ 
                tail = (tail - 1 + capacity) % capacity;
                T tmp = data[tail];
                --count;
                return tmp;
            }
            return T();
        }

        void printList() const {
            for (int i = 0; i < capacity; i++) {
                std::cout << i << ":[" << data[i] << "] ";
            }
            std::cout << "\nHead: " << head << " Tail: " << tail << " Count: " << count << "\n";
        }
};

int main() {
    ArrayCircolare<int> arr(5);
    arr.pushBack(1);
    arr.pushBack(2);
    arr.pushBack(3);
    arr.pushBack(4);
    arr.pushBack(5);
    arr.printList();
    arr.pushFront(6);
    arr.printList();
    arr.popFront();
    arr.printList();
    arr.popBack();
    arr.printList();
}