#include <iostream>
#include <string>
#include <cstring>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm> // for std::sort
#include <functional> // for std::greater

using namespace std;

const int  MAXM = 1001;
const int  MAXN = 100001;
 
int un[MAXM], ub[MAXM];
int v[MAXN];
int next[MAXN];


int main() {
    int m, n, t;
    int ui, bi;
    vector<int> borrowedBooks;
    int next[MAXN];
    string cmd;

    while (cin >> m >> n) {
        cin >> t;
        borrowedBooks.clear();
        memset(next, 0, sizeof(next));

        while (t--) {
            cin >> cmd;
            if (cmd == "B") {
                cin >> ui >> bi;
                if (borrowedBooks.size() == 9) {
                    cout << "You are not allowed to borrow any more" << endl;
                } else if (borrowedBooks.empty() || borrowedBooks.back() != bi) {
                    borrowedBooks.push_back(bi);
                    next[bi] = ui;
                    cout << "Borrow success" << endl;
                }
            } else if (cmd == "R") {
                cin >> bi;
                if (borrowedBooks.empty() || borrowedBooks.back() != bi) {
                    cout << "The book is already in the library" << endl;
                } else {
                    ui = borrowedBooks.back();
                    borrowedBooks.pop_back();
                    next[ui] = next[bi];
                    cout << "Return success" << endl;
                }
            } else if (cmd == "Q") {
                cin >> ui;
                if (borrowedBooks.empty()) {
                    cout << "Empty" << endl;
                } else {
                    sort(borrowedBooks.begin(), borrowedBooks.end(), greater<int>());
                    for (int i = 0; i < borrowedBooks.size() - 1; ++i) {
                        cout << borrowedBooks[i] << " ";
                    }
                    cout << borrowedBooks[borrowedBooks.size() - 1] << endl;
                }
            }
        }
        cout << endl;
    }

    return 0;
}
