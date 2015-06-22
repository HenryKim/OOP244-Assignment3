/*Hyungi kim
025 741 125
assignment 3
ISBNP.cpp*/


#include<iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;
#include "ISBN.h"
int isValid(const char str[])
{
   int i, a=0, b=10, rc, sum=0;
 
   if( str != NULL )
   {
      if( strlen( str ) != 10 )
         return false;
      else
         if( str[9] == 'X' || ( str[9] >= '0' && str[9] <= '9' ) )//checking the digits are correct
         {
            for( i = 0; i < 9; i++ )
            {
               if( str[i] < '0' && str[i] > '9' )
                  return false;/// is numer in correct digits
            }
         }
 
      if( str[9] == 'X' )
         rc = 10;//if check digits are X than value is 10
      else
         rc = str[9] - '0';//if not the value is value
 
     for(a=0;a<9;a++,b--)
      {
         sum += ( str[a] - '0' ) * b; // make ur sum           
      }
 
      sum += rc;//check digit + sum
 
      if( sum % 11 == 0 ){
         return true;
	  }
      else{
         return false;
	  }
   }
 
   return false;
}
ISBN::ISBN(){
	int t = 0, a = 0, p = 0,i=0;
	for(i=0;i<11;i++){
		ISBNcd[i]='\0';
	}//safe empty satate
	for(t=0;t<7;t++){
      title[t] = '\0';
   }//safe empty satate
 
	 for( a=0;a<6;a++ ){
      area[a] = '\0';
   }//safe empty satate
 
   for(p=0;p<8;p++ ){
      publisher[p] = '\0';
   }////safe empty satate
   registered=false;//safe declarition of null values and false
}//ISBN Constructior ends
bool ISBN::empty() const{
	if(ISBNcd[0]=='\0'){
		return true;
	}
	else{
		return false;
	}
}//ISBN::empty ends
bool operator == (const ISBN& left, const ISBN& right){
	char temp[11], tempx[11];
	left.toStr(temp);
	right.toStr(tempx);
	if(strcmp(temp,tempx)==0){
		return true;
	}
	return false;
}
/*a function compares ISBNcode from two lsbn class reference
if both isbn code is are equal return true else return false*/
 bool ISBN::isRegistered(const ISBNPrefix& list)
{
   int t = 0, a = 0, p = 0;
 
  for(t=0;t<7;t++){
      title[t] = '\0';
   }
 
   for(a=0;a<6;a++){
      area[a] = '\0';
   }
 
 for(p=0;p<8;p++){
      publisher[p] = '\0';
   }//setting all values in to null
 
   for( a=0; a<5; a++ ){
      area[a] = ISBNcd[a];//area=ISBNcd;
      for( p=1; p<8; p++ ){
         publisher[p - 1] = ISBNcd[a + p];
         if( list.isRegistered(atoi( area ), publisher ) ) {
            for( t=1; t<7; t++ ){
               if(a+p+t == 9 ){
                  t = 7;//is digit count goes max(9)
			   }
               else{
                  title[t - 1] = ISBNcd[t + a + p];
			   }
            }
            return true;
         }
      }
      for(p=0;p<8;p++){
         publisher[p] = '\0';//or reset publisher array
      }
   }
return false;
 
}//ISBN::isRegistered const ISBNPrefix & ends
ISBN::ISBN(const char* s2, const ISBNPrefix& list){
	if(isValid(s2)==true){//is valid str?
		strcpy(ISBNcd,s2);
		if(isRegistered(list))
		{
			registered=true;
		}
		else{
			registered=false;
		}
	}//if isVlaid=true
	else{
		*this =ISBN();}
}//ISBN::ISBN(const char*,const ISBNprefix&) ends
 bool ISBN::isRegistered() const{
	 return registered;
 }//end of ISBN::isRegistered()
 void ISBN::toStr(char* str) const{
	 strcpy(str,ISBNcd);//copys ISBN cd to str and return
 }//tostr ends
 void ISBN::toStrWithStyle(char* str) const{
	 if(isValid(str)==true){
		strcpy(str, area);
        strcat(str, "-");
        strcat(str, publisher);
        strcat(str, "-");
        strcat(str, title);
        strcat(str, "-");
        strcat(str, &ISBNcd[9]);//area-publiser-titler to str and return
	 }
	 else{
		 toStr(str);//if not valid than changes to no style mod
	 }
 }//tostrwithstyle ends
 bool ISBN::read(istream& is, const ISBNPrefix list){
	 char temp[11];
	 int i=0;
	 while (i==0){
		 cout<<"ISBN 0 to quit :"<<endl;
		 is.getline(temp,11);
		 if(strcmp(temp,"0")==0)
			{
			return false;
			}
		 if(strlen(temp)>10){
			 return false;
		 }
		 else if(strlen(temp) ==10 && isValid(temp) == true){
			 i++;
			 *this=ISBN(temp, list);
		 }
		 else{
			 cout<<"Invalid check digit. Please try again"<<endl;
		 }	 
	 }
	 return true;
 }//read ends
 void ISBN::display(ostream& os) const{
	 char temp[13];
	 if(registered==true){
		 toStrWithStyle(temp);
	 }
	 else{
		 toStr(temp);
	 }
	 os.width(13);
	 os<<temp<<endl;
 }//display ends

 ostream& operator<<(ostream& is, const ISBN& a){
	 a.display(is);
	 return is;
 }
 /*an function that sends ostream to display*/
