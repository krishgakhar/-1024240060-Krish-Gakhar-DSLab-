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

    void preorder(Node* node) {
        if(node != NULL) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    Node* searchrec(Node* root, int key) {
        if(root == NULL || root->data == key) 
            return root;
        if(key < root->data)
            return searchrec(root->left, key);
        return searchrec(root->right, key);
    }

    Node* searchnonrec(Node* root, int key) {
        Node* temp = root;
        while(temp != NULL) {
            if(temp->data == key) return temp;
            if(key < temp->data) temp = temp->left;
            else temp = temp->right;
        }
        return NULL;
    }

    Node* findMin(Node* root) {
        while(root->left != NULL) root = root->left;
        return root;
    }

    Node* findMax(Node* root) {
        while(root->right != NULL) root = root->right;
        return root;
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

    Node* inorderPredecessor(Node* root, Node* x) {
        if(x->left != NULL) return findMax(x->left);
        Node* pred = NULL;
        Node* curr = root;
        while(curr != NULL) {
            if(x->data > curr->data) {
                pred = curr;
                curr = curr->right;
            } else if(x->data < curr->data) {
                curr = curr->left;
            } else break;
        }
        return pred;
    }
};

int main() {
    BST tree;
    vector<int> v = {10,5,6,8,1,3,2,4,89};
    Node* root = tree.bst(v);

    tree.preorder(root);
    cout << endl;

    Node* x = tree.searchrec(root, 6);
    Node* succ = tree.inorderSuccessor(root, x);
    Node* pred = tree.inorderPredecessor(root, x);

    if(succ){
        cout << succ->data << endl;
    }    
    if(pred){
        cout << pred->data << endl;
    }
    return 0;
}
