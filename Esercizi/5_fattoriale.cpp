#include <iostream>

int fattoriale(int num);

int main(){

    long long int num;
    long long int* numPtr = &num;

    std::cout << "Inserisci un numero : ";
    std::cin >> *numPtr;
    std::cout << std::endl;
    std::cout << "Il fattoriale di " << num << " e' : " << fattoriale(num) << std::endl;

    return 0;
}

/*
 * @brief Calcola il fattoriale di un numero intero.
 * 
 * @param num Il numero di cui calcolare il fattoriale.
 * @return Il fattoriale del numero passato come parametro.
 * @ complexity O(n)
 * Resiste circa fino a 20
 */
int fattoriale(int num){
    if(num == 0){
        return 1;
    }else{
        return num * fattoriale(num-1);
    }

}