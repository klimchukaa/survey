#include <bits/stdc++.h>

using namespace std;

void get_results() {
    ifstream in; in.open("results.txt");
    vector < vector <string> > res;
    string inf; int ind = 0; int l = 0;
    while (getline(in, inf)) {
        if (l == ind) {
            res.push_back(vector <string> ());
            l++;
        }
        if (inf == "end_user") {
            swap(res[ind][0], res[ind][1]);
            ind++;
        } else if (inf != "") {
            res[ind].push_back(inf);
        }
    }
    sort(res.begin(), res.end());
    for (auto user : res) {
        for (auto information : user) {
            cout << information << "\n";
        }
        cout << "\n";
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
    f << "end_user\n\n";
}
