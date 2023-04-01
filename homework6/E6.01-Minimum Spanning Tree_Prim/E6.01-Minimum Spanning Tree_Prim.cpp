#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii; // ����pair����

const int MAXN = 100005;
const int INF = 11111111;

vector<pii> g[MAXN]; // ͼ���ڽӱ��ʾ
bool vis[MAXN]; // ��ǽڵ��Ƿ�����С��������

int prim(int n) {
    int ans = 0; // ��С�������ı�Ȩ��
    priority_queue<pii, vector<pii>, greater<pii>> pq; // ��С��
    pq.push(make_pair(0, 1)); // �ӽڵ�1��ʼ

    while (!pq.empty()) {
        int u = pq.top().second; // ȡ���Ѷ��ڵ�
        int w = pq.top().first; // ȡ���Ѷ��ڵ��Ȩֵ
        pq.pop();

        if (vis[u]) continue; // ����ڵ��Ѿ�����С�������У�������
        vis[u] = true; // ��ǽڵ��Ѿ�����С��������

        ans += w; // ������С�������ı�Ȩ��

        for (auto& e : g[u]) { // �����ڵ�u���ڽӱ�
            int v = e.first;
            int weight = e.second;
            if (!vis[v]) {
                pq.push(make_pair(weight, v)); // ���ڵ�v������С��
            }
        }
    }

    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }

    cout << prim(n) << endl;

    return 0;
}
