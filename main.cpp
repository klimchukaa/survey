#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


void set_asks() {

}


void get_results(int k) {
    ifstream in; in.open("results.txt");
    vector < vector <string> > res;
    string inf; int ind = 0; int l = 0;
    set <string> books;
    while (getline(in, inf)) {
        if (l == ind) {
            res.push_back(vector <string> ());
            l++;
        }
        if (inf == "end_user") {
            swap(res[ind][0], res[ind][k - 1]);
            books.insert(res[ind][2]);
            ind++;
        } else if (inf != "") {
            res[ind].push_back(inf);
        }
    }
    res.pop_back();
    sort(res.begin(), res.end());
    for (int i = 0; i < ind; ++i) {
        swap(res[i][0], res[i][k - 1]);
        auto user = res[i];
        for (auto information : user) {
            cout << information << "\n";
        }
        cout << "\n";
    }
    cout << "People: " << ind << ' ' << "Different books" << ' ' << books.size() << "\n";
}


void new_user() {
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


signed main() {
    cout << "What do you need? (results/set_asks/new_user) ";
    string need; getline(cin, need);
    if (need == "results") {
        cout << "What cell in your priority? ";
        int k; cin >> k;
        get_results(k);
        return 0;
    }
    else{
        new_user();
    }
}
