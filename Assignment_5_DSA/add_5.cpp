#include<iostream>
using namespace std;

class Node{
public:
    int coeff;
    int pow;
    Node*next;
    Node(int c,int p){
        coeff=c;
        pow=p;
        next=NULL;
    }
};

class List{
    Node*head;

public:
    List(){
        head=NULL;
    }

    void pushback(int c,int p){
        Node*newnode=new Node(c,p);
        if(head==NULL){
            head=newnode;
        }
        else{
            Node*temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newnode;
            
        }
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->coeff << "|" << temp->pow << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    List adding(List list1,List list2){
        List l;

        Node*p1=list1.head;
        Node*p2=list2.head;

        while(p1!=NULL && p2!=NULL){
            if(p1->pow==p2->pow){
                int sum=p1->coeff+p2->coeff;
                if(sum!=0){
                    l.pushback(sum,p1->pow);
                }
                p1=p1->next;
                p2=p2->next;
            }

            else if(p1->pow>p2->pow){
                l.pushback(p1->coeff,p1->pow);
                p1=p1->next;
            }
            else{
                l.pushback(p2->coeff,p2->pow);
                p2=p2->next;
            }
            
        }

        while(p1!=NULL){
            l.pushback(p1->coeff,p1->pow);
            p1=p1->next;
        }
        while(p2!=NULL){
            l.pushback(p2->coeff,p2->pow);
            p2=p2->next;
        }

        return l;

    }


};

int main(){
    List l1,l2,l3;
    l1.pushback(5,2);
    l1.pushback(4,1);
    l1.pushback(2,0);

    l2.pushback(5,1);
    l2.pushback(5,0);

    l1.display();
    l2.display();

    l3=l3.adding(l1,l2);
    l3.display();

}