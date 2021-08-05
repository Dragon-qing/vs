typedef int Type;
class seqlist
{
public:
	~seqlist();			//析构函数
	seqlist(int max);	//带参数的构造函数
	seqlist();			//不带参数的构造函数
	void InsertRear(const Type& item);	//尾插
	void Insert(int id, const Type& item);	//定点插入
	void Erase(int id);				//定点删除
	void Clear();					//清表
	Type Getdata(int id)const;			//取值
	int Size()const;						//取数据个数
	int Empty()const;					//判空
	int Full()const;						//判满
	seqlist(const seqlist& x);      //复制构造函数（深层复制）
	void Swap(int id1, int id2);
	seqlist& operator=(const seqlist& l);
	const Type& operator[](int i)const;
	void Replace(int id1, const Type& item);
private:
	Type* data;
	int size;
	int max;
};
