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
    void print(){
        cout<<"<"<<val<<", "<<this<<">"<<endl;
    }
};


class LinkedList {
private:
    Node *start_node= nullptr;
    int len = 0;
public:
    LinkedList(){
        start_node = new Node;
    }
    LinkedList(int start_value) {
        start_node = new Node;
        start_node->set_val(start_value);
        Node *new_node = new Node;
        start_node->set_next(new_node);
        len++;
    }

    void add_to_end(int value) {
        Node *temp = start_node;
        for (int i = 0; i < len-1; i++) {
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

    void insert(int value){
        
    }

    void print_list(){
        Node* temp = start_node;
        cout<<"Linked list"<<"("<<len<<")"<<"{"<<endl;
        for (int i=0; i < len; i++){
            temp->print();
            temp = temp->get_next();
        }
        cout<<"}"<<endl;
    }

};


int main() {
    LinkedList myList(5);
    for (int i=6; i<25; i++){
        myList.add_to_end(i);
    }
    for(int i=4;i>0;i--){
        myList.add_to_start(i);
    }
    myList.print_list();
    return 0;
}
