#include <iostream>

void bubbleSort(int numeri[], int size);
int main(){

    int numeri[] = {2,35,1,2,43,234,5,7,8,245,10,22,45,6};
    int size = sizeof(numeri)/sizeof(numeri[0]);

    bubbleSort(numeri,size);
    std::cout << "Address array : "<< numeri << std::endl;
    for(int i = 0; i < size ; i++){

        std::cout << numeri[i] << " ";
    }

}

void bubbleSort(int numeri[], int size){
    int tmp;

    for(int i = 0; i < size ; i++){
        for(int j = 0 ;  j < size ; j++){
            if(numeri[i] < numeri[j]){
                tmp = numeri[i];
                numeri[i] = numeri[j];
                numeri[j] = tmp;
            }
        }
    }

}