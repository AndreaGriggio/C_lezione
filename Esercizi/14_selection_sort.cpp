#include <iostream>

int selectionSort(int numeri[],int size);
int main(){
    int numeri[] = {245, 234, 45, 43, 35, 22, 10, 8, 7, 6, 5, 4, 3, 1};
    int size = sizeof(numeri)/sizeof(numeri[0]);

    int swaps = selectionSort(numeri,size);
    for(int i = 0; i < size ; i++){
        std::cout << numeri[i] << " ";
    }
    std::cout << std::endl;

    std:: cout << "Swaps : " << swaps << std::endl;
}

int selectionSort(int numeri[],int size){
    int swaps = 0;
    int idx;//variabile minimo
    int tmp;//variabile per scambio

    for(int i = 0; i < size ; i++){
        idx = i;
        for(int j = i ; j < size ; j++){
            if(numeri[j]<numeri[idx]){
                idx = j; //trovo indice del minimo
            }
        }
        if( idx != i){
            swaps++;
            tmp = numeri[i];
            numeri[i] = numeri[idx];
            numeri[idx] = tmp;
        }
        
    }
    return swaps;
}