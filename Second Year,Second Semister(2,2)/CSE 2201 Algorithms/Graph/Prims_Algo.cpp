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
bool ok[N];
vector<int> parent(N),dist(N);
const int INF = 1e9;
int Prims(int src,int n){
	int cost = 0;
	for(int i=0;i<n;i++){
		dist[i] = INF;
	}
	set<pair<int,int>> st;
	dist[src] = 0;
	st.insert({src,0});// vtx,wt
	cout << "Connected Edges!\n";
	while(!st.empty()){
		auto x = *st.begin();
		st.erase(x);
		int v1 = x.first;
		int wt = x.second;
		int v2 = parent[v1];
		ok[v1] = true;
		cost += wt;
		cout << v1 << " " << v2 << " " << wt << endl;
		for(auto it:graph[v1]){
			int v = it[0];
			int w = it[1];
			if(ok[v] == true) continue;
			if(dist[v]>w){
				st.erase({v,dist[v]});
				dist[v] = w;
				st.insert({v,dist[v]});
				parent[v] = v1;
			}
		}
	}
	return cost;
}
int main(){
	code();
	int n,m;	cin >> n >> m;
	for(int i=0;i<m;i++){
		int v1,v2,wt;	cin >> v1 >> v2 >> wt;
		graph[v1].push_back({v2,wt});
		graph[v2].push_back({v1,wt});
	}
	int cost = Prims(0,n);
	cout << "Total Cost: "<< cost << endl;
}
