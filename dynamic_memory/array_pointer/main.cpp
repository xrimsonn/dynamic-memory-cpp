#include <iostream>
using namespace std;

int* make_array(int size) {
  if (size > 0) {
    int* array = new int[size];
    return array;
  } else {
    cerr << "The lenght has to be greater than 0" << endl;
    exit(1);
  }
}

void delete_array(int* array) {
  if (array) {
    delete[] array;
    array = nullptr;
  }
}

int main(int argc, char const *argv[])
{
  int* my_array = make_array(5);
  
  for (int i = 0; i < 5; i++) {
    my_array[i] = i * 2 + 13;
  }

  for (int i = 0; i < 5; i++) {
    cout << my_array[i] << "\n";
  }
  cout << endl;

  delete_array(my_array);
  return 0;
}
