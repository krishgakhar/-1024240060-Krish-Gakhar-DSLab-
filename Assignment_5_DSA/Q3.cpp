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

    void middle(){
        Node*front=head;
        Node*back=head;
        int count=0;
        if(front==NULL){
            cout << 0 << endl;
        }
        while(front->next!=NULL && front->next->next!=NULL){
            front=front->next->next;
            back=back->next;
            count++;
            if(front->next==NULL) {
                cout << count+1 << endl;
            }
            else if(front->next->next==NULL){
                cout << count+1 << ", " << count+2 << endl;
            }
        }
        
    }
};


int main(){
    List l;

    l.insertAtEnd(1);
    l.insertAtEnd(2);
    l.insertAtEnd(1);
    l.insertAtEnd(1);
    l.insertAtEnd(5);
    l.insertAtEnd(5);

    l.display();
    l.middle();


    

    
}