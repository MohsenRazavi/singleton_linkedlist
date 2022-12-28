#include <iostream>

using namespace std;

class Node {
private:
    int val;
    Node *next = nullptr;
public:
    Node() {

    }

    Node(int value, Node *next_node) {
        Node::set_val(value);
        Node::set_next(next_node);
    }

    void set_val(int value) {
        this->val = value;
    }

    void set_next(Node *next_node) {
        this->next = next_node;
    }

    Node *get_next() {
        return next;
    }

    void print() {
        cout << "<" << val << ", " << this << ">" << endl;
    }
};


class LinkedList {
private:
    static LinkedList *self;
    Node *start_node = nullptr;
    int len = 0;
public:
    LinkedList() {
        start_node = new Node;
        if (self == nullptr)
            self = this;
    }

    LinkedList(int start_value) {
        start_node = new Node;
        start_node->set_val(start_value);
        Node *new_node = new Node;
        start_node->set_next(new_node);
        len++;
        if (self == nullptr)
            self = this;
    }

    LinkedList *get_back_my_linked_list() {
        if (self == nullptr) {
            return new LinkedList;
        }
        return self;
    }

    void add_to_end(int value) {
        Node *temp = start_node;
        for (int i = 0; i < len - 1; i++) {
            temp = temp->get_next();
        }
        Node *new_node = new Node;
        new_node->set_val(value);
        temp->set_next(new_node);
        len++;
    }

    void add_to_start(int value) {
        Node *new_node = new Node;
        new_node->set_val(value);
        new_node->set_next(start_node);
        start_node = new_node;
        len++;
    }

//    void insert(int index, int value) {
//        Node *new_node = new Node(value, nullptr);
//        Node *temp = start_node;
//        for (int i = 0; i < len; i++) {
//            temp = temp->get_next();
//            if (i == index)
//                break;
//        }
//        Node *next_node = temp->get_next();
//        temp->set_next(new_node);
//        new_node->set_next(next_node);
//        len++;
//    }

    Node *at(int index) {
        Node *temp = start_node;
        for (int i = 0; i < len - 1; i++) {
            temp = temp->get_next();
            if (i == index)
                return temp;
        }
    }

    void print_list() {
        Node *temp = start_node;
        cout << "Linked list" << "(" << len << ")" << "{" << endl;
        for (int i = 0; i < len; i++) {
            temp->print();
            temp = temp->get_next();
        }
        cout << "}" << endl;
    }

};

LinkedList *LinkedList::self = nullptr;

int main() {
    LinkedList myList(5);
    LinkedList my_another_list;
    for (int i=6; i<25; i++){
        myList.add_to_end(i);
    }
    for (int i = 4; i > 0; i--) {
        myList.add_to_start(i);
    }
//    myList.insert(10, 99);
    myList.print_list();
    my_another_list.get_back_my_linked_list()->at(0)->print();
    myList.at(0)->print();
    return 0;
}
