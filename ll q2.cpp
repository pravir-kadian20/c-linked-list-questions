// PALINDROME
// Check if a linked list is a palindrome.( Boolean return type )

// Input Format:
// Add N space separated elements in the list

// Constraints:
// None

// Output Format
// Boolean answer( true or false)

// Sample Input
// 5
// 1 2 3 6 8
// Sample Output
// False
#include<iostream>
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

void buildlist(node *&head,int n){
    int count=1;
    int data;
    cin>>data;
    insertathead(head,data);
    while(count < n){
        cin>>data;
        insertattail(head,data);
        count++;
    }
}


node* reverse(node *head){
    if(head->next==NULL || head==NULL){
        return head;
    }
    node *smallhead=reverse(head->next);
    node *c=head;
    c->next->next=c;
    c->next=NULL;
    return smallhead;
}

bool ispalindrome(node *&head){
    node *newhead=reverse(head);
    node *temp=head;
    node *temp1=newhead;
    while(temp!=NULL){
        if(temp->data!=temp1->data){
            return false;
        }
        temp=temp->next;
        temp1=temp1->next;
    }
    return true;
}
int main() {
    int n;
    cin>>n;
    node *head=NULL;
    buildlist(head,n);
    head=reverse(head);
    if(ispalindrome(head)){
        cout << "True";
    }
    else{
        cout << "False";
    }
	return 0;
}
