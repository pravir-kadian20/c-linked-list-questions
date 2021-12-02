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
    
    ListNode *reverse(ListNode *l){
        if(l==NULL || l->next==NULL){
            return l;
        }
        ListNode *newhead = reverse(l->next);
        l->next->next = l;
        l->next = NULL;
        return newhead;
    }
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;
        int sum=0;
        int carry=0;
        while(l1!=NULL || l2!=NULL){
            if(l1!=NULL){
                sum+=l1->val;
                l1 = l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2 = l2->next;
            }
            sum+=carry;
            
            ListNode *n = new ListNode(sum%10);
            temp->next = n;
            temp = temp->next;
            
            carry = sum/10;
            sum = 0;
        }
        if(carry!=0){
            ListNode *n = new ListNode(carry);
            temp->next = n;
        }
        ListNode *ans = reverse(dummy->next);
        return ans;
        
        
    }
};