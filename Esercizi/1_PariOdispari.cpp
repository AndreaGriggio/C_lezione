#include <iostream>

int main(){

    int num;

    std::cout << "Inserisci un numero : ";
    std::cin >> num;

    if(num%2 == 0){
        std::cout << "pari" << std::endl;
    }else{
        std::cout << "dispari" << std::endl;
    }
}