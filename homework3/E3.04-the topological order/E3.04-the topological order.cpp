#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() 
{
    int n, m;
    cin >> n >> m;
    vector<int> indegree(n, 0); // ��¼ÿ���ڵ�����
    vector<vector<int>> graph(n); // �ڽӱ�
    for (int i = 0; i < m; ++i) 
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v); // ��ӱ�
        ++indegree[v]; // �������
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) 
    {
        if (indegree[i] == 0) 
        { // �ҵ����Ϊ0�Ľڵ�
            q.push(i);
        }
    }

    vector<int> top_order;
    while (!q.empty()) 
    {
        int cur = q.front();
        q.pop();
        top_order.push_back(cur); // ����ǰ�ڵ������������
        for (int neighbor : graph[cur]) 
        { // �����ڽӽڵ�����
            --indegree[neighbor];
            if (indegree[neighbor] == 0) 
            { // ������Ϊ0��������
                q.push(neighbor);
            }
        }
    }

    for (int i = 0; i < n; ++i) 
    {
        cout << top_order[i] << " ";
    }
    cout << endl;

    return 0;
}
