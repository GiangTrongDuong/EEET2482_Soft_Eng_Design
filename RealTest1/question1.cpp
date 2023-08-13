/*
  RMIT University Vietnam
  Course: EEET2482/COSC2082
  Semester: 2023-2
  Lab Assessment: 1
  Author: Giang Trong Duong
  ID: s3926135
  Compiler used: 8.1.0
  Created  date: 8/5/2023
  Acknowledgement: Previous tutorial exercise
*/
#include <iostream>
#include <sstream>
#include <fstream>



using namespace std;

int recPal(int sumDigit){
    int paramResult = sumDigit;
    stringstream ss;
    string tempParam, tempDigit;
    int arr[100];
    ss << paramResult;
    ss >> tempParam;
    for(int i = 0; i < tempParam.size(); i++){
        ss.clear();
        tempDigit = tempParam[i];
        ss << tempDigit;
        ss >> arr[i];
    }
    
    for(int i = 0; i < tempParam.size()/2 && tempParam.size()!=0; i++){
            if(arr[i] != arr[tempParam.size() - i -1]){
                arr[tempParam.size() - i -1] = arr[i];
            }
    }

    int z, k = 0;
    for (z = 0; z < tempParam.size(); z++)
        k = 10 * k + arr[z];
    
    if(paramResult > k){
        cout <<  "Minus " << paramResult - k << " to make it a palindrome" << endl << endl;
        return (paramResult - k);
    } else if (k > paramResult){
        cout <<  "Add " << k - paramResult << " to make it a palindrome" << endl << endl;
        return -(k - paramResult);
    }
}

int sumDigit(int digit){
    stringstream ss;
    string tempDigits;
    string tempDigit;
    int arr[100], sum = 0;

    ss << digit;
    ss >> tempDigits;

    for(int i = 0; i < tempDigits.size(); i++){
        ss.clear();
        tempDigit = tempDigits[i];
        ss << tempDigit;
        ss >> arr[i];
        sum += arr[i];
    }
    return sum;
}

bool checkPal(int Intparam){
    int paramResult = sumDigit(Intparam);
    stringstream ss;
    string tempParam, tempDigit;
    bool isTrue = true;
    int arr[100];
    ss << paramResult;
    ss >> tempParam;

    for(int i = 0; i < tempParam.size(); i++){
        ss.clear();
        tempDigit = tempParam[i];
        ss << tempDigit;
        ss >> arr[i];
    }
    
    for(int i = 0; i < tempParam.size()/2 && tempParam.size()!=0; i++){
            if(arr[i] != arr[tempParam.size() - i -1]){
                isTrue = false;
                break;
            }
    }

    if(isTrue == false){
        cout << Intparam << ": " << "Result " << paramResult << " is not a palindrome" << endl;
        recPal(paramResult);
        return false;
    } else {
        cout << Intparam << ": " << "Result " << paramResult << " is a palindrome" << endl << endl;
        return true;
    }
}

int main(int argc, char *argv[]){
    stringstream ss;
    string data;
    ifstream datafile;
    ofstream writefile;
    int tempData;
    string iftrue = "Result is a palindrome!", iffalse = "Result is not a Palindrome!";
    if(argc != 2){
        cout << "Insufficient arguments\n";
    } else {
        string input(argv[1]);
        datafile.open(input, std::ios::out);
        writefile.open("Result.txt",std::ios::out);
        if(!datafile){
        cerr << "File could not be opened \n";
    }
        while(datafile.peek() != EOF){
            ss.clear();
            getline(datafile,data,'\n');
            ss << data;
            ss >> tempData;
            checkPal(tempData);
            if(checkPal(tempData) == true){
                writefile << tempData << ": " << iftrue << endl << endl;
            } else if (checkPal(tempData) == false){
                writefile << tempData << ": " << iffalse << endl << "Addition " << recPal(tempData) << " to make a palidome." << endl << endl; 
            }
        }
        datafile.close();
        writefile.close();
    }
}