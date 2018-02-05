#include<bits/stdc++.h>
using namespace std;
long long d[100010];
bool visited[100010];
vector <long long> adj[100010];

long dfsUtil(long long v){
		if(visited[v]==true){
			return 0;
		}
		visited[v]=true;
        long long size =1;
		for(long long i=0;i<adj[v].size();i++){
			size+=dfsUtil(adj[v][i]);
		}
		return size;
	}
//dfs function/ the main boss
long long dfs(long long lim,vector<long long> adj[]){
	long long result=0;
	long size=0,sum=0;
	for(long long i=0;i<lim;i++){
		if(!visited[i]){
			size = dfsUtil(i);
			result+=sum*size;
			sum+=size;
		}
	}
	return result;
}

int main(){
	long long n,p,u,v;
	cin>>n>>p;
	memset(d,-1,sizeof(d));
	memset(visited,false,sizeof(visited));
	while(p--){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	long long result=dfs(n,adj);
	cout<<result;

	return 0;
}