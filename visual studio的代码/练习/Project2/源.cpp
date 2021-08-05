#include<iostream>
using namespace std;
class String
{
public:
    String(const char* str = NULL);    //ͨ�ù��캯��
    String(const String& str);        //�������캯��
    ~String();                        //��������

    String operator+(const String& str) const;    //����+
    String& operator=(const String& str);        //����=
    String& operator+=(const String& str);        //����+=
    bool operator==(const String& str) const;    //����==
    char& operator[](int n) const;                //����[]

    size_t size() const;        //��ȡ����
    const char* c_str() const;    //��ȡC�ַ���

    friend istream& operator>>(istream& is, String& str);//����
    friend ostream& operator<<(ostream& os, const String& str);//���

private:
    char* itr;        //�ַ���
    size_t length;    //����
};
/*����������г�Ա������ʵ�֡�
ͬ�����캯������һ���ַ����������String�ĳ�ʼ����Ĭ�ϵ��ַ�������Ϊ�ա�����ĺ��������в���Ҫ�ٶ��������Ĭ��ֵ����Ϊ�������Ѿ��������ˡ�
���⣬����C����strlen��ʱ����Ҫע���ַ��������Ƿ�Ϊ�գ��Կ�ָ�����strlen�������ڴ����*/
String::String(const char* str)//ͨ�ù��캯��
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
//�������캯����Ҫ������ơ�
String::String(const String& str)//�������캯��
{
    length = str.length;
    itr = new char[length + 1];
    strcpy(itr, str.itr);
}
//����������Ҫ�����ڴ���ͷż����ȵĹ��㡣
String::~String()//��������
{
    delete[]itr;
    length = 0;
}
//�����ַ����������㣬�������᷵��һ���µ��ַ�����
String String::operator+(const String& str) const//����+
{
    String newString;
    newString.length = length + str.size();
    newString.itr = new char[newString.length + 1];
    strcpy(newString.itr, itr);
    strcat(newString.itr, str.itr);
    return newString;
}
//�����ַ�����ֵ���㣬��������ı�ԭ���ַ�����ֵ��Ϊ�˱����ڴ�й¶�������ͷ���ԭ��������ڴ�����������һ���ʵ���С���ڴ����µ��ַ�����
String& String::operator=(const String& str)//����=
{
    if (this == &str)    return *this;

    delete[]itr;
    length = str.length;
    itr = new char[length + 1];
    strcpy(itr, str.c_str());
    return *this;
}
//�����ַ���+=���������������������������Ľ�ϡ�
String& String::operator+=(const String& str)//����+=
{
    length += str.length;
    char* newData = new char[length + 1];
    strcpy(newData, itr);
    strcat(newData, str.itr);
    delete[]itr;
    itr = newData;
    return *this;
}
//������ȹ�ϵ���㣬���ﶨ��Ϊ���������ӿ������ٶȡ�
inline bool String::operator==(const String& str) const//����==
{
    if (length != str.length)    return false;
    return strcmp(itr, str.itr) ? false : true;
}
//�����ַ��������������������һ���򵥵Ĵ�����������̫��ʱ�Զ���ȡ���һ���ַ���
inline char& String::operator[](int n) const//����[]
{
    if (n >= length) return itr[length - 1]; //������
    else return itr[n];
}
//����������ȡ˽�г�Ա�ĺ������ֱ��ȡ���Ⱥ�C�ַ�����
inline size_t String::size() const//��ȡ����
{
    return length;
}
//���������������������һ���㹻����ڴ�������������ַ������ٽ������ַ��������ɡ�����һ���Ƚϼ����ص�ʵ�֣����Ϻܶ�ֱ��is>>str.data�ķ����Ǵ���ģ���Ϊ����ȷ��str.data�Ĵ�С�ͼ���������ַ����Ĵ�С��ϵ��
istream& operator>>(istream& is, String& str)//����
{
    char tem[1000];  //�򵥵�����һ���ڴ�
    is >> tem;
    str.length = strlen(tem);
    str.itr = new char[str.length + 1];
    strcpy(str.itr, tem);
    return is;
}
//��������������ֻ��򵥵�����ַ��������ݼ��ɡ�ע��Ϊ��ʵ������cout<<a<<b�����������������Ҫ��������������������Ҳ�����ơ�
ostream& operator<<(ostream& os, const String& str)//���
{
    os << str.itr;
    return os;
}
inline const char* String::c_str() const//��ȡC�ַ���
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

    /*�����������Ϊ��
    123456789: 9
    Hello + World! = HelloWorld!
    Second: s1 == s3
    Press any key to continue . . .
    */
}