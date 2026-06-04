/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        Node *temp = head;
        while(temp != nullptr){
            Node *nextNode = temp->next;
            Node *cloneNode = new Node(temp->val);

            temp->next = cloneNode;
            cloneNode->next = nextNode;
            temp = nextNode;
        }

        temp = head;
        while(temp != nullptr){
            if(temp->random != nullptr){
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }

        Node *dummy = new Node(0);
        temp = head;
        Node *newHead = dummy;
        while(temp != nullptr){
            Node *nextNode = temp->next->next;
            newHead->next = temp->next;
            newHead = newHead->next;
            temp->next = nextNode;
            temp = nextNode;
        }
        Node *rs = dummy->next;
        delete dummy;
        return rs;
    }
};
