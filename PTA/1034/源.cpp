#include<iostream>
using namespace std;
void display(int a, int b)
{
	if (a >= 0) {
		if (a < b) {
			cout << a << '/' << b;
		}
		else {
			cout << a / b << ' ' << a % b << '/' << b;
		}
	}
	else {
		if (abs(a) < b) {
			cout <<'('<< a << '/' << b<<')';
		}
		else {
			cout <<'('<< a / b << ' ' << abs(a) % b << '/' << b<<')';
		}
	}
}
void f1(int a1, int a2, int b1, int b2)
{
	if (a1 >= 0) {
		if (a1 / b1) {
			
		}
	}
}
int main()
{
	int a1, a2, b1, b2;
	int i, j;
	string s1, s2;
	cin >> s1 >> s2;
	a1=atoi(s1.data());
	a2 = atoi(s2.data());
	for (i = 0, j = 0; s1[i] != '/' || s2[j] != '/';) {
		if (s1[i] != '/')++i;
		if (s2[j] != '/')++j;
	}
	b1 = atoi(&s1[i+1]);
	b2 = atoi(&s2[j + 1]);
	display(4, 2);
	return 0;
}