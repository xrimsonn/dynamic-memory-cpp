#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

struct Student {
  string name;
  int age;
  double gpa;

  void printDetails() {
    cout << "Name: " << name << "\nAge: " << age << "\nGPA: " << gpa << endl;
  }
};

Student* add(Student* list, int& size, string name, int age, double gpa) {
  if (list && size > 0 && !name.empty()) {
    Student* new_list = new Student[size + 1];
    for (int i = 0; i < size; ++i) {
      new_list[i] = list[i];
    }
    new_list[size].name = name;
    new_list[size].age = age;
    new_list[size].gpa = gpa;
    delete[] list;
    size++;
    return new_list;
  } else {
    cerr << "Something  went wrong" << endl;
    exit(1);
  }
}

int main(int argc, char const* argv[]) {
  int size = 5;
  string names[5] = {"Pierre-Emile", "Yves", "Heung-min", "James", "Mickey"};
  Student* _class = new Student[size];

  for (int i = 0; i < size; ++i) {
    _class[i].name = names[i];
    _class[i].age = 17 + i;
    _class[i].gpa = (i * 2) + 60.5;
  }

  int opt;
  string name;
  int age;
  double gpa;

  do {
    printf("---Student list manager---\n");
    printf(
        "Select an option\n1. Print student list\n2. Add student\n0. Quit\n> ");
    cin >> opt;
    printf("\n");
    switch (opt) {
      case 1:
        cout << "---There is " << size << " students in the class---\n";
        for (int i = 0; i < size; ++i) {
          _class[i].printDetails();
        }
        printf("\n");
        break;

      case 2:
        printf("---Inserting student into class---\n");
        printf("Name\n> ");
        cin >> name;
        printf("Age\n> ");
        cin >> age;
        printf("GPA\n> ");
        cin >> gpa;
        _class = add(_class, size, name, age, gpa);
        printf("Student added\n");
        printf("\n");
        break;

      default:
        break;
    }
  } while (opt);

  delete[] _class;
  return 0;
}
