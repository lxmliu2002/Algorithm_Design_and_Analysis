#include<iostream>
using namespace std;
int Binary_Search(int* a, int n,int x)
{
    int length = n;
	int left = 0, right = length - 1;
	int mid = 0;
	while (left <= right)
	{
        mid = left + (right - left) / 2;

        if (a[mid] == x)
        {
            return mid;
        }
        if (a[mid] < x)
        {
            left = mid + 1;
        }
        if (a[mid] > x)
        {
            right = mid - 1;
        }
	}
    return -1;
}
int main()
{
    int n = 0;
    cout << "�������������n=";
    cin >> n;
    int* a = new int[n];
    cout << "��������������Ԫ��";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int x = 0;
    cout << "ȥ�����Ԫ��x=";
    cin >> x;
    if (Binary_Search(a,n, x) == -1)
    {
        cout << "δ�ҵ�";
    }
    else
    {
        cout << "Ԫ��x�������±�Ϊ" << Binary_Search(a, n, x);
    }
    return 0;
}