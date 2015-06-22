/*Hyungi kim
025 741 125
assignment 3
order.h*/
#include <cstdio>
#include <cstring>
#include <stdio.h>
#include <fstream>
using namespace std;
#include "ISBN.h"
class Order{
	int ord;
	int deli;
	ISBN isbnOrder;
public:
	Order();
	Order(const ISBN& isbn);
	bool has(const ISBN& isbn) const;
	int outstanding() const;
	bool add(istream& is);
	bool add(int n);
	bool receive(istream& is);
	void display(ostream& os) const;
};