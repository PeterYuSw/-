/*
*ͨ����������ʵ���˶����������򴴽������ֱ����ĵݹ�ͷǵݹ鷽��
*/
#include<iostream>
#include<stack>

using namespace std;

//��������ͣ���������
struct BiTreeNode {
	char data;
	BiTreeNode *lchild;
	BiTreeNode *rchild;
};

//����������
class BiTree {
public:
	void Init();
	//�ݹ�ǰ�����
	void PreOrderTraverse1();
	//�ǵݹ�ǰ�����
	void PreOrderTraverse2();
	//�ݹ��������
	void InOrderTraverse1();
	//�ǵݹ��������
	void InOrderTraverse2();
	//�ݹ�������
	void PostOrderTraverse1();
	//�ǵݹ�������
	void PostOrderTraverse2();
	//���򴴽�������
	void CreateBiTree();

private:
	BiTreeNode *root;
	void PreOrder_Traverse1(BiTreeNode *r);
	void PreOrder_Traverse2(BiTreeNode *r);
	void InOrder_Traverse1(BiTreeNode *r);
	void InOrder_Traverse2(BiTreeNode *r);
	void PostOrder_Traverse1(BiTreeNode *r);
	void PostOrder_Traverse2(BiTreeNode *r);
	void Create_BiTree(BiTreeNode **r);
};

//��ʼ��������
void BiTree::Init()
{
	root = nullptr;
}

//�ݹ��ǰ�����
void BiTree::PreOrder_Traverse1(BiTreeNode *r)
{
	if (r)
	{
		cout << r->data << " ";
		PreOrder_Traverse1(r->lchild);
		PreOrder_Traverse1(r->rchild);
	}
}
void BiTree::PreOrderTraverse1()
{
	PreOrder_Traverse1(root);
	cout << endl;
}

//�ǵݹ�ǰ�����
void BiTree::PreOrder_Traverse2(BiTreeNode *r)
{
	stack<BiTreeNode*> s1;
	s1.push(r);
	BiTreeNode *p, *q;
	while (!s1.empty())
	{
		while ((p = s1.top()) && p)
		{
			cout << p->data << " ";
			s1.push(p->lchild);
		}
		s1.pop();
		if (!s1.empty())
		{
			q = s1.top();
			s1.pop();
			s1.push(q->rchild);
		}
	}

}
void BiTree::PreOrderTraverse2()
{
	PreOrder_Traverse2(root);
	cout << endl;
}

//�ݹ���������
void BiTree::InOrder_Traverse1(BiTreeNode *r)
{
	if (r)
	{
		InOrder_Traverse1(r->lchild);
		cout << r->data << " ";
		InOrder_Traverse1(r->rchild);
	}
}
void BiTree::InOrderTraverse1()
{
	InOrder_Traverse1(root);
	cout << endl;
}

//�ǵݹ���������
void BiTree::InOrder_Traverse2(BiTreeNode *r)
{
	stack<BiTreeNode*> s1;
	BiTreeNode *q, *p;
	s1.push(r);
	while (!s1.empty())
	{
		while ((q = s1.top()) && q)
			s1.push(q->lchild);
		s1.pop();
		if (!s1.empty())
		{
			p = s1.top();
			cout << p->data << " ";
			s1.pop();
			s1.push(p->rchild);
		}
	}
}
void BiTree::InOrderTraverse2()
{
	InOrder_Traverse2(root);
	cout << endl;
}

//�ݹ�ĺ������
void BiTree::PostOrder_Traverse1(BiTreeNode *r)
{
	if (r)
	{
		PostOrder_Traverse1(r->lchild);
		PostOrder_Traverse1(r->rchild);
		cout << r->data << " ";
	}
}
void BiTree::PostOrderTraverse1()
{
	PostOrder_Traverse1(root);
	cout << endl;
}

//�ǵݹ�������
void BiTree::PostOrder_Traverse2(BiTreeNode *r)
{
	stack<BiTreeNode*>s1;
	s1.push(r);
	s1.push(r);
	BiTreeNode *p;
	while (!s1.empty())
	{
		p = s1.top();
		s1.pop();
		if (!s1.empty() && p == s1.top())
		{
			if (p->rchild)
			{
				s1.push(p->rchild);
				s1.push(p->rchild);
			}
			if (p->lchild)
			{
				s1.push(p->lchild);
				s1.push(p->lchild);
			}
		}
		else
			cout << p->data << " ";
	}
}
void BiTree::PostOrderTraverse2()
{
	PostOrder_Traverse2(root);
	cout << endl;
}

//�ݹ�ʵ�����򴴽�������
void BiTree::Create_BiTree(BiTreeNode **r)
{

	char e;
	cin >> e;
	if (e == '#')
		r = NULL;
	else
	{
		*r = new BiTreeNode();
		(*r)->data = e;
		Create_BiTree(&(*r)->lchild);
		Create_BiTree(&(*r)->rchild);
	}
}
void BiTree::CreateBiTree()
{
	Create_BiTree(&root);
}

int main()
{
	BiTree T1;
	T1.Init();
	T1.CreateBiTree();
	cout << "ǰ���������Ϊ�� " << endl;
	T1.PreOrderTraverse1();
	T1.PreOrderTraverse2();
	cout << "�����������Ϊ�� " << endl;
	T1.InOrderTraverse1();
	T1.InOrderTraverse2();
	cout << "�����������Ϊ�� " << endl;
	T1.PostOrderTraverse1();
	T1.PostOrderTraverse2();
	return 0;
}