// LINKED LIST-K APPEND
// Append the last K elements of a linked list to the front.K can be greater than N.

// Input Format:
// Enter the size N, N space separated elements and number of elements that are to be appended(n).

// Constraints:
// None

// Output Format
// Display all the elements in the list

// Sample Input
// 7
// 1 2 2 1 8 5 6
// 3
// Sample Output
// 8 5 6 1 2 2 1

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

void insertathead(node *&head,int data){
    node *n=new node(data);
    n->next=head;
    head=n;
}

void insertattail(node *&head,int data){
    node *n=new node(data);
    node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->next=NULL;
}

void buildlist(node *&head,int n){
    int data;
    cin>>data;
    insertathead(head,data);
    int count = 1;
    while(count < n){
        cin>>data;
        insertattail(head,data);
        count++;
    }
}

void print(node *head){
    while(head!=NULL){
        cout << head->data << " ";
        head=head->next;
    }
}

void append(node *&head,int n,int k){
    node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head;
    node*temp1=head;
    int jumps = 1;
    while(jumps < (n-k)){
        temp1=temp1->next;
        jumps++;
    }
    node *newhead=temp1->next;
    head=newhead;
    temp1->next=NULL;
}
int main() {
    node*head=NULL;
    int n;
    cin>>n;
    buildlist(head,n);
    int k;
    cin>>k;
    if(k==n){
        print(head);
    }
    if(k<n){
        append(head,n,k);
        print(head);
    }
    if(k>n){
        k=k-n;
        append(head,n,k);
        print(head);
    }

    return 0;
}