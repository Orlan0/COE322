//name: Orlan Oconer
//eid: ojo366
//TACC username: orlan 

#include <memory>
#include <iostream>

using std::cout;
using std::cin;
using std::shared_ptr;
using std::make_shared;

class Node {
private: 
    int dataval{0}; 
    int datacount{0}; 
    shared_ptr<Node> next{nullptr};

public: 
    //default 
    Node(){}; 

    //this is a constructor with a value and an optional pointer 
    //this makes sure the node is set up 
    Node(int value, shared_ptr<Node> next=nullptr)
        : dataval(value), datacount(1), next(next) {};

    //checks if the node is connected
    bool has_next() const {return next != nullptr; }

    //now will check the shared point node 
    shared_ptr<Node> nextnode() const {return next;}

    //Down below I am just getting the values for the current node 
    int value() const{return dataval;}
    int count() const{return datacount;}
    void increment() {datacount++;}

    void print() {
        cout << dataval; 
        if (datacount > 1) {
            cout << ":" << datacount; 
        }
        // now print the rest of the numbers
        if (has_next()) {
            cout << ","; 
            next->print(); 
        }
    }

    //returns the amount of nodes 
    int length() {
        //this if it has a next it will just return the current node 
        if(!has_next())
            return 1; 
        else 
            return 1 + next->length(); 
    }


    //this will check all the values, if there is no more nodes then it will make a new node 
    void insert(int value) {
        //case 1: matches the current val 
        if (value == dataval) {
            datacount++; 
            return; 
        }
        //list will fix it all up and put it in order 
        if(value < dataval) {
            return; 
        }
        //case 3: no next node
        if(!has_next()) {
            next = make_shared<Node>(value); 
            return;
        }
        //case 4: insert before the next node
        if (value < next->value()) {
            auto new_node = make_shared<Node>(value);
            new_node->set_next(next); 
            set_next(new_node); 
            return; 
        }
        //insert further down the list
        next->insert(value); 
    }

    //inserts it to the right order 
    //I have this so that I can pass it through and set it to the next node 
    void set_next(shared_ptr<Node> next_node) {
        next = next_node;
    }

};

//this will make the numbers in order 
class List {
public: 
    shared_ptr<Node> head{nullptr};

public:
    List(){};

    //this will allow the public to have access to head 
    shared_ptr<Node> headnode()const {return head;}

    //this will print the entire list 
    void print() {
        if(head != nullptr) {
            head->print();
        }
        cout << '\n';
    }

    int length () {
        if (head == nullptr){
            return 0; 
        } else {
            return head->length(); 
        }
    }

    //check if the value exists in the list 
    bool contains_val(int value) {
        auto current = head; 
        while (current != nullptr) {
            if (current->value() == value)
                return true;
            current = current->nextnode();
        }
        return false; 
    }

    //sharing is caring this logic is much like the same in the other one. 
    void insert(int value) {
        //case 1: empty list 
        if (head == nullptr) {
            head = make_shared<Node>(value);
            return;
        }
        //case 2: value goes before the head (new head node)
        if(value < head->value()) {
            auto new_node = make_shared<Node>(value);
            new_node->set_next(head); 
            head = new_node; 
            return;
        }
        //case 3: insert after the head 
        head->insert(value);
    }
};

int main() {
    List list; 
    int number; 
    cout << "Gimme a number and I will sort it with magic from 0 to the end: \n"; 
    while(true) {
        cout << "gimme a number: "; 
        cin >> number;

        if(number == 0) {
            break;
        }

        list.insert(number); 
        list.print(); 
    }
    return 0;
}
