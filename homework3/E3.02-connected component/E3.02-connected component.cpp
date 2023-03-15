#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 1000; // ����ͼ�����ڵ���
vector<int> adj[N]; // �洢ͼ���ڽӱ�
bool vis[N]; // ��ǽڵ��Ƿ񱻱�����

void BFS(int s, vector<int>& comp) 
{
    queue<int> q; // �����������BFS
    q.push(s); // ����ʼ�ڵ�s�������
    vis[s] = true; // �����ʼ�ڵ��Ѿ������ʹ�
    while (!q.empty()) 
    { // �����в�Ϊ��ʱ
        int u = q.front(); // ȡ�����׽ڵ�u
        q.pop(); // �������׽ڵ�
        comp.push_back(u); // ���ڵ�u���뵱ǰ��ͨ����
        for (int v : adj[u]) 
        { // ����u���ھӽڵ�v
            if (!vis[v]) 
            { // ����ڵ�vû�б����ʹ�
                vis[v] = true; // ��ǽڵ�v�Ѿ������ʹ�
                q.push(v); // ���ڵ�v�������
            }
        }
    }
}

void DFS(int u, vector<int>& comp) 
{
    vis[u] = true; // ��ǽڵ�u�Ѿ������ʹ�
    comp.push_back(u); // ���ڵ�u���뵱ǰ��ͨ����
    for (int v : adj[u]) 
    { // �����ڵ�u���ھӽڵ�v
        if (!vis[v]) 
        { // ����ڵ�vû�б����ʹ�
            DFS(v, comp); // �ݹ�ط��ʽڵ�v
        }
    }
}

int main() {
    int n, m, i;
    cin >> n >> m >> i; // ����ڵ�������������Ҫ������ͨ�����Ľڵ���
    for (int j = 0; j < m; j++) {
        int u, v;
        cin >> u >> v; // ����һ���ߵ������˵�
        adj[u + 1].push_back(v + 1); // �洢�ߵ���Ϣ
        adj[v + 1].push_back(u + 1);
    }
    vector<int> bfs_comp, dfs_comp; // �ֱ�洢BFS��DFS�ҵ�����ͨ����
    BFS(i + 1, bfs_comp); // ִ��BFS�㷨
    memset(vis, 0, sizeof(vis)); // ��ʼ���������
    DFS(i + 1, dfs_comp); // ִ��DFS�㷨
    for (int u : bfs_comp) {
        cout << (u - 1) << " "; // ���BFS�ҵ�����ͨ����
    }
    cout << endl;
    for (int u : dfs_comp) {
        cout << (u - 1) << " "; // ���DFS�ҵ�����ͨ����
    }
    cout << endl;
    return 0;
}
