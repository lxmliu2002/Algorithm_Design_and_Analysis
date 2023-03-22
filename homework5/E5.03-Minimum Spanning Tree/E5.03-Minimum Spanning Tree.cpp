#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1000;
struct Edge {
    int u, v, cost;
    Edge(int u, int v, int cost) : u(u), v(v), cost(cost) {}
    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};
int p[MAXN];
int find(int x) {
    if (p[x] == x)
        return x;
    else
        return p[x] = find(p[x]);
}
void unite(int x, int y) {
    p[find(x)] = find(y);
}
bool same(int x, int y) {
    return find(x) == find(y);
}
int kruskal(vector<Edge>& edges, int n) {
    sort(edges.begin(), edges.end()); // �����б߰���Ȩ��С��������
    for (int i = 1; i <= n; i++)
        p[i] = i; // ��ʼ�����鼯
    int res = 0;
    for (Edge e : edges) { // �������б�
        if (!same(e.u, e.v)) { // ����������㲻��ͬһ����ͨ�����У������Ǻϲ���������Ȩ�ۼӵ������
            unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res; // ������С�������ı�Ȩ֮��
}
int main() {
    int n, m;
    cin >> n >> m; // ����ڵ����ͱ���
    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w; // ����ÿ���ߵ���ʼ�ڵ㡢��ֹ�ڵ�ͱ�Ȩֵ
        edges.emplace_back(u, v, w); // ���ߴ洢��������
    }
    cout << kruskal(edges, n); // ����kruskal�㷨������С�������ı�Ȩ֮�Ͳ�������
    return 0;
}