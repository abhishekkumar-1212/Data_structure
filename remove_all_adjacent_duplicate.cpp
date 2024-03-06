// Remove All Adjacent Duplicates in String 
/*
Input: "abbaca"
output: "ca"
*/


#include<iostream>
using namespace std;
#include<bits/stdc++.h>


void f(string& s){

string ans;
ans="";  // string size take dynammically
for(int i=0;i<s.length() ;i++){

if( ans.length()>0 and ans[ans.length()-1]==s[i] ){  // for leetcode to avoid access -1 index which is not exist 

ans.pop_back();

}
else{

  ans.push_back(s[i]);
  }


}

cout<<ans;

}


int main(){
string s;
cin>>s;


f(s);

}