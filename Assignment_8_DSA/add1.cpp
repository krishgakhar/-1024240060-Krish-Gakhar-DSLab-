class Solution {
public:
    int sum =0;
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        if(root->left){
            if(root->left->left==NULL && root->left->right==NULL){
                sum+=root->left->val;
            }
        }
        sumOfLeftLeaves(root->left);
        sumOfLeftLeaves(root->right);
        
        return sum;

        
    }
};