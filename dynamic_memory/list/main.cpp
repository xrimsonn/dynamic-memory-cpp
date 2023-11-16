#include <iostream>
using namespace std;

template <typename T>
struct Node {
  int index;
  T data;
  Node* next;
};

template <typename T>
class List {
  Node<T>* first_node;
  Node<T>* last_node;
  int index;

 public:
  List() : first_node(nullptr), last_node(nullptr) {}

  void add(T item) {
    if (this->first_node == nullptr) {
      index = 0;
      Node<T>* newNode = new Node<T>{index, item, nullptr};
      this->first_node = newNode;
      this->last_node = newNode;
    } else {
      index++;
      Node<T>* newNode = new Node<T>{index, item, nullptr};
      last_node->next = newNode;
      last_node = newNode;
    }
  }

  void print() {
    if (this->first_node == nullptr) {
      cout << "There is no items in this list." << endl;
    } else {
      Node<T>* temp = first_node;
      cout << "[ ";
      while (temp != nullptr) {
        if (temp->next != nullptr) {
          cout << temp->data << ", ";
        } else {
          cout << temp->data;
        }
        temp = temp->next;
      }
      cout << " ]" << endl;
    }
  }

  void remove(int i) {
    Node<T>* temp = first_node;
    Node<T>* prev = nullptr;
    while (temp != nullptr) {
      if (temp->index == i) {
        if (prev == nullptr) {
          first_node = temp->next;
        } else {
          prev->next = temp->next;
        }
        delete temp;
        return;
      }
      prev = temp;
      temp = temp->next;
    }
  }

  int size() {
    int count = 0;
    Node<T>* temp = first_node;
    while (temp != nullptr) {
      count++;
      temp = temp->next;
    }
    return count;
  }

  bool is_empty() { return (this->first_node == nullptr) ? true : false; }
};

int main(int argc, char const* argv[]) {
  List<string>* list = new List<string>();
  list->print();
  list->add("rene");
  list->add("antonio");
  list->add("carlitos");
  list->print();
  list->is_empty();
  list->size();
  return 0;
}
