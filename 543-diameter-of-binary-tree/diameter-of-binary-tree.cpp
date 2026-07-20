class Solution {
public:
    int diaCheck(TreeNode* root, int &dia){
        if(root==NULL) return 0;
        int left = diaCheck(root->left, dia);
        int right = diaCheck(root->right, dia);
        dia = max(dia,left+right);
        return max(left,right)+1;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        diaCheck(root,dia);
        return dia;
    }
};