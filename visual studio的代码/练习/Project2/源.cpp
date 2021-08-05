#include<iostream>
using namespace std;
class String
{
public:
    String(const char* str = NULL);    //通用构造函数
    String(const String& str);        //拷贝构造函数
    ~String();                        //析构函数

    String operator+(const String& str) const;    //重载+
    String& operator=(const String& str);        //重载=
    String& operator+=(const String& str);        //重载+=
    bool operator==(const String& str) const;    //重载==
    char& operator[](int n) const;                //重载[]

    size_t size() const;        //获取长度
    const char* c_str() const;    //获取C字符串

    friend istream& operator>>(istream& is, String& str);//输入
    friend ostream& operator<<(ostream& os, const String& str);//输出

private:
    char* itr;        //字符串
    size_t length;    //长度
};
/*下面逐个进行成员函数的实现。
同样构造函数适用一个字符串数组进行String的初始化，默认的字符串数组为空。这里的函数定义中不需要再定义参数的默认值，因为在类中已经声明过了。
另外，适用C函数strlen的时候需要注意字符串参数是否为空，对空指针调用strlen会引发内存错误。*/
String::String(const char* str)//通用构造函数
{
    if (!str)
    {
        length = 0;
        itr = new char[1];
        *itr = '\0';
    }
    else
    {
        length = strlen(str);
        itr = new char[length + 1];
        strcpy(itr, str);
    }
}
//拷贝构造函数需要进行深复制。
String::String(const String& str)//拷贝构造函数
{
    length = str.length;
    itr = new char[length + 1];
    strcpy(itr, str.itr);
}
//析构函数需要进行内存的释放及长度的归零。
String::~String()//析构函数
{
    delete[]itr;
    length = 0;
}
//重载字符串连接运算，这个运算会返回一个新的字符串。
String String::operator+(const String& str) const//重载+
{
    String newString;
    newString.length = length + str.size();
    newString.itr = new char[newString.length + 1];
    strcpy(newString.itr, itr);
    strcat(newString.itr, str.itr);
    return newString;
}
//重载字符串赋值运算，这个运算会改变原有字符串的值，为了避免内存泄露，这里释放了原先申请的内存再重新申请一块适当大小的内存存放新的字符串。
String& String::operator=(const String& str)//重载=
{
    if (this == &str)    return *this;

    delete[]itr;
    length = str.length;
    itr = new char[length + 1];
    strcpy(itr, str.c_str());
    return *this;
}
//重载字符串+=操作，总体上是以上两个操作的结合。
String& String::operator+=(const String& str)//重载+=
{
    length += str.length;
    char* newData = new char[length + 1];
    strcpy(newData, itr);
    strcat(newData, str.itr);
    delete[]itr;
    itr = newData;
    return *this;
}
//重载相等关系运算，这里定义为内联函数加快运行速度。
inline bool String::operator==(const String& str) const//重载==
{
    if (length != str.length)    return false;
    return strcmp(itr, str.itr) ? false : true;
}
//重载字符串索引运算符，进行了一个简单的错误处理，当长度太大时自动读取最后一个字符。
inline char& String::operator[](int n) const//重载[]
{
    if (n >= length) return itr[length - 1]; //错误处理
    else return itr[n];
}
//重载两个读取私有成员的函数，分别读取长度和C字符串。
inline size_t String::size() const//获取长度
{
    return length;
}
//重载输入运算符，先申请一块足够大的内存用来存放输入字符串，再进行新字符串的生成。这是一个比较简单朴素的实现，网上很多直接is>>str.data的方法是错误的，因为不能确定str.data的大小和即将输入的字符串的大小关系。
istream& operator>>(istream& is, String& str)//输入
{
    char tem[1000];  //简单的申请一块内存
    is >> tem;
    str.length = strlen(tem);
    str.itr = new char[str.length + 1];
    strcpy(str.itr, tem);
    return is;
}
//重载输出运算符，只需简单地输出字符串的内容即可。注意为了实现形如cout<<a<<b的连续输出，这里需要返回输出流。上面的输入也是类似。
ostream& operator<<(ostream& os, const String& str)//输出
{
    os << str.itr;
    return os;
}
inline const char* String::c_str() const//获取C字符串
{
    return itr;
}
int main()
{
    String s;
    cin >> s;
    cout << s << ": " << s.size() << endl;

    char a[] = "Hello", b[] = "World!";
    String s1(a), s2(b);
    cout << s1 << " + " << s2 << " = " << s1 + s2 << endl;

    String s3 = s1 + s2;
    if (s1 == s3)    cout << "First: s1 == s3" << endl;
    s1 += s2;
    if (s1 == s3)    cout << "Second: s1 == s3" << endl;

    /*程序输入输出为：
    123456789: 9
    Hello + World! = HelloWorld!
    Second: s1 == s3
    Press any key to continue . . .
    */
}