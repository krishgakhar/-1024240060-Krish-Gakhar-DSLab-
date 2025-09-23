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

    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next;   
            curr->next = prev;   
            prev = curr;         
            curr = next;         
        }
        head = prev;  
    }



};


int main(){
    List l;

    l.insertAtEnd(1);
    l.insertAtEnd(2);
    l.insertAtEnd(3);
    l.insertAtEnd(4);

    l.display();

    l.reverse();

    l.display();




    

    
}