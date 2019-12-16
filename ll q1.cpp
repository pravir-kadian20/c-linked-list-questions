// Given a head to Linked List L, write a function to reverse the list taking k elements at a time. Assume k is a factor of the size of List.

// You need not have to create a new list. Just reverse the old one using head.

// Input Format:
// The first line contains 2 space separated integers N and K

// The next line contains N space separated integral elements of the list.

// Constraints:
// 0 <= N <= 10^6 0 <= K <= 10^6

// Output Format
// Display the linkedlist after reversing every k elements

// Sample Input
// 9 3
// 9 4 1 7 8 3 2 6 5
// Sample Output
// 1 4 9 3 8 7 5 6 2

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
node *reverse(node *head,int k){
    node *C=head;
    node *P=NULL;
    node *N=NULL;
    int count =0;
    while(C!=NULL && count < k){
        N=C->next;
        C->next=P;
        P=C;
        C=N;
        count++;
    }
    if(N!=NULL){
        head->next = reverse(N,k);
    }

    return P;

}
int main() {
    node *head=NULL;
    int n,k;
    cin>>n>>k;
    buildlist(head,n);
    head=reverse(head,k);
    print(head);
	return 0;
}