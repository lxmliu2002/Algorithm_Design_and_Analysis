#include<iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n; // ����һ������n
    if (n >= 0) // ���nΪ�Ǹ�����ֱ�����n���˳�
    {
        cout << n;
    }
    else // ���nΪ��������Ҫ����ת��
    {
        n = abs(n); // ��nȡ����ֵ�����������һ������
        if (n < 10) // ���n�ľ���ֵС��10�������0
        {
            cout << "0";
        }
        else // ���n�ľ���ֵ���ڵ���10���������һ������
        {
            int last_two_digits = n / 100; // ȡn�ĳ�ȥ�����ڶ�λ�͵�����һλ����
            int last_digit = n % 10; // ȡn�ĸ�λ��
            int second_last_digit = (n / 10) % 10; // ȡn��ʮλ��
            // ��n�ĵ����ڶ�λ�͵�����һλ��ɵ���λ����n�ĸ�λ����ʮλ���ֱ�Ƚϣ�ȡ�ϴ�ֵ��������෴��
            cout << -min(last_two_digits * 10 + last_digit, last_two_digits * 10 + second_last_digit);
        }
    }
}
