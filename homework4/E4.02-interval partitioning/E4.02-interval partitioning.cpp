#include<bits/stdc++.h>
using namespace std;

int interval_partitioning(int n, vector<pair<int, int>> lectures) 
{
    // ���ս����Ľ���ʱ����������
    sort(lectures.begin(), lectures.end(), [](auto& a, auto& b) {return a.second < b.second; });

    // ��һ��vector�洢�Ѿ����佲���Ľ��ҵ����ʱ��
    vector<int> classrooms;

    // ����ÿ�����������Խ�����䵽���еĽ����л��½�һ������
    for (int i = 0; i < n; i++) 
    {
        bool scheduled = false;
        for (int j = 0; j < classrooms.size(); j++) 
        {
            // �����ǰ�������Ա����䵽�ý��ң������
            if (lectures[i].first >= classrooms[j]) 
            {
                classrooms[j] = lectures[i].second; // ���¸ý��ҵ����ʱ��
                scheduled = true;
                break;
            }
        }
        // ����޷������䵽�κ�һ�����ң����½�һ������
        if (!scheduled) 
        {
            classrooms.push_back(lectures[i].second);
        }
    }

    // ����ʹ�õĽ�����
    return classrooms.size();
}

int main() {
    int n;
    cin >> n;

    // ����ÿ�������Ŀ�ʼ�ͽ���ʱ�䣬������һ��vector<pair<int, int>>�洢����
    vector<pair<int, int>> lectures;
    for (int i = 0; i < n; i++) 
    {
        int start, end;
        cin >> start >> end;
        lectures.push_back({ start, end });
    }

    // ����interval_partitioning������������
    cout << interval_partitioning(n, lectures) << endl;
    system("pause");

    return 0;
}
