class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> values;
        while(head!=NULL){
            values.push_back(head->val);
            head = head->next;
        }
        int n = values.size();
        vector<int> ans(n,0);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(st.size()>0 && values[st.top()]<values[i]){
                ans[st.top()] = values[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};