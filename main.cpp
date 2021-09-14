#include <bits/stdc++.h>

using namespace std;

signed main() {
    cout << "Your name: ";
    string name; cin >> name;
    cout << "Your surname: ";
    string surname; cin >> surname;
    cout << "Book you recommend reading: ";
    string emp; getline(cin, emp);
    string book; getline(cin, book);
    ofstream f; f.open("C:\\Users\\Alexander\\Desktop\\survey\\results.txt", ios::app);
    f << name << ' ' << surname << ' ' << book << "\n";
}
