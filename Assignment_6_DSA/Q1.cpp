// #include<iostream>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* prev;
//     Node* next;

//     Node(int val) {
//         data = val;
//         prev = nullptr;
//         next = nullptr;
//     }
// };

// class LinkedList{
//     Node*head;

// public: 
//     LinkedList(){
//         head=NULL;
//     }

//     void insertEnd(int val){
//         Node*newNode=new Node(val);
//         if(head==NULL){
//             head=newNode;
//         }
//         else{
//             Node*temp=head;
//             while(temp->next!=NULL){
//                 temp=temp->next;
//             }
//             temp->next=newNode;
//             newNode->prev=temp;
//         }

//     }

//     void insertFirst(int val){
//         Node*newNode=new Node(val);
//         if(head==NULL){
//             head=newNode;
//         }
//         else{
//             newNode->next=head;
//             head->prev=newNode;
//             head=newNode;
//         }
//     }

//     int search(int val){
//         Node*temp=head;
//         int count=1;
//         while(temp->data!=val){
//             temp=temp->next;
//             count++;
//         }

//         cout << "The node with " << val << " as data is found at " << count << " place" << endl;
//         return count;
//     }
//     void insertafter(int val,int number){
//         Node*newNode=new Node(val);
//         Node*temp=head;
//         int count=1;
//         while(count!=number){
//             temp=temp->next;
//             count++;
//         }
//         newNode->next=temp->next;
//         newNode->next->prev=newNode;
//         temp->next=newNode;
//         newNode->prev=temp;
//     }

//     void insertbefore(int val,int number){
//         Node*newNode=new Node(val);
//         Node*temp=head;
//         int count=1;
//         while(count!=number){
//             temp=temp->next;
//             count++;
//         }
//         newNode->next=temp;
//         temp->prev->next=newNode;
//         newNode->prev=temp->prev;
//         temp->prev=newNode;
//     }

//     void deletion(int val){
//         int count=search(val);
//         Node*temp=head;
//         for(int i=1;i<count;i++){
//             temp=temp->next;
//             if(temp==NULL){
//                 cout<< "Element not found." <<endl;
//                 return;
//             }
//         }
//         if(temp->prev==NULL){
//             head=temp->next;
//             head->prev=NULL;
            
//         }
//         else if(temp->next==NULL){
//             temp->prev->next=NULL;
//         }
//         else{
//             temp->prev->next=temp->next;
//             temp->next->prev=temp->prev;
            
//         }
//         delete temp;

//     }
//     void display() {
//         Node* temp = head;
//         cout << "List (forward): ";
//         while (temp != nullptr) {
//             cout << temp->data << " ";
//             temp = temp->next;
//         }
//         cout << endl;
//     }

// };

// int main(){
//     LinkedList l;
//     l.insertFirst(1);
//     l.insertFirst(2);
//     l.insertFirst(3);
//     l.insertFirst(4);
//     l.display();

//     l.deletion(1);
//     l.display();

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

    void insertFirst(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    int search(int val){
        Node* temp = head;
        int count = 1;
        while(temp != nullptr && temp->data != val){
            temp = temp->next;
            count++;
        }
        if(temp == nullptr){
            cout << "Value not found." << endl;
            return -1;
        }
        cout << "The node with " << val << " as data is found at " << count << " place" << endl;
        return count;
    }

    void insertafter(int val, int number){
        Node* newNode = new Node(val);
        Node* temp = head;
        int count = 1;
        while(temp != nullptr && count != number){
            temp = temp->next;
            count++;
        }
        if(temp == nullptr){
            cout << "Position not found." << endl;
            return;
        }
        newNode->next = temp->next;
        if(temp->next != nullptr)
            temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertbefore(int val,int number){
        Node* newNode = new Node(val);
        Node* temp = head;
        int count = 1;
        while(temp != nullptr && count != number){
            temp = temp->next;
            count++;
        }
        if(temp == nullptr){
            cout << "Position not found." << endl;
            return;
        }
        newNode->next = temp;
        newNode->prev = temp->prev;
        if(temp->prev != nullptr)
            temp->prev->next = newNode;
        else
            head = newNode;
        temp->prev = newNode;
    }

    void deletion(int val){
        int count = search(val);
        if(count == -1) return;
        Node* temp = head;
        for(int i = 1; i < count; i++){
            temp = temp->next;
            if(temp == NULL){
                cout << "Element not found." << endl;
                return;
            }
        }

        if(temp->prev == NULL){
            head = temp->next;
            if(head != nullptr)
                head->prev = nullptr;
        }
        else if(temp->next == NULL){
            temp->prev->next = nullptr;
        }
        else{
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        delete temp;
    }


    void display() {
        Node* temp = head;
        cout << "List (forward): ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

};

int main(){
    LinkedList l;
    l.insertFirst(1);
    l.insertFirst(2);
    l.insertFirst(3);
    l.insertFirst(4);
    l.display();

    l.deletion(1);
    l.search(3);
    l.display();
}
