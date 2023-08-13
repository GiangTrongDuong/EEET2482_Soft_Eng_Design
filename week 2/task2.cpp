#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]){
    if (strlen(argv[1]) > 4){
        cout << "invalid hex length " << strlen(argv[1]);
    } else {
        if (argv[1][0] != '0'){
            cout << "invalid hex value 0";
        } else {
            if ((argv[1][1] != 'x') && (argv[1][1] != 'X')){
                cout << "invalid hex value x " << argv[1][1];
            } else {
                if (((argv[1][2] >= 'A') && (argv[1][2] <= 'F')) || ((argv[1][2] >= '0') && (argv[1][2] <= '9'))){
                    cout << "OK" << endl;
                    if (((argv[1][3] >= 'A') && (argv[1][3] <= 'F')) || ((argv[1][3] >= '0') && (argv[1][3] <= '9'))){
                    cout << "OK" << endl;
                    } else {
                        cout << "invalid value 2" << endl;
                    }
                } else {
                    cout << "invalid value 1" << endl;
                }
            }
        }
    }
}