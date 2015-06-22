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

class ISBN{
	char ISBNcd[11];
	char area[6];
	char publisher[8];
	char title[7];
	bool registered;
	bool isregistered(const ISBNPrefix&);
public:
	ISBN();
	ISBN(const char* str, const ISBNPrefix&);
	ISBN & operator=(const ISBN&);
	 bool isRegistered() const;
	 bool isRegistered(const ISBNPrefix&);
	 bool empty() const;
	 void toStr(char* str) const;
	 void toStrWithStyle(char* str) const;
	 bool read(istream&, const ISBNPrefix&);
	 void display(ostream&) const;
	 friend bool operator == (const ISBN&, const ISBN&);
};
int isValid(const char* str);
ostream& operator<<(ostream&, const ISBN&);