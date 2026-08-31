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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next==nullptr || head->next->next==nullptr) return {-1,- 1};
        vector<int> storage;

        ListNode* temp = head->next;
        int pre = head->val;
        int i=1;
        while(temp->next!=nullptr){
            if((pre<temp->val && temp->val>temp->next->val) || (pre>temp->val && temp->val<temp->next->val)) storage.push_back(i);
            i++;
            pre = temp->val;
            temp = temp->next;
        }

        if(storage.size()<2) return {-1,-1};

        int mnd = INT_MAX, mxd = storage.back()-storage.front();

        for(int i=1; i<storage.size(); i++){
            mnd = min(mnd, storage[i] - storage[i-1]);
        }

        return {mnd, mxd};
    }
};