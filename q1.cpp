#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
    string ID;
    string contactInfo;

public:
    Person() : name("Unknown"), age(0), ID("N/A"), contactInfo("N/A") {}

    Person(string n, int a, string id, string contact)
        : name(n), age(a), ID(id), contactInfo(contact) {}

    void displayBasicInfo() const {
        cout << "Name: " << name << "\nAge: " << age
             << "\nID: " << ID << "\nContact: " << contactInfo << endl;
    }
};

class Student : public Person {
private:
    float cgpa;
    string* courses;
    int courseCount;

public:
    Student() : Person(), cgpa(0.0), courseCount(0), courses(nullptr) {}

    Student(string n, int a, string id, string contact,
            float c, string* courseList, int count)
        : Person(n, a, id, contact), cgpa(c), courseCount(count) {
        courses = new string[courseCount];
        for (int i = 0; i < courseCount; ++i) {
            courses[i] = courseList[i];
        }
    }

    Student(const Student& other) : Person(other), cgpa(other.cgpa), courseCount(other.courseCount) {
        courses = new string[courseCount];
        for (int i = 0; i < courseCount; ++i) {
            courses[i] = other.courses[i];
        }
    }

    ~Student() {
        delete[] courses;
    }

    void display() const {
        displayBasicInfo();
        cout << "CGPA: " << cgpa << "\nCourses Enrolled:\n";
        for (int i = 0; i < courseCount; ++i) {
            cout << "- " << courses[i] << "\n";
        }
    }
};

int main() {
    string courseList[] = {"Maths", "Physics", "BEEE"};
    Student s1("Harleen", 19, "24069", "9763524311", 8, courseList, 3);
    Student s2 = s1; 

    s1.display();
    cout << "\nCopied Student Details:\n";
    s2.display();

    return 0;
}
