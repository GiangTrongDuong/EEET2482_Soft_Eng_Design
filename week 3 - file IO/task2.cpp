#include <iostream>

using namespace std;

class Student{
    private:
    int score;
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

    cout << "Student with max score is " << maxName << " with score of " << maxscore;


}