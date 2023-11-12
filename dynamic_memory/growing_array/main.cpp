#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void add_items(string*& array, string text, int& size, int& num_items) {
  if (num_items >= size) {
    size *= 2;
    string* temp = new string[size];
    for (int i = 0; i < num_items; i++) {
      temp[i] = array[i];
    }
    delete[] array;
    array = temp;
  }
  array[num_items] = text;
  num_items++;
}

int main() {
  int size = 2;
  int num_lines = 0;
  string* names_arr = new string[size]{"antonio"};

  fstream names_file_in("./names.txt", ios::in);
  if (names_file_in.is_open()) {
    string line;
    while (getline(names_file_in, line)) {
      add_items(names_arr, line, size, num_lines);
    }
    cout << "People registered: " << num_lines << "\n";
  } else {
    cerr << "There was a problem opening the file" << endl;
  }
  names_file_in.close();

  fstream names_file_out("./names.txt", ios::app);
  if (names_file_out.is_open()) {
    cout << "Register with your name: ";
    string name;
    cin >> name;

    bool name_exists = false;
    for (int i = 0; i < num_lines; i++) {
      if (names_arr[i] == name) {
        name_exists = true;
        break;
      }
    }

    if (!name_exists) {
      names_file_out << name << endl;
      cout << "Succesfully registered" << endl;
    } else {
      cerr << "Name already exists" << endl;
    }

  } else {
    cerr << "There was a problem opening the file" << endl;
  }
  names_file_out.close();

  delete[] names_arr;
  return 0;
}
