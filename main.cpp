#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


void get_questions_from_file(vector<string>& res) {
    res.clear();
    ifstream in;
    in.open("questions.txt");
    string q; string an;
    while (getline(in, q)) {
        res.push_back(q);
    }
}


void set_questions() {
    vector<string> questions;
    vector<string> old_questions;
    get_questions_from_file(old_questions);
    cout << "Old questions was: " << "\n";
    for (auto& q : old_questions) {
        cout << "\t" << q << "\n";
    }
    cout << "How many questions? : ";
    int n;
    string sn;
    getline(cin, sn);
    n = stoi(sn);
    ofstream qfile;
    qfile.open("questions.txt");
    for (int i = 0; i < n; ++i) {
        string q;
        getline(cin, q);
        qfile << q << "\n";
    }
    qfile.close();
    ofstream f; f.open("results.txt");
    f.close();
}


void get_results(int k) {
    ifstream in; in.open("results.txt");
    vector < vector <string> > res;
    string inf; int ind = 0; int l = 0;
    while (getline(in, inf)) {
        if (l == ind) {
            res.push_back(vector <string> ());
            l++;
        }
        if (inf == "end_user") {
            swap(res[ind][0], res[ind][k - 1]);
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
    cout << "People: " << ind << "\n";
}


void new_user() {
    vector<string> questions;
    get_questions_from_file(questions);
    vector <string> answers;
    string q; string an;
    for(auto &q: questions) {
        cout << q << ' ';
        getline(cin, an);
        answers.push_back(an);
    }
    ofstream f; f.open("results.txt", ios::app);
    for (auto ans : answers) {
        f << ans << "\n";
    }
    f << "end_user\n\n";
    f.close();
}


signed main() {
    cout << "What do you need? (results/set_questions/new_user) ";
    string need; getline(cin, need);
    if (need == "results") {
        cout << "What cell in your priority? ";
        int k; cin >> k;
        get_results(k);
        return 0;
    }
    else if (need == "set_questions") {
        set_questions();
    }
    else{
        new_user();
    }
}
