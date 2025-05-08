#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Person {
public:
    string name;
    int age;
    Person(string n, int a) : name(n), age(a) {}
    virtual void displayDetails() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
    virtual double calculatePayment() const { return 0.0; }  
};

class Professor : public Person {
protected:
    string department;
public:
    Professor(string n, int a, string dept) : Person(n, a), department(dept) {}
    void displayDetails() override {
        cout << "Professor " << name << ", Age: " << age << ", Department: " << department << endl;
    }
    double calculatePayment() const override {
        return 50000.0;  
    }
};

class AssistantProfessor : public Professor {
public:
    AssistantProfessor(string n, int a, string dept) : Professor(n, a, dept) {}
    double calculatePayment() const override {
        return Professor::calculatePayment() + 5000;  
    }
};

class Student : public Person {
public:
    vector<string> courses;
    Student(string n, int a, vector<string> c) : Person(n, a), courses(c) {}
    void displayDetails() override {
        cout << "Student " << name << ", Age: " << age << ", Courses: ";
        for (const auto& course : courses) cout << course << " ";
        cout << endl;
    }
    double calculatePayment() const override {
        return 0.0;  
    }
};

class GraduateStudent : public Student {
private:
    Professor* advisor;
public:
    GraduateStudent(string n, int a, vector<string> c, Professor* adv) 
        : Student(n, a, c), advisor(adv) {}
    void displayDetails() override {
        Student::displayDetails();
        cout << "Advisor: " << advisor->name << endl;
    }
    double calculatePayment() const override {
        return 10000.0;  
    }
};

int main() {
   
    AssistantProfessor p1("Dr.Aman ", 40, "BEEE");
    Professor p2("Dr.Manoj ", 42, "Maths");

    GraduateStudent s1("Riya", 25, {"BEEE121", "MATHS201"}, &p1);
    Student s2("Rahul", 20, {"BEEE121"});

    cout << "Dr. Aman Payment: " << p1.calculatePayment() << endl;
    cout << "Dr. Manoj Payment: " << p2.calculatePayment() << endl;

    cout << "Riya Payment: " << s1.calculatePayment() << endl;

    s1.displayDetails();
    s2.displayDetails();

    return 0;
}
