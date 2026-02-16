#include <iostream>


template <typename T>
class LifoStack{

    private:
        
        T* data;
        int top;
        int capacity;
    public:
        
        LifoStack(int numeroElementi) : 
            capacity(numeroElementi),top(0) , data(new T [numeroElementi]) {} ;
        
            ~LifoStack();
        bool push(T num);
        bool pop();

        bool isEmpty() const;
        bool isFull() const;
        int size() const;
        T peek(int idx) const;
        int getCapacity() const { return capacity; }
};
template <typename T>
LifoStack<T>::~LifoStack(){
    delete[] data;
}

template <typename T>
bool LifoStack<T>::pop(){
    if(!isEmpty()){
        top--;
        return true;
    }else{
        return false;
    }
}


template <typename T>
bool LifoStack<T>::push(T num){
    if(!isFull()){
        data[top] = num;
        top++;
        return true;
    }else{
        return false;
    }
}

template <typename T>
int LifoStack<T>::size() const{
    return top;
}

template <typename T>
T LifoStack<T>::peek(int idx) const{
    if(idx>= 0 &&idx < top) return data[idx];
    else return -1;
    
}

template <typename T>
bool LifoStack<T>::isEmpty() const{
    return top == 0;
}
template <typename T>
bool LifoStack<T>::isFull() const{
    return top == capacity;
}
int main(){

    LifoStack <int> stack(5);

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    

    for(int i = 0; i < stack.size(); i++){
        std::cout << stack.peek(i) << " ";
    }
    
    return 0;
}