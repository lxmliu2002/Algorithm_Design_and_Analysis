#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 1000; // �������ڵ���
vector<int> graph[N]; // �ڽӱ�洢ͼ
int colors[N]; // �������ÿ���ڵ����ɫ����ʼ��Ϊ0

bool BFS(int s) // BFS����
{ 
    queue<int> q;
    q.push(s);
    colors[s] = 1; // ����ʼ�ڵ����ɫ���Ϊ1
    while (!q.empty()) 
    {
        int u = q.front();
        q.pop();
        for (int v : graph[u]) 
        {
            if (colors[v] == colors[u]) return false; // ������ڽڵ���ɫ��ͬ�����Ƕ���ͼ
            if (colors[v] == 0) // ������ڽڵ�δ�������ɫ
            { 
                colors[v] = -colors[u]; // ������ɫ���Ϊ�뵱ǰ�ڵ㲻ͬ����ɫ
                q.push(v);
            }
        }
    }
    return true;
}

int main() 
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) 
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) 
    {
        if (colors[i] == 0) // �����ǰ�ڵ�δ�������ɫ
        { 
            if (!BFS(i)) // ����Ե�ǰ�ڵ�Ϊ��ʼ�ڵ����ͼ���Ƕ���ͼ
            { 
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
