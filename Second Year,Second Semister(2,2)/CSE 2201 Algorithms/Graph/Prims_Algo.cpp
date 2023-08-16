#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
vector<vector<int>> graph[N];
const int INF = 1e9;
vector<int> dist(N),parent(N);
bool vis[N];
int prims(int src,int n){
	int total = 0;
	for(int i=0;i<n;i++){
		dist[i] = INF;
	}
	set<vector<int>> st;
	dist[src] = 0;
	st.insert({0,src}); // wt,vertex
	cout << "Connected Edges!\n";
	while(!st.empty()){
		auto x = *st.begin();
		st.erase(x);
		int w = x[0];
		int u = x[1];
		int v = parent[u];
		vis[u] = true;
		total += w;
		cout << u << " " << v <<" " << w << endl;
		for(auto it:graph[u]){
			int v = it[0];
			int wt = it[1];
			if(vis[v] == true) continue;
			if(dist[v]>wt){
				st.erase({dist[v],v});
				dist[v] = wt;
				st.insert({dist[v],v});
				parent[v] = u;
			}
		}
	}
	return total;
}
int main(){
	int n,m;	cin >> n >> m;
	for(int i=0;i<m;i++){
		int v1,v2,wt;	cin >> v1 >> v2 >> wt;
		graph[v1].push_back({v2,wt});
		graph[v2].push_back({v1,wt});
	}
	int cost = prims(0,n);
	cout << "Total Cost: " << cost << endl;
}

/*
input:
6 9
0 4 4
4 3 9
0 3 1
0 1 2
3 2 5
2 1 3
3 1 3
1 5 7
2 5 8
output:
Connected Edges!!
0 0 0
3 0 1
1 0 2
2 1 3
4 0 4
5 1 7
Total Cost: 17
*/


/*
input:
4 5
0 1 10
1 2 15
0 2 5
3 1 2
3 2 40
output
Connected Edges!!
0 0 0
2 0 5
1 0 10
3 1 2
Total Cost: 17
*/
