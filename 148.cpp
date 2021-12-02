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
    
    ListNode *findMiddle(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode *merge(ListNode *head1,ListNode *head2){
        
        if(head1==NULL) return head2;
        if(head2==NULL) return head1;
        
        if(head1->val <= head2->val){
            ListNode *newHead = merge(head1->next,head2);
            head1->next = newHead;
            return head1;
        }
        else{
            ListNode *newHead = merge(head1,head2->next);
            head2->next = newHead;
            return head2;
        }
    }
    
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)  return head;
        
        ListNode *middle = findMiddle(head);
        
        ListNode *newHead = middle->next;
        
        middle->next = NULL;
        
        ListNode *head1 = sortList(head);
        ListNode *head2 = sortList(newHead);
        
        ListNode *ans = merge(head1,head2);
        return ans;
    }
};