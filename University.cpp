#include <iostream>
#include <unordered_map>

using namespace std;

class Person {
private:
    int ssn;
public:
    string name;
    Person(string n, int s) : name(n), ssn(s) { };
    Person() : name("unknown"), ssn(0) { };
};

class Faculty : virtual public Person {
    int fac_id;
public:
    Faculty(string n, int i, int j) : Person(n, i), fac_id(j) { };
    string GetName() { return name; };
    void setName(const string& n) { name = n; };
};

class Student : virtual public Person {
    int stu_id;
    float gpa;
public:
    Student() : stu_id(0), gpa(0.0) { };
    Student(string n, int i, int j) : Person(n, i), stu_id(j), gpa(0.0) { };
    string FindName() { return name; };
    void ChangeName(const string& n) { name = n; };
    void SetGPA(float g) { gpa = g; };
    float GetGPA() { return gpa; };
    int GetStudentID() { return stu_id; };
};

class TA :  public Faculty, public Student {
public:
    TA(string n, int fid, int sid, int ssn) :
            Faculty(n, ssn, fid), Student(n, ssn, sid) { };
};

class University {
private:
    unordered_map<int, Student> students;
public:
    University() { };
    void AddStudent(Student s) {
        students[s.GetStudentID()] = s;
    }
    Student& GetStudent(int id) {
        return students[id];
    }
};

int main() {
    TA ta1("Thanh", 200, 300, 400);
    ta1.Student::ChangeName("Alex");
    cout << "TA Name is: " << ta1.Faculty::GetName() << endl;

    University U1;
    U1.AddStudent(Student("Emily", 2, 3));
    for (int i=5; i< 100000; i++) {
        U1.AddStudent(Student("John" +to_string(i), i, i + 1));
    }

    Student& S1 = U1.GetStudent(2);
    S1.SetGPA(3.7);

    Student& S2 = U1.GetStudent((2));

    cout << "GPA: " << S2.GetGPA() << endl;
    cout << "Student 1000 name is: " << U1.GetStudent(1000).FindName() << endl;

    return 0;
}























