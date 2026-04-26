#include <bits/stdc++.h>
using namespace std;

class Bank {
private:
    unordered_map<int, int> balance; // userId -> money

public:

    // CREATE X Y
    bool create(int user, int amount) {
        if (balance.count(user)) {
            balance[user] += amount;
            return false;
        }
        balance[user] = amount;
        return true;
    }

    // DEBIT X Y
    bool debit(int user, int amount) {
        if (!balance.count(user) || balance[user] < amount) {
            return false;
        }
        balance[user] -= amount;
        return true;
    }

    // CREDIT X Y
    bool credit(int user, int amount) {
        if (!balance.count(user)) {
            return false;
        }
        balance[user] += amount;
        return true;
    }

    // BALANCE X
    int getBalance(int user) {
        if (!balance.count(user)) {
            return -1;
        }
        return balance[user];
    }
};

int main() {
    int Q;
    cin >> Q;

    Bank bank;

    while (Q--) {
        string query;
        cin >> query;

        // optional: make input case-insensitive
        for (auto &c : query) c = toupper(c);

        if (query == "CREATE") {
            int X, Y;
            cin >> X >> Y;
            cout << (bank.create(X, Y) ? "true" : "false") << endl;
        }
        else if (query == "DEBIT") {
            int X, Y;
            cin >> X >> Y;
            cout << (bank.debit(X, Y) ? "true" : "false") << endl;
        }
        else if (query == "CREDIT") {
            int X, Y;
            cin >> X >> Y;
            cout << (bank.credit(X, Y) ? "true" : "false") << endl;
        }
        else if (query == "BALANCE") {
            int X;
            cin >> X;
            cout << bank.getBalance(X) << endl;
        }
    }

    return 0;
}