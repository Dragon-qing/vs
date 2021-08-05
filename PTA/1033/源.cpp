#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
	string s1,s2;
	map<char, int>m;
	getline(cin, s1);
	getline(cin, s2);
	int flag = 0;
	for (int i = 0; i < (int)s1.size(); ++i) {
		if (s1[i] >= 'A' && s1[i] <= 'Z') {
			m[s1[i]] = 1;
			m[s1[i] + ('a' - 'A')] = 1;
		}
		else {
			m[s1[i]] = 1;
			if (( s1[i] == '+')&&flag==0) {
				for (char c = 'A'; c <= 'Z'; ++c) {
					m[c] = 1;
				}
				flag = 1;
			}
		}
	}
	for (string::iterator p=s2.begin(); p < s2.end(); ) {
		if (m[*p]) {
			p=s2.erase(p);
			continue;
		}
		++p;
	}
	if (s2.empty()) {
		cout << '\n';
	}
	else {
		cout << s2;
	}
	return 0;
}