#include<bits/stdc++.h>
using namespace std;


// ��������������ϲ���һ����������
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // ������ʱ�������������������������ֵ
    int* L = new int[n1];
    int* R = new int[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    // �ϲ�����������
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // ����ʣ���Ԫ��
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// �鲢����
void mergesort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // �ݹ�ؽ�����ֳ�����������
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);

        // �ϲ�����������
        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    cin >> n;

    // �������鲢��ȡ����
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // ʹ�ù鲢����������������
    mergesort(arr, 0, n - 1);

    // ������
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
