// #include<iostream>
// using namespace std;
// #include<bits/stdc++.h>

// // Making the binary it is the data :
// // 1 2 5 -1 -1 6 -1 -1 3 9 -1 -1 -1


// class Node{

// public:
// int data;
// Node*left;
// Node*right;

// // root node yha pr kyo nahi banaya:

// Node(int data){
// this->data=data;
// this->left=NULL;
// this->right=NULL;
// }


// };

// // function to create a Tree:->
// Node* create_tree(){
// int data;
// cout<<"Enter the data: "<<endl;
// cin>>data;
// // ek node create hue or uske ander maine data insert kiya 
// Node*root=new Node(data);
// // If data is -1 
// if(data==-1){
//     return NULL;
// }


//   cout<<"Enter the data in the Left of : "<<data<<endl;
// root->left=create_tree();
// cout<<"Enter the data in the Right of : "<<data<<endl;
// root->right=create_tree();

// return root;

// }

// /*

// void print_leafNode(Node*root){

// // base case 
//     if(root==NULL) return;

//     // recusive case            (Leaf Node are those who have no child) 
   
//     if(root->left==NULL and root->right==NULL){
// cout<<root->data<<endl;
//     }

//        print_leafNode(root->left);  // root update root->left
//        print_leafNode(root->right);


// }

// // Bfs in the tree(Level order traversal )
// void BFS(Node*root){

// // base case 
// if(root==NULL) return ;

// queue<Node*>q;
// if(root) q.push(root); // ek bar root ko queue me insert kardo 
// while(q.size()){
// Node*a=q.front();
// q.pop();  // here remove first element of the queue
// cout<<a->data<<" ";
// if(a->left) q.push(a->left);
// if(a->right)q.push(a->right);

// }


// }
// /*

// // Level order traveral with each level first 
// void LevelOrder(Node*root){

// // base case 
// if(root==NULL) return ;

// // It just like two for loop in the pattern
// queue<Node*>q;
// if(root) q.push(root);
// while(q.size()){
//     int size=q.size();
//     while(size--){
// Node*a=q.front();
// q.pop();  // here remove first element of the queue
// cout<<a->data<<" ";
// if(a->left) q.push(a->left);
// if(a->right)q.push(a->right);


//     }
//     cout<<endl;
// }


// }

// int count_Node(Node*root){
// // base case 

// if(root==NULL) return 0 ;

// return 1+count_Node(root->right)+count_Node(root->left);;

// }


// /*
// // Void zig_zag traversal 
// void zig_zag_LOrder_traversal(Node*root,int &cnt){

//     // base case 
// if(root==NULL) return ;

// // It just like two for loop in the pattern
// queue<Node*>q;
// if(root) q.push(root);
// while(q.size()){

//  //   int i=q.size();
//     int siz=q.size();
//     cnt++;
//     while(siz--){
// Node*a=q.front();

// q.pop();  // here remove first element of the queue:->


// cout<<a->data<<" ";

   
// if(cnt%2==0){
    
// if(a->right) q.push(a->right);
// if(a->left) q.push(a->left);

// }
// else{

// if(a->left) q.push(a->left);
// if(a->right) q.push(a->right);

// }

//     }
//     cout<<endl;
// }




// }   */



// void levelorder2(Node*root){

// queue<Node*>q;
// q.push(root);
// q.push(NULL);

// while(!q.empty()){
// Node*n=q.front();
// q.pop();

// if(n==NULL){
// cout<<endl;
// if(!q.empty()){
//     q.push(NULL);
// }


// }
// else{
// cout<<n->data<<" ";
// if(n->left) q.push(n->left);
// if(n->right) q.push(n->right);

// }


// }


// }




// int main() {

// Node*root=NULL;   // Here we initaised the root Node
// root=create_tree();  // here root Node hold the address of the whole tree 
// /* cout<<"THE Leaf Node is: "<<endl;
// print_leafNode(root);
// cout<<endl;
// BFS(root);
// cout<<endl;
// cout<<"Level order Traversal is : "<<endl;
// LevelOrder(root);
// cout<<endl;
// cout<<count_Node(root);
// cout<<endl;
// //zig_zag_LOrder_traversal(root,cnt);*/


// root=level_order_input();
// cout<<endl;

// levelorder2(root);
  
// }