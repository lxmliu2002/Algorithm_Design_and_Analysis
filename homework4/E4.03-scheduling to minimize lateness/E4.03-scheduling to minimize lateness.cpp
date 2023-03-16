#include<bits/stdc++.h>
using namespace std;

// ���幤���ṹ��
struct Job {
    int id;                 // ���� ID
    int processing_time;    // ����ʱ��
    int deadline;           // ��ֹʱ��
};

// �Զ��������������ս�ֹʱ���С��������
bool cmp(Job a, Job b) 
{
    return a.deadline < b.deadline;
}

int main() 
{
    int n;
    cin >> n;

    // ���������б�
    vector<Job> jobs(n);
    for (int i = 0; i < n; i++) 
    {
        jobs[i].id = i + 1;   // ���� ID �� 1 ��ʼ
        cin >> jobs[i].processing_time >> jobs[i].deadline;  // ���봦��ʱ��ͽ�ֹʱ��
    }

    // �Թ����б��ս�ֹʱ���С��������
    sort(jobs.begin(), jobs.end(), cmp);

    int current_time = 0;   // ��ǰʱ���ʼ��Ϊ 0
    int max_lateness = 0;   // ����ӳ�ʱ���ʼ��Ϊ 0
    vector<int> schedule;   // ���ȱ��ʼ��Ϊ��

    // ��ÿ���������д���
    for (int i = 0; i < n; i++) 
    {
        current_time += jobs[i].processing_time;   // ���µ�ǰʱ��
        int lateness = current_time - jobs[i].deadline;   // �����ӳ�ʱ��

        if (lateness > max_lateness) 
        {   // ��������ӳ�ʱ��
            max_lateness = lateness;
        }

        schedule.push_back(jobs[i].id);   // ������ ID ��ӵ����ȱ���
    }

    // ����ӳ�ʱ��
    cout << max_lateness << endl;
    system("pause");
    return 0;
}
