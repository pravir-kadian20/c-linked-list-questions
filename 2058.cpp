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
        vector<int>ans;
        if(head==NULL || head->next==NULL || head->next->next==NULL){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        ListNode *prev = head;
        ListNode *curr = head->next;
        ListNode *nex = head->next->next;
        int cnt = 2;
        int flag = 0;
        int mini = INT_MAX;
        int p = 0;
        int first = 0;
        while(nex!=NULL){
            if((curr->val > nex->val && curr->val > prev->val) || (curr->val < nex->val && curr->val < prev->val) )             {
                if(flag==0){
                    first = cnt;
                    flag=1;
                    p = cnt;
                }
                else{
                    mini = min(mini,cnt-p);
                    p = cnt;
                }
            }
            curr = curr->next;
            prev = prev->next;
            nex = nex->next;
            cnt++;
        }
        if(mini==INT_MAX){
            ans.push_back(-1);
            ans.push_back(-1);
        }
        else{
            ans.push_back(mini);
            ans.push_back(p-first);
        }
        return ans;
        
    }
};