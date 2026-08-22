/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr) return false;
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(slow != fast){
            slow = slow->next;
            if (slow->next == nullptr || fast == nullptr || fast->next == nullptr) return false;
            fast = fast->next->next;
        }

        return true;
    }
};