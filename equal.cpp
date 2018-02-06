#include<bits/stdc++.h>
using namespace std;
int operations(int n){
	int result=0;
	result += n/5;
	n=n%5;
	result += n/2;
	n=n%2;
	result += n;
	return result;
}
int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int small = INT_MAX,input;
		vector <int> ar;
		for(int i=0;i<n;i++){
			cin>>input;
			ar.push_back(input);
			small = (input<small)?input:small;
		}
		int answer = INT_MAX;
		for(int i=0;i<4;i++){
			int minOps = 0;
			for (int j = 0; j < n; ++j)
			{
				minOps += operations(ar[j]-small+i);
			}
			if(minOps<answer){
				answer = minOps;
			}
		}
		cout<<answer<<endl;
	}
	return 0;
}