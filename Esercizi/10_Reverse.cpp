#include <iostream>

void reverse(int numeri[], int size);
int main(){

    int numeri[] = {1,2,3,4,5,6,7,8,9,0,10,11,12,13};
    int size = sizeof(numeri)/sizeof(numeri[0]);

    for(int i = 0; i < size; i++){
        std::cout << numeri[i] << " ";
    }
    std::cout << std::endl;
    reverse(numeri,size);
    for(int i = 0; i < size; i++){
        std::cout << numeri[i] << " ";
    }
    std::cout << std::endl;
}

void reverse(int numeri[],int size){
    int tmp;

    for(int i = 0; i < int(size/2) ; i++){
        tmp = numeri[i];
        numeri[i] = numeri[size -i -1 ];
        numeri[size -i -1] = tmp;
    }
}