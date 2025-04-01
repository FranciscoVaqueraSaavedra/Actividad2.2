/*
 * SonarQube, open source software quality management tool.
 * Copyright (C) 2008-2013 SonarSource
 * http://github.com/SonarOpenCommunity/sonar-cxx
 *
 * SonarQube is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * SonarQube is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
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
