#include <iostream>

#define SOGLIA 0.00001

double media(double numeri[], int size);
double max(double numeri[], int size);
double min(double numeri[], int size);
int main(){

    double numeri[] = {1,2,3,4,5,6,7,8,9,0,10,11,12};
    int size = sizeof(numeri)/sizeof(numeri[0]);

    std::cout << "Media : " << media(numeri,size) << std::endl;
    std::cout << "Max : " << max(numeri,size) << std::endl;
    std::cout << "Min : " << min(numeri,size) << std::endl;

    return 0;
}


double media(double numeri[], int size){
    double sum = 0;
    for(int i = 0; i < size; i++){
        sum += numeri[i];
    }
    return sum/size;
}
double max(double numeri[], int size){
    double tmp = 0 ;
    for(int i = 0; i< size ; i++){
        if( tmp < numeri[i]){
            tmp = numeri[i];
        }
    }

    return tmp;
}
double min(double numeri[], int size){
    double tmp = numeri[0];
    for(int i = 0; i< size ; i++){
        if( tmp > numeri[i]){
            tmp = numeri[i];
        }
    }

    return tmp;
}