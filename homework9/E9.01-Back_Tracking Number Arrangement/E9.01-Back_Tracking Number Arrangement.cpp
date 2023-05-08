#include<iostream>
using namespace std;


const int MAXN = 100;

int n;
int a[MAXN + 1]; // �洢1��n��������a[1]��ʼ�洢

void dfs(int k) 
{
    if (k > n) 
    { // ����Ѿ����˵�n+1��λ�ã������ǰ����
        for (int i = 1; i <= n; i++) 
        {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = k; i <= n; i++) // ö�ٵ�ǰλ�ÿ�������Щ��
    { 
        swap(a[k], a[i]); // ����i�����͵�k�����������൱�ڹ̶��˵�k��λ��Ϊa[i]
        dfs(k + 1); // �����ݹ�����һ��λ��
        swap(a[k], a[i]); // �ָ�ԭ����״̬��������
    }
}

int main() 
{
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        a[i] = i;
    }
    dfs(1); // �ӵ�1��λ�ÿ�ʼ����
    return 0;
}

