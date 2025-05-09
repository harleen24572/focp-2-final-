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
        cout << name << ", Age: " << age << endl;
    }
    virtual double calculatePayment() const { return 0.0; }
};

class Professor : public Person {
public:
    string department;
    Professor(string n, int a, string dept) : Person(n, a), department(dept) {}
    double calculatePayment() const override {
        return 50000.0;
    }
};

class Student : public Person {
public:
    vector<string> courses;
    Student(string n, int a, vector<string> c) : Person(n, a), courses(c) {}
    void displayDetails() override {
        cout << name << ", Age: " << age << ", Courses: ";
        for (const auto& course : courses) cout << course << " ";
        cout << endl;
    }
};

class Course {
public:
    string code, name;
    Course(string c, string n) : code(c), name(n) {}
};

class UniversitySystem {
public:
    vector<Student*> students;
    vector<Professor*> professors;
    vector<Course> courses;
    void addStudent(Student* s) { students.push_back(s); }
    void addProfessor(Professor* p) { professors.push_back(p); }
    void addCourse(string code, string name) { courses.emplace_back(code, name); }
    void showCourses() {
        for (auto& c : courses) cout << c.code << " - " << c.name << endl;
    }
};

int main() {
    Professor p1("Dr.Aman", 40, "BEEE");
    Student* s1 = new Student("Riya", 25, {"BEEE121", "MATHS201"});

    UniversitySystem uni;
    uni.addProfessor(&p1);
    uni.addStudent(s1);
    uni.addCourse("BEEE121", "Basics of Electrical and electronics ");
    uni.addCourse("MATHS201", " Maths 2");

    s1->displayDetails();
    uni.showCourses();

    return 0;
}
