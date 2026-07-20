class Solution {
public:
    int check(TreeNode* root){
        if(root==NULL) return true;
        int left = check(root->left);
        int right = check(root->right);
        if(left==-1 || right==-1) return -1;
        if(abs(left-right)>1) return -1;
        return 1+max(left,right);

    }
    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
};