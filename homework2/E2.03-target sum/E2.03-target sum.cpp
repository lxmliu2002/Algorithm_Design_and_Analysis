#include<iostream>
#include<time.h> 
#include"Binary Search.h" // ������ֲ��Һ���ͷ�ļ�
using namespace std;

// O(n^2) �㷨�������֮�͵���Ŀ��ֵ�����
void target_sum_nn(int* a, int n, int t)
{
	int i = 0, j = 0, sum = 0;
	while (i < n)
	{
		while (j < n)
		{
			if (a[i] + a[j] == t && a[i] != a[j])//�ҵ�������ͬ�������������ǵĺ͵���Ŀ����t
			{
				cout << a[i] << "+" << a[j] << "=" << t << endl;
				sum++;//��¼�ҵ��������������Եĸ���
			}
			j++;
		}
		i++;
		j = i;
	}
	if (sum == 0)//����Ҳ�����������������
	{
		cout << "�Ҳ�������������" << endl; //����޷��ҵ��������������Ե���ʾ��Ϣ
	}
}

// O(nlogn) �㷨�������֮�͵���Ŀ��ֵ�����
void target_sum_nlogn(int* a, int n, int t)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int tmp = t - a[i];//����Ŀ����t�뵱ǰ��a[i]�Ĳ�ֵtmp
		int re = Binary_Search(a, n, tmp);;//������a�ж��ֲ����Ƿ���ֵ����tmp��Ԫ�أ����ظ�Ԫ�ص��±�re
		if (re == -1)//�������a�в�����ֵ����tmp��Ԫ��
		{
			continue;//����������һ����
		}
		if (i != re)//����ҵ��˲�ͬ����������ʹ���ǵĺ͵���Ŀ����t
		{
			cout << a[i] << "+" << a[re] << "=" << t << endl; //����������������ǵĺ�
			sum++;//��¼�ҵ��������������Եĸ���
		}
	}
	if (sum == 0)//����Ҳ�����������������
	{
		cout << "�Ҳ�������������" << endl; //����޷��ҵ��������������Ե���ʾ��Ϣ
	}
}

// O(n) �㷨�������֮�͵���Ŀ��ֵ�����
void target_sum_n(int* a, int n, int t)
{
	int i = 0, j = n - 1;//i��j�ֱ��ʾ����a�ĵ�һ�������һ��Ԫ�ص��±�
	int sum = 0; //���ڼ�¼�������������Եĸ���
	while (i != j)//��i��jû������
	{
		if (a[i] + a[j] < t) //�����ǰ�������ĺ�С��Ŀ����t
		{
			i++;//�����ƶ�iָ�룬ʹ��ǰ�������ĺ�����
		}
		if (a[i] + a[j] > t) //�����ǰ�������ĺʹ���Ŀ����t
		{
			j--;//�����ƶ�jָ�룬ʹ��ǰ�������ĺͼ�С
		}
		if (a[i] + a[j] == t)//����ҵ��˲�ͬ����������ʹ���ǵĺ͵���Ŀ����t
		{
			cout << a[i] << "+" << a[j] << "=" << t << endl;//����������������ǵĺ�
			i++, j--;//���������ƶ�ָ��j��i
			sum++;//��¼�ҵ��������������Եĸ���
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

	// ��ʱ������ O(n^2) �㷨
	clock_t start_time_nn = clock();
	target_sum_nn(a, n, T);
	clock_t end_time_nn = clock();
	cout << "O(n^2)�㷨���õ�ʱ��Ϊ" << double(static_cast<double>(end_time_nn - start_time_nn) / CLOCKS_PER_SEC * double(1000)) << "ms" << endl;

	// ��ʱ������ O(nlogn) �㷨
	clock_t start_time_nlogn = clock();
	target_sum_nlogn(a, n, T);
	clock_t end_time_nlogn = clock();
	cout << "O(nlogn)�㷨����ʱ��Ϊ" << double(static_cast<double>(end_time_nlogn - start_time_nlogn) / CLOCKS_PER_SEC * double(1000)) << "ms" << endl;
	
	// ��ʱ������ O(n) �㷨
	clock_t start_time_n = clock();
	target_sum_n(a, n, T);
	clock_t end_time_n = clock();
	cout << "O(n)�㷨����ʱ��Ϊ" << double(static_cast<double>(end_time_n - start_time_n) / CLOCKS_PER_SEC * double(1000)) << "ms";
	return 0;
}