// #include <iostream>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* next;

//     Node(int value) {
//         data = value;
//         next = nullptr;
//     }
// };

// class CircularLinkedList {
// private:
//     Node* head;
//     Node* tail;

// public:
//     CircularLinkedList() {
//         head = nullptr;
//         tail = nullptr;
//     }

//     void insert(int value) {
//         Node* newNode = new Node(value);

//         if (head == nullptr) {
//             head = newNode;
//             tail = newNode;
//             newNode->next = head;  
//         } else {
//             tail->next = newNode;
//             tail = newNode;
//             tail->next = head;  
//         }
//     }

//     void display() {
//         int size=0;
//         if (head == nullptr) {
//             cout << "List is empty." << endl;
//             return;
//         }

//         Node* temp = head;
//         do {
//             cout << temp->data << " ";
//             temp = temp->next;
//             size++;
//         } while (temp != head);
//         cout <<"size of cll is" << size << endl;
//     }

// };

// int main() {
//     CircularLinkedList cll;

//     cll.insert(100);
//     cll.insert(200);
//     cll.insert(300);

//     cout << "Circular Linked List: ";
//     cll.display();
// }

#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class LinkedList{
    Node* head;

public: 
    LinkedList(){
        head = NULL;
    }

    void insertEnd(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
        }
        else{
            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
    
    void display() {
        Node* temp = head;
        int size=0;
        cout << "List (forward): ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
            size++;
        }
        cout << "size is" << size << endl;
    }

};

int main(){
    LinkedList l;
    l.insertEnd(1);
    l.insertEnd(1);
    l.insertEnd(1);
    l.insertEnd(1);
    l.insertEnd(1);
    l.display();

}
