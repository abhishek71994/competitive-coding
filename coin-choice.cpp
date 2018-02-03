#include <bits/stdc++.h>

using namespace std;

long getWays(long n, vector < long > c){
    // Complete this function
    vector <long> combo(n+1);
    combo[0]=1;
    for(int i=0;i<c.size();i++){
        for(int j=1;j<combo.size();j++){
            if(j>=c[i]){
                combo[j]+=combo[j-c[i]];
            }
        }
    }
    return combo[n];
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<long> c(m);
    for(int c_i = 0; c_i < m; c_i++){
       cin >> c[c_i];
    }
    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
    long ways = getWays(n, c);
    cout<<ways;
    return 0;
}
