class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Recursive way-:
        if(head==NULL || head->next == NULL) return head;
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        // Now slow is at the left middle or middle
        ListNode* newHead = reverseList(slow->next);
        ListNode* a = head;
        ListNode* b = newHead;
        slow->next = NULL;  // For breaking the list
        // Merge these two alternatively - a and b
        ListNode* c = new ListNode(100);
        ListNode* tempC = c;
        ListNode* tempA = a;
        ListNode* tempB = b;
        while(tempA!=NULL && tempB!=NULL){
            tempC->next = tempA;
            tempA = tempA->next;
            tempC = tempC->next;

            tempC->next = tempB;
            tempB = tempB->next;
            tempC = tempC->next;
        }
        tempC->next = tempA;
        head =  c->next;
    }
};