#include <iostream>
#include <fstream>
#include <string>

using namespace std;
fstream pwdfile;
void pwdIn();
void pwdOut();
void menu();

void pwdIn(){
    pwdfile.open("pwd.dat", std::ios::out);
    string pwd;

    cout << "Enter your Pasword: ";
    cin.ignore();
    getline (cin, pwd);
    // cin >> pwd;

    pwdfile << pwd;
    
    cout << "Saved to file";
    pwdfile.close();

    menu();
}

void pwdOut(){
    pwdfile.open("pwd.dat", std::ios::in);
    string pwdCurrent;
    pwdfile.unsetf(ios_base::skipws);
    getline(pwdfile, pwdCurrent);
    
    cout << "Your current password is " << pwdCurrent << endl; 
    pwdfile.close();

    menu();
}

void menu(){
    int choice;

    choice = 0;

    cout << "Password Management Program \n" << "1. Save your password \n"
    << "2. Read your password \n" << "3. Exits \n";

    cout << "Your choices: ";

    cin >> choice;

    if((choice == 1)){
        pwdIn();
    } else if ((choice == 2)){
        pwdOut();
    } else if((choice == 3)){
        cout << "Ending program";
    } else {
        cout << "Invalid password \n";
        menu();
    }

}





int main(){
    //create file
    pwdfile.open("pwd.dat", std::ios::out);

    //check if file exist
    if(!pwdfile){
        cerr << "Fail to create/open file \n";
        return -1;
    }
    pwdfile.close();
    menu();
    
}

