#include <iostream>

using namespace std;

int main(){
    double a,b;
    cout << "Enter value for a, then b \n";
    cin >> a >> b;

    try{
        while(b == 0){
            throw "exception b = 0 is not allow";
            cout << "Re-enter b \n";
            cin >> b;
        }
        
    } catch (...){
        cerr << "Generic exception ! \n";
    }
}