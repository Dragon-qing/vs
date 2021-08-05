#include<iostream>
using namespace std;
String operator+ (const char* c, const String& s) {
	String w;
	int len = strlen(c)+s.size;
	delete[]w.str;
	w.str = new char[len+1];
	if (w.str == NULL) s.error("overflow");
	strcpy(w.str,c);
	strcat(w.str,s.str);
	w.size = len;
	return w;
}
