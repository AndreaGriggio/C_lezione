#include <iostream>

int somman(int num){
    
    for ( int i = num-1; i > 0 ; i--){
        num+= i;
        
    }
    return num;
}
int main(){
    int num;

    std::cout << "inserisci il numero : ";
    std::cin >> num;
    std::cout << std::endl;
    std::cout << "La somma è : " << somman(num);

}