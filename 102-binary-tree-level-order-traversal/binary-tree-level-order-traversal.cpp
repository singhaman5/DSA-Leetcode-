class Solution {
public:
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }
    void lorder(TreeNode* root, vector<vector<int>>& ans, int level){
        if(root==NULL) return;
        ans[level].push_back(root->val);
        lorder(root->left,ans,level+1);
        lorder(root->right,ans,level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int n = levels(root);
        vector<vector<int>> ans;
        for(int i=1;i<=n;i++){
            vector<int> v;
            ans.push_back(v);
        }
        lorder(root,ans,0);
        return ans;
    }
};