#include <bits/stdc++.h>

using namespace std;

signed main() {
    ifstream in; f.open("questions.txt");
    vector <string> answers;
    string an;
    while (getline(in, an)) {
        answers.push_back(an);
    }
    ofstream f; f.open("results.txt", ios::app);
    for (auto ans : answers) {
        f << ans << "\n";
    }
    f << "\n";
}
