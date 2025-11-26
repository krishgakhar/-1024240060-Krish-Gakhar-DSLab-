class Solution {
private:
    bool valid(TreeNode*root,TreeNode*max,TreeNode*min){
        if (!root) return true;
        if(min!=NULL && root->val<=min->val){
            return false;
        }
        if(max!=NULL && root->val>=max->val){
            return false;
        }

        return valid(root->left,root,min) && valid(root->right,max,root);
    }
public:
    bool isValidBST(TreeNode* root) { 


        return valid(root,NULL,NULL);



        
    }
};