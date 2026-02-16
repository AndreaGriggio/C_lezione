#include <iostream>


bool palindromo(std::string parola);

int main(){
    std::string parola;

    std::cout << "Inserisci la parola : ";
    std::getline(std::cin,parola);
    
    palindromo(parola) ? std::cout << "La parola e' palindroma" <<std::endl : std::cout << "La parola non e' palindroma"<< std::endl;

}

bool palindromo(std::string parola){
    std::string parolaInversa;
    for(int i = parola.size() - 1 ; i >= 0 ; i--){
        parolaInversa += parola[i];
    }
    return parolaInversa == parola;
}