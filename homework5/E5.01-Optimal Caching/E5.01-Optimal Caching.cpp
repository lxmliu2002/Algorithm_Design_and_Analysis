#include <bits/stdc++.h>
using namespace std;
bool need_evicite(vector<int> vec, int a)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == a)
            return false;
    }
    return true;
}
bool ifFF(vector<int> vecc, vector<int> vecr, int pos, vector<int>& newvecc)
{
    int num = 0;
    for (int i = 0; i < vecc.size(); i++)
    {
        int m = 0;
        for (int j = pos + 1; j < vecr.size(); j++)
        {
            if (vecr[j] == vecc[i])
            {
                m++;
                num++;
                break;
            }
        }
        if (m == 0) // ��m==0��˵��������������޵�ǰ�������еĸ�Ԫ�أ��������ӵ��»�������
            newvecc.push_back(vecc[i]);
    }
    return num != vecc.size();
}
int getpos1(vector<int> vec, int pos, int a)
{
    for (int i = pos + 1; i < vec.size(); i++)
    {
        if (vec[i] == a)
            return i; // �ں�벿����ʱ���ҵ���һ����Ҫ����
    }
    return -1; // ��ʵûɶʵ���ô�����Ϊ����������϶����ú����з��ء�
}
int getpos2(vector<int> vec, int pos, int a)
{
    int m = 0;
    for (int i = 0; i < pos; i++)
    {
        if (vec[i] == a)
            m = i; // ��ǰ�벿����ʱ����Ҫ�����һ�α�ʹ�ù����±꣬���Ҫ���ϸ���m
    }
    return m;
}
int main()
{
    int k, n, s;
    cin >> k >> n >> s;
    vector<int> cache;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        cache.push_back(t);
    }
    vector<int> requests(s);
    for (int i = 0; i < s; i++)
        cin >> requests[i];
    for (int i = 0; i < requests.size(); i++)
    {
        if (cache.size() < k && need_evicite(cache, requests[i])) // ��������δ�����޵�ǰ����
        {
            cache.push_back(requests[i]); // ����ǰ���ݼ��뻺����
        }
        else if (!need_evicite(cache, requests[i])) // �������������е�ǰ���ݣ�ֱ��������������
            continue;
        else if (need_evicite(cache, requests[i]) && cache.size() == k) // ���������޵�ǰ�����һ���������
        {
            vector<int> newcache;                    // �»����������ڻ���ʱ�õ�
            if (!ifFF(cache, requests, i, newcache)) // �����������������ݶ�����֮��������������ҵ�
            {
                int max = -1;
                int far = -1;               // ������Զ�����ݵ��±�
                vector<int> d(k);           // ������������
                for (int j = 0; j < k; j++) // ������ǰ��������Ϊÿ�����ݸ�����
                {
                    d[j] = getpos1(requests, i, cache[j]); // getpos1���η��ػ������и������ݶ�Ӧ���±�
                    if (d[j] > max)                        // ֱ�����ø��±�����ӳ�������ݾ����Զ����Խ��˵�����ԽԶ
                    {
                        max = d[j];
                        far = j;
                    }
                }
                cout << cache[far] << ' '; // �ӵ���Զ���Ǹ����ݣ�Ȼ���滻��requests[i]
                cache[far] = requests[i];
            }
            else
            {
                int min = 10000;
                int far = -1;
                vector<int> d(newcache.size());
                for (int j = 0; j < newcache.size(); j++) // ������ǰ��������Ϊÿ�����ݸ�����
                {
                    d[j] = getpos2(requests, i, newcache[j]); // getpos2���ص���ǰ�벿���У����������ݶ�Ӧ���±�
                    if (d[j] < min)
                    {
                        min = d[j]; // ��ʱҪ�ӵ�����ʹ��ģ����±���С�ģ���˲��ϸ���min
                        far = j;
                    }
                }
                cout << newcache[far] << ' ';
                for (int j = 0; j < cache.size(); j++)
                {
                    if (cache[j] == newcache[far])
                    {
                        cache[j] = requests[i]; // �ӵ���÷��ʹ���
                        break;
                    }
                }
            }
        }
    }
    system("pause");
    return 0;
}