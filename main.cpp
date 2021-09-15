#include <bits/stdc++.h>

using namespace std;

void get_results() {
    ifstream in; in.open("results.txt");
    string inf;
    while (getline(in, inf)) {
        cout << inf << "\n";
    }
}

signed main() {
    cout << "What do you need? ";
    string need; getline(cin, need);
    if (need == "results") {
        get_results();
        return 0;
    }
    ifstream in; in.open("questions.txt");
    vector <string> answers;
    string q; string an;
    while (getline(in, q)) {
        cout << q << ' ';
        getline(cin, an);
        answers.push_back(an);
    }
    ofstream f; f.open("results.txt", ios::app);
    for (auto ans : answers) {
        f << ans << "\n";
    }
    f << "\n";
}
