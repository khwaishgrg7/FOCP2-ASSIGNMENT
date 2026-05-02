#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>
using namespace std;

string replacePlaceholder(string excuse, string actualName) {
    string placeholder = "{name}";
    int pos = excuse.find(placeholder);
    if (pos != string::npos) {
        excuse.replace(pos, placeholder.length(), actualName);
    }
    return excuse;
}

int main() {

    string name;
    cout << "Enter your name, student: ";
    cin >> name;

    vector<string> excuses = {
        "Sorry Professor, {name} was abducted by aliens and just got back.",
        "{name}'s dog ate the homework and filed a lawsuit.",
        "The professor wouldn't believe this, but {name} was a ghost all along.",
        "{name} tried to submit via telepathy — still waiting for confirmation.",
        "A time traveler warned {name} not to open the textbook.",
        "{name}'s WiFi achieved sentience and refused to load the assignment.",
        "The homework was done, but {name}'s printer printed invisible ink.",
        "{name} sneezed and accidentally solved a different subject entirely.",
        "Due to a clerical error, {name} exists in two timelines simultaneously.",
        "{name} was busy teaching squirrels calculus. They're slow learners.",
    };

    // 🐛 BUG IS HERE: seed is hardcoded to 0 instead of time(0)
    // Same seed → same number sequence → always picks the same excuse
    mt19937 rng(0);   // ← should be rng(time(0))

    uniform_int_distribution<int> dist(0, excuses.size() - 1);
    int randomIndex = dist(rng);

    string chosen = excuses[randomIndex];
    string finalExcuse = replacePlaceholder(chosen, name);

    cout << "\n📋 Today's excuse:\n\n";
    cout << finalExcuse << "\n";

    return 0;
}