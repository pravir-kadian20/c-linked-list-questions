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
    
    int length(ListNode *head){
        int ans = 0;
        while(head!=NULL){
            ans++;
            head=head->next;
        }
        return ans;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL)  return NULL;
        int l1 = length(headA);
        int l2 = length(headB);
        
        int diff = abs(l1-l2);
        int cnt = diff;
        if(l1>=l2){
            while(cnt!=0){
                headA = headA->next;
                cnt--;
            }
        }
        else{
            while(cnt!=0){
                headB = headB->next;
                cnt--;
            }
        }
        while(headA!=NULL && headB!=NULL){
            if(headA==headB){
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};