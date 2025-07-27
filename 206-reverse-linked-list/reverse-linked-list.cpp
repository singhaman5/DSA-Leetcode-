class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Iterative way
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* Next = head; //Remember that "next" is not same as Next;
        while(curr!=NULL){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }
};