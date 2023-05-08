#include <bits/stdc++.h>
using namespace std;

struct State 
{
    vector<int> assignment;
    int cost;

    // ��������� �������ȶ�����״̬�����ȼ�
    bool operator<(const State& other) const 
    {
        return cost > other.cost; 
    }
};

// ��ȡ������ʱ��
int get_cost(vector<int>& assignment, vector<vector<int>>& times) 
{
    int total_time = 0;
    for (int i = 0; i < assignment.size(); i++) 
    {
        total_time += times[i][assignment[i]];
    }
    return total_time;
}

void assign_courses(vector<vector<int>>& times) 
{
    int n = times.size();
    priority_queue<State> heap;
    heap.push({ {}, 0 }); // ��ʼ״̬��û���˷���γ̣�������ʱ��Ϊ0
    while (!heap.empty()) 
    {
        State state = heap.top();
        heap.pop();
        // �ҵ���һ�����������ķ��䷽��
        if (state.assignment.size() == n) 
        { 
            // ������䷽��
            cout << "Assignment: ";
            for (int i = 0; i < state.assignment.size(); i++) 
            {
                cout << char(state.assignment[i] + 'A') << " ";
            }
            cout << endl;
            // ���������ʱ��
            cout << "Total cost: " << state.cost << endl;
            break;
        }
        for (int i = 0; i < n; i++) 
        {
            bool is_assigned = false;
            for (int j : state.assignment) 
            {
                if (j == i) 
                {
                    is_assigned = true; // ������Ѿ������˿γ�
                    break;
                }
            }
            if (is_assigned) continue;
            State new_state = state;
            new_state.assignment.push_back(i); // ����γ�
            new_state.cost = get_cost(new_state.assignment, times); // ���㱸����ʱ��
            heap.push(new_state); // ����״̬�������ȶ���
        }
    }
}

int main() {
    vector<vector<int>> times = { {2, 10, 9, 7},
                                  {15, 4, 14, 8},
                                  {13, 14, 16, 11},
                                  {4, 15, 13, 9} 
                                };
    assign_courses(times);
    system("pause");
    return 0;
}
