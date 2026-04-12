#include <iostream>
#include <string>
using namespace std;


bool canTurnOffAllBulbs(int size, int maxOps, const string& bulbs, int winSize) {
    int opsUsed = 0;

    for (int i = 0; i < size; ) {
        if (bulbs[i] == '1') {
            opsUsed++;
            i += winSize;
        } else {
            i++; 
        }
    }

    return opsUsed <= maxOps;
}

int main() {
    int size, maxOps;
    cin >> size >> maxOps;

    string bulbs;
    cin >> bulbs;

 
    int lo = 1;
    int hi = size;
    int minWin = size;  

    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (canTurnOffAllBulbs(size, maxOps, bulbs, mid)) {
            minWin = mid;  
            hi = mid - 1;
        } else {
            lo = mid + 1;  
        }
    }

    cout << minWin << endl;
    return 0;
}
