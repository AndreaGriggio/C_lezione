#include <iostream>

int trovaSecondoMassimo(int numeri[], int size);
int main(){

    int numeri[] = {1,2,3,4,5,6,7,8,9,0,10,11,12,13};
    int size = sizeof(numeri)/sizeof(numeri[0]);

    std::cout << "Secondo massimo : " << trovaSecondoMassimo(numeri,size) << std::endl;

}

int trovaSecondoMassimo(int numeri[], int size){
    int max = numeri[0];
    int max2 = numeri[0];
    int tmp;

    for(int i = 0; i < size ; i++){

        if(max < numeri[i]){
            max = numeri[i];//trovo il massimo
        }
        
    }
    tmp = max;

    for(int i = 0; i < size ; i++){

        if(abs(max - numeri[i]) < tmp && numeri[i] != max){
            tmp = abs(max - numeri[i]);
            max2 = numeri[i];
        }

    }
    return max2;
}