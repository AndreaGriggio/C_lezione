#include <iostream>

int max(int num[],int size);

int main(){

    int num[3];
    int size = sizeof(num)/sizeof(num[0]);
    int i = 0;

    while(i<size){
        std::cout << "Inserisci un numero : ";
        std::cin >> num[i];
        i++;
    }
    std::cout << "Array : " << num[0] << "," << num[1] << "," << num[2] << std::endl;
    std::cout << "Il numero piu grande e' : " << max(num,size) << std::endl;
}
int max(int num[],int size){
    int tmp = num[0];

    for ( int i = 0; i < size ; i++){
        if(tmp < num[i]){
            tmp = num[i];
        }
    }

    return tmp;
}
