class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) return {-1, -1};

        vector<int> criticalIndices;
        int idx = 1;
        ListNode* a = head;
        ListNode* b = head->next;
        ListNode* c = head->next->next;

        while (c) {
            if ((b->val > a->val && b->val > c->val) || (b->val < a->val && b->val < c->val)) {
                criticalIndices.push_back(idx);
            }
            a = b;
            b = c;
            c = c->next;
            idx++;
        }

        if (criticalIndices.size() < 2) return {-1, -1};

        int minDist = INT_MAX;
        for (int i = 1; i < criticalIndices.size(); i++) {
            minDist = min(minDist, criticalIndices[i] - criticalIndices[i - 1]);
        }

        int maxDist = criticalIndices.back() - criticalIndices.front();

        return {minDist, maxDist};
    }
};
