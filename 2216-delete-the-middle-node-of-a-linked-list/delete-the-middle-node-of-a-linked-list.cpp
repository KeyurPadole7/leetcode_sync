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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return nullptr;
        if(head->next->next == nullptr){
            delete head->next;
            head->next = nullptr;
            return head; 
        }

        ListNode *slow = head, *fast=head;
        while(fast->next->next!=nullptr && fast->next->next->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *mid = slow->next;

        slow->next = mid->next;
        delete mid;
        return head;
    }
};