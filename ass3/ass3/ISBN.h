/*Hyungi kim
025 741 125
assignment 3
ISBN.h*/

#include<iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;
#include"ISBNPrefix.h"
class ISBN{
	char ISBNcd[11];
	char area[6];
	char publisher[8];
	char title[7];
	bool registered;
	bool isregistered(const ISBNPrefix& list);
public:
	ISBN();
	ISBN(const char* s2, const ISBNPrefix& list);
	 bool isRegistered() const;
	 bool isRegistered(const ISBNPrefix& list);
	 bool empty() const;
	 void toStr(char* str) const;
	 void toStrWithStyle(char* str) const;
	 bool read(istream& is, const ISBNPrefix list);
	 void display(ostream& os) const;
};
int isValid(const char* str);
bool operator == (const ISBN& left, const ISBN& right);
ostream& operator<<(ostream& os, const ISBN& a);