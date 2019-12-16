// KTH ELEMENT FROM LAST IN LINKED LIST
// Given a linked list with n nodes. Find the kth element from last without computing the length of the linked list.

// Input Format:
// First line contains space separated integers representing the node values of the linked list. The list ends when the input comes as '-1'. The next line contains a single integer k.

// Constraints:
// n < 10^5

// Output Format
// Output a single line containing the node value at the kth element from last.

// Sample Input
// 1 2 3 4 5 6 -1
// 3
// Sample Output
// 4
#include <iostream>
using namespace std;

class node{
public:
    int data;
    node *next;

    node(int d){
        data=d;
        next=NULL;
    }
};

void insertattail(node *&head,int data){
    node *n=new node(data);
    node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void insertathead(node *&head,int data){
    node *n=new node(data);
    n->next=NULL;
    head=n;
}
void buildlist(node *&head){
    int data;
    cin>>data;
    insertathead(head,data);
    cin>>data;
    while(data!=-1){
        insertattail(head,data);
        cin>>data;
    }
}

node *kthfromlast(node *head,int k){
    node *slow=head;
    node *fast = head;
    int jumps = 1;
    while(jumps<=k){
        fast =fast->next;
        jumps++;
    }
    while(fast!=NULL){
        fast=fast->next;
        slow = slow->next;
    }
    return slow;
}



int main() {
    node *head = NULL;
    buildlist(head);
    int k;
    cin>>k;

    node *e=kthfromlast(head,k);
    cout << e->data << endl;
    return 0;
}