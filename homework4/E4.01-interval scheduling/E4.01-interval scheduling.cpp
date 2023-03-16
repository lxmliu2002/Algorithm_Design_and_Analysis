#include<bits/stdc++.h>
using namespace std;
// ���幤���Ŀ�ʼʱ��ͽ���ʱ��Ľṹ��
struct Job {
    int start_time;
    int end_time;
};

// ��������㷨����
vector<Job> interval_scheduling(int n, vector<Job>& jobs) 
{
    // ������ʱ���С��������
    sort(jobs.begin(), jobs.end(), [](Job& a, Job& b) { return a.end_time < b.end_time; });
    // ��ʼ��������飬�����һ������
    vector<Job> result{ jobs[0] };
    // �������๤��
    for (int i = 1; i < n; i++) 
    {
        // �����ǰ�����Ŀ�ʼʱ�����ڽ�����������һ�������Ľ���ʱ��
        if (jobs[i].start_time >= result.back().end_time) 
        {
            // ����ǰ��������������
            result.push_back(jobs[i]);
        }
    }
    return result;
}

int main() 
{
    int n;
    cin >> n;
    vector<Job> jobs(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> jobs[i].start_time >> jobs[i].end_time;
    }
    vector<Job> result = interval_scheduling(n, jobs);
    cout << result.size() << endl;
    system("pause");
    return 0;
}
