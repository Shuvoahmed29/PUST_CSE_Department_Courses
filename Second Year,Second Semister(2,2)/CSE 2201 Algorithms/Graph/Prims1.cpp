#include<bits/stdc++.h>
using namespace std;
void code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
const int N = 1e5+9;
vector<vector<int>> graph[N];
const int INF = 1e9+9;
bool ok[N];
vector<int>dist(N),parent(N);
int prims(int src,int n){
	int total = 0;
	for(int i=0;i<n;i++){
		dist[i] = INF;
	}
	dist[src] = 0;
	set<pair<int,int>> st;
	st.insert({0,src});// wt,vertex
	cout << "Connected Edges!\n";
	while(!st.empty()){
		auto x = *st.begin();
		st.erase(x);
		int wt = x.first;
		int u = x.second;
		int v = parent[u];
		ok[u] = true;
		total += wt;
		cout << u << " " << v << " " << wt << endl;
		for(auto it:graph[u]){
			int v1 = it[0];
			int w = it[1];
			if(ok[v1] == true) continue;
			if(dist[v1]>w){
				st.erase({dist[v1],v1});
				dist[v1] = w;
				st.insert({dist[v1],v1});
				parent[v1] = u;
			}
		}
	}
	return total;
}
int main(){
	code();
	int n,m;	cin >> n >> m;
	for(int i=0;i<m;i++){
		int v1,v2,wt;	cin >> v1 >> v2 >> wt;
		graph[v1].push_back({v2,wt});
		graph[v2].push_back({v1,wt});
	}
	int cost = prims(0,n);
	cout << "\nTotal cost: " << cost << endl;
}
