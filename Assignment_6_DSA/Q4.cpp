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
        cout << endl;
    }

    bool ispalindrome(){
        if(!head || !head->next) return true;
        Node*right =head;
        Node*left=head;
        Node*temp1=head;

        while(right->next!=NULL ){
            right=right->next;
        }
        
        while(right!=left && right->next!=left){
            if(left->data!=right->data) return false;
            left=left->next;
            right=right->prev;

        }

        return true;
        
    }

};

int main(){
    LinkedList l;
    l.insertEnd(1);
    l.insertEnd(2);
    l.insertEnd(2);
    l.insertEnd(1);
    l.display();

    cout << l.ispalindrome() << endl;

}
