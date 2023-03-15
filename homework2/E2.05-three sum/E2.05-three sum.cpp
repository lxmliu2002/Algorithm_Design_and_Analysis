#include<iostream>
#include<time.h> 
#include"Binary Search.h" // ������ֲ��Һ���ͷ�ļ�
using namespace std;

// O(n^3) �㷨�������֮�͵���Ŀ��ֵ�����
void target_sum_nnn(int* a, int n, int t)
{
	int i = 0, j = 0, k = 0, sum = 0;
	while (k < n)
	{
		while (i < n)
		{
			while (j < n)
			{
				if (a[i] + a[j] +a[k] == t && a[i] != a[j] && a[i] != a[k])//�ҵ�������ͬ�������������ǵĺ͵���Ŀ����t
				{
					cout << a[k] << "+" << a[i] << "+" << a[j] << "=" << t << endl;
					sum++;//��¼�ҵ��������������Եĸ���
				}
				j++;
			}
			i++;
			j = i;
		}
		k++;
		i = k;
	}
	if (sum == 0)//����Ҳ�����������������
	{
		cout << "�Ҳ�������������" << endl; //����޷��ҵ��������������Ե���ʾ��Ϣ
	}
}

// O(n^2*logn) �㷨�������֮�͵���Ŀ��ֵ�����
void target_sum_nnlogn(int* a, int n, int t)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int tmp = t - a[i] - a[j];//����Ŀ����t�뵱ǰ��a[i]��a[j]�Ĳ�ֵtmp
			int re = Binary_Search(a, n,tmp); //������a�ж��ֲ����Ƿ���ֵ����tmp��Ԫ�أ����ظ�Ԫ�ص��±�re
			if (re == -1)//�������a�в�����ֵ����tmp��Ԫ��
			{
				continue;//����������һ����
			}
			if (i != re && i != j && re > j)//����ҵ��˲�ͬ����������ʹ���ǵĺ͵���Ŀ����t
			{
				cout << a[i] << "+" << a[j] << "+" << a[re] << "=" << t << endl; //����������������ǵĺ�
				sum++;//��¼�ҵ��������������Եĸ���
			}
		}
	}
	if (sum == 0)//����Ҳ�����������������
	{
		cout << "�Ҳ�������������" << endl; //����޷��ҵ��������������Ե���ʾ��Ϣ
	}
}

// O(n^2) �㷨�������֮�͵���Ŀ��ֵ�����
void target_sum_nn(int* a, int n, int t)
{
	int i = 0, j = i + 1, k = n - 1;
	int sum = 0;
	for (i; i < n - 3; i++)
	{
		j = i + 1;
		while(j != k)
		{
			if (a[i] + a[j] + a[k] < t) //�����ǰ�������ĺ�С��Ŀ����t
			{
				j++;//�����ƶ�jָ�룬ʹ��ǰ�������ĺ�����
			}
			if (a[i] + a[j] + a[k] > t) //�����ǰ�������ĺʹ���Ŀ����t
			{
				k--;//�����ƶ�jָ�룬ʹ��ǰ�������ĺͼ�С
			}
			if (a[i] + a[j] + a[k] == t)//����ҵ��˲�ͬ����������ʹ���ǵĺ͵���Ŀ����t-a[i]
			{
				cout << a[i] << "+" << a[j] << "+" << a[k] << "=" << t << endl;//����������������ǵĺ�
				j++;
				sum++;//��¼�ҵ��������������Եĸ���
			}
		}
	}
	if (sum == 0)//����Ҳ�����������������
	{
		cout << "�Ҳ�������������" << endl; //����޷��ҵ��������������Ե���ʾ��Ϣ
	}
}

int main()
{
	cout << "�����������ĸ���n=";
	int n = 0;
	cin >> n;
	int* a = new int[n];
	cout << "���������������Ԫ��";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "��������������T=";
	int T = 0;
	cin >> T;

	// ��ʱ������ O(n^3) �㷨
	clock_t start_time_nnn = clock();
	target_sum_nnn(a, n, T);
	clock_t end_time_nnn = clock();
	cout << "O(n^3)�㷨���õ�ʱ��Ϊ" << double(static_cast<double>(end_time_nnn - start_time_nnn) / CLOCKS_PER_SEC * double(1000)) << "ms" << endl;

	// ��ʱ������ O(n^2*logn) �㷨
	clock_t start_time_nnlogn = clock();
	target_sum_nnlogn(a, n, T);
	clock_t end_time_nnlogn = clock();
	cout << "O(n^2*logn)�㷨����ʱ��Ϊ" << double(static_cast<double>(end_time_nnlogn - start_time_nnlogn) / CLOCKS_PER_SEC * double(1000)) << "ms" << endl;

	// ��ʱ������ O(n^2) �㷨
	clock_t start_time_nn = clock();
	target_sum_nn(a, n, T);
	clock_t end_time_nn = clock();
	cout << "O(n^2)�㷨����ʱ��Ϊ" << double(static_cast<double>(end_time_nn - start_time_nn) / CLOCKS_PER_SEC * double(1000)) << "ms";
	return 0;
}