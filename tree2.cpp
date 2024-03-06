#include<iostream>
using namespace std;
#include<bits/stdc++.h>

// Making the binary it is the data :
// 1 2 5 -1 -1 6 -1 -1 3 9 -1 -1 -1

// Making the tree
// 8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

class Node{

public:
int data;
Node*left;
Node*right;

// root node yha pr kyo nahi banaya:

Node(int data){
this->data=data;
this->left=NULL;
this->right=NULL;
}


};

// function to create a Tree:->
Node* create_tree(){
int data;
cout<<"Enter the data: "<<endl; 
cin>>data;
// ek node create hue or uske ander maine data insert kiya 
Node*root=new Node(data);
// If data is -1 
if(data==-1){
    return NULL;
}


  cout<<"Enter the data in the Left of : "<<data<<endl;
root->left=create_tree();
cout<<"Enter the data in the Right of : "<<data<<endl;
root->right=create_tree();

return root;

}

/*

void print_leafNode(Node*root){

// base case 
    if(root==NULL) return;

    // recusive case            (Leaf Node are those who have no child) 
   
    if(root->left==NULL and root->right==NULL){
cout<<root->data<<endl;
    }

       print_leafNode(root->left);  // root update root->left
       print_leafNode(root->right);


}

// Bfs in the tree(Level order traversal )
void BFS(Node*root){

// base case 
if(root==NULL) return ;

queue<Node*>q;
if(root) q.push(root); // ek bar root ko queue me insert kardo 
while(q.size()){
Node*a=q.front();
q.pop();  // here remove first element of the queue
cout<<a->data<<" ";
if(a->left) q.push(a->left);
if(a->right)q.push(a->right);

}


}
/*


int count_Node(Node*root){
// base case 

if(root==NULL) return 0 ;

return 1+count_Node(root->right)+count_Node(root->left);;

}


/*
// Void zig_zag traversal 
void zig_zag_LOrder_traversal(Node*root,int &cnt){

    // base case 
if(root==NULL) return ;

// It just like two for loop in the pattern
queue<Node*>q;
if(root) q.push(root);
while(q.size()){

 //   int i=q.size();
    int siz=q.size();
    cnt++;
    while(siz--){
Node*a=q.front();

q.pop();  // here remove first element of the queue:->


cout<<a->data<<" ";

   
if(cnt%2==0){
    
if(a->right) q.push(a->right);
if(a->left) q.push(a->left);

}
else{

if(a->left) q.push(a->left);
if(a->right) q.push(a->right);

}

    }
    cout<<endl;
}




}   */

void preorder(Node*root){
if(root==NULL) return ;

// recusive case 
cout<<root->data<<" ";
preorder(root->left);
preorder(root->right);


}

void inorder(Node*root ){
   
if(root==NULL) return ;

// recusive case 

inorder(root->left);
cout<<root->data<<" ";

inorder(root->right);
}

// height of the tree
int height(Node*root){
//  base case 
if(!root) return 0;

// recusive case 
return max (height(root->left),height(root->right))+1;

}

// count Nodes
int cntNodes(Node*root){
// base case 
if(!root) return 0;

// recusive case 
return cntNodes(root->left)+cntNodes(root->right)+1;

}

// diameter of the tree
int diameter(Node*root){

// base case 
if(root==NULL) return 0;


// recusive case 
//1: Dia meter via root Node
int op1=height(root->left)+height(root->right);

// 2: Dia meter exists in LST
int op2=diameter(root->left);

//3: Dia meter exists in RST
int op3=diameter(root->right);

return max(op1,max(op2,op3));

}

// Now to reduce the complexity of the code we used concept of Pair to find the Diameter of the tree
class Pair{

public:
int height;
int diameter;
};

Pair fastDia(Node*root){
// base case 
if(root==NULL){
    return{ 0,0}; // here return {height=0,diameter=0}

}

// recursive case 
Pair left= fastDia(root->left);
Pair right=fastDia(root->right);

// inside the recursive case we made a Pair 
Pair p;
// height of the tree
p.height=max(left.height,right.height)+1;

// Diameter  of the tree
int op1=left.height+right.height; // iske calling kaise ho rahe hai 
int op2=left.diameter;
int op3=right.diameter;

p.diameter=max(op1,max(op2,op3));
return p;

}




// search key inside the BT 
Node* searchBT(Node*root,int key){
// base case 
if(!root) return NULL;

// recusive case 
if(root->data==key){
    return root;
}

searchBT(root->left,key);
searchBT(root->right,key);

}

void levelorder2(Node*root){
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
cout<<n->data;
if(n->left) q.push(n->left);
if(n->right) q.push(n->right);

}

}
}

void mirror(Node*root){

// base case 
if(root==NULL) return ;

// recusive case 
swap(root->left,root->right);
// recusion tu bata root->left and root->right
mirror(root->left);
mirror(root->right);

}

// Level order traversal 
void LevelOrderTraversal(Node* root){
queue<Node*>q;
q.push(root);
q.push(NULL);
while(!q.empty()){
Node*temp=q.front();
q.pop();
if(temp==NULL){
cout<<endl;
if(!q.empty()){
    q.push(NULL);
}

}
else{

cout<<temp->data<<" ";
if(temp->left) q.push(temp->left);
if(temp->right) q.push(temp->right);


}


}





}


int main() {

Node*root=NULL;   // Here we initaised the root Node
root=create_tree();  // here root Node hold the address of the whole tree 
/* cout<<"THE Leaf Node is: "<<endl;
print_leafNode(root);
cout<<endl;
BFS(root);
cout<<endl;
cout<<"Level order Traversal is : "<<endl;
LevelOrder(root);
cout<<endl;
cout<<count_Node(root);
cout<<endl;
//zig_zag_LOrder_traversal(root,cnt);*/
levelorder2(root);
cout<<endl;
preorder(root);
cout<<endl;
inorder(root);
cout<<endl;
cout<<cntNodes(root);
cout<<endl;
cout<<height(root);
cout<<endl;
cout<<diameter(root)<<endl;
   
   Node* x=searchBT(root,13);
   if(x!=NULL){
  cout<<"Found key: "<<x->data<<endl;

   }
   else{
    cout<<"Key is not found"<<endl;
   }

   // Now call the pair of the fastDia
   Pair ans=fastDia(root);
   cout<<"Fast Height: "<<ans.height<<endl;
   cout<<"Fast Diameter: "<<ans.diameter<<endl;
// mirror(root);
// cout<<"AFTER MIRROR : Preoder is"<<endl;
preorder(root);
cout<<endl;
cout<<"Level order traversal is :"<<endl;
LevelOrderTraversal(root);

}

// Making the tree
// 8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
