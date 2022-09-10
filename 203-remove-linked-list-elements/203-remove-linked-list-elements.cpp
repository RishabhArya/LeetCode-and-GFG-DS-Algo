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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* mover = new ListNode(0), * res;
        mover->next = head;
        res = mover;
        while(mover->next){
            if(mover->next->val==val){ 
                mover->next=mover->next->next;}
            else mover=mover->next; 
        }
        return res->next;
    }
};