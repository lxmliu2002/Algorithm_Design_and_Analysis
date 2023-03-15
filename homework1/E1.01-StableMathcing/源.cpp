#include <iostream>
using namespace std;

bool man_null(int* man_data, int n)
{
	for (int i = 1; i <= n; i++)
	{
		if (man_data[i] == -1)
		{
			return true;
		}
	}
	return false;
}
bool judge(int** woman, int n, int w, int chman, int otherman)//w��ϲ��chman����true
{
	int* inverse = new int[n + 1];

	for (int i = 1; i <= n; i++)
	{
		int k = woman[w][i];
		inverse[k] = i;
	}

	if (inverse[chman] < inverse[otherman])
	{
		return true;
	}
	return false;

}

int main()
{
	int n;
	cin >> n;
	char** p = new char* [n * 2];
	int** man = new int* [n + 1];
	int** woman = new int* [n + 1];
	int* man_data = new int[n + 1];
	int* woman_data = new int[n + 1];
	int* position = new int[n + 1];

	//��ʼ��Man��Woman�����б�
	for (int i = 0; i < n + 1; i++)
		man[i] = new int[n + 1];
	for (int i = 0; i < n + 1; i++)
		woman[i] = new int[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			man[i][j] = 0;
			woman[i][j] = 0;
		}
	}

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			cin >> man[i][j];
		}
	}


	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			cin >> woman[i][j];
		}
	}

	//��ʼ��man��Լ������¼
	for (int i = 0; i < n + 1; i++)
	{
		man_data[i] = -1;
	}
	//��ʼ��woman��Լ������¼
	for (int i = 0; i < n + 1; i++)
	{
		woman_data[i] = -1;
	}

	//��ʼ��man�����ȱ�λ��
	for (int i = 0; i < n + 1; i++)
	{
		position[i] = 0;
	}

	while (man_null(man_data, n))
	{
		//ѡ��ǰѭ��Ҫ�Ҷ����man����Ϊchman
		int chman = 1;
		for (chman = 1; chman <= n; chman++)
		{
			if (man_data[chman] == -1)
			{
				break;
			}
		}

		//ѡ��chmanҪ���Լ���woman w  
		int tem = position[chman] + 1;
		int w = man[chman][tem];
		if (woman_data[w] == -1)//w is free
		{
			//��chman��wԼ��
			woman_data[w] = chman;
			man_data[chman] = w;
			position[chman]++;
		}
		else// w ���ںͱ���Լ��
		{
			int otherman = woman_data[w];
			if (judge(woman, n, w, chman, otherman))//w��ϲ��chman
			{
				//�� otherman free
				man_data[otherman] = -1;

				//��chman��wԼ��
				woman_data[w] = chman;
				man_data[chman] = w;
				position[chman]++;

			}
			else//w��ϲ��ԭ����otherman
			{
				position[chman]++;
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << man_data[i] << " ";
	}
	return 0;
}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <map>
//
//using namespace std;
//
//// ����һ���ṹ�壬��ʾһ���˼���ϲ���б�
//struct Person {
//	string name;            // ����
//	vector<string> prefs;   // ϲ���б�
//};
//
//// �ȽϺ��������ڽ������˵�ϲ���б��������
//bool cmp(const Person& a, const Person& b) {
//	return a.prefs.size() < b.prefs.size();
//}
//
//int main() {
//	int n;
//	cin >> n;
//
//	// ��������map�����ڴ洢���Ժ�Ů�Ե����
//	map<string, string> matchesM;
//	map<string, string> matchesW;
//
//	vector<Person> men(n), women(n);
//
//	// �������Ե���Ϣ
//	for (int i = 0; i < n; i++) {
//		string name;
//		cin >> name;
//
//		men[i].name = name;
//
//		for (int j = 0; j < n; j++) {
//			string pref;
//			cin >> pref;
//
//			men[i].prefs.push_back(pref);
//		}
//	}
//
//	// ����Ů�Ե���Ϣ
//	for (int i = 0; i < n; i++) {
//		string name;
//		cin >> name;
//
//		women[i].name = name;
//
//		for (int j = 0; j < n; j++) {
//			string pref;
//			cin >> pref;
//
//			women[i].prefs.push_back(pref);
//		}
//	}
//
//	// �����Ժ�Ů�Ե�ϲ���б��������
//	sort(men.begin(), men.end(), cmp);
//	sort(women.begin(), women.end(), cmp);
//
//	// ���ν������Ե����
//	for (int i = 0; i < n; i++) {
//		string m = men[i].name;
//
//		for (int j = 0; j < n; j++) {
//			string w = men[i].prefs[j];
//
//			// ������Ů�Ի�û�б���ԣ�����Գɹ�
//			if (matchesW.find(w) == matchesW.end()) {
//				matchesM[m] = w;
//				matchesW[w] = m;
//				break;
//			}
//			// �����ж����Ů���Ƿ�ϲ����ǰ���Ը�ʤһ��
//			else {
//				string m2 = matchesW[w];
//
//				// �����ǰ���Ը������Ů��ϲ��������Գɹ�����һ�Խ�����
//				if (find(women.begin(), women.end(), m) - women.begin() < find(women.begin(), women.end(), m2) - women.begin()) {
//					matchesM[m] = w;
//					matchesW[w] = m;
//					matchesM[m2] = "";
//					break;
//				}
//			}
//		}
//	}
//
//	// �����Խ��
//	for (auto match : matchesM) {
//		if (match.second != "") {
//			cout << "(" << match.first << "," << match.second << ") ";
//		}
//	}
//	cout << endl;
//
//	return 0;
//}
