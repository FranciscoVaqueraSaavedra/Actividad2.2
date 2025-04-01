/*
 * SonarQube, open source software quality management tool.
 * Copyright (C) 2008-2024 SonarSource
 * https://github.com/SonarOpenCommunity/sonar-cxx
 *
 * Licensed under the GNU Lesser General Public License; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This file implements a naive suffix array construction algorithm.
 * It sorts all suffixes of a given string and outputs their starting indices.
 *
 * SonarQube is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> suffix_array_naive(string S) {
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

   vector<int> suffixArray = suffix_array_naive(text);

    for (int index : suffixArray) {
        cout << index << endl;
    }

    return 0;
}
