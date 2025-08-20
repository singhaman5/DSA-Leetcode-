class Solution {
public:
    int find(TreeNode* root,int &dia){
        if(root==NULL) return 0;
        int l=find(root->left,dia);
        int r=find(root->right,dia);
        dia=max(dia,l+r);
        return max(l,r)+1;


    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=0;
        find(root,dia);
        return dia;
    }
};