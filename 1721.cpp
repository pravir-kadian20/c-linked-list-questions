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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL)  return head;
        ListNode *slow=head;
        ListNode *fast = head;
        
        int cnt = 1;
        while(cnt!=k){
            fast = fast->next;
            cnt++;
        }
        ListNode *temp = fast;
        
        while(fast->next!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        int var = temp->val;
        temp->val = slow->val;
        slow->val = var;
        
        return head;
    }
};