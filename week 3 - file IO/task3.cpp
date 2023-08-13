#include <iostream>
#include <fstream>



using namespace std;

class Student{
    private:
    int score;
    fstream pwdfile;
    string password;

    public:
    string name;
    // int score;

    Student(string inpName, int inpScore){
        this->name = inpName;
        this->score = inpScore;
    }

    int getScore(){
        return score;
    }

    void changePwd(){
        string tempPassword;
        string inputPassword;
        string fname = this->name.append(".txt");
        bool passcorrect = false;
        pwdfile.open(fname, std::ios::out);
        if(!pwdfile){
        cerr << "File could not be opened \n";
    }

        if(pwdfile.peek() == EOF){
            cout << "Insert your new password" << endl;
            getline(cin,inputPassword);
            pwdfile << inputPassword << endl;
            

            cout << "Successfully saved password for user " << this->name << " with value of " << inputPassword;

        } else {
                getline(pwdfile,tempPassword);
                cout << "Password detected, insert old password ";
                getline(cin, inputPassword);
                while(passcorrect==false){
                if(tempPassword == inputPassword){
                    passcorrect = true;
                    cout << "Successfull, insert new password";
                    getline(cin,inputPassword);
                    pwdfile << inputPassword;
                }

                cout << "Wrong password, retry" << endl;
                getline(cin,inputPassword);

            }
        }
        
        pwdfile.close();
    }
};

int main(){
    Student student1("Duong",100), student2("Duch",99);
    int maxscore = 0;
    string maxName;

    Student studentArr[3] = {Student("Duong",100),Student("Duch",101),Student("Adam",98)};

    for(int i = 0; i < 3; i++){
        if(maxscore < studentArr[i].getScore()){
            maxscore = studentArr[i].getScore();
            maxName = studentArr[i].name;
        }
    }

    cout << "Student with max score is " << maxName << " with score of " << maxscore << endl;
    student1.changePwd();

}