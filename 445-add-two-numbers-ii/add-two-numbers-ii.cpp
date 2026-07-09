class Solution {
public:
    ListNode* reverseList(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* Next = NULL;
        while(curr != NULL){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* r1 = reverseList(l1);
        ListNode* r2 = reverseList(l2);
        int carry = 0;
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(r1 != NULL || r2 != NULL || carry){
            int sum = carry;
            if(r1!=NULL){
                sum += r1->val;
                r1 = r1->next;
            }
            if(r2!=NULL){
                sum += r2->val;
                r2 = r2->next;
            }
            carry = sum / 10;
            ListNode* temp = new ListNode(sum % 10);
            if(head == NULL){
                head = tail = temp;
            }
            else{
                tail->next = temp;
                tail = temp;
            }
        }
        return reverseList(head);
    }
};