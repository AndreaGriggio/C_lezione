#include <iostream>
#include <string>
#include <limits>

int main() {
    // std::string nome;
    // std::cout << "Nome: ";
    // std::getline(std::cin, nome);

    // int eta = 0;
    // while (true) {
    //     std::cout << "Eta (numero intero): ";
    //     if (std::cin >> eta) break;

    //     std::cout << "Input non valido. Riprova.\n";
    //     std::cin.clear();
    //     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // }

    // std::cout << "Ciao " << nome << ", hai " << eta << " anni.\n";

    for(int i = 0; i< 10 ; ){
        std::cout << ++i << std::endl;
    }
    return 0;
}
