#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;  


vector<int> suffixArrayNaive(string S) {
    int n = S.length() + 1;
    vector<string> sa;
    vector<int> A(n);
    S = S + "$";

    for (int i = 0; i < n; i++)
        sa.push_back(S.substr(i));

    sort(sa.begin(), sa.end());


    for (int i = 0; i < n; i++)
        A[i] = n - sa[i].size() + 1;

    return A;
}

int main() {
    string text;
    getline(cin, text);

    vector<int> suffixArray = suffixArrayNaive(text);

    for (int index : suffixArray) {
        cout << index << endl;
    }

    return 0;
}
