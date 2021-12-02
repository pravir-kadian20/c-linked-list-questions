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
    ListNode* partition(ListNode* head, int x) {
        ListNode *beforeDummy = new ListNode(-1);
        ListNode *afterDummy = new ListNode (-1);
        
        ListNode *before = beforeDummy;
        ListNode *after = afterDummy;
        
        while(head!=NULL){
            if(head->val < x){
                before->next = head;
                before = before->next;
            }
            else{
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }
        if(beforeDummy->next == NULL){
            return afterDummy->next;
        }
        if(afterDummy->next==NULL){
            return beforeDummy->next;
        }
        before->next = afterDummy->next;
        after->next = NULL;
        
        return beforeDummy->next;
    }
};