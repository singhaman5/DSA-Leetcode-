class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // Recursive
        // if(root==NULL || root->val==val) return root;
        // else if(root->val > val) return searchBST(root->left, val);
        // else return searchBST(root->right, val);

        // Iterative Approach -: 
        while(root!=NULL){
            if(root->val == val) return root;
            if(val < root->val){
                root = root->left;
            }else{
                root = root->right;
            } 
        }
        return NULL;
    }
};