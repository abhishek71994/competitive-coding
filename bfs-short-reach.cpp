#include<bits/stdc++.h>
using namespace std;
int d[1010];
bool vis[1010];
void bfs(int n,vector<int> adj[]){
    queue<int> q;
    q.push(n);
    vis[n]=true;
    d[n]=0;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0;i<adj[x].size();i++){
            if(!vis[adj[x][i]]){
                d[adj[x][i]] = d[x] + 6;
                q.push(adj[x][i]);
                vis[adj[x][i]] = true;
            }
        }
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t,u,v,n,m,s;
    cin>>t;
    while(t>0){
        t--;
        cin>>n>>m;
        vector<int> adj[1010];
        memset(d,-1,sizeof(d));
        memset(vis,false,sizeof(vis));
        while(m--){
            cin>>u>>v;
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }
        cin>>s;
        bfs(s-1,adj);
        for(int i=0;i<n;i++)
            if(i!=s-1) cout<<d[i]<<" ";
        cout<<endl;
    }
    return 0;
}
