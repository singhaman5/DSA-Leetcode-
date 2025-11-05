class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        while(curr!=NULL){
            if(curr->left!=NULL){ // Find the pred
                TreeNode* pred = curr->left;
                while(pred->right!=NULL && pred->right!=curr){
                    pred = pred->right;
                }
                if(pred->right==NULL){ // Link
                    pred->right = curr;
                    curr = curr->left;
                }
                else{ // pred->right == curr : Unlink
                    pred->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
            else{ // It means curr->left==NULL
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        return ans;
    }
};