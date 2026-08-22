/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    void flat(Node* curr, Node* cld, Node* nxt){
        curr->next = cld;
        cld->prev = curr;
        while(cld->next != nullptr) cld = cld->next;
        cld->next = nxt;
        if(!nxt) return;
        else nxt->prev = cld;
        return;
    }

    Node* flatten(Node* head) {
        if(!head) return head;
        Node* nxt = head->next;
        Node* curr = head;

        while(curr!=nullptr){
            if(curr->child != nullptr){
                flat(curr,curr->child,nxt);
                curr->child = nullptr;
                nxt = curr->next;
            }

            curr = curr->next;
            if(nxt == nullptr) break;
            nxt = nxt->next;
        }

        return head;
    }
};