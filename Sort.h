#pragma once
//#ifndef SORT_H
//#define SORT_H
#include<algorithm>
using namespace std;

//1-1ð������
void Bubble_sort(int a[], int n)
{
	for (int i =n-1; i !=0; i--)
	{
		for (int j = 0; j != i; j++)    //������Ԫ�طŵ����
		{
			if (a[j + 1] < a[j])    //ֻ���ϸ�С�ڲŽ���Ԫ�أ��㷨���ȶ���
			{
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
}

//1-2�Ż���ð������
void BBubble_sort(int a[], int n)
{
	int flag = 0;    //����һ��flag���ڱ�ʾ�Ƿ����˽���
	for (int i = n - 1; i != 0; i--)
	{
		flag = 0;
		for (int j = 0; j != i; j++)    //һ��ð��
		{
			if (a[j + 1] < a[j])    
			{
				flag = 1;    //��ʶ�����˽���
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
		if (flag == 0)    //������κ�һ��û�з������������˳�ѭ��
			break;
	}
}

//2.���������˿���ץ�ƣ�
void Insertion_sort(int a[], int n)
{
	int i = 0;
	for (int p = 1; p != n; p++)
	{
		int temp = a[p];    //����һ����
		for (i = p; i >= 1 && a[i-1] > temp; --i)
			a[i] = a[i - 1];    //�Ƴ���λ
		a[i] = temp;    //��������
	}
}

//3.ϣ�������Ż��Ĳ�������
void Shell_sort(int a[], int n)
{
	for (int D = n / 2; D != 0; D /= 2)    //��������
	{
		int i = 0, p = 0;
		for (p = D; p != n; p++)    //һ����������
		{
			int temp = a[p];
			for (i = p; i >= D && a[i - D] > temp; i -= D)    
				a[i] = a[i - D];
			a[i] = temp;
		}
	}
}

//4.ѡ������
void Selection_sort(int a[], int n)
{
	for (int i = 0; i != n-1; i++)    //n������ÿ�ΰ���С��Ԫ���������Ԫ�ؽ���
	{
		int min = i;
		for (int j = i+1; j != n; j++)    //����δ���򲿷ֵ���СԪ�ص��±�
			if (a[j] < a[min])
				min = j;
		int t = a[i];    //����Ԫ��
		a[i] = a[min];
		a[min] = t;
	}
}

//5.1 �鲢���򣨵ݹ��㷨��
void Merge(int a[], int tempa[], int L, int R, int Rend)    //��һ������ǰ�󲿷ֹ鲢��һ����������
{
	int temp = L;
	int Lend = R - 1;
	int size = Rend - L + 1;
	while (L <= Lend && R <= Rend)
	{
		if (a[L] <= a[R])
			tempa[temp++] = a[L++];
		else
			tempa[temp++] = a[R++];
	}
	while (L <= Lend)
		tempa[temp++] = a[L++];
	while (R <= Rend)
		tempa[temp++] = a[R++];
	for (int i = Rend; i != Rend - size; i--)
		a[i] = tempa[i];
}

void Msort(int a[], int tempa[], int L, int Rend)    //�ݹ�鲢һ������
{
	int center;
	if (L < Rend)
	{
		center = (L + Rend) / 2;
		Msort(a, tempa, L, center);
		Msort(a, tempa, center + 1, Rend);
		Merge(a, tempa, L, center + 1, Rend);
	}
}

void Merge_sort(int a[], int n)    //�鲢����ӿ�
{
	int *p = new int[n];
	Msort(a, p, 0, n - 1);
	delete p;
}

//5.2�鲢���򣨷ǵݹ飩

//���ٽ�tempa[]��Ԫ��copy��a[]��
void Merge1(int a[], int tempa[], int L, int R, int Rend)
{
	int temp = L;
	int Lend = R - 1;
	while (L <= Lend && R <= Rend)
	{
		if (a[L] <= a[R])
			tempa[temp++] = a[L++];
		else
			tempa[temp++] = a[R++];
	}
	while (L <= Lend)
		tempa[temp++] = a[L++];
	while (R <= Rend)
		tempa[temp++] = a[R++];
}

//һ�˹鲢
void Merge_pass(int a[], int tempa[], int n, int length)
{
	int i = 0;
	for (i; i <=(n -2*length); i += 2 * length)
	{
		Merge1(a, tempa, i, i + length, i + 2 * length - 1);
	}
	if (i + length < n)
		Merge1(a, tempa, i, i + length, n - 1);
	else
		for (int j = i; j < n; j++)
			tempa[j] = a[j];
}

//ͨ�ýӿ�
void Merge_sort1(int a[], int n)
{
	int length = 1;
	int *p = new int[n];
	while (length<n)
	{
		Merge_pass(a, p, n, length);
		length *= 2;
		Merge_pass(p, a, n, length);
		length *= 2;
	}
	free(p);
}

//6.��������
void find_pivot(int a[], int left, int right)
{
	int mid = (left + right) / 2;
	if (a[left] > a[mid])
		swap(a[left], a[mid]);
	if (a[left] > a[right])
		swap(a[left], a[right]);
	if (a[mid] > a[right])
		swap(a[mid], a[right]);
	swap(a[mid], a[right]);
}

void Qsort(int a[],int left,int right)
{
	if (right > left)
	{
		find_pivot(a, left, right);
		int i = left, j = right;
		while (j > i)
		{
			while (a[i] < a[right])
				++i;
			while (a[j] > a[right])
				--j;
			if (i < j)
				swap(a[i++], a[j--]);
		}
		swap(a[i], a[right]);
		Qsort(a, left, i - 1);
		Qsort(a, i + 1, right);
	}
}

void Quick_sort(int a[], int n)
{
	Qsort(a, 0, n - 1);
}

//#endif