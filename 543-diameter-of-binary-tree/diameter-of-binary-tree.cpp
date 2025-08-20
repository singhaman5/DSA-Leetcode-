class Solution {
public:
    int maxDia = 0;
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int dia = levels(root->left) + levels(root->right);
        maxDia = max(maxDia, dia);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return maxDia;
    }
};