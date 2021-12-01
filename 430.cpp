/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node *curr = head;
        
        stack<Node*>s;
        Node *tail=head;
        while(curr!=NULL){
            if(curr->child!=NULL){
                if(curr->next){
                    s.push(curr->next);
                    curr->next->prev = NULL;
                }
                curr->next = curr->child;
                curr->next->prev = curr;
                curr->child = NULL;
            }
            tail = curr;
            curr = curr->next;
        }
       
        while(!s.empty()){
            Node *n = s.top();
            s.pop();
            tail->next = n;
            n->prev = tail;
            curr = n;
            while(curr!=NULL){
                tail = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};