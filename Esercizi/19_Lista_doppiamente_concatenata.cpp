#include <iostream>
#include <sstream>
#include <string>
/*
template <typename T>
class Node{
    private:
        T value;
        Node<T>* next;
        Node<T>* prev;
    public :
        Node(T value , Node<T>* next = nullptr , Node<T>* prev = nullptr) : value(value), next(next), prev(prev) {}


        const T& getValue() const {return value;} //getter per un nodo
        Node<T>* getNext() const {return next;}
        Node<T>* getPrev() const {return prev;}


        void setValue(T value) {this->value = value;} //setter per un nodo
        void setNext(Node<T>* next) {this.next = next;}
        void setPrev(Node<T>* prev) {this.prev = prev;}

        std::string toString() const {
            std::ostringstream s;
            s << "N : [ " << value << " ]";
            return s.str();
        }
};*/

template <typename T>
struct Node{
    T value;
    Node* next = nullptr;
    Node* prev = nullptr;
};

template <typename T>
std::string toString(Node<T>* n) {
    std::ostringstream s;
    s << "N:[" << n->value << "]";
    return s.str();
}

template <typename T>
class ListaDoppiamenteConcatenata {
    private :
        Node<T>* head = nullptr;
        Node<T>* tail = nullptr;
        int size = 0;

    public :
        ListaDoppiamenteConcatenata() = default;
        ListaDoppiamenteConcatenata(Node<T>* node){
            if(node != nullptr){
                head = node;
                tail = node;

                head->next = tail->prev = tail->next = head->prev = nullptr;

                size = 1;
            }else{
                head = tail = nullptr;

                size = 0;
            }

        }
        ~ListaDoppiamenteConcatenata();//distruttore

        //metodi per accedere alla lista
        Node<T>* getHead() const {return this->head;}
        Node<T>* getTail() const {return this->tail;}
        int getSize() const {return this->size;}
        bool isEmpty() const {return this->head == nullptr;}

        //metodi per stampa
        void printList();

        //metodi per aggiungere
        void pushFront(T const value);
        void pushBack(T const value);
        void pushAt(T const value, int index);

        //metodi per rimuovere
        Node<T>* removeFront();
        Node<T>* removeBack();
        Node<T>* removeValue(T value);
        Node<T>* removeAt(int index);
};

template <typename T>
ListaDoppiamenteConcatenata<T>::~ListaDoppiamenteConcatenata(){
    Node<T>* tmp = this->head;
    if(isEmpty()){return;}

    while(tmp->next !=nullptr){
        tmp = tmp->next;
        delete tmp->prev;
    }

    delete tmp;
}

template <typename T>
void ListaDoppiamenteConcatenata<T>::printList(){
    Node<T>* tmp = this->head;

    std::cout << "nullptr - ";
    while(tmp != nullptr){
        if(tmp == this->head){
            std::cout << toString(tmp)<< "h" << " - ";
        }else if( tmp == this->tail){
            std::cout << toString(tmp)<< "t" << " - ";
        }else{
            std::cout << toString(tmp) << " - ";
        }
        
        tmp = tmp->next;
    }
    std::cout << "nullptr" << std::endl;
}

template <typename T>
void ListaDoppiamenteConcatenata<T>::pushFront(T const value ){
    Node <T>* n = new  Node<T>;
    n->value = value;

    if(isEmpty()){
        this->head = n;
        this->tail = n;
        n->next = nullptr;
        n->prev = nullptr;
    }else{
        n->next = this->head;
        this->head->prev = n;
        this->head = n;
        n->prev = nullptr;
    }
    this->size ++;
}

template <typename T>
void ListaDoppiamenteConcatenata<T>::pushBack(T const value){
    Node <T>* n = new Node <T>;
    n->value = value;

    if(isEmpty()){
        this->head = n ;
        this->tail = n ;
        n->next = nullptr;
        n->prev = nullptr;
    }else{
        this->tail->next = n;//Il nuovo elemento sarà il successivo della coda
        n->prev = this->tail;
        n->next = nullptr;
        this->tail = n;
    }
    this->size ++;

}

template <typename T>
void ListaDoppiamenteConcatenata<T>::pushAt(T const value, int index){
    /*
        3 casi :
            1. Lista vuota
            2. In mezzo alla lista
            3. In fondo alla lista
    */

    //allocazione memoria nodo
    

    //1. caso
    if( isEmpty() || index <= 0){ pushFront(value); return;}

    
    Node<T>* tmp = this->head;

    while(tmp->next != nullptr  && index >1){
        tmp = tmp->next;
        index --;
    }

    //3. caso
    if(tmp->next == nullptr){ pushBack(value); return;}

    Node<T>* n = new Node<T>;
    n->value = value;
    //2. caso
    n->next = tmp->next;
    n->prev = tmp;

    tmp->next->prev = n;
    tmp->next = n;

    this->size ++;
}
template <typename T>
Node<T>* ListaDoppiamenteConcatenata<T>::removeFront(){
    
    if(isEmpty()){ return nullptr;}

    Node<T>* tmp = this->head;

    if(this->size == 1){
        
        this->head = nullptr;
        this->tail = nullptr;

        this->size --;
        return tmp;
    }
    
    this->head = this->head->next;
    this->head->prev = nullptr;
    tmp->next = nullptr;
    this->size --;
    
    return tmp;

}

template <typename T>
Node<T>* ListaDoppiamenteConcatenata<T>::removeBack(){

    if( isEmpty() ){ return nullptr; }

    Node<T>* tmp = this->tail;
    
    if( this->size == 1 ){
        this->tail = nullptr;
        this->head = nullptr;
        this->size --;

        return tmp;
    }

    this->tail = this->tail->prev;
    this->tail->next = nullptr;
    tmp->prev = nullptr;
    this->size --;

    return tmp;
}

template <typename T>
Node<T>* ListaDoppiamenteConcatenata<T>::removeValue(T value){
    Node<T>* tmp = this->head;

    if(isEmpty()){ return nullptr; }

    if(tmp->value == value){return removeFront(); }

    while(tmp->next != nullptr){
        if(tmp->value == value){

            Node<T>* prev = tmp->prev;
            Node<T>* next = tmp->next;

            prev->next = next;
            next->prev = prev;
            tmp->next = nullptr;
            tmp->prev = nullptr;
            this->size --;

            return tmp;
        }
        tmp = tmp->next;
    }

    if(tmp->value == value ){return removeBack(); }

    return nullptr;
}

int main(){
    Node<int>*  head = new Node<int>;
    Node <int>* tail = new Node<int>;
    head->value = 1;
    tail->value = 2;

    head->next = tail;
    head->prev = nullptr;
    tail->prev = head;
    tail->next = nullptr;

    auto l = ListaDoppiamenteConcatenata<int>{};
    l.printList();



    l.pushBack(3);
    l.pushBack(2);
    l.pushBack(1);
    l.pushBack(0);

    l.pushAt(10,0);
    l.pushAt(11,2);
    l.pushAt(-10,l.getSize());

    l.printList();
    l.removeValue(10);
    l.printList();


    return 0;
}