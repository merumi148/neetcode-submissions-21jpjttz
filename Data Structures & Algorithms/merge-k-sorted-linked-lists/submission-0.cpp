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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         
        
        int n = lists.size();
        vector<int> value;
        for(int i = 0; i < n; ++i){
            ListNode* temp = lists[i];
            while(temp !=  nullptr){
                value.push_back(temp->val);
                temp = temp->next;
            }
        }
        sort(value.begin(), value.end());
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        for(int i = 0; i < value.size(); ++i){
            ListNode* newNode = new ListNode(value[i]);
            head->next = newNode;
            head = head->next;
        }
        ListNode* rs = dummy->next;
        delete dummy;
        return rs;


    }
};
