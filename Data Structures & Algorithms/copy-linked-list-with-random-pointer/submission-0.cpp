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
        unordered_map<Node*, Node*> clone;
        Node* temp = head;
        while(temp != nullptr){
            Node *newNode = new Node(temp->val);
            clone[temp] = newNode;
            temp = temp->next;
        }
        temp = head;
        while(temp != nullptr){
            clone[temp]->next = clone[temp->next];
            clone[temp]->random = clone[temp->random];
            temp = temp->next;
        }
        temp = head;
        return clone[temp];
    }
};
