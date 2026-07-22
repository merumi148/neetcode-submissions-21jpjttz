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
    ListNode* reverse(ListNode* head, ListNode* tail){
        ListNode *temp = head;
        ListNode *prev = tail;
        while(temp != tail){
            ListNode *nextNode = temp->next;
            temp->next = prev;

            prev = temp;
            temp = nextNode;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevGroup = dummy;
        ListNode* endGroup = dummy;
        while(true){
            endGroup = prevGroup;
            for(int i = 0; i < k; ++i){
                if(endGroup == nullptr) return dummy->next;
                else endGroup = endGroup->next;
            }
            if(endGroup == nullptr) break;
            ListNode* nextGroup = endGroup->next;
            ListNode* oldHead = prevGroup->next;
            ListNode* newHead = reverse(prevGroup->next, nextGroup);
            endGroup = oldHead;
            prevGroup->next = newHead;
            prevGroup = oldHead;
        }
        return dummy->next;
    }
};
