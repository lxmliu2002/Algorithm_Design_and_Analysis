#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000; // ���ڵ���
const int INF = 1061109567; // ��ʾ������һ����ֵ
struct Edge {
    int to, cost;
    Edge(int t, int c) : to(t), cost(c) {}
};
typedef pair<int, int> P; // first: ��С���룬second: ������
vector<Edge> G[MAXN];
int d[MAXN]; // �洢Դ�㵽���������̾���
void dijkstra(int s) { // sΪԴ��
    priority_queue<P, vector<P>, greater<P>> q; // С���ѣ����ڴ洢��С����Ͷ�����
    fill(d, d + MAXN, INF); // ��ʼ�����о���Ϊ�����
    d[s] = 0; // Դ�㵽����ľ���Ϊ0
    q.push(P(0, s)); // ��Դ��������
    while (!q.empty()) { // �����в�Ϊ��ʱѭ��
        P p = q.top(); // ȡ������Ԫ�أ���С���룩
        q.pop(); // ��������Ԫ��
        int v = p.second; // ȡ��������
        if (d[v] < p.first) continue; // �����ǰ�������̾����Ѿ����¹�������Ըö���
        for (int i = 0; i < G[v].size(); i++) { // �����뵱ǰ�������ڵ����б�
            Edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) { // �������ͨ����ǰ����������ڶ������̾��룬����²�������������
                d[e.to] = d[v] + e.cost;
                q.push(P(d[e.to], e.to));
            }
        }
    }
}
int main() {
    int n, m, s;
    cin >> n >> m >> s; // ����ڵ�����������Դ����
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z; // ����ߵ���ʼ�ڵ㡢��ֹ�ڵ�ͱ�Ȩֵ
        G[x].push_back(Edge(y, z)); // ���ߴ洢���ڽӱ���
    }
    dijkstra(s); // ����dijkstra�㷨�������·��
    for (int i = 1; i <= n; i++)
        cout << d[i] << " "; // ������
    return 0;
}