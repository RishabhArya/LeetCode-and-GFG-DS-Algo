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
    ListNode* merge(ListNode* first, ListNode* second){
        ListNode* result = NULL;
        if(first == nullptr)
            return second;
        if(second == nullptr)
            return first;
        
        if(first->val <= second->val){
            result = first;
            result->next = merge(first->next,second);
        }
        else{
            result = second;
            result->next = merge(first,second->next);
        }
        return result;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k == 0)
            return NULL;
        int start = 0;
        int end = k-1;
        int temp;
        while(end != 0){
            start = 0;
            temp = end;
            while(start < temp){
                lists[start] = merge(lists[start],lists[temp]);
                start++;
                temp--;
                if(start >= temp){
                    end = temp;
                }
            }
        }
        return lists[0];
    }
};