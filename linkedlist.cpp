/*
*���ܣ�ʵ��һ���򵥵Ĵ�ͷ���ĵ�����
*/
#include<iostream>

using namespace std;

//������ṹ�嶨��
struct LNode {
	int val;
	LNode *next;
	//Ĭ�Ϲ��캯��
	LNode():val(0),next(nullptr){}
	//����һ�������Ĺ��캯��
	LNode(int x) :val(x), next(nullptr) {}
};

//������������ͷ���
void create(LNode *l)
{
	l->val = 0;
	l->next = nullptr;
}

//�ڱ�ͷ����Ԫ��
void insert(LNode *l,int e)
{
	LNode *q = new LNode(e);
	q->next = l->next;
	l->next = q;
}

//ɾ����ͷԪ��
void erase(LNode *l, int &e)
{
	if (l->next)
	{
		e = l->next->val;
		l->next = l->next->next;
	}
	else
		cout << "��Ϊ�գ�" << endl;
}

//������ӡ����Ԫ��
void traverse(LNode *l)
{
	LNode *q = l;
	while (q->next)
	{
		cout << q->next->val << " ";
		q = q->next;
	}
	cout << endl;
}

//������
int length(LNode *l)
{
	LNode *q = l;
	int i = 0;
	while (q->next)
	{
		++i;
		q = q->next;
	}
	return i;
}

//���ҵ�i��Ԫ�ص�ֵ
int find_ith(LNode *l, int i)
{
	int j = 0;
	LNode *q = l;
	while (q->next&&j != i - 1)
	{
		q = q->next;
		++j;
	}
	if (!q->next)
		return -1;
	return q->next->val;
}

//�滻��i��Ԫ�ص�ֵ
void change_ith(LNode *l, int i,int e)
{
	int j = 0;
	LNode *q = l;
	while (q->next&&j != i - 1)
	{
		q = q->next;
		++j;
	}
	if (!q->next||j>=i)
		cout << "Ԫ�ز����ڣ�" << endl;
	q->next->val = e;
}
int main()
{
	LNode *l = new LNode();  //����ͷ���
	create(l);
	int e = 0;
	insert(l, 2);
	insert(l, 3);
	insert(l, 4);
	insert(l, 5);
	cout << "����Ԫ��Ϊ�� " << endl;
	traverse(l);
	erase(l, e);
	cout << "ɾ��Ԫ��Ϊ�� "<<e << endl;
	cout << "����Ԫ��Ϊ�� " << endl;
	traverse(l);
	cout << "������Ϊ�� " << endl;
	cout << length(l) << endl;
	cout << "��2��Ԫ��Ϊ�� "<<find_ith(l, 2) << endl;
	change_ith(l, 2, 5);  //�滻�ڶ���Ԫ��ֵ
	cout << "����Ԫ��Ϊ�� " << endl;
	traverse(l);
	return 0;
}