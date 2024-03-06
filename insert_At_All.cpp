#include<iostream>
using namespace std;

// making the LL
class Node{
    public:
    int data;
    Node*next;
    
// making the constructor
Node(int data){
    
    this->data =data;
    this->next=NULL;
   
}

// for delete the element in the linked list 
~Node(){


}



};

// calculate the length of the linked list 
int findLength(Node*head){
    Node*temp=head;
    int cnt=0;
    while(temp!=NULL){
      cnt++;
      temp=temp->next;

    }

return cnt;

}





void insertAt_head(Node*&head,Node*&tail,int data){
    
    // if LL is empty 
    if(head==NULL){
        // create a newNode 
        Node * newNode=new Node(data);
        newNode->next=head;
        head=newNode;
        tail=newNode;
        
        
    }
    
    // If LL is NOt empty 
    //1: create a new Node
      Node * newNode=new Node(data);
      newNode->next=head;
      head=newNode;
    
}

// insertAT_TAIL
void insertAT_TAIL(Node*&head,Node*&tail,int data ){

 //if LL is empty 
    if(head==NULL){
        // create a newNode 
        Node * newNode=new Node(data);
        newNode->next=head;
        head=newNode;
        tail=newNode;
        
        
    }
else{

Node*newNode=new Node(data);
tail->next=newNode;
tail=newNode;

}

}

// insert at the position
/*
->1: InsertAthead
->2: InsertAtmiddle(between head to tail)
->3:insertAtTail

*/

void insertAtPosition(int position,Node*&head,Node*&tail,int data){

 //if LL is empty 
    if(head==NULL){
        // create a newNode 
        Node * newNode=new Node(data);
        newNode->next=head;
        head=newNode;
        tail=newNode;
        return;
        
    }


// if linked list is Not Empty

// insertAt_zeroth_ position
if(position==0){
insertAt_head(head,tail,data);
return ;

}


// insertAtTail of the linked list 
int len=findLength(head);
if(position==len){
insertAT_TAIL(head,tail,data);
return ;

}


// 1: find the position

int i=1;
Node*curr;
Node*prev=head;
while(i<position){
// Find the previous 
prev=prev->next;
i++;

}
// Also find the current 
curr=prev->next;

// 2: create a newNode 
Node* newNode=new Node(data);

// newNode->next=curr;
newNode->next=curr;
// prev->next=newNode;
prev->next=newNode;

}

// print the linked list 
void print(Node*head){
   Node*temp=head;
   while(temp!=NULL){
       cout<<temp->data<<" ";
       temp=temp->next;
       
   }
    
}

// delete from the head of the linked_List 

// agar delete krna hai to linked list me phele se hi value honge 
void delete_head(Node*&head ){

// If LL is empty
if(head==NULL){
    cout<<"LL is EMpty"<<endl;
}



Node*temp=head;
// temp->next=NULL;
head=head->next;
temp->next=NULL;
delete temp;

}

void delete_tail(Node*&head,Node*&tail ){
// If LL is empty
if(head==NULL){
    cout<<"LL is Empty"<<endl;
    head=tail=NULL;
}

// LL is Not empty 
//1: find the previous position of tail
Node*prev=head;
Node*temp=tail;
while(prev->next!=tail){
    prev=prev->next;

}
//temp->next=NULL; (it is optional  )
delete temp;  

tail=prev;
tail->next=NULL;

}

// delete atMiddle of the linked list





int main(){
    Node*head=NULL;
    Node*tail=NULL;
    
    insertAt_head(head,tail,45);
    insertAt_head(head,tail,40);
    insertAt_head(head,tail,12);
    insertAt_head(head,tail,10);
    
    print(head);
    cout<<endl;
    insertAT_TAIL(head,tail,100);
    print(head);
cout<<endl;
cout<<"After inserting the position "<<endl;
cout<<endl;
   // insertAt the position 
   insertAtPosition(2,head,tail,54);

      print(head);
 cout<<endl;
 cout<<"After deleting from the head: "<<endl;
 delete_head(head);
   print(head);
   cout<<endl;
   cout<<"DELETING from tail"<<endl;
   delete_tail(head,tail);
     print(head);


}