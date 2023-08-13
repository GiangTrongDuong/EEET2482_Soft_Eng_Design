#include <iostream>
#include <string>

using namespace std;

class Student{
    protected:
    string name;
    int studentID;

    public:
    Student(string name, int id){
        this->name = name;
        this->studentID = id;
        cout << "Constructor of student called \n";
    }

    ~Student(){
        cout << "Destructor called for Student \n";
    }

    string toString(){
        string studentToString = "Student name: " + name + "\n"
        + "Student id: " + to_string(studentID) + "\n";
        return studentToString;
    }
};

class Staff{
    protected:
    string name;
    int staffID;

    public:
    Staff(string name, int id){
        this->name = name;
        this->staffID = id;
        cout << "Constructor of Staff called \n";
    }

    ~Staff(){
        cout << "Destructor called for Staff \n";
    }

    string toString(){
        string staffToString = "Staff name: " + name + "\n"
        + "Staff id: " + to_string(staffID) + "\n";
        return staffToString;
    }

};

class Tutor : Student, Staff{
    private:

    public:
    Tutor(string student_name, int student_id, string staff_name, int staff_id)
        : Student(student_name,student_id), Staff(staff_name,staff_id){
                cout << "Constructor of tutor called \n";
        }
    
    ~Tutor(){
        cout << "Destructor called for Tutor \n";
    }
    
    void consultation(){
        cout << "Doing consultation!";
    }

    void setName(string name){
        Staff::name = name;
    }

    string toString(){
        return Staff::toString();
        return Student::toString();
    }

};

void showInfoStudent(Student &stu){
    cout << stu.toString();
}

void showInfoStaff(Staff &staf){
    cout << staf.toString();
}

int main(){
    Staff Zing("Zing",88);
    Student SIMW("Simw", 21);
    Tutor Adam("Duch",25,"Adam",84);

    Adam.setName("Adam Da Den");
    
    showInfoStaff(Zing);
    showInfoStudent(SIMW);
    
}
