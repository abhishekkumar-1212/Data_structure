// print the address of the pointer 
#include<iostream>
using namespace std;
int main(){
int arr[5]={1,2,3,4,5};
int *ptr=arr;  // inside pointer we put the address of the first index
// Print the address of the first element in the array 
cout<<arr<<endl;
cout<<arr+0<<endl;   // for above arr
cout<<&arr[0]<<endl;
cout<<ptr<<endl;

//print address of the second element 
cout<<arr+1<<endl;
cout<<&arr[1]<<endl;

// print value of O th index
cout<<arr[0]<<endl;
cout<<*arr<<endl;
cout<<*(arr+0)<<endl;
cout<<*ptr<<'\n';

int n=sizeof(arr)/sizeof(arr[0]);  //size of the array in the given
//Print all the value of the array 
for(int i=0;i<n;i++){

cout<<*(arr+i)<<endl;


//Print all the element by using the pointers
       for(int i=0;i<n;i++){
        cout<<ptr[i]<<endl;
       }

// print all the adresses by using pointer 
for(int i=0;i<n;i++)
{
  cout<<(ptr+i)<<" ";

}
cout<<endl;






}


// Perform the arithemetic operation(like ++,--) by using the pointer 
for(int i=0;i<n;i++){
cout<<*ptr<<endl;
ptr=ptr+1;  // or ptr++

}







}