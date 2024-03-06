#include<iostream>
using namespace std;
// Linekd_List 

class Node{

public:
int data;
Node*next;

// making the parameterised constructor (By default value dene ke kiya linked list ke single nodes ko )
Node(int data ){
this-> data=data;  // this-> data here indicate the data inside constructor Node(// here data indiacate ){}
this->next=NULL;


}


};

void insertat_front(Node*&head,Node*&tail,int data){

// If LL is empty ( initially always this case is executed )
if(head==NULL){

//1: first create a newNode 
Node*newNode=new Node( data );
newNode->next=head;
head=newNode;
tail=newNode;
   return;
}

// if LL is NON Empty 
//1: create a newNode
Node*newNode=new Node( data );
newNode->next=head;
head=newNode;



}

void insertAT_Tail(Node*&head,Node*&tail,int data){

// LL is empty 
if(head==NULL){
// 1: create a new Node 

Node*newNode=new Node( data );
newNode->next=head;
head=newNode;
tail=newNode;
   return;

}

// if LL is not empty 
//1: also create a newNode 
Node*newNode=new Node(data);

tail->next=newNode;
tail=newNode;

}

// make a function to calculate the length of the linked list 

int findLength(Node*head){
    Node*temp=head;
    int cnt=0;
    while(temp!=NULL){
   cnt++;
    temp=temp->next;


    }

return cnt;

}



// Now insertAt_middle or at Any position of the linked list  to the linked list 

void insertAt_Position(int position,Node*&head,Node*&tail,int data){

// LL is empty 
if(head==NULL){
// 1: create a new Node 

Node*newNode=new Node(data);
newNode->next=head;
head=newNode;
tail=newNode;
   return;

}

// LL is not empty 
//1: Find current and previous position 

if(position==0){
insertat_front(head,tail,data);
return;

}

int len=findLength(head);
if(position==len){
    insertAT_Tail(head,tail,data);
    return;
}


// insert at the position is start from i=1 and i=len-1 so that we take i=1;(So it handle the middle of the Linkedlist)
// a. first we find the prev
int i=1;

Node*prev=head;   

while(i< position){

prev= prev->next;
i++;

}

//b. also find the current 

Node*curr;
curr=prev->next;


//2. Create a newNode 
Node*newNode=new Node(data);

//3. newNode->next=curr;
newNode->next=curr;
//4. prev->next=newNode;
prev->next=newNode;



}







// Now to print the linked list 
void printLL(Node*head){
Node*temp=head;
while(temp!=NULL){
cout<<temp->data<<" ";
temp=temp->next;


}



}



int main(){

// making the object of head and tail without dynamically 
Node*head=NULL;
Node*tail=NULL;

insertat_front(head,tail,8);
insertat_front(head,tail,7);
insertat_front(head,tail,6);
insertat_front(head,tail,90);
printLL(head);
cout<<endl;
cout<<"After inserting AT the Tail:"<<endl;
insertAT_Tail(head,tail,100);

printLL(head);

cout<<endl;
cout<<"After inserting at Middle 5"<<endl;

insertAt_Position(1,head,tail,5);
printLL(head);

}