#include <iostream>

int countVocali(std::string parola);
int main(){

    std::string parola;

    std::cout << "Inserisci la parola : ";
    std::getline(std::cin,parola);

    std::cout << "Le vocali sono : " << countVocali(parola) << std::endl;

}

int countVocali(std::string parola){

    int count = 0;
    
    for(int i = 0 ; i < parola.size() ; i++ ){
        switch(parola[i]){
            case 'a': count ++; break;
            case 'e': count ++; break;
            case 'i': count ++; break;
            case 'o': count ++; break;
            case 'u': count ++; break;
        }
    }
    return count;
    
}