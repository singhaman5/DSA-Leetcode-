class Solution {
public:
    TreeNode* build(vector<int>& in,int inLo,int inHi, vector<int>& post, int postLo,int postHi){
        if(inLo > inHi) return NULL;
        TreeNode* root = new TreeNode(post[postHi]);
        if(inLo==inHi) return root;
        int i = inLo;
        while(i<=inHi){
            if(in[i]==post[postHi]) break;
            i++;
        }
        int leftCount = i - inLo;
        int rightCount = inHi - i;
        root->left = build(in, inLo, i-1, post, postLo, postLo+leftCount-1);
        root->right = build(in, i+1, inHi, post, postLo+leftCount, postHi-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n = in.size();
        return build(in,0,n-1,post,0,n-1);
    }
};