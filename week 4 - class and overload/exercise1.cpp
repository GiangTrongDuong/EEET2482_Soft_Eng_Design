#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class CompINUM{
    private: 
    double real;
    double imag;

    public:
    //declare friend
    
    friend int absoluteV(CompINUM i);

    friend CompINUM operator - (double num, CompINUM cn);
    
    //declare constructor
    CompINUM() : real(0), imag(0){}

    CompINUM(double realTemp = 0, double imagTemp = 0){
        this->real = realTemp;
        this->imag = imagTemp;
    }

    

    CompINUM operator - (CompINUM &cn){
        this->real += cn.real;
        this->imag += cn.imag;
        return this->real, this->imag;
    }

    CompINUM operator - (double num){
        this->real -= num;
        this->imag -= num;
        return this->real, this->imag;
    }

    CompINUM operator --(int){
        this->real--;
        this->imag--;
        return this->real, this->imag;
    }

    CompINUM operator --(){
        --this->real;
        --this->imag;
        return this->real, this->imag;
    }
};

int absoluteV(CompINUM i){
    double abv;
    abv = sqrt(pow(i.real,2));
    return abv;
}

CompINUM operator - (double num, CompINUM cn){
    num -= cn.real;
    return num;
}

int main(){
    CompINUM comp1(2,3);
    CompINUM comp2(5,6);
    double result;
    
    cout << absoluteV(comp1);

    
    return 0;
}