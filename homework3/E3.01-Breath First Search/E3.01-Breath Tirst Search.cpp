#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 1000;
vector<int> G[N]; // �ڽӱ�洢ͼ
int layer[N]; // ���ڴ洢ÿ���ڵ����ڵĲ���
bool vis[N]; // ��ǽڵ��Ƿ��Ѿ������ʹ�
queue<int> Q; // ���ڴ洢�������Ľڵ�

void BFS(int start)
{
    memset(vis, 0, sizeof(vis)); // ��ʼ�����нڵ�δ���ʹ�
    layer[start] = 0; // ��ʼ�ڵ�Ĳ���Ϊ0
    vis[start] = true; // �����ʼ�ڵ��ѷ��ʹ�
    Q.push(start); // ����ʼ�ڵ�������

    while (!Q.empty())
    {
        int u = Q.front(); // ȡ�����׽ڵ�
        Q.pop(); // �������׽ڵ�
        for (int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            if (!vis[v])// ����ڵ�vδ���ʹ�
            {
                layer[v] = layer[u] + 1; // ���½ڵ�v�Ĳ���
                vis[v] = true; // ��ǽڵ�v�ѷ��ʹ�
                Q.push(v); // ���ڵ�v�������
            }
        }
    }
}

int main()
{
    int n, m, start;
    cin >> n >> m >> start;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u + 1].push_back(v + 1); // ����(u,v)�����ڽӱ�
        G[v + 1].push_back(u + 1);;// ����ͼ��Ҫ����(v,u)Ҳ�����ڽӱ�
    }
    BFS(start + 1);
    for (int i = 1; i <= n; i++)
    {
        cout << layer[i] << " ";
    }

    return 0;
}
