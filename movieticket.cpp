#include <bits/stdc++.h>
using namespace std;

class MovieTicket {
private:
    
    unordered_map<int, set<int>> bookings;

    
    unordered_map<int, int> available;

public:

    MovieTicket() {
        
    }
    bool book(int user, int movie) {
        if (available[movie] == 0 && bookings[movie].size() == 0) {
            available[movie] = 100; // initialize
        }

    
        if (bookings[movie].count(user) || available[movie] == 0) {
            return false;
        }

        bookings[movie].insert(user);
        available[movie]--;
        return true;
    }

    
    bool cancel(int user, int movie) {
        if (bookings[movie].count(user) == 0) {
            return false;
        }

        bookings[movie].erase(user);
        available[movie]++;
        return true;
    }


    bool isBooked(int user, int movie) {
        return bookings[movie].count(user);
    }


    int availableTickets(int movie) {
        if (available[movie] == 0 && bookings[movie].size() == 0) {
            return 100; // not used yet
        }
        return available[movie];
    }
};

int main() {
    int Q;
    cin >> Q;

    MovieTicket mt;

    while (Q--) {
        string query;
        cin >> query;

        if (query == "BOOK") {
            int X, Y;
            cin >> X >> Y;
            cout << (mt.book(X, Y) ? "true" : "false") << endl;
        }
        else if (query == "CANCEL") {
            int X, Y;
            cin >> X >> Y;
            cout << (mt.cancel(X, Y) ? "true" : "false") << endl;
        }
        else if (query == "IS_BOOKED") {
            int X, Y;
            cin >> X >> Y;
            cout << (mt.isBooked(X, Y) ? "true" : "false") << endl;
        }
        else if (query == "AVAILABLE_TICKETS") {
            int Y;
            cin >> Y;
            cout << mt.availableTickets(Y) << endl;
        }
    }

    return 0;
}