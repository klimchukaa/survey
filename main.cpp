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
    cout << "Your name: ";
    string name; cin >> name;
    cout << "Your surname: ";
    string surname; cin >> surname;
    cout << "Book you recommend reading: ";
    string emp; getline(cin, emp);
    string book; getline(cin, book);
    ofstream f; f.open("results.txt", ios::app);
    f << name << ' ' << surname << ' ' << book << "\n";
}
