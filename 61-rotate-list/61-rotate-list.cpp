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
    ListNode* rotateRight(ListNode* head, int k) {
       int length = 1;
       ListNode *tail =head;
       if(!head) 
           return head;
       while(tail->next) 
           tail = tail->next, length++;
       tail->next = head;
       if(k %= length) {
       for(int i = 0; i< length - k;k++){
           tail = tail->next;
       }}
       ListNode *newHead = tail->next;
       tail->next = NULL;
       return newHead;
    }
};