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
        Node* b = dummy->next;
        Node* a = head;
        unordered_map<Node*,Node*> m;
        // Step 2: Make a map of <original,duplicate> Node;
        Node* tempa = a;
        Node* tempb = b;
        while(tempa){
            m[tempa] = tempb;
            tempa = tempa->next;
            tempb = tempb->next;
        }
        for(auto x: m){
            Node* orig = x.first;
            Node* dupl = x.second;
            if(orig->random!=NULL){
                Node* oRandom = orig->random;
                Node* dRandom = m[orig->random];
                dupl->random = dRandom;
            }
        }
        return b;
    }
};