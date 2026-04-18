#include<iostream>
#include<vector>
using namespace std;

int main() {
    
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];
        
        
        int freq[1001] = {0};
        for(int i = 0; i < n; i++) {
            freq[arr[i]]++;  
        }
        
        long long alex = 0, bob = 0;
        bool alexEaten[1001] = {false};
        bool bobEaten[1001]  = {false};
        int turn = 0; 
        
        for(int val = 1000; val >= 1; val--) {
            
            
            for(int j = 0; j < freq[val]; j++) {
                
                if(turn == 0) {
                    if(alexEaten[val]) continue;  
                    alexEaten[val] = true;
                    alex += val;
                } else {
                    if(bobEaten[val]) continue;   
                    bobEaten[val] = true;
                    bob += val;
                }
                turn = 1 - turn;
            }
        }
        
        if(alex > bob)
            cout << "Alex" << "\n";
        else
            cout << "Bob" << "\n";
    }
    
    return 0;
}