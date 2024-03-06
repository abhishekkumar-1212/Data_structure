#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<algorithm>
class Node{
public:
int data;
Node*right=NULL;
Node*left=NULL;

};

void inorder(Node*root){

// base case 
if(root==NULL) return ;
// recusive case 
inorder(root->left);
cout<<root->data<<" ";
inorder(root->right);


}

// Height of the tree
int  height(Node*root){

// base case 
if(root==NULL) return 0;

// recusive case 
int heightLeft=  height(root->left);
int  heightRight=height(root->right);
return max(heightLeft,heightRight)+1;


}
void mirrorImage(Node*root){

// base case 
if(root==NULL) return ;

// recusive case
swap(root->left,root->right);
 
mirrorImage(root->left);
mirrorImage(root->right);

}

int main() {
Node*root=new Node();
root->data=90;
Node*node1=new Node();
node1->data=5;
Node*node2=new Node();
node2->data=10;

// Here we Link the nodes 
root->left=node1;
root->right=node2; 

Node*node3=new Node();
node3->data=11;
Node*node4=new Node();
node4->data=13;
node1->left= node3;
node1->right=node4;  // Dy default left and right is set NULL
inorder(root);
cout<<endl;
cout<<height(root);

cout<<endl;
mirrorImage(root);
cout<<"After mirror the tree print Inorder: ";
inorder(root);

}