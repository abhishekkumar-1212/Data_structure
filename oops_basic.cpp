#include<iostream>
using namespace std;
#include<cstring>

class Car{
public:
char name[100];
int price;
int model;
int seats;

Car(){
cout<<"Inside the constructor "<<endl;

}

// arameterised constructor 
Car(char *n,int p,int m,int s ){
cout<<"INside the parameterised constructor "<<endl;
strcpy(name,n);
price=p;
model=m;
seats=s;

}

void operator=(Car&x){
cout<<"Inside the copy assignment "<<endl;
strcpy(name,x.name);
price=x.price;
model=x.model;
seats=x.seats;
}
void print(){

cout<<"Name: "<<name<<endl;
cout<<"Price:"<<price<<endl;
cout<<"MOdel"<<model<<endl;
cout<<"Seats: "<<seats<<endl;

    
}

~ Car(){


    cout<<"Deleting the object "<<name<<endl;
}


};



int main() {
  Car a;
  strcpy(a.name,"BMW");
  a.price=10;
  a.model=2023;
  a.seats=5;

  Car b("Maruti", 100 ,1276,4);
  a.print();
  b.print();

  b=a;
  a.print();

  return 0;

}