#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node*next;

    Node(int val){
        data=val;
        next=NULL;
    }
};

class List{
    Node*head;

public:
    List(){
        head=NULL;
    }
    void insertAtEnd(int val)
    {
        Node *newnode = new Node(val);

        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }

int searchAndDelete(int val) {
    int count = 0;

    while (head != NULL && head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }


    Node* prev = head;
    while (prev != NULL && prev->next != NULL) {
        if (prev->next->data == val) {
            Node* temp = prev->next;
            prev->next = temp->next;
            delete temp;
            count++;
        } else {
            prev = prev->next;
        }
    }

    return count;
}


    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};


int main(){
    List l;

    l.insertAtEnd(1);
    l.insertAtEnd(2);
    l.insertAtEnd(1);
    l.insertAtEnd(1);
    l.insertAtEnd(5);

    l.display();

    cout << l.searchAndDelete(1) << endl;
    l.display();

    

    
}