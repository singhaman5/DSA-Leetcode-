class Solution {
public:
    // Best method -: S.C = O(1)
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        TreeNode* curr = root;
        while(curr!=NULL){
            if(curr->left!=NULL){
                // Save the right
                TreeNode* r = curr->right;
                curr->right = curr->left;
                // Finding pred
                TreeNode* pred = curr->left;
                while(pred->right!=NULL) pred = pred->right;
                // Linking
                pred->right = r;
                curr = curr->left;
            }
            else curr = curr->right;
        }
        TreeNode* temp = root;
        while(temp->right!=NULL){
            temp->left = NULL;
            temp = temp->right;
        }
    }
};