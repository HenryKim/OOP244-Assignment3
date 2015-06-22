/*Hyungi kim
025 741 125
assignment 3
ISBNPrefix.h*/
#include <cstdio>
#include <cstring>
#include <stdio.h>
#include <fstream>
using namespace std;
class ISBNPrefix{
FILE *fp;
private:
ISBNPrefix(const ISBNPrefix& source);
ISBNPrefix& operator=(const ISBNPrefix& source);
public:
ISBNPrefix();
ISBNPrefix(const char* filename);
bool isRegistered(int area) const;
int minNoDigits(int area) const;
bool isRegistered(int area, const char* publisher) const;
 ~ISBNPrefix();
};