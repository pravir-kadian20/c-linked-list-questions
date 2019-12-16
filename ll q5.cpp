// EVEN-AFTER-ODD
// Arrange elements in a Linked List such that all even numbers are placed after odd numbers.

// Input Format:
// Enter N space separated Elements

// Constraints:
// None

// Output Format
// Linked list with all the odd numbers before even numbers

// Sample Input
// 5
// 1 2 2 2 1
// Sample Output
// 1 1 2 2 2
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

void print(node *head){
    while(head!=NULL){
        cout << head->data << " ";
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

void evenafterodd(node *&head){
	node *temp=head;
	node *temp1=NULL;
	node *temp2=NULL;
	node*fir;
	node *fir1;
	int count=0,count1=0;
	while(temp!=NULL){
		if(temp->data&1){
			if(count==0){
				fir1=temp;
				temp1=temp;
			}
			if(count>0){
				temp1->next=temp;
				temp1=temp1->next;
			}
			count++;
		}
		else{
			if(count1==0){
				fir=temp;
				temp2=temp;
			}
			if(count1>0){
				temp2->next=temp;
				temp2=temp2->next;
			}
			count1++;
		}
		temp=temp->next;
	}
	if(temp1!=NULL && temp2!=NULL){
		temp1->next=fir;
	}
	if(temp1!=NULL){
		head=fir1;
	}
	else{
		head=fir;
	}
	if(temp2!=NULL){
		temp2->next=NULL;
	}
	else{
		temp1->next=NULL;
	}
}
int main() {
	int n;
	cin>>n;
	node *head=NULL;
	buildlist(head,n);
	evenafterodd(head);
	print(head);
	return 0;
}