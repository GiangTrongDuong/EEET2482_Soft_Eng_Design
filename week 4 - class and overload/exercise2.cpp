#include <iostream>
#include <fstream>

using namespace std;
fstream pwdfile;

class BankAcc{
    public:
    string name;
    float amount;
    
    BankAcc(string inp, float amt){
        this->name = inp;
        this->amount = amt;
    }

    void withdraw(float num){
        cout << "Withdrawing from account: " << name << endl;
        if(num > amount){
            cout << "Cannot withdraw account with insufficient fund";
        } else if(num <= amount){
            amount -= num;
            cout << "Withdrawing: " << num << endl << "Balance remaining: " << amount << endl;
        }   
    }
};

int main(){
    BankAcc zing("zing", 2000);
    BankAcc duch("duch", 3000);
    BankAcc adam("adam", 1000);

    // cout << "Account name: " << zing.name << " Balance: " << zing.amount << endl;
    // cout << "Account name: " << duch.name << " Balance: " << duch.amount << endl;
    // cout << "Account name: " << adam.name << " Balance: " << adam.amount << endl;

    //zing.withdraw(500);
    cout << "Insert name for file to save password";
    string filename;
    cin >> filename;
    
    if(filename.empty()){
        cout << "File not saved";
    } else {
        filename.append(".dat");
        pwdfile.open(filename, std::ios::out);
        pwdfile << zing.name << "," << zing.amount << endl;
        pwdfile << duch.name << "," << duch.amount << endl;
        pwdfile << adam.name << "," << adam.amount << endl;
        pwdfile.close();
    }

    return 0;
}