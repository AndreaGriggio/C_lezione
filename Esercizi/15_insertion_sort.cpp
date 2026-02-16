#include <iostream>

void insertionSort(int numeri[], int size);
int main(){
    int numeri[] = {245, 234, 45, 43, 35, 22, 10, 8, 7, 6, 5, 4, 3, 1};
    int size = sizeof(numeri)/sizeof(numeri[0]);

    insertionSort(numeri,size);
    for(int i = 0; i < size ; i++){
        std::cout << numeri[i] << " ";
    }
    std::cout << std::endl;
}

void insertionSort(int numeri[], int size){
    int tmp;
    for(int i = 1; i < size ; i++){
        for(int j = i ; j > 0 ; j--){
            if(numeri[j] < numeri[j-1]){
                tmp = numeri[j];
                numeri[j] = numeri[j-1];
                numeri[j-1] = tmp;
            }
        }
    }
}