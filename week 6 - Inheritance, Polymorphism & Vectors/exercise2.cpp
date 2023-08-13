#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Student{
    protected:
    string name;
    int studentID;

    public:
    Student(string name, int id){
        this->name = name;
        this->studentID = id;
        // cout << "Constructor of student called \n";
    }

    ~Student(){
        // cout << "Destructor called for Student \n";
    }

    string toString(){
        string studentToString = "Student name: " + name + "\n"
        + "Student id: " + to_string(studentID) + "\n";
        return studentToString;
    }

    string getter(){
        return name + "," + to_string(studentID);
    }

    int viewID(){
        return studentID;
    }
};

class SchoolSystem{
    private:
    vector<Student> students;

    public:
    void addStudent(){
        string name;
        int id;
        cout << "Insert student name";
        cin.ignore();
        getline(cin,name);

        cout << "Insert student id";
        cin >> id;

        students.push_back(Student(name,id));
    }

    void removeStudent(){
        int inputId;
        cout << "Insert ID of student you want to delete! \n";
        cin >> inputId;

        for(int i = 0; i < students.size(); i++){
            if(students[i].viewID() == inputId){
                cout << "Student you want to delete is \n";
                cout << students[i].toString();
                students.erase(students.begin() + i - 1);
            }
        }
    }

    void viewStudent(){
        for (int i = 0; i < students.size(); i++){
            cout << students[i].toString() << endl;
        }
    }

    void readStudent(){
        string name, tempname, tempid;
        int id;

        stringstream ss;
        fstream readStud;
        //Create file and check for if it can open
        readStud.open("students.dat",ios::out);
        if(!readStud){
            cerr << "File could not be opened \n";
        }
        
        while(readStud.peek() != EOF){
            ss.clear();
            getline(readStud,tempname,',');
            ss << tempname;
            ss >> name;
            ss.clear();

            getline(readStud,tempid);
            ss << tempid;
            ss >> id;
            ss.clear();

            students.push_back(Student(name,id));
        }

        readStud.close();
    }
    void writeStudent(){
        fstream file;
        file.open("students.dat",ios::out);
        if(!file){
            cerr << "File could not be opened \n";
        }

        for(int i = 0; i < students.size(); i++){
            file << students[i].getter() << '\n';
        }
        file.close();
    }
};

void menu(SchoolSystem &sch){
    int choice;

    cout << "School Management System \n 1. View all students \n 2. Add Student \n 3. Remove Student \n 4. Exit \nEnter your choice \n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        sch.viewStudent();
        menu(sch);
    break;

    case 2:
        sch.addStudent();
        menu(sch);
    break;

    case 3:
        sch.removeStudent();
        menu(sch);
    break;

    case 4:
    sch.writeStudent();
    break;

    default:
    cout << "\n \n \n \n \n";
    cout << "Error, invalid input! \n \n";
    menu(sch);
    break;
    }
    
}

int main(){
    SchoolSystem school;
    school.readStudent();
    menu(school);
    
}