#include <iostream>
#include <cmath> // ������ѧ��
#include <vector> // ����������
#include <algorithm> // �����㷨��
using namespace std;

// ����ṹ�壬��ʾ��ά��
struct Point 
{
	double x;
	double y;
	Point(double x, double y) : x(x), y(y) {}
};

// ����һ�����������ڼ���������֮���ŷ����þ���
double euclideanDistance(const Point& p1, const Point& p2) 
{
	double dx = p1.x - p2.x;
	double dy = p1.y - p2.y;
	return sqrt(dx*dx + dy*dy); // ����sqrt��������ƽ����
}

// ����һ�����������ڼ���һ����������������֮���ŷ����þ���
double closestPair(vector<Point>& points) 
{
	sort(points.begin(), points.end(), [](const Point& p1, const Point& p2) { return p1.x < p2.x; }); // ����x�����С��������
	double minDist = euclideanDistance(points[0], points[1]); // ��ʼ����Ϊǰ������ľ���
	int left = 0;
	for (int i = 0; i < points.size(); i++) 
	{
		while (points[i].x - points[left].x > minDist) 
		{
			left++; // ��ָ�������ƣ�ֱ������x����֮��С�ڵ���minDist
		}
		for (int j = left; j < i; j++) 
		{ // ֻ�������ָ���i֮��ĵ�
			double dist = euclideanDistance(points[i], points[j]); // ����������֮��ľ���
			if (dist < minDist)
			{
				minDist = dist; // �������С�ڵ�ǰ��С���룬�������С����
			}
		}
	}
	return minDist; // ������С����
}

int main() 
{
	vector<Point> points{ {1, 2}, {3, 4}, {2, 7}, {8, 9}, {5, 6} }; // ��ʼ��һ���
	double minDist = closestPair(points); // ������С����
	cout << "�����������֮��ľ����ǣ�" << minDist << endl;
	return 0;
}