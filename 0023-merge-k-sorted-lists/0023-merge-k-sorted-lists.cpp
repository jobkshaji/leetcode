class Solution {
public:

    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // min heap
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        // push first node of each list
        for (auto node : lists) {
            if (node != NULL)
                pq.push(node);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (!pq.empty()) {
            ListNode* curr = pq.top();
            pq.pop();

            tail->next = curr;
            tail = tail->next;

            if (curr->next != NULL) {
                pq.push(curr->next);
            }
        }

        return dummy->next;
    }
};