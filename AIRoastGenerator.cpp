#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>    // ← needed for time(0)
using namespace std;

string replacePlaceholder(string roast, string actualName) {
    string placeholder = "{name}";
    int pos = roast.find(placeholder);
    if (pos != string::npos) {
        roast.replace(pos, placeholder.length(), actualName);
    }
    return roast;
}

int main() {

    string name;
    cout << "What's your name? ";
    cin >> name;

    vector<string> roasts = {
        "Hey {name}, even your WiFi password is too weak for you.",
        "Scientists confirmed {name} is the missing link.",
        "{name} tried to outsmart a door — the door won.",
        "{name}'s search history is a cry for help.",
        "Even autocorrect gave up on {name}.",
    };

    mt19937 rng(time(0));  // ✅ FIXED: seed changes every run

    uniform_int_distribution<int> dist(0, roasts.size() - 1);
    int randomIndex = dist(rng);

    string chosen = roasts[randomIndex];
    string finalRoast = replacePlaceholder(chosen, name);

    cout << "\n🔥 Today's roast:\n\n";
    cout << finalRoast << "\n";

    return 0;
}