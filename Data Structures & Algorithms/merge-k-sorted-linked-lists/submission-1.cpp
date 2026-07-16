/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    struct cmp{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }

    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<
            ListNode*,
            vector<ListNode*>,
            cmp
        >q;

        for(ListNode *head : lists){
            if(head != nullptr) q.push(head);
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(!q.empty()){
            ListNode* node = q.top();
            q.pop();

            tail->next = node;
            tail = tail->next;

            if(node->next != nullptr) q.push(node->next);
        }
     
        return dummy.next;

    }
};
