// Definition for a Node.
// class Node {
// public:
//     int val;
//     Node* next;
//     Node* random;
// };
class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Step 1-> Create the deep copy without random pointer
        Node* dummy = new Node(100);
        Node* tempC = dummy;
        Node* temp = head;
        while(temp){
            Node* a = new Node(temp->val);
            tempC->next = a;
            tempC = tempC->next;
            temp = temp->next;
        }
        Node* duplicate = dummy->next;
        // Step 2-> Create alternate connections
        Node* a = head;
        Node* b = duplicate;
        dummy = new Node(100);
        Node* tempD = dummy;
        while(a){
            tempD->next = a;
            a = a->next;
            tempD = tempD->next;

            tempD->next = b;
            b = b->next;
            tempD = tempD->next;

        }
        dummy = dummy->next;
        // Step 3-> Assigning random pointer to duplicate
        Node* t1 = dummy; // t1 will traverse in the original list
        while(t1){
            Node* t2 = t1->next; // t2 will traverse in the duplicate list
            if(t1->random != NULL) t2->random = t1->random->next;
            t1 = t1->next->next;
        }
        // Step 4-> Removing the connections(separate the two linked list)
        Node* d1 = new Node(100);
        Node* d2 = new Node(100);
        t1 = d1;
        Node* t2 = d2;
        Node* t = dummy;
        while(t){
            t1->next = t;
            t = t->next;
            t1 = t1->next;

            t2->next = t;
            t = t->next;
            t2 = t2 ->next;
        }
        t1->next = NULL;
        t2->next = NULL;
        d1 = d1->next; // Original list with random
        d2 = d2->next; // Duplicate list with random
        return d2;
    }
};