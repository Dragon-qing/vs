#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
	int number;//��ʦ��
	char name[10];//����
	char sex[5];//�Ա�
	char company[20];//��λ
	char add[20];//��ַ
	long long phone;//�绰
	double base_pay;//��������
	double allowance;//����
	double living_allowances;//�����
	double salary;//Ӧ������
	double telephone_bill;//�绰��
	double water_and_electricity;//ˮ���
	double rent;//����
	double income_tax;//����˰
	double sanitation_fee;//������
	double accumulation_fund;//������
	double Aggregate_deductions; //�ϼƿۿ�
	double net_payroll;//ʵ������
}Information;
typedef struct Node {
	Node* prev;
	Node* next;
	Information data;
}Node;
typedef struct {
	Node* head;
	Node* tail;
	int size;
}List;
Node* GetNode(Information a, Node* p, Node* n)
{
	Node* re = (Node*)malloc(sizeof(Node));
	if (re == NULL) { exit(1); }
	else
	{
		re->data = a;
		re->next = n;
		re->prev = p;
	}
	return re;
}
void InitList(List* l) {
	Information n = { 0 };
	l->head = GetNode(n, NULL, NULL);
	l->tail = GetNode(n, NULL, NULL);
	l->head->next = l->tail;
	l->tail->prev = l->head;
	l->size = 0;
}
void delname(List* l, char* n)//ɾ��(ͨ��nameɾ)
{
	Node* p = l->head->next;
	if (p == l->tail)
	{
		printf("����Ϣ��ɾ����\n");
		return;
	}
	else
	{
		while (strcmp(p->data.name, n) && p != l->tail)
		{
			p = p->next;
		}
		if (strcmp(p->data.name, n) == 0)
		{
			p->next->prev = p->prev;
			p->prev->next = p->next;
			l->size--;
			free(p);
			printf("ɾ���ɹ���\n");
		}
		else
		{
			printf("δ�ҵ���\n");
		}
	}
}
void delid(List* l, int number)//ɾ��(ͨ��idɾ)
{
	Node* p = l->head->next;
	if (p == l->tail)
	{
		printf("����Ϣ��ɾ����\n");
		return;
	}
	else
	{
		while (p->data.number != number && p != l->tail)
		{
			p = p->next;
		}
		if (p->data.number == number)
		{
			p->next->prev = p->prev;
			p->prev->next = p->next;
			l->size--;
			free(p);
			printf("ɾ���ɹ���\n");
		}
		else
		{
			printf("δ�ҵ���\n");
		}
	}
}
void browseid(List* l, int number)//�����ͨ��id����
{
	Node* p = l->head->next;
	if (p == l->tail)
	{
		printf("δ��������\n");
		return;
	}
	while (p->data.number != number && p != l->tail)
	{
		p = p->next;
	}
	if (p->data.number == number)
	{
		printf("��ʦ��:%d\n", p->data.number);
		printf("����:%s\n", p->data.name);
		printf("�Ա�:%s\n", p->data.sex);
		printf("��λ����:%s\n", p->data.company);
		printf("��ͥסַ:%s\n", p->data.add);
		printf("��ϵ�绰:%lld\n", p->data.phone);
		printf("��������:%.2f\n", p->data.base_pay);
		printf("����:%.2f\n", p->data.allowance);
		printf("�����:%.2f\n", p->data.living_allowances);
		printf("Ӧ������:%.2f\n", p->data.salary);
		printf("�绰��:%.2f\n", p->data.telephone_bill);
		printf("ˮ���:%.2f\n", p->data.water_and_electricity);
		printf("����:%.2f\n", p->data.rent);
		printf("����˰:%.2f\n", p->data.income_tax);
		printf("������:%.2f\n", p->data.sanitation_fee);
		printf("������:%.2f\n", p->data.accumulation_fund);
		printf("�ϼƿۿ�:%.2f\n", p->data.Aggregate_deductions);
		printf("ʵ������:%.2f\n", p->data.net_payroll);
	}
	else
	{
		printf("δ�ҵ���\n");
	}
}
void browsename(List* l, char* n)//�����ͨ��name����
{
	Node* p = l->head->next;
	if (p == l->tail)
	{
		printf("δ��������\n");
		return;
	}
	while (strcmp(p->data.name, n) && p != l->tail)
	{
		p = p->next;
	}
	if (strcmp(p->data.name, n) == 0)
	{
		printf("��ʦ��:%d\n", p->data.number);
		printf("����:%s\n", p->data.name);
		printf("�Ա�:%s\n", p->data.sex);
		printf("��λ����:%s\n", p->data.company);
		printf("��ͥסַ:%s\n", p->data.add);
		printf("��ϵ�绰:%lld\n", p->data.phone);
		printf("��������:%.2f\n", p->data.base_pay);
		printf("����:%.2f\n", p->data.allowance);
		printf("�����:%.2f\n", p->data.living_allowances);
		printf("Ӧ������:%.2f\n", p->data.salary);
		printf("�绰��:%.2f\n", p->data.telephone_bill);
		printf("ˮ���:%.2f\n", p->data.water_and_electricity);
		printf("����:%.2f\n", p->data.rent);
		printf("����˰:%.2f\n", p->data.income_tax);
		printf("������:%.2f\n", p->data.sanitation_fee);
		printf("������:%.2f\n", p->data.accumulation_fund);
		printf("�ϼƿۿ�:%.2f\n", p->data.Aggregate_deductions);
		printf("ʵ������:%.2f\n", p->data.net_payroll);
	}
	else
	{
		printf("δ�ҵ���\n");
	}
}
void Insert(List* l, Node* itr, Information item) //β��
{
	itr->prev->next = GetNode(item, itr->prev, itr);
	itr->prev = itr->prev->next;
	l->size++;
}
Information data()
{
	Information aa;
	printf("��������ʦ�Ľ�ʦ�ţ�");
	scanf_s("%d", &aa.number);
	printf("�������ʦ����:");
	scanf_s("%s", &aa.name,sizeof(aa.name));
	printf("�������ʦ�Ա�");
	scanf_s("%s", &aa.sex,sizeof(aa.sex));
	printf("�������ʦ��ͥסַ:");
	scanf_s("%s", &aa.add,sizeof(aa.add));
	printf("�������ʦ������λ��");
	scanf_s("%s", &aa.company,sizeof(aa.company));
	printf("�������ʦ�绰���룺");
	scanf_s("%lld", &aa.phone);
	printf("�������ʦ��������");
	scanf_s("%lf", &aa.base_pay);
	printf("�������ʦ����");
	scanf_s("%lf", &aa.allowance);
	printf("�������ʦ�����");
	scanf_s("%lf", &aa.living_allowances);
	printf("�������ʦ�绰��");
	scanf_s("%lf", &aa.telephone_bill);
	printf("�������ʦˮ���");
	scanf_s("%lf", &aa.water_and_electricity);
	printf("�������ʦ����");
	scanf_s("%lf", &aa.rent);
	printf("�������ʦ����˰");
	scanf_s("%lf", &aa.income_tax);
	printf("�������ʦ������");
	scanf_s("%lf", &aa.sanitation_fee);
	printf("�������ʦ������");
	scanf_s("%lf", &aa.accumulation_fund);
	aa.salary = aa.base_pay + aa.allowance + aa.living_allowances;
	aa.Aggregate_deductions = aa.income_tax + aa.rent + aa.sanitation_fee + aa.telephone_bill + aa.water_and_electricity + aa.accumulation_fund;
	aa.net_payroll = aa.salary - aa.Aggregate_deductions;
	return aa;
}
void charu(List* l) {
	Information aa;
	int d = 1;
	while (d != 0)
	{
		aa = data();
		Insert(l, l->tail, aa);
		printf("�Ƿ�������루����0ֹͣ��\n");
		scanf_s("%d", &d);
	}
}
Node* search(List* l, int a)
{
	Node* i = l->head->next;
	while (i->data.number != a && i != l->tail)
	{
		i = i->next;
	}
	if (i == l->tail)
	{
		printf("δ�ҵ���\n");
		return NULL;
	}
	else { return i; }
}
void xiugai(List* l, int a) {
	int aa;
	int i = 1;
	Node* haha = search(l, a);
	while (i != 0)
	{
		printf("��ʦ��%dΪ%s��ʦ\n", a, haha->data.name);
		printf("*************************\n");
		printf("*����1���޸�����        *\n");
		printf("*����2���޸��Ա�        *\n");
		printf("*����3���޸ļ�ͥסַ    *\n");
		printf("*����4���޸Ĺ�����λ    *\n");
		printf("*����5���޸ĵ绰����    *\n");
		printf("*����6���޸Ļ�������    *\n");
		printf("*����7���޸Ľ�ʦ����    *\n");
		printf("*����8���޸Ľ�ʦ�����*\n");
		printf("*����9���޸ĵ绰��      *\n");
		printf("*����10���޸ķ���       *\n");
		printf("*����11���޸�����˰     *\n");
		printf("*����12���޸�������     *\n");
		printf("*����13���޸Ĺ�����     *\n");
		printf("*����14���޸�ˮ���     *\n");
		printf("*************************\n");
		scanf_s("%d", &aa);
		switch (aa) {
		case 1:
			printf("������Ҫ�޸ĵ�����\n");
			scanf_s("%s", haha->data.name,sizeof(haha->data.name));
			break;
		case 2:
			printf("������Ҫ�޸ĵ��Ա�\n");
			scanf_s("%s", haha->data.sex,sizeof(haha->data.sex));
			break;
		case 3:
			printf("������Ҫ�޸ĵļ�ͥסַ\n");
			scanf_s("%s", haha->data.add,sizeof(haha->data.add));
			break;
		case 4:
			printf("������Ҫ�޸ĵĹ�����λ\n");
			scanf_s("%s", haha->data.company,sizeof(haha->data.company));
			break;
		case 5:
			printf("������Ҫ�޸ĵĵ绰����\n");
			scanf_s("%lld", &haha->data.phone);
			break;
		case 6:
			printf("������Ҫ�޸ĵĻ�������\n");
			scanf_s("%lf", &haha->data.base_pay);
			break;
		case 7:
			printf("������Ҫ�޸ĵĽ�ʦ����\n");
			scanf_s("%lf", &haha->data.allowance);
			break;
		case 8:
			printf("������Ҫ�޸ĵĽ�ʦ�����\n");
			scanf_s("%lf", &haha->data.living_allowances);
			break;
		case 9:
			printf("������Ҫ�޸ĵĵ绰��\n");
			scanf_s("%lf", &haha->data.rent);
			break;
		case 10:
			printf("������Ҫ�޸ĵķ���\n");
			scanf_s("%lf", &haha->data.income_tax);
			break;
		case 11:
			printf("������Ҫ�޸ĵ�����˰\n");
			scanf_s("%lf", &haha->data.income_tax);
		case 12:
			printf("������Ҫ�޸ĵ�������\n");
			scanf_s("%lf", &haha->data.sanitation_fee);
			break;
		case 13:
			printf("������Ҫ�޸ĵĹ�����\n");
			scanf_s("%lf", &haha->data.accumulation_fund);
			break;
		case 14:
			printf("������Ҫ�޸ĵ�ˮ���\n");
			scanf_s("%lf", &haha->data.water_and_electricity);
			break;
		}
		haha->data.salary = haha->data.base_pay + haha->data.allowance + haha->data.living_allowances;
		haha->data.Aggregate_deductions = haha->data.income_tax + haha->data.rent + haha->data.sanitation_fee + haha->data.telephone_bill + haha->data.water_and_electricity + haha->data.accumulation_fund;
		haha->data.net_payroll = haha->data.salary - haha->data.Aggregate_deductions;
		printf("�Ƿ�����޸Ĵ��˵���Ϣ��0�˳���\n");
		scanf_s("%d", &i);
		system("CLS");
	}
}
int menue(List* l)
{
	int i;
	printf("****************\n");
	printf("*��ǰ��%d����ʦ *\n", l->size);
	printf("****************\n");
	printf("*1.�����ʦ��Ϣ*\n");
	printf("*2.�޸Ľ�ʦ��Ϣ*\n");
	printf("*3.ɾ����ʦ��Ϣ*\n");
	printf("*4.��ѯ��ʦ��Ϣ*\n");
	printf("*5.��ʦ��ϢĿ¼*\n");
	printf("*6.�˳�        *\n");
	printf("****************\n");
	scanf_s("%d", &i);
	system("CLS");
	return i;
}
int way()
{
	int i;
a:
	system("CLS");
	printf("1.����ʦ��\n");
	printf("2.������\n");
	scanf_s("%d", &i);
	if (i != 1 && i != 2)goto a;
	return i;
}
void OutputList(List* l)
{
	Node* first = l->head->next;
	Node* last = l->tail;
	printf("��ʦ�ţ�\t");
	printf("����:\n");
	if (first == last)
	{
		printf("�޽�ʦ��Ϣ�ڿ⣡");
	}
	while (first != last)
	{
		printf("%d\t", first->data.number);
		printf("        %s\n", first->data.name);
		first = first->next;
	}
}
void select(List* l)
{
	int x, i;
	x = menue(l);
	switch (x)
	{
	case 1:
		charu(l);
		break;
	case 2:
		system("CLS");
		printf("������Ҫ�޸Ľ�ʦ�ı�ţ�");
		scanf_s("%d", &i);
		xiugai(l, i);
		break;
	case 3:
		i = way();
		if (i == 1)
		{
			system("CLS");
			printf("�����ʦ�ţ�");
			scanf_s("%d", &i);
			delid(l, i);
		}
		else
		{
			char name[10];
			system("CLS");
			printf("�����ʦ������");
			scanf_s("%s", name,sizeof(name));
			delname(l, name);
		}
		break;
	case 4:
		i = way();
		if (i == 1)
		{
			system("CLS");
			printf("�����ʦ�ţ�");
			scanf_s("%d", &i);
			browseid(l, i);
		}
		else
		{
			char name[10];
			system("CLS");
			printf("�����ʦ������");
			scanf_s("%s", name, sizeof(name));
			browsename(l, name);
		}
		break;
	case 5:
		OutputList(l);
		break;
	case 6:
		return;
		break;
	default: printf("�������\n");
		break;
	}
}
void read(List* l)
{
	FILE* a;
	fopen_s(&a,"C:\\Users\\dell\\Desktop\\text.txt", "r");
	if (a != NULL)
	{
		while (!feof(a))
		{
			Information n;
			fscanf_s(a, "%d", &n.number);
			if (feof(a))break;
			fscanf_s(a, "%s", &n.name,sizeof(n.name));
			fscanf_s(a, "%s", &n.sex,sizeof(n.sex));
			fscanf_s(a, "%s", &n.add,sizeof(n.add));
			fscanf_s(a, "%s", &n.company,sizeof(n.company));
			fscanf_s(a, "%lld", &n.phone);
			fscanf_s(a, "%lf", &n.base_pay);
			fscanf_s(a, "%lf", &n.allowance);
			fscanf_s(a, "%lf", &n.living_allowances);
			fscanf_s(a, "%lf", &n.telephone_bill);
			fscanf_s(a, "%lf", &n.water_and_electricity);
			fscanf_s(a, "%lf", &n.rent);
			fscanf_s(a, "%lf", &n.income_tax);
			fscanf_s(a, "%lf", &n.sanitation_fee);
			fscanf_s(a, "%lf", &n.accumulation_fund);
			fscanf_s(a, "%lf", &n.salary);
			fscanf_s(a, "%lf", &n.Aggregate_deductions);
			fscanf_s(a, "%lf", &n.net_payroll);
			Insert(l, l->tail, n);
		}
		fclose(a);
	}
	else { printf("�����ݿɶ�ȡ��\n"); }
}
void swap(Information* a, Information* b)
{
	Information c = *a;
	*a = *b;
	*b = c;
}
void sort(List* l)
{
	int cnt = 0;
	Node* p = l->head->next->next;
	while (cnt < l->size - 1)
	{
		p = l->head->next->next;
		for (p; p != l->tail; p = p->next)
		{
			if (p->data.number < p->prev->data.number)
				swap(&p->data, &p->prev->data);
		}
		cnt++;
	}
}
void write(List* l)
{
	int i = 0;
	printf("�Ƿ񱣴棿(1ȷ��)");
	scanf_s("%d", &i);
	if (i == 1)
	{
		FILE* b;
		fopen_s(&b,"C:\\Users\\dell\\Desktop\\text.txt", "w+");
		Node* p = l->head->next;
		while (p != l->tail)
		{
			fprintf(b, "%d ", p->data.number);
			fprintf(b, "%s ", p->data.name);
			fprintf(b, "%s ", p->data.sex);
			fprintf(b, "%s ", p->data.add);
			fprintf(b, "%s ", p->data.company);
			fprintf(b, "%lld ", p->data.phone);
			fprintf(b, "%lf ", p->data.base_pay);
			fprintf(b, "%lf ", p->data.allowance);
			fprintf(b, "%lf ", p->data.living_allowances);
			fprintf(b, "%lf ", p->data.telephone_bill);
			fprintf(b, "%lf ", p->data.water_and_electricity);
			fprintf(b, "%lf ", p->data.rent);
			fprintf(b, "%lf ", p->data.income_tax);
			fprintf(b, "%lf ", p->data.sanitation_fee);
			fprintf(b, "%lf ", p->data.accumulation_fund);
			fprintf(b, "%lf ", p->data.salary);
			fprintf(b, "%lf ", p->data.Aggregate_deductions);
			fprintf(b, "%lf\n", p->data.net_payroll);
			p = p->next;
		}
		fclose(b);
	}
	else { return; }
}
void back_to_menue()
{
	printf("\n**********************\n");
	printf("�Ƿ񷵻ز˵���0�˳���\n");
	printf("**********************\n");

}
int main()
{
	int o = 1;
	List l;
	InitList(&l);
	read(&l);
	while (o)
	{
		select(&l);
		back_to_menue();
		scanf_s("%d", &o);
		system("CLS");
	}
	sort(&l);
	write(&l);
	return 0;
}
