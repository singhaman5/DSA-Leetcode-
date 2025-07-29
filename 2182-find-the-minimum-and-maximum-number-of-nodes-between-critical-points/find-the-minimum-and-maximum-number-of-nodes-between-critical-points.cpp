class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int idx = 1;
        int firstIdx = -1; // First index
        int lastIdx = -1; // Second index
        ListNode* a = head;
        ListNode* b = head->next;
        ListNode* c = head->next->next;
        if(c==NULL) return{-1,-1};
        int mind = INT_MAX;
        int f = -1;
        int s = -1;
        while(c){
            if(b->val > a->val && b->val > c->val || b->val < a->val && b->val < c->val){
                // MaxD
                if(firstIdx==-1) firstIdx = idx;
                else lastIdx = idx;
                // MinD
                f = s;
                s = idx;
                if(f != -1){
                    int d = s - f;
                    mind = min(mind,d);
                }
            }
            a = a->next;
            b = b->next;
            c = c->next;
            idx++;
        }
        if(lastIdx == -1) return{-1,-1};
        int maxd = lastIdx - firstIdx;
        return {mind,maxd};
    }
}; 