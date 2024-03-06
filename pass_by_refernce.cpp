#include<iostream>
using namespace std;
// swap by using the refernce variable 

void swapped(int &p,int&second)
{
        int temp=p;
        p=second;
        second=temp;


}


int main(){
/*int num=10;
int &temp=num;
temp=temp+1;
cout<<temp;
*/

int first=10,second=20;
swapped(first,second);
cout<<"After swapped"<<endl;
cout<<first<<" "<<second<<endl;
}