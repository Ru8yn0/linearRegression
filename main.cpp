

#include <iostream>
#include <cmath>
int Weight(int Grandezze[3],int pesi[3],float& weight,float& mediaY,int& mediaX){
    
    float calcoloTotX,calcoloTotY,calcoloTot;
    float sommaX, sommaY = 0;
    //x
    for(int i = 0; i < 3;i++){
        sommaX+= Grandezze[i];
        mediaX = (sommaX)/3;

    }
    //y
    for(int i = 0; i < 3;i++){
        sommaY += pesi[i];
        mediaY = (sommaY)/3;
    }
    //(xi-x)(yi-y)
    int abc = 0;
    for(int i = 0; i <= 2; i++){
        calcoloTotX = (Grandezze[i]-mediaX);
        calcoloTotY = (pesi[i]-mediaY);

        calcoloTot += calcoloTotX*calcoloTotY;
        abc+=calcoloTotX*calcoloTotX;
    }
    //risultato
    weight = calcoloTot/abc;
    return weight;
}


float bias(int Grandezze[3],int pesi[3]){
    float weight;
    float a,b;
    float mediaY;
    int mediaX;
    float bias = 0;
    Weight(Grandezze, pesi, weight,mediaY,mediaX);
    bias = mediaY - (weight*mediaX);
    return bias;
}



int main(int argc, const char * argv[]) {
    int Grandezze[3] = {1,2,3};
    int pesi[3] = {2,3,5};
    int dataSum = 0;
    
    float weight,mediaY,b;
    int mediaX;
    Weight(Grandezze, pesi, weight, mediaY, mediaX);
    b = bias(Grandezze, pesi);
    int x;
    float DataTest = 0;
    float MSE = 0;
    for(int i = 0; i < 3; i++){
        DataTest = weight*Grandezze[i]+b;
        MSE += pow(pesi[i]-DataTest, 2);
    }
    
    MSE = MSE/3;
    std::cout << "inserisci grandezza" << std::endl;
    std::cin>> x;
    std::cout << weight*x+b << std::endl;
    std::cout << "errore medio: " << MSE << std::endl;
}
