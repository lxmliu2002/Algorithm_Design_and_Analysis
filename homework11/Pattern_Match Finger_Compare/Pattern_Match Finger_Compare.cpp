#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int BASE = 26;  // �ַ����Ļ���
const int MOD = 1000000007;  // ȡģ��ֵ

// �����ַ�����ָ��ֵ
int calculateFingerprint(const string& str, int length) {
    int fingerprint = 0;
    for (int i = 0; i < length; i++) {
        fingerprint = (fingerprint * BASE + (str[i] - 'a')) % MOD;
    }
    return fingerprint;
}

// ����ָ�Ƶĸ���ֵ
int calculateUpdatedFingerprint(int fingerprint, int length, char removedChar, char addedChar) {
    fingerprint = (fingerprint * BASE) % MOD;
    fingerprint = (fingerprint + (addedChar - 'a')) % MOD;

    int removedValue = (removedChar - 'a') * static_cast<int>(pow(BASE, length - 1)) % MOD;
    fingerprint = (fingerprint + MOD - removedValue) % MOD;

    return fingerprint;
}

int patternMatching(const string& X, const string& Y) {
    int n = X.length();
    int m = Y.length();

    if (n < m) {
        return -1;  // X�ĳ���С��Y��Y�޷�ƥ��
    }

    // ����ģʽ��Y��ָ��ֵ
    int targetFingerprint = calculateFingerprint(Y, m);

    // �����ı���X�е�һ������Ϊm���Ӵ���ָ��ֵ
    int currentFingerprint = calculateFingerprint(X, m);

    // Ԥ�ȼ��� BASE �� m �η������ڸ���ָ��ʱ�ļ���
    int basePower = 1;
    for (int i = 0; i < m - 1; i++) {
        basePower = (basePower * BASE) % MOD;
    }

    // ����Ƚ��ı���X�е��Ӵ���ģʽ��Y��ָ��ֵ
    for (int i = 0; i <= n - m; i++) {
        if (currentFingerprint == targetFingerprint) {
            // ���ָ��ֵƥ�䣬��һ���Ƚ��Ӵ���ģʽ��������
            if (X.substr(i, m) == Y) {
                return i;  // ƥ��ɹ������ص�һ��λ�õ�����
            }
        }

        // ����ָ��ֵ
        if (i < n - m) {
            currentFingerprint = calculateUpdatedFingerprint(currentFingerprint, m, X[i], X[i + m]);
        }
    }

    return -1;  // û���ҵ�ƥ���λ��
}

int main() {
    string X, Y;
    cout << "�������ַ���X��";
    cin >> X;
    cout << "�������ַ���Y��";
    cin >> Y;

    int result = patternMatching(X, Y);
    cout << "Y��X�е�һ�γ��ֵ�λ�ã�" << result << endl;

    return 0;
}
