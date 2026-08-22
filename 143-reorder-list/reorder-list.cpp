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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* premid = slow;
        slow = slow->next;
        premid->next = nullptr;

        ListNode* pre = nullptr;
        ListNode* curr = slow;
        ListNode* nxt = nullptr;

        while(curr!=nullptr){
            nxt = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nxt;
        }

        // Do i really neeed to use this? premid->next = pre;

        ListNode* ptr1 = head;
        ListNode* ptr2 = pre;

        ListNode *nxt1 = nullptr, *nxt2 = nullptr;

        while(ptr1 != nullptr && ptr2 != nullptr){
            nxt1 = ptr1->next;
            nxt2 = ptr2->next;

            ptr1->next = ptr2;
            ptr2->next = nxt1;

            ptr1 = nxt1;
            ptr2 = nxt2;
        }


    }
};