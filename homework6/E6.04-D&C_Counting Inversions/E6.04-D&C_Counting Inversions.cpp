#include<bits/stdc++.h>
using namespace std;

// �鲢���򲢼�������Ե�����
long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i, j, k;
    long long count = 0;

    i = left;  // ��벿�ֵ���ʼ�±�
    j = mid;   // �Ұ벿�ֵ���ʼ�±�
    k = left;  // �ϲ����������ʼ�±�

    while (i <= mid - 1 && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            count += (mid - i);  // ��������Ե�����
        }
    }

    // ��ʣ��Ԫ�ظ��Ƶ� temp ������
    while (i <= mid - 1) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // �� temp �����е�Ԫ�ظ��ƻ� arr ������
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return count;
}

// �鲢����
long long merge_sort(int arr[], int temp[], int left, int right) {
    int mid;
    long long count = 0;

    if (right > left) {
        mid = (right + left) / 2;

        // �ݹ�ض���벿�ֺ��Ұ벿�ֽ��й鲢����
        count += merge_sort(arr, temp, left, mid);
        count += merge_sort(arr, temp, mid + 1, right);

        // �鲢�����������������鲢��������Ե�����
        count += merge(arr, temp, left, mid + 1, right);
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    // �������鲢��ȡ����
    int* arr = new int[n];
    int* temp = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // ʹ�ù鲢�����������Ե�����
    long long count = merge_sort(arr, temp, 0, n - 1);

    // ������
    cout << count << endl;

    return 0;
}
