#include<bits/stdc++.h>
using namespace std;
// ������������
struct Node {
    int freq;
    char ch;
    Node* left, * right;
    Node(int f, char c) : freq(f), ch(c), left(nullptr), right(nullptr) {}
};

// ������ȽϺ��������ڽ�����С��
struct NodeComparator {
    bool operator() (const Node* a, const Node* b) {
        return a->freq > b->freq;
    }
};

// ����Huffman�����̰���㷨
string huffman(int n, vector<int>& freq) {
    // ��ʼ����С�ѣ�ÿ����㶼��һ�õ�������
    priority_queue<Node*, vector<Node*>, NodeComparator> pq;
    for (int i = 0; i < n; i++) {
        pq.push(new Node(freq[i], char(i + 'a')));
    }

    // ����Huffman����ֱ������ֻ��һ����
    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();
        Node* parent = new Node(left->freq + right->freq, '-');
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    // ����Huffman�������ɱ���
    map<char, string> codes;
    string code;
    Node* root = pq.top();
    function<void(Node*, string)> traverse = [&](Node* node, string code) {
        if (node->left == nullptr && node->right == nullptr) {
            codes[node->ch] = code;
            return;
        }
        traverse(node->left, code + '0');
        traverse(node->right, code + '1');
    };
    traverse(root, code);

    // ����ƽ�����볤��
    double avg_len = 0;
    for (auto p : codes) {
        avg_len += freq[p.first - 'a'] * p.second.size();
    }
    avg_len /= accumulate(freq.begin(), freq.end(), 0);

    // ���ر�������ƽ�����볤��
    return to_string(avg_len);
}

int main() {
    // ��������
    int n;
    cin >> n;
    vector<int> freq(n);
    for (int i = 0; i < n; i++) {
        cin >> freq[i];
    }

    // ����Huffman���벢������
    string code = huffman(n, freq);
    cout << fixed << setprecision(2) << code << endl;

    return 0;
}