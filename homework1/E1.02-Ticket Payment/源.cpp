#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int n, m, a, b;
    int res = 0;
    cin >> n >> m >> a >> b;

    if (n < m || a < b / m) // ��� n < m ���� a < b/m ����ôѡ���һ��Ʊ��
    {
        res = n * a;
    }
    else // ����ѡ��ڶ���Ʊ��
    {
        res = (n / m) * b; // ���������ĳ�������ķ���
        if (n % m != 0) // �����ʣ��ĳ�����Ҫ����
        {
            res += min((n % m) * a, b); // ѡ�񻨷Ѹ��ٵķ�ʽ����ʣ�೵��
        }
    }

    cout << res << endl;

    return 0;
}