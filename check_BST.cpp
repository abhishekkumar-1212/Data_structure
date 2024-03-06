// here we create the BST 
#include<iostream>
using namespace std;
#include<bits/stdc++.h>

// here we provide any Input it convert into the BST preorder , inorder and postorder 


class Node{
    public:
int data;
Node*left;
Node*right;
//making the parameterised constructor
Node( int data){
this->data=data;
this->left=NULL;
this->right=NULL;

}
};

// here we InsertAtBst
Node* InsertInBST(Node* root,int data){

// base case 
if(root==NULL) {
    root=new Node(data);
 return root;
}

// recusive case 
if(data<=root->data){
    root->left=InsertInBST(root->left,data);  // root change in recusive call

}
else{
    root->right=InsertInBST(root->right, data);
    

}
return root;

}

// create a BST 
Node* createBST(){
Node* root=NULL;
int data;
cin>>data;

while(data!=-1){
 root=InsertInBST(root,data);
cin>>data;

}
return root;

}



Node* searchInBST(Node*root,int key){

// base case 
if(root==NULL){
    return NULL;
}

// recusive case
if(root->data==key){
     return root;
}
else if(root->data>=key){  // why root->left =searchInBST(root->left,key) is not working 
searchInBST(root->left,key);

}
else{
 searchInBST(root->right,key);

}

}

/*
void pr(Node*root, int k1,int k2){
   if(root->data<k1 and root->data>k2){
    return ;
   }

// recusive case 
if(root->data>=k1 and root->data<=k2 ){
    cout<<root->data<<" ";
}

if(root->data<k1){
    pr(root->right,k1,k2);
}

if(root->data>k2){
        pr(root->left,k1,k2);
}

 
 else{
pr(root->left,k1,k2);
pr(root->right,k1,k2);

 }


}

*/



// Print the RangesInBST
void printRangeBST(Node*root,int k1,int k2){

if(!root) return ;

if(root->data>=k1 and root->data<=k2){
    cout<<root->data<<" ";
}

if(root->data<k1){
    printRangeBST(root->right,k1,k2);
}

if(root->data>k2){
        printRangeBST(root->left,k1,k2);
}

else{
  printRangeBST(root->left,k1,k2);
  printRangeBST(root->right,k1,k2);

}

}

// height of the tree
int height(Node* root){
// base case 
if(!root) return 0;

// recusive case 
int left_height=height(root->left);
int right_height=height(root->right);
return max(left_height,right_height)+1;


}




bool isBalanced(Node* root){
// base case 
if(!root){
    return true;
}

// recusive case 
int left_height=height(root->left);
int right_height=height(root->right);

int curr_diff= abs(left_height-right_height);
if(curr_diff<=1 and isBalanced(root->left) and isBalanced(root->right)){
    return true;
}
else{
    return false;
}

}



// To reduced the time complexity of the isbalanced (with TC: O(N))
class Pair{
 public:
 int height;
 bool balanced;


};

Pair fastBalanced(Node*root){
Pair p;

// base case 
if(!root){
   
    return {0,true};
}

Pair left=fastBalanced(root->left);
Pair right=fastBalanced(root->right);
p.height=max(left.height,right.height)+1;
if(abs(left.height-right.height)<=1 and left.balanced and right.balanced){
p.balanced=true;
}
else{
    p.balanced=false;
}
return p;
}

// check the given tree is Bst or Not
bool isBST(Node*root,int mi=INT_MIN,int mx=INT_MAX){
// base case 
if(!root) return true;

// recursive case 
if(root->data>=mi and root->data<=mx and isBST(root->left,mi,root->data) and isBST(root->right,root->data,mx)){
    return true;
}
else{
    return false;
}


}

// Making BST By using the array
int a[]={1,2,8,9,10,11,12};
int n=sizeof(a)/sizeof(int );

Node*makeTree(int s, int e){

// base case 
if(s>e){
    return NULL;
}

// recusive case 
int mid=(s+e)/2;
Node*root= new Node(a[mid]);
root->left=makeTree(s,mid-1);
root->right=makeTree(mid+1,e);
return root;

}


// void Level order traversal
 void LOT(Node*root){

 queue<Node*>q;
 q.push(root);
 q.push(NULL);

 while(!q.empty()){
 Node*n=q.front();
 q.pop();

 if(n==NULL){
 cout<<endl;
 if(!q.empty()){
   q.push(NULL);
 }


 }
 else{
 cout<<n->data<<" ";
 if(n->left) q.push(n->left);
 if(n->right) q.push(n->right);

 }


 }


 }




int main() {
  Node* root=NULL;
  root=createBST();
// preorder(root);
// cout<<endl;


Node*ans=searchInBST(root,1);
if(ans){
    cout<<"Found: "<<ans->data<<endl;
}
else{
    cout<<"Not Found "<<endl;
}
height(root);

printRangeBST(root,3,10);
cout<<endl;
if(isBalanced(root)){
    cout<<"Balanced Hai "<<endl;
}
else{
    cout<<"Tree Balanced Nahi Hai"<<endl;
}

Pair ans1=fastBalanced(root);

    cout<<"fast Height: "<<ans1.height<<endl;
if(ans1.balanced){
cout<<"Is Balanced"<<endl;

}
else{
    cout<<"Not Balanced "<<endl;
}

makeTree(0,n-1);

LOT(root);
}