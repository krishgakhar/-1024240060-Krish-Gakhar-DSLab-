#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class List
{
    Node *head;

public:
    List()
    {
        head = NULL;
    }
    void push_front(int val)
    {
        Node *newnode = new Node(val);
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
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

    void popfromFront()
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "the list is empty" << endl;
        }
        else if (temp->next == NULL)
        {
            cout << temp->data << " removed" << endl;
            head = NULL;
            delete temp;
        }
        else
        {
            head = temp->next;
            cout << temp->data << " removed" << endl;
            delete temp;
        }
    }

    void popfromBack()
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "the list is empty" << endl;
        }
        else if (temp->next == NULL)
        {
            cout << temp->data << "removed" << endl;
            head = NULL;
            delete temp;
        }
        else
        {
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            cout << temp->next->data << " removed" << endl;
            delete temp->next;
            temp->next = NULL;
        }
    }
};

int main()
{
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.insertAtEnd(4);
    ll.insertAtEnd(5);

    ll.popfromFront();
    ll.popfromBack();

    ll.display();
}
