#include <iostream>

int* rimuoviDuplicati(int numeri[], int size);
int main(){

    int numeri[] = {1,2,2,3,3,4,5,6,7,6,8,9,0,10,11,12,13};
    int size = sizeof(numeri)/sizeof(numeri[0]);

    for(int i = 0; i < size; i++){
        std::cout << numeri[i] << " ";
    }
    std::cout << std::endl;
    int *num = rimuoviDuplicati(numeri,size);
    for(int i = 0; i < size; i++){
        std::cout << num[i] << " ";
    }
    std::cout << std::endl;
}

int* rimuoviDuplicati(int numeri[], int size){
    
    int* num = new int[size];

    for(int i = 0; i< size ; i++){
        for(int j = 0 ; j < size ; j++){


            if(numeri[i] == numeri[j] && i != j){
                num[i] = j;//array con indici da non copiare
            }
        }
    }



    return num;
}