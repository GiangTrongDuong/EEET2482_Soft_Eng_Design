#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int doubleVal(int intnum){
    return intnum*2;
}

float doubleVal(float floatnum){
    return floatnum*2;
}

int doubleVal(string hexnum){
    //using stringstream to cast numberical string to interger /double
    unsigned int numu;
    stringstream ss;
    ss << hex  << hexnum;
    ss >> numu;
        return numu *2;
}

int main(int argc, char *argv[]){
    //This is to check if arguments is correct
    if(argc != 2){
        cout << "Insufficient arguments\n";
    } else {
        int intNum, hexnum;
        float floatNum;

        string input(argv[1]);
        stringstream ss;
        int len = input.length();
        //find the value first of the value inside bracket
        int pos = input.find_first_of(".xX");
    // Learn about npos https://daynhauhoc.com/t/hoi-ve-string-npos/92579/2
        if(pos != string::npos){
            //check if there is a dot number
            if(input[pos] == '.'){
                ss <<input;
                ss >> floatNum;
                floatNum = doubleVal(floatNum);
                //Output, check fixed in https://www.geeksforgeeks.org/ios-manipulators-fixed-function-in-c/
                cout << fixed << setprecision(2) << floatNum << endl;
            } else if (input[pos] == 'x' || input[pos] == 'X'){
                hexnum = doubleVal(input);
                cout << showbase << hex << hexnum << endl;
            } 


        } else {
            ss << input;
            ss >> intNum;
            intNum = doubleVal(intNum);
            cout << intNum << endl;
        }
    }
    return 0;

}