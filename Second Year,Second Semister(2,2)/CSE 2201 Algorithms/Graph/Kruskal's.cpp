#include<bits/stdc++.h>
using namespace std;
void code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
const int N = 1e5+9;;
int parent[N],sz[N];
void make(int i){
	parent[i] = i;
	sz[i] = 1;
}
int find(int v){
	if(parent[v] == v) return parent[v];
	return parent[v] = find(parent[v]);
}
void Union(int v1,int v2){
	v1 = find(v1);
	v2 = find(v2);
	if(v1 != v2){
		if(sz[v1] < sz[v2]) swap(v1,v2);
		parent[v2] = v1;
		sz[v1] += sz[v2];
	}
}
int main(){
	code();
	vector<pair<int,pair<int,int>>> garph;
	int n,m;	cin >> n >> m;
	for(int i=0;i<m;i++){
		int v1,v2,wt;	cin >> v1 >> v2 >> wt;
		garph.push_back({wt,{v1,v2}});
	}
	sort(garph.begin(),garph.end());
	for(int i=1;i<=n;i++) make(i);
	int total_cost = 0;
	cout << "Connected Edges!\n";
	for(auto it:garph){
		int wt = it.first;
		int v1 = it.second.first;
		int v2 = it.second.second;
		if(find(v1) == find(v2)) continue;
		Union(v1,v2);
		total_cost += wt;
		cout << v1 << " " << v2 << endl;
	}
	cout <<"Total Cost: "<< total_cost << endl;
}
