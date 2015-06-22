/*Hyungi kim
025 741 125
assignment 3
order.cpp*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <cstdlib>

#include"Order.h"
using namespace std;


Order::Order(){
	ISBN temp;
	isbnOrder = temp;
	ord=0;
	deli=0;
}
/* safe empty state mode*/
Order::Order(const ISBN& str){
	isbnOrder = str;
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
	return ord;
}
/* a funcion returns ordered value in current object;*/

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
	return flag;
};
/* receive the refrence form istream and gets value from user
if user enters 0 quits and continuses askes untill user enter proper positivie number of deli variable
and add with current deli variable in this obj*/
bool Order::add(istream& is){
	bool flag = false;
	int x=0;
	int y=0;
	do{
		cout<<"Quantity(0 to quit)";
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
	return flag;
}
/* receive the refrence form istream and gets value from user
if user enters 0 quits and continuses askes untill user enter proper positivie number of ord variable
and add with current ord variable in this obj*/
bool Order::add(int n){
	if( n>0 && !(isbnOrder == ISBN())){
		ord= ord+n;
		return true;
	}
	return false;
}
/*a fuction recives intiger that will going to current ord varabile in this obj
yet it return true is isbnOrder value is in safe empty state else return false*/
void Order::display(ostream& os) const{
 
   os << right << setw(13) << isbnOrder
      << setw(9) << ord
      << setw(11) << deli;
}
// DISPLAY

ostream& operator<<(ostream& os, const Order& list){
	list.display(os);
	return os;
}/*function send ostream to display */