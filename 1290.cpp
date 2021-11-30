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
    
    int length(ListNode *head){
        int ans=0;
        while(head!=NULL){
            ans++;
            head = head->next;
        }
        return ans;
    }
    
    int getDecimalValue(ListNode* head) {
        int len = length(head);
        
        len-=1;
        int ans=0;
        while(head!=NULL){
            ans+=((head->val)*pow(2,len));
            len--;
            head = head->next;
        }
        return ans;
    }
};