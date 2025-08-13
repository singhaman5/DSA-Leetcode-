class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        stack<ListNode*> st;
        ListNode* temp = head;
        while(temp!=NULL){
            while(st.size()>0 && st.top()->val < temp->val){
                ListNode* helper = st.top();
                st.pop();
                helper->val = temp->val;
            }
            st.push(temp);
            temp = temp->next;
        }
        while(st.size()>0){
            ListNode* helper = st.top();
            st.pop();
            helper->val = 0;
        }
        vector<int> ans;
        while(head!=NULL){
            ans.push_back(head->val);
            head = head->next;
        }
        return ans;
    }
};