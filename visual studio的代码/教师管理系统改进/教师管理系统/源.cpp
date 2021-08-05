#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
	int number;//教师号
	char name[10];//姓名
	char sex[5];//性别
	char company[20];//单位
	char add[20];//地址
	long long phone;//电话
	double base_pay;//基本工资
	double allowance;//津贴
	double living_allowances;//生活补贴
	double salary;//应发工资
	double telephone_bill;//电话费
	double water_and_electricity;//水电费
	double rent;//房租
	double income_tax;//所得税
	double sanitation_fee;//卫生费
	double accumulation_fund;//公积金
	double Aggregate_deductions; //合计扣款
	double net_payroll;//实发工资
	int code;//加密次数
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
Node* GetNode(Information a, Node* p, Node* n);//获取节点
void InitList(List* l);//建空表
void delname(List* l, char* n);//通过姓名删除
void delid(List* l, int number);//通过教师号删除
void codetimes(int x);//获取加密情况
void browseid(List* l, int number);//通过教师号搜索
void browsename(List* l, char* n);//通过姓名搜索
void Insert(List* l, Node* itr, Information item);//插入
Node* search(List* l, int a);//搜索节点
Information data();//输入信息
Node* searchname(List* l, char* a);//通过姓名搜索节点
void xiugai(List* l, int a);//修改
void jiamizhiding1(List* l);//加密
void jiamizhiding2(List* l);//加密
void jiami3(List* l);//加密
int menue(List* l);//菜单
int way();//方式
void jiami(List* l);//加密菜单
void OutputList(List* l);//输出信息目录
void jiemizhiding1(List* l);//解密
void jiemizhiding2(List* l);//解密
void jiemi3(List* l);//解密
void select(List* l);//选择
void read(List* l);//读取文本
void swap(Information* a, Information* b);//交换
void sort(List* l);//排序
void write(List* l);//保存函数
void back_to_menue();//返回菜单
void charu(List* l);//插入老师信息
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
		scanf("%d", &o);
		system("CLS");
	}
	sort(&l);
	write(&l);
	return 0;
}
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
void InitList(List* l) 
{
	Information n = { 0 };
	l->head = GetNode(n, NULL, NULL);
	l->tail = GetNode(n, NULL, NULL);
	l->head->next = l->tail;
	l->tail->prev = l->head;
	l->size = 0;
}
void delname(List* l, char* n)//删除(通过name删)
{
	Node* p = l->head->next;
	if (p == l->tail)
	{
		printf("无信息可删除！\n");
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
			printf("删除成功！\n");
		}
		else
		{
			printf("未找到！\n");
		}
	}
}
void delid(List* l, int number)//删除(通过id删)
{
	Node* p = l->head->next;
	if (p == l->tail)
	{
		printf("无信息可删除！\n");
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
			printf("删除成功！\n");
		}
		else
		{
			printf("未找到！\n");
		}
	}
}
void codetimes(int x)
{
	if (x == 0) { printf("未加密\n"); }
	else if (x < 0) { printf("解密过%d次\n", -x); }
	else { printf("加密过%d次\n", x); }
}
void browseid(List* l, int number)//浏览（通过id看）
{
	Node* p = l->head->next;
	if (p == l->tail)
	{
		printf("未搜索到！\n");
		return;
	}
	while (p->data.number != number && p != l->tail)
	{
		p = p->next;
	}
	if (p->data.number == number)
	{
		printf("教师号:%d\n", p->data.number);
		printf("姓名:%s\n", p->data.name);
		printf("性别:%s\n", p->data.sex);
		printf("单位名称:%s\n", p->data.company);
		printf("家庭住址:%s\n", p->data.add);
		printf("联系电话:%lld\n", p->data.phone);
		printf("基本工资:%.2f\n", p->data.base_pay);
		printf("津贴:%.2f\n", p->data.allowance);
		printf("生活补贴:%.2f\n", p->data.living_allowances);
		printf("应发工资:%.2f\n", p->data.salary);
		printf("电话费:%.2f\n", p->data.telephone_bill);
		printf("水电费:%.2f\n", p->data.water_and_electricity);
		printf("房租:%.2f\n", p->data.rent);
		printf("所得税:%.2f\n", p->data.income_tax);
		printf("卫生费:%.2f\n", p->data.sanitation_fee);
		printf("公积金:%.2f\n", p->data.accumulation_fund);
		printf("合计扣款:%.2f\n", p->data.Aggregate_deductions);
		printf("实发工资:%.2f\n", p->data.net_payroll);
		codetimes(p->data.code);
	}
	else
	{
		printf("未找到！\n");
	}
}
void browsename(List* l, char* n)//浏览（通过name看）
{
	Node* p = l->head->next;
	if (p == l->tail)
	{
		printf("未搜索到！\n");
		return;
	}
	while (strcmp(p->data.name, n) && p != l->tail)
	{
		p = p->next;
	}
	if (strcmp(p->data.name, n) == 0)
	{
		printf("教师号:%d\n", p->data.number);
		printf("姓名:%s\n", p->data.name);
		printf("性别:%s\n", p->data.sex);
		printf("单位名称:%s\n", p->data.company);
		printf("家庭住址:%s\n", p->data.add);
		printf("联系电话:%lld\n", p->data.phone);
		printf("基本工资:%.2f\n", p->data.base_pay);
		printf("津贴:%.2f\n", p->data.allowance);
		printf("生活补贴:%.2f\n", p->data.living_allowances);
		printf("应发工资:%.2f\n", p->data.salary);
		printf("电话费:%.2f\n", p->data.telephone_bill);
		printf("水电费:%.2f\n", p->data.water_and_electricity);
		printf("房租:%.2f\n", p->data.rent);
		printf("所得税:%.2f\n", p->data.income_tax);
		printf("卫生费:%.2f\n", p->data.sanitation_fee);
		printf("公积金:%.2f\n", p->data.accumulation_fund);
		printf("合计扣款:%.2f\n", p->data.Aggregate_deductions);
		printf("实发工资:%.2f\n", p->data.net_payroll);
		codetimes(p->data.code);
	}
	else
	{
		printf("未找到！\n");
	}
}
void Insert(List* l, Node* itr, Information item) //尾插
{
	itr->prev->next = GetNode(item, itr->prev, itr);
	itr->prev = itr->prev->next;
	l->size++;
}
Information data()
{
	Information aa;
	printf("请输入老师的教师号：");
	scanf("%d", &aa.number);
	printf("请输入教师姓名:");
	scanf("%s", &aa.name);
	printf("请输入教师性别：");
	scanf("%s", &aa.sex);
	printf("请输入教师家庭住址:");
	scanf("%s", &aa.add);
	printf("请输入教师工作单位：");
	scanf("%s", &aa.company);
	printf("请输入教师电话号码：");
	scanf("%lld", &aa.phone);
	printf("请输入教师基本工资");
	scanf("%lf", &aa.base_pay);
	printf("请输入教师津贴");
	scanf("%lf", &aa.allowance);
	printf("请输入教师生活补贴");
	scanf("%lf", &aa.living_allowances);
	printf("请输入教师电话费");
	scanf("%lf", &aa.telephone_bill);
	printf("请输入教师水电费");
	scanf("%lf", &aa.water_and_electricity);
	printf("请输入教师房租");
	scanf("%lf", &aa.rent);
	printf("请输入教师所得税");
	scanf("%lf", &aa.income_tax);
	printf("请输入教师卫生费");
	scanf("%lf", &aa.sanitation_fee);
	printf("请输入教师公积金");
	scanf("%lf", &aa.accumulation_fund);
	aa.salary = aa.base_pay + aa.allowance + aa.living_allowances;
	aa.Aggregate_deductions = aa.income_tax + aa.rent + aa.sanitation_fee + aa.telephone_bill + aa.water_and_electricity + aa.accumulation_fund;
	aa.net_payroll = aa.salary - aa.Aggregate_deductions;
	aa.code = 0;
	return aa;
}
Node* searchname(List* l, char* a) {
	Node* i = l->head->next;
	while (strcmp(i->data.name, a) != 0 && i != l->tail)
	{
		i = i->next;
	}
	if (i == l->tail)
	{
		printf("未找到！\n");
		return NULL;
	}
	else { return i; }
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
		printf("未找到！\n");
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
		printf("教师号%d为%s老师\n", a, haha->data.name);
		printf("*************************\n");
		printf("*输入1则修改姓名        *\n");
		printf("*输入2则修改性别        *\n");
		printf("*输入3则修改家庭住址    *\n");
		printf("*输入4则修改工作单位    *\n");
		printf("*输入5则修改电话号码    *\n");
		printf("*输入6则修改基本工资    *\n");
		printf("*输入7则修改教师津贴    *\n");
		printf("*输入8则修改教师生活补贴*\n");
		printf("*输入9则修改电话费      *\n");
		printf("*输入10则修改房租       *\n");
		printf("*输入11则修改所得税     *\n");
		printf("*输入12则修改卫生费     *\n");
		printf("*输入13则修改公积金     *\n");
		printf("*输入14则修改水电费     *\n");
		printf("*************************\n");
		scanf("%d", &aa);
		switch (aa) {
		case 1:
			printf("请输入要修改的姓名\n");
			scanf("%s", haha->data.name);
			break;
		case 2:
			printf("请输入要修改的性别\n");
			scanf("%s", haha->data.sex);
			break;
		case 3:
			printf("请输入要修改的家庭住址\n");
			scanf("%s", haha->data.add);
			break;
		case 4:
			printf("请输入要修改的工作单位\n");
			scanf("%s", haha->data.company);
			break;
		case 5:
			printf("请输入要修改的电话号码\n");
			scanf("%lld", &haha->data.phone);
			break;
		case 6:
			printf("请输入要修改的基本工资\n");
			scanf("%lf", &haha->data.base_pay);
			break;
		case 7:
			printf("请输入要修改的教师津贴\n");
			scanf("%lf", &haha->data.allowance);
			break;
		case 8:
			printf("请输入要修改的教师生活补贴\n");
			scanf("%lf", &haha->data.living_allowances);
			break;
		case 9:
			printf("请输入要修改的电话费\n");
			scanf("%lf", &haha->data.rent);
			break;
		case 10:
			printf("请输入要修改的房租\n");
			scanf("%lf", &haha->data.income_tax);
			break;
		case 11:
			printf("请输入要修改的所得税\n");
			scanf("%lf", &haha->data.income_tax);
		case 12:
			printf("请输入要修改的卫生费\n");
			scanf("%lf", &haha->data.sanitation_fee);
			break;
		case 13:
			printf("请输入要修改的公积金\n");
			scanf("%lf", &haha->data.accumulation_fund);
			break;
		case 14:
			printf("请输入要修改的水电费\n");
			scanf("%lf", &haha->data.water_and_electricity);
			break;
		}
		haha->data.salary = haha->data.base_pay + haha->data.allowance + haha->data.living_allowances;
		haha->data.Aggregate_deductions = haha->data.income_tax + haha->data.rent + haha->data.sanitation_fee + haha->data.telephone_bill + haha->data.water_and_electricity + haha->data.accumulation_fund;
		haha->data.net_payroll = haha->data.salary - haha->data.Aggregate_deductions;
		printf("是否继续修改此人的信息（0退出）\n");
		scanf("%d", &i);
		system("CLS");
	}
}
void jiamizhiding1(List* l) {
	int a, b, i;
	Node* re;
a:
	printf("请输入需要加密信息的老师的教师号：");
	scanf("%d", &a);
	re = search(l, a);
	if (re == NULL)
	{
		printf("是否继续加密？（输入0则结束加密）");
		scanf("%d", &b);
		if (b != 0)
		{
			goto a;
		}
	}
	else
	{
		for (i = 0; i < strlen(re->data.name); i++)
		{
			re->data.name[i] += 1;
		}
		for (i = 0; i < strlen(re->data.add); i++)
		{
			re->data.add[i] += 1;
		}
		for (i = 0; i < strlen(re->data.company); i++)
		{
			re->data.company[i] += 1;
		}
		re->data.phone -= 2000;
		re->data.base_pay -= 100;
		re->data.allowance -= 10;
		re->data.living_allowances += 5;
		re->data.salary *= 2;
		re->data.telephone_bill *= 2;
		re->data.water_and_electricity += 12.1;
		re->data.rent -= 12;
		re->data.income_tax += 52;
		re->data.sanitation_fee += 54;
		re->data.accumulation_fund += 65;
		re->data.Aggregate_deductions += 12.54;
		re->data.net_payroll += 154;
		re->data.code += 1;
	}
}
void jiamizhiding2(List* l) {
	int b, i;
	char a[10];
	Node* re;
a:
	printf("请输入需要加密信息的老师的姓名：");
	scanf("%s", a);
	re = searchname(l, a);
	if (re == NULL) {
		printf("是否继续加密？（输入0则结束加密）");
		scanf("%d", &b);
		if (b != 0) {
			goto a;
		}
	}
	else {
		for (i = 0; i < strlen(re->data.name); i++) {
			re->data.name[i] += 1;
		}
		for (i = 0; i < strlen(re->data.add); i++) {
			re->data.add[i] += 1;
		}
		for (i = 0; i < strlen(re->data.company); i++) {
			re->data.company[i] += 1;
		}
		re->data.phone -= 2000;
		re->data.base_pay -= 100;
		re->data.allowance -= 10;
		re->data.living_allowances += 5;
		re->data.salary *= 2;
		re->data.telephone_bill *= 2;
		re->data.water_and_electricity += 12.1;
		re->data.rent -= 12;
		re->data.income_tax += 52;
		re->data.sanitation_fee += 54;
		re->data.accumulation_fund += 65;
		re->data.Aggregate_deductions += 12.54;
		re->data.net_payroll += 154;
		re->data.code += 1;
	}
}
void jiami3(List* l) {
	int i;
	Node* first = l->head->next;
	Node* last = l->tail;
	for (; first != last; first = first->next) {
		for (i = 0; i < strlen(first->data.name); i++) {
			first->data.name[i] += 1;
		}
		for (i = 0; i < strlen(first->data.add); i++) {
			first->data.add[i] += 1;
		}
		for (i = 0; i < strlen(first->data.company); i++) {
			first->data.company[i] += 1;
		}
		first->data.phone -= 2000;
		first->data.base_pay -= 100;
		first->data.allowance -= 10;
		first->data.living_allowances += 5;
		first->data.salary *= 2;
		first->data.telephone_bill *= 2;
		first->data.water_and_electricity += 12.1;
		first->data.rent -= 12;
		first->data.income_tax += 52;
		first->data.sanitation_fee += 54;
		first->data.accumulation_fund += 65;
		first->data.Aggregate_deductions += 12.54;
		first->data.net_payroll += 154;
		first->data.code += 1;
	}
}
int menue(List* l)
{
	int i;
	printf("****************\n");
	printf("*当前有%d名老师 *\n", l->size);
	printf("****************\n");
	printf("*1.输入教师信息*\n");
	printf("*2.修改教师信息*\n");
	printf("*3.删除教师信息*\n");
	printf("*4.查询教师信息*\n");
	printf("*5.教师信息目录*\n");
	printf("*6.加密        *\n");
	printf("*7.解密        *\n");
	printf("*0.退出        *\n");
	printf("****************\n");
	scanf("%d", &i);
	system("CLS");
	return i;
}
int way()
{
	int i;
a:
	system("CLS");
	printf("1.按教师号\n");
	printf("2.按姓名\n");
	scanf("%d", &i);
	if (i != 1 && i != 2)goto a;
	return i;
}
void jiami(List* l) {
	int i;
	printf("********************\n");
	printf("*1.加密指定教师信息*\n");
	printf("*2.加密所有教师信息*\n");
	printf("********************\n");
	printf("****************\n");
	scanf("%d", &i);
	switch (i)
	{
	case 1:
		i = way();
		system("CLS");
		if (i == 1)
		{
			jiamizhiding1(l);
		}
		else
		{
			jiamizhiding2(l);
		}
		break;
	case 2:
		jiami3(l);
		break;
	default:
		printf("输入错误！\n");
		break;
	}
	printf("\n加密成功！\n");
}
void OutputList(List* l)
{
	Node* first = l->head->next;
	Node* last = l->tail;
	printf("教师号：\t");
	printf("姓名:\n");
	if (first == last)
	{
		printf("无教师信息在库！");
	}
	while (first != last)
	{
		printf("%d\t", first->data.number);
		printf("        %s\t\t", first->data.name);
		codetimes(first->data.code);
		first = first->next;
	}
}
void jiemizhiding1(List* l) {
	int a, b, i;
	Node* re;
a:
	printf("请输入需要解密信息的老师的教师号：");
	scanf("%d", &a);
	re = search(l, a);
	if (re == NULL) {
		printf("是否继续解密？（输入0则结束解密）");
		scanf("%d", &b);
		if (b != 0) {
			goto a;
		}
	}
	else {
		for (i = 0; i < strlen(re->data.name); i++) {
			re->data.name[i] -= 1;
		}
		for (i = 0; i < strlen(re->data.add); i++) {
			re->data.add[i] -= 1;
		}
		for (i = 0; i < strlen(re->data.company); i++) {
			re->data.company[i] -= 1;
		}
		re->data.phone += 2000;
		re->data.base_pay += 100;
		re->data.allowance += 10;
		re->data.living_allowances -= 5;
		re->data.salary /= 2;
		re->data.telephone_bill /= 2;
		re->data.water_and_electricity -= 12.1;
		re->data.rent += 12;
		re->data.income_tax -= 52;
		re->data.sanitation_fee -= 54;
		re->data.accumulation_fund -= 65;
		re->data.Aggregate_deductions -= 12.54;
		re->data.net_payroll -= 154;
		re->data.code -= 1;
	}
}
void jiemizhiding2(List* l) {
	int b, i;
	char a[10];
	Node* re;
a:
	printf("请输入需要解密信息的老师的姓名：");
	scanf("%s", a);
	re = searchname(l, a);
	if (re == NULL) {
		printf("是否继续解密？（输入0则结束解密）");
		scanf("%d", &b);
		if (b != 0) {
			goto a;
		}
	}
	else {
		for (i = 0; i < strlen(re->data.name); i++) {
			re->data.name[i] -= 1;
		}
		for (i = 0; i < strlen(re->data.add); i++) {
			re->data.add[i] -= 1;
		}
		for (i = 0; i < strlen(re->data.company); i++) {
			re->data.company[i] -= 1;
		}
		re->data.phone += 2000;
		re->data.base_pay += 100;
		re->data.allowance += 10;
		re->data.living_allowances -= 5;
		re->data.salary /= 2;
		re->data.telephone_bill /= 2;
		re->data.water_and_electricity -= 12.1;
		re->data.rent += 12;
		re->data.income_tax -= 52;
		re->data.sanitation_fee -= 54;
		re->data.accumulation_fund -= 65;
		re->data.Aggregate_deductions -= 12.54;
		re->data.net_payroll -= 154;
		re->data.code -= 1;
	}
}
void jiemi3(List* l) {
	int i;
	Node* first = l->head->next;
	Node* last = l->tail;
	for (; first != last; first = first->next)
	{
		for (i = 0; i < strlen(first->data.name); i++) {
			first->data.name[i] -= 1;
		}
		for (i = 0; i < strlen(first->data.add); i++) {
			first->data.add[i] -= 1;
		}
		for (i = 0; i < strlen(first->data.company); i++) {
			first->data.company[i] -= 1;
		}
		first->data.phone += 2000;
		first->data.base_pay += 100;
		first->data.allowance += 10;
		first->data.living_allowances -= 5;
		first->data.salary /= 2;
		first->data.telephone_bill /= 2;
		first->data.water_and_electricity -= 12.1;
		first->data.rent += 12;
		first->data.income_tax -= 52;
		first->data.sanitation_fee -= 54;
		first->data.accumulation_fund -= 65;
		first->data.Aggregate_deductions -= 12.54;
		first->data.net_payroll -= 154;
		first->data.code -= 1;
	}
}
void jiemi(List* l) {
	int i;
	printf("********************\n");
	printf("*1.解密指定教师信息*\n");
	printf("*2.解密所有教师信息*\n");
	printf("********************\n");
	printf("****************\n");
	scanf("%d", &i);
	switch (i) {
	case 1:
		i = way();
		system("CLS");
		if (i == 1) {
			jiemizhiding1(l);
		}
		else {
			jiemizhiding2(l);
		}
		break;
	case 2:
		jiemi3(l);
		break;
	default:
		printf("输入错误！\n");
		break;
	}
	printf("\n解密成功!\n");
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
		printf("请输入要修改教师的编号：");
		scanf("%d", &i);
		xiugai(l, i);
		break;
	case 3:
		i = way();
		if (i == 1)
		{
			system("CLS");
			printf("输入教师号：");
			scanf("%d", &i);
			delid(l, i);
		}
		else
		{
			char name[10];
			system("CLS");
			printf("输入教师姓名：");
			scanf("%s", name);
			delname(l, name);
		}
		break;
	case 4:
		i = way();
		if (i == 1)
		{
			system("CLS");
			printf("输入教师号：");
			scanf("%d", &i);
			browseid(l, i);
		}
		else
		{
			char name[10];
			system("CLS");
			printf("输入教师姓名：");
			scanf("%s", name, sizeof(name));
			browsename(l, name);
		}
		break;
	case 5:
		OutputList(l);
		break;
	case 6:
		jiami(l);
		break;
	case 7:
		jiemi(l);
		break;
	case 0:
		return;
		break;
	default: printf("输入错误！\n");
		break;
	}
}
void read(List* l)
{
	FILE* a;
	a = fopen("C:\\Users\\dell\\Desktop\\text.txt", "r");
	if (a != NULL)
	{
		while (!feof(a))
		{
			Information n;
			fscanf(a, "%d", &n.number);
			if (feof(a))break;
			fscanf(a, "%s", &n.name);
			fscanf(a, "%s", &n.sex);
			fscanf(a, "%s", &n.add);
			fscanf(a, "%s", &n.company);
			fscanf(a, "%lld", &n.phone);
			fscanf(a, "%lf", &n.base_pay);
			fscanf(a, "%lf", &n.allowance);
			fscanf(a, "%lf", &n.living_allowances);
			fscanf(a, "%lf", &n.telephone_bill);
			fscanf(a, "%lf", &n.water_and_electricity);
			fscanf(a, "%lf", &n.rent);
			fscanf(a, "%lf", &n.income_tax);
			fscanf(a, "%lf", &n.sanitation_fee);
			fscanf(a, "%lf", &n.accumulation_fund);
			fscanf(a, "%lf", &n.salary);
			fscanf(a, "%lf", &n.Aggregate_deductions);
			fscanf(a, "%lf", &n.net_payroll);
			fscanf(a, "%d", &n.code);
			Insert(l, l->tail, n);
		}
	}
	else { printf("无数据可读取！\n"); }
	fclose(a);
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
	printf("是否保存？(1确认)");
	scanf("%d", &i);
	if (i == 1)
	{
		FILE* b;
		b = fopen("C:\\Users\\dell\\Desktop\\text.txt", "w+");
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
			fprintf(b, "%lf ", p->data.net_payroll);
			fprintf(b, "%d\n", p->data.code);
			p = p->next;
		}
		fclose(b);
	}
	else { return; }
}
void back_to_menue()
{
	printf("\n**********************\n");
	printf("是否返回菜单（0退出）\n");
	printf("**********************\n");

}
void charu(List* l) {
	Information aa;
	int d = 1;
	while (d != 0)
	{
		aa = data();
		Insert(l, l->tail, aa);
		printf("是否继续插入（输入0停止）\n");
		scanf("%d", &d);
	}
}
