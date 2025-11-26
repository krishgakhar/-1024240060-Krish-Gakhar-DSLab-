//  inorder

class Solution {
private:
    void inorder(TreeNode*root, vector<int>&ans){
        if(!root){
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
        
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
       

        return ans;
        
    }
};

//pre order

class Solution {
private:
    void preorder(TreeNode*root, vector<int>&ans){
        if(!root){
            return;
        }
        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);
        
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root,ans);
       

        return ans;
        
    }
};

// post order

class Solution {
private:
    void postorder(TreeNode*root, vector<int>&ans){
        if(!root){
            return;
        }
        postorder(root->left,ans);
        postorder(root->right,ans);
        ans.push_back(root->val);
        
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root,ans);
       

        return ans;
        
    }
};
