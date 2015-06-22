/*Hyungi kim
025 741 125
assignment 3
ISBNPrefix.cpp*/

#include<iostream>
#include <cstdio>
#include <cstring>
#include <stdio.h>
#include <fstream>

using namespace std;
#include"ISBNPrefix.h"

ISBNPrefix::ISBNPrefix(){
	fp=NULL;
}
ISBNPrefix::ISBNPrefix(const char* filename){
	if(filename !=NULL){
	fp = fopen ("prefixRanges.txt","r");
	}
	else{
		fp=NULL;
	}
}
ISBNPrefix::ISBNPrefix(const ISBNPrefix& a){
	*this=a;
}
/*private copy constructor prevents copy from nowhere*/

ISBNPrefix& ISBNPrefix::operator=(const ISBNPrefix& source){
	fp=source.fp;
	return *this;
}
/*private copy constructor prevents copy from nowhere*/
bool ISBNPrefix::isRegistered(int area) const{
	int a,ps,pl;
    if(fp!=NULL){
		rewind(fp);
		do{
        fscanf(fp,"%d%d%d",&a,&ps,&pl);
        if (a == area){
			return true;
		}
		}while(a!=area && !feof(fp));
	}
    return false;
}
int ISBNPrefix::minNoDigits(int area) const{
	int minno = 0, a;
        char pmin[8], pmax[8];
        int i = 0;
 
        if (area < 0)
                return 0;
 
        rewind(fp);
        while (!feof(fp))
        {
                fscanf(fp, "%d %s %s", &a, &pmin, &pmax);
                if (area == a)
                {
                        minno = strlen(pmin);
                        break;
                }
        }
        return minno;
}
bool ISBNPrefix::isRegistered(int area, const char* publisher) const{
	int a,minck=0;
    char pu[10],pl[10];
    if(fp !=NULL){
		rewind(fp);		
		do{
        fscanf(fp,"%d%s%s",&a,pu,pl);
        if(a == area){
            if(strlen(publisher)==strlen(pu)){
				if((strcmp(publisher,pu) >=0) && (strcmp(publisher,pl)<=0)){
					return true;
				}
			}
		}//a==area;
	}while (minck==0 && !feof(fp));
	}// if !=NULL
    return false;
}
ISBNPrefix::~ISBNPrefix(){
	if( fp !=NULL){
		fclose(fp);
	}
}