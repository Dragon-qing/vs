typedef int Type;
class seqlist
{
public:
	~seqlist();			//��������
	seqlist(int max);	//�������Ĺ��캯��
	seqlist();			//���������Ĺ��캯��
	void InsertRear(const Type& item);	//β��
	void Insert(int id, const Type& item);	//�������
	void Erase(int id);				//����ɾ��
	void Clear();					//���
	Type Getdata(int id)const;			//ȡֵ
	int Size()const;						//ȡ���ݸ���
	int Empty()const;					//�п�
	int Full()const;						//����
	seqlist(const seqlist& x);      //���ƹ��캯������㸴�ƣ�
	void Swap(int id1, int id2);
	seqlist& operator=(const seqlist& l);
	const Type& operator[](int i)const;
	void Replace(int id1, const Type& item);
private:
	Type* data;
	int size;
	int max;
};
