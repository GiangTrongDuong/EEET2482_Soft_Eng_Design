#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

ifstream pwdfile;

class Student{
    private:
    string name;
    int scores[3];

    public:
    Student(){}

    Student(string name, int arr[]){
        this->name = name;
        for (int i = 0; i < 3; i++){
            this->scores[i] = arr[i];
        }
    }
    
    void inputData(){
        cout << "Input name for student: \n";
        cin.ignore();
        getline(cin,this->name);
        cout << "Input 3 scores for student: \n";
        for(int i = 0; i < 3; i++){
            cin >> scores[i];
        }
        

    }

    void inputDataA(string name, int arr[]){
        this->name = name;
        for (int i = 0; i < 3; i++){
            this->scores[i] = arr[i];
        }
    }

    void showInfo(){
        cout << "Student " << name << " with score of " << 
        scores[0] << ", " << scores[1] << " ," << scores[2] << endl;
    }
    friend istream &operator >> (istream &input, Student &stud);
    friend ostream &operator << (ostream &output, Student &student);
    friend Student operator + (int n, Student &stud);

    bool operator > (Student &stud){
        int total1 = 0, total2 = 0;
        float average1, average2;
        for(int i = 0; i < 3; i++){
            total1 += scores[i];
            total2 += stud.scores[i];
        }

        average1 = total1 / 3;
        average2 = total2 / 3;

        if(average1 > average2){
            return true;
        } else {
            return false;
        }
    }

};

istream &operator >> (istream &input, Student &student){
        student.inputData();
        return input;
    }

    ostream &operator << (ostream &output, Student &student){
        student.showInfo();
        return output;
    }

    
    Student operator + (int n, Student &stud){
        for(int i = 0; i < 3; i++){
            stud.scores [i] = stud.scores[i] + n;
        }
        return stud;
    }

int main(){
    // Student student1, student2;
    // student1.inputData();
    // student1.showInfo();
    // student1 = 5 + student1;
    // cin >> student2;

    // student1.showInfo();
    // student2.showInfo();

    // bool answer = student1 > student2;
    // cout << answer;

    Student StudArr[10];
    float avgarr[10];
//create 2 string to store name and initial data 
    string tempName, sdata;

    stringstream ss;
    int tempscore[3], total = 0, studInd = 0;

//check if file can be open
    pwdfile.open("data.txt", std::ios::out);
    if(!pwdfile){
        cerr << "File could not be opened \n";
        return -1;
    }
//Check if file peek to end of file!
    while(pwdfile.peek() != EOF){
        total = 0;
        //clear ss to make sure it is okk
        ss.clear();

        getline(pwdfile, tempName, ',');
        cout << tempName;
        getline(pwdfile, sdata, '\n');

    //Reading sdata into ss (converting string to int)
        ss << sdata;
        for(int i = 0; i < 3; i++){
            ss >> tempscore[i];
            total += tempscore[i];
        }

        StudArr[studInd].inputDataA(tempName,tempscore);
        studInd++;
        avgarr[studInd] = total / 3;
    }
    
    pwdfile.close();
    //Print out all student
    for(int i = 0; i < 10; i++){
        StudArr[i].showInfo();
    }
    
    cout << endl;

    //Comparing to find the highest
    float highest = avgarr[0];
    int index = 0;

    for(int i = 0; i < 10; i++){
        for (int y = 1; y < 10; y++){
            if(avgarr[i] < avgarr[y]){
                highest = avgarr[y];
                //By the end of loop, index will be of the highest number;
                index = y;
            }
        }
    }
    //print out
    cout << "Highest average was " << highest << " by " << StudArr[index]; 
}