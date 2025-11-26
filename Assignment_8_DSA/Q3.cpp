#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    Node* insert(Node* node, int val) {
        if(node == NULL) return new Node(val);
        if(val < node->data)
            node->left = insert(node->left, val);
        else
            node->right = insert(node->right, val);
        return node;
    }

    Node* bst(vector<int>& v) {
        if(v.size() == 0) return NULL;
        root = new Node(v[0]);
        for(int i = 1; i < v.size(); i++)
            insert(root, v[i]);
        return root;
    }

    void inorder(Node* node) {
        if(node != NULL) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    Node* findMin(Node* root) {
        while(root->left != NULL) root = root->left;
        return root;
    }

    Node* searchrec(Node* root, int key) {
        if(root == NULL || root->data == key) 
            return root;
        if(key < root->data)
            return searchrec(root->left, key);
        return searchrec(root->right, key);
    }

    Node* inorderSuccessor(Node* root, Node* x) {
        if(x->right != NULL) return findMin(x->right);
        Node* succ = NULL;
        Node* curr = root;
        while(curr != NULL) {
            if(x->data < curr->data) {
                succ = curr;
                curr = curr->left;
            } else if(x->data > curr->data) {
                curr = curr->right;
            } else break;
        }
        return succ;
    }
    
    Node*delNode(Node*root,int key){
        if(!root) return NULL;
        if(key<root->data){
            root->left=delNode(root->left,key);
        }
        else if(key>root->data){
            root->right=delNode(root->right,key);
        }
        else{
            if(root->left==NULL){
                Node*temp=root->right;
                delete root;
                return temp;
            }
            else if(root->right==NULL){
                Node*temp=root->left;
                delete root;
                return temp;
            }
            else{
                Node*IS=findMin(root->right);
                root->data=IS->data;
                root->right=delNode(root->right, IS->data);

            }
            return root;
        }
    }
    
};

int main() {
    BST tree;
    vector<int> v = {10,5,6,8,1,3,2,4,89};
    
    Node* root = tree.bst(v);
    
    tree.inorder(root);
    cout << endl;
    
    root = tree.delNode(root, 5);

    tree.inorder(root);


    return 0;
}
