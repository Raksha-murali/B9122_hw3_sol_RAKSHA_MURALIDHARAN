// Question 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <String> 
using namespace std;

// This question requires us to build a class with the following members classified either as
// public or private. Each function that performs a setting 'task' on private member is of type void
// and the remaining function types are specified as required. I have set a generic password to be
// PASSWORD and set a warning message for the char type functions, but couldn't figure out how to print an
// appropriate message when the password didn't match for the functions of type int.
// In the main, I just called some of the functions just to check that they worked.
// This question took me far too long to understand how to do but it was quite a useful question to have
// done.

class Student
{
public:
    // Public data members of class student
    string first_name;
    string last_name;
    int UNI;

    // Class constructor
    Student(string fname, string lname, int uni_p);

    // Public methods of class student
    void SetSSN(int SSN);
    int GetMidtermExam(string pwd);
    void SetMidtermExam(string pwd, int score);
    void SetFinalExam(string pwd, int score);
    int GetFinalExam(string pwd);
    void SetHomeworkScore(string pwd, int i, int score);
    int GetHomeworkScore(string pwd, int i);
    float ComputeAvgHomework();
    void GetAllStudentScores(string  pwd);
    void AssignFinalGrade(string pwd, string final_grade);
    string GetFinalGrade(string pwd);

private:
    // Private data members of class student
    int SSN;
    int homework[5];
    int midterm;
    int final;
    string grade;
    string password;
};

Student::Student(string fname, string lname, int uni_p) {
    first_name = fname;
    last_name = lname;
    UNI = uni_p;
    midterm = 0;
    final = 0;
    for (int i = 0; i < 5; i++) {
        homework[i] = 0;
    }
    password = "PASSWORD";
}


void Student::SetSSN(int social_sec) {
    SSN = social_sec;
}


void Student::SetMidtermExam(string pwd, int score) {
    if (pwd == password) {
        midterm = score;
    } 
    else {
        cout << "Wrong password";
    }
}

int Student::GetMidtermExam(string pwd) {
    if (pwd == password) {
        return midterm;
    }
}

void Student::SetFinalExam(string pwd, int score) {
    if (pwd == password) {
        final = score;
    }
    else {
        cout << "Wrong password";
    }
}

int Student::GetFinalExam(string pwd) {
    if (pwd == password) {
        return final;
    }
}

void Student::SetHomeworkScore(string pwd, int i, int score) {
    if (pwd == password) {
        homework[i] = score;
    }
    else {
        cout << "Wrong password";
    }
}

int Student::GetHomeworkScore(string pwd, int i) {
    if (pwd == password) {
        return homework[i];
    }
}

float Student::ComputeAvgHomework() {
    int sum = 0;
    int min = homework[0];
    for (int i = 0; i < 5; i++) {
        sum += homework[i];
        if (homework[i] < min) {
            min = homework[i];
        }
    }
    sum -= min;
    float avg = sum / 4;
    return avg;
}

void Student::GetAllStudentScores(string pwd) {
    if (pwd == password) {
        cout << "\nMidterm Exam: " << GetMidtermExam(pwd);
        cout << "\nFinal Exam: " << GetFinalExam(pwd);
        cout << "\nHomework scores: ";
        for (int i = 0; i < 5; i++) {
            cout << GetHomeworkScore(pwd, i);
            if (i != 4) {
                cout << ", ";
            }
        }
        cout << "\nAverage of top four scores: " << ComputeAvgHomework();
    }
    else {
        cout << "Wrong password";
    }
}


void Student::AssignFinalGrade(string pwd, string final_grade) {
    if (pwd == password) {
        grade = final_grade;
    }
    else {
        cout << "Wrong password";
    }
}

string Student::GetFinalGrade(string pwd) {
    if (pwd == password) {
        return grade;
    }
    else {
        cout << "Wrong password";
        return "-";
    }
}



int main()
{   
    Student S("Harry", "Potter", 111);
    cout << S.GetHomeworkScore("PASSWORD", 0);
    S.GetAllStudentScores("PASSWORD");
    return 0;
}

