#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e7 + 1;
int main(){
    vector<int> omega(MAXN, 0);
    for(int i = 2; i < MAXN; i++){
        if(omega[i] == 0){ 
            for(int j = i; j < MAXN; j += i){
                omega[j]++;
            }
        }
    }
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        printf("%d\n", 1 << omega[n]);
    }
    return 0;
}