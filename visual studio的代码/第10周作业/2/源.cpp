#include<iostream>
using namespace std;
// base cd class
class Cd {
private:
	string performers;
	string label;
	int selections;                  //曲目数
	double playtime;                //播放时间
public:
	Cd(const string s1, const string s2, int n, double x);
	Cd();
	~Cd() {};
	virtual void Report() const;         // 显示CD所有数据
};
Cd::Cd(const string s1, const string s2, int n, double x):performers(s1),label(s2),selections(n),playtime(x){}
Cd::Cd() : Cd("", "", 0, 0){}
void Cd::Report() const
{
	cout << "performers:" << performers << endl;
	cout << "label:" << label << endl;
	cout << "selections:" << selections << endl;
	cout << "playtime:" << playtime << endl;
}
class Classic :public Cd
{
	string primarywork;
public:
	Classic(const string s1, const string s2, const string s3, int n, double x) :Cd(s1, s2, n, x)
	{
		primarywork = s3;
	}
	Classic():Classic("", "",  "", 0, 0) {}
	~Classic() {};
	void Report() const;
};
void Classic::Report() const
{
	Cd::Report();
	cout << "primarywork:" << primarywork << endl;
}
void Bravo(const Cd& disk);
int main()
{
    Cd c1("Beatles", "Capitol", 14, 35.5);

    Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
        "Alfred Brendel", "Philips", 2, 57.17);

    Cd* pcd = &c1;
    cout << "=======Using object directly:============\n";
    cout << "=======c1.Report()============\n";
    c1.Report();
    cout << "=======c2.Report()============\n";
    c2.Report();
    cout << "============Using type cd * pointer to objects:============\n";
    cout << "=======&cd1============\n";
    pcd->Report();
    pcd = &c2;
    cout << "=======&cd2============\n";
    pcd->Report();
    cout << "============Calling a function with a Cd reference argument:\n============";
    cout << "=======Calling Bravo(c1)============\n";
    Bravo(c1);
    cout << "=======Calling Bravo(c2)============\n";
    Bravo(c2);

    cout << "=======Testing assignment: =======\n";
    Classic copy;
    copy = c2;
    copy.Report();

    return 0;
}

void Bravo(const Cd& disk)
{
    disk.Report();
}


