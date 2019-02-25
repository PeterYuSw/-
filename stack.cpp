/*
*��������ʵ��һ���򵥵�ջ
*2019-2-25
*/

#include<iostream>

using namespace std;

//����һ������ڵ�Ľṹ��
struct Node {
	int val;
	Node *next;
};

//����ջ����
class Stack {
public:
	void init();
	void push(int e);
	void pop();
	int top();
	bool IsEmpty();
	int Length();
private:
	int length=0;
	Node *head;
};

//��ʼ��ջ
void Stack::init()
{
	head= new Node();
	length = 0;
}

//push����
void Stack::push(int e)
{
	Node *p = new Node();
	p->val = e;
	p->next = nullptr;
	if (!head->next)
	{
		head->next = p;
		++length;
	}
	else
	{
		p->next = head->next;
		head->next = p;
		++length;
	}
}

//pop����
void Stack::pop()
{
	if (!head->next)
		cout << "ջΪ�գ�" << endl;
	else
	{
		Node *q = head->next;
		head->next = q->next;
		delete q;
		--length;
	}
}

//��ȡջ��Ԫ��ֵ
int Stack::top()
{
	if (!head->next)
		return -1;
	else
	{
		return head->next->val;
	}
}

//�ж�ջ�Ƿ�Ϊ��
bool Stack::IsEmpty()
{
	if (!head->next)
		return true;
	else
		return false;
}

//��ȡջ�ĳ���
int Stack::Length()
{
	return length;
}

int main()
{
	Stack s;
	s.init();
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.pop();
	cout << "ջ��Ԫ��Ϊ�� " << endl;
	cout << s.top() << endl;
	cout << "ջ����Ϊ�� " << endl;
	cout << s.Length() << endl;
	return 0;
}