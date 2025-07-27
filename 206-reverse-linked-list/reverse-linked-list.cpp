class Solution {
public:
    // Brute Force approach -> O(n2)
    ListNode* getNodeAt(ListNode* head, int idx){
        ListNode* temp = head;
        for(int i=1;i<=idx;i++){
            temp=temp->next; 
        }
        return temp;
    }
    ListNode* reverseList(ListNode* head) {
        int n = 0;
        ListNode*temp = head;
        // Calculate the length of the linked list
        while(temp!=NULL){
            temp = temp->next;
            n++;    // length of the linkedlist is calculated
        }
        int i= 0;
        int j = n-1;
        while(i<j){
            ListNode* left = getNodeAt(head, i);
            ListNode* right = getNodeAt(head, j);
            int t = left->val;
            left->val = right->val;
            right->val = t;
            i++;
            j--;
        }
        return head;
    }
};