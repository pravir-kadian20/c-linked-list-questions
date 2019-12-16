// INTERSECTION POINT TWO LINKED LISTS
// There are two linked lists. Due to some programming error, the end node of one of the linked list got linked into the second list, forming an inverted Y shaped list. Now it's your job to find the point(Node) at which the two linked lists are intersecting.

// Input Format:
// The first line of input is the size(N1) of the first linked list, followed by its content(Xi). The third line of input is the size(N2) of the second linked list, followed by its content( Yi ).

// Constraints:
// 1<=N, N2<=100 0<=Xi, Yi<=100

// Output Format
// A single integer denoting the intersection point of two linked lists. If the linked lists are not intersecting at any point then print -1.

// Sample Input
// 5
// 10 20 30 40 50
// 4
// 15 25 40 50
// Sample Output
// 40
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

void print(node *head){
    while(head!=NULL){
        cout << head->data << "->";
        head = head->next;
    }
}
void buildlist(node *&head,int n){
    int count=1;
    int data;
    cin>>data;
    insertathead(head,data);
    while(count<n){
        cin>>data;
        insertattail(head,data);
        count++;
    }
}
int intersection(node *head1,node *head2,int n1,int n2){
    int d;
    int jumps=1;
    node *temp1=head1;
    node *temp2=head2;
    if(n1>=n2){
        d=n1-n2;
        while(jumps<=d){
            temp1=temp1->next;
            jumps++;
        }
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->data==temp2->data){
                return temp1->data;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
    else{
        d=n2-n1;
        while(jumps<=d){
            temp2=temp2->next;
            jumps++;
        }
        while(temp1!=NULL || temp2!=NULL){
            if(temp1==temp2){
                return temp2->data;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
    return -1;
}
int main() {
    node *head1=NULL;
    node *head2=NULL;
    int n1;
    cin>>n1;
    buildlist(head1,n1);
    int n2;
    cin>>n2;
    buildlist(head2,n2);
    cout << intersection(head1,head2,n1,n2);
	return 0;
}