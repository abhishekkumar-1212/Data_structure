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

void preorder(Node*root){
    // base case 
    if(!root) return;
     cout<<root->data<<" ";
  preorder(root->left);
   preorder(root->right);

}


int main() {
  Node* root=NULL;
  root=createBST();
preorder(root);

}