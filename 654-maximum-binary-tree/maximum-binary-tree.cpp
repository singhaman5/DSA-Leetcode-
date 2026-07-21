class Solution {
public:
    TreeNode* build(vector<int>& nums, int left, int right){
        if(left>right) return NULL;
        int maxIdx = left;
        for(int i=left; i<=right; i++){
            if(nums[i]>nums[maxIdx]){
                maxIdx = i;
            }
        }
        TreeNode* root = new TreeNode(nums[maxIdx]);
        root->left = build(nums,left,maxIdx-1);
        root->right = build(nums,maxIdx+1,right);
        return root;

    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size()-1);
    }
};