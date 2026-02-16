#include <iostream>

int contaParole(std::string frase);
int main(){
    std::string frase;

    std::cout << "Inserisci una frase : ";
    std::getline(std::cin,frase);

    std::cout << "La frase contiene " << contaParole(frase) << " parole" << std::endl;
}
int contaParole(std::string frase){
    int count = 0;
    if(!frase.empty()){
        count ++;
        for(int i = 0; i < frase.size(); i++){

        if(frase[i] == ' '){
            count++;
        }
    }
    }
    
    return count;
}