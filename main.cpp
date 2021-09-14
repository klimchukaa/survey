#include <bits/stdc++.h>

using namespace std;

signed main() {
    cout << "Your name: ";
    string name; cin >> name;
    cout << "Your surname: ";
    string surname; cin >> surname;
    cout << "Your favourite movie: ";
    string emp; getline(cin, emp);
    string movie; getline(cin, movie);
    ofstream f; f.open("C:\\Users\\Alexander\\Desktop\\survey\\results.txt", ios::app);
    f << name << ' ' << surname << ' ' << movie << "\n";
}
