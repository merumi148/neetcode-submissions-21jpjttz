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
    ListNode* reverseList(ListNode* head) {
        ListNode *temp = head;
        ListNode *prev = nullptr;
        while(temp != NULL){
            ListNode *nextNode = temp->next;
            temp->next = prev;

            prev = temp;
            temp = nextNode;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
       ListNode *fast = head;
       ListNode *slow = head;

       while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
       }

        ListNode *second = reverseList(slow->next);
       slow->next = nullptr;

        ListNode *first = head;
        while(second){
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;

            first->next = second;
            second->next = tmp1;

            first = tmp1;
            second = tmp2;
        }
    }
};
