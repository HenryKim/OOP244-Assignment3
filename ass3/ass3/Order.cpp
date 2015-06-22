/*Hyungi kim
025 741 125
assignment 3
order.cpp*/
#include<iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;
#include"Order.h"

Order::Order(){
	ISBN temp;
	isbnOrder =temp;
	ord=0;
	deli=0;
}
/* safe empty state mode*/
Order::Order(const ISBN& str){
	isbnOrder =str;
	ord=0;
	deli=0;
}
/* copy consturctor*/

bool Order::has(const ISBN& str) const{
	if (isbnOrder == str){
		return true;}
	else{
	return false;}
	
}
/* compare classes and return true it matched else return false*/

int Order::outstanding() const{
	return ord	;
}

bool Order::receive(istream& is){
	bool flag=false;
	int x=0;
	int y=0;
	do{
		if(x>ord){
			cout<<"error"<<endl;
			cin.ignore(1000,'\n');
		}
		else if(x<0){
			cout<<"enter positive number please"<<endl;
			cin.ignore(1000,'\n');
		}
		else if(x ==0){
			cin.ignore(1000,'\n');
			y=1;
		}
		else{
		cin.ignore(1000,'\n');
		flag=true;
		deli=deli+x;

		}
	}while(y==0 && !flag);
};
/* return value of ord in current objecive*/
bool Order::add(istream& is){
	bool flag = false;
	int x=0;
	int y=0;
	do{
		cout<<"Quantity";
		is>>x;
		if( x <0){
			cout<<"enter positive number please"<<endl;
			cin.ignore(1000,'\n');
		}
		else if ( x==0){
			cout<<"exiting"<<endl;
			cin.ignore(1000,'\n');
			y=1;
		}
		else{
			cin.ignore(1000,'\n');
			flag=true;
			ord= ord+x;
		}

	}while(y==0 && !flag);
}
bool Order::add(int n){
	if( n>0 && !(isbnOrder == ISBN())){
		ord= ord+n;
		return true;
	}
	return false;
}

void Order::display(ostream& os) const{
 
   os << right << setw(13) << isbnOrder
      << setw(9) << ord
      << setw(11) << deli;
}
// DISPLAY