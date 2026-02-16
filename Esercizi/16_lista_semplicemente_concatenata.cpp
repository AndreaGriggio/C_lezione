#include <iostream>

struct node{
    int value;
    node* next;
};
struct list{
    node* head;
    node* tail;
};

void insertFront(int value,list* l);
void insertBack(int value, list* l);
void insertAt(int value,int idx , list* l);

bool isEmpty(list* l);
int size(list* l);
void printList(list* l);
void printNode(node* n);
node* removeFront(list* l);
node* removeBack(list* l);
node* removeValue(list* l,int value);
int main(){
    list* l = new list ;

    l->head = nullptr;
    l->tail = nullptr;

    insertFront(1,l);
    insertFront(2,l);
    insertFront(3,l);

    insertBack(0,l);

    insertAt(10,0,l);    

    std::cout << "La dimensione è : " << size(l)<< std::endl;
    printList(l);

    node* n = removeValue(l,0);

    if( n == nullptr){
        std::cout << "Elemento non trovato" << std::endl;
    }
    printNode(l->tail); 
    std::cout << std::endl;

    printList(l);
    return 0;
}

void insertFront(int value,list* l){
    if(isEmpty(l)){
        l->head = new node;
        l->head->value = value;
        l->tail = l->head;
        l->tail->next = nullptr;
    }else{
        node* newNode = new node;
        newNode->value = value;
        newNode->next = l->head;
        l->head = newNode;
    }
    
   
} 

void insertBack(int value, list* l){
    if(isEmpty(l)){
        insertFront(value,l);
    }else {
        node* newNode = new node;
        newNode->value = value;
        newNode->next = nullptr;

        l->tail->next = newNode;
        l->tail = newNode;
        
    }
        
}

void insertAt(int value,int idx , list* l){
    if (idx <= 0 || isEmpty(l)) { insertFront(value, l); return; }

    node* prev = l->head;
    while (prev->next != nullptr && idx > 1) {
        prev = prev->next;
        idx--;
    }

    if (prev->next == nullptr) { insertBack(value, l); return; }

    node* newNode = new node{value, prev->next};
    prev->next = newNode;
}



bool isEmpty(list* l){
    return l->head == nullptr;
}

int size(list* l){
    int count = 0;
    node* tmp = l-> head;

    while(tmp != nullptr){
        count++;
        tmp = tmp->next;
    }

    return count;
}

void printList(list* l){

    if(isEmpty(l)){
        std::cout << "La lista è vuota" << std::endl;
    }else{
        node* tmp = l -> head;
        while(tmp != nullptr){
            printNode(tmp);
            tmp = tmp -> next;
        }
        std::cout <<"nullptr" <<std::endl;
    }
}

void printNode(node* n){
    std::cout << "[N: " <<n->value <<"]->";
}

node* removeFront(list* l){
    if(isEmpty(l)) return nullptr;

    node* tmp = l->head;

    l->head = l->head->next;

    if(l->head == nullptr){
        l->tail = nullptr;
    }

    tmp->next = nullptr;
    
    return tmp;
    
}

node* removeBack(list* l){
    if(isEmpty(l)){
        std::cout << "La lista è vuota! "<<std::endl;
        return nullptr;
    }else if(l->head == l->tail){
        return removeFront(l);
    }else{
        node* tmp = l->head;

        while(tmp->next->next != nullptr){
            tmp = tmp->next;
        }

        l->tail = tmp;

        tmp = tmp->next;
        
        l->tail->next = nullptr;

        return tmp;

    }
}
node* removeValue(list* l,int value){
  /*  if(isEmpty(l)){
        std::cout << "La lista é vuota! "<<std::endl;
        return nullptr;
    }else if( l->head->value == value){
        return removeFront(l);
    }
    else{
        node* tmp = l->head;

        while(tmp->next->next != nullptr && tmp->next->value != value){
            tmp = tmp->next;
        }
        

        if(tmp->next->value == value&& tmp->next->next != nullptr){
            printNode(tmp);
            node* tmp2 = tmp->next;
            tmp->next = tmp->next->next;

            tmp2->next = nullptr;
            return tmp2;
        }else if(tmp->next->next == nullptr && tmp->next->value == value){
            
            printNode(tmp);
            l->tail = tmp;

            tmp = tmp->next;
            
            l->tail->next = nullptr;

            return tmp;    
            
        }else{
            return nullptr;
        }
            if (isEmpty(l)) return nullptr;
        }
    */

    if (l->head->value == value) return removeFront(l);

    node* prev = l->head;
    while (prev->next != nullptr && prev->next->value != value) {
        prev = prev->next;
    }

    if (prev->next == nullptr) return nullptr; // non trovato

    node* out = prev->next;
    prev->next = out->next;

    if (out == l->tail) l->tail = prev; // se ho tolto l'ultimo, aggiorno tail

    out->next = nullptr;
    return out;
}       
