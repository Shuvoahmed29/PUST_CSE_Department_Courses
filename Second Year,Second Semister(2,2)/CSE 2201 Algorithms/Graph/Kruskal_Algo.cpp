#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
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
    vector<pair <int, pair<int,int>>> graph;
    int n,m;    cin >> n >> m;
    for(int i=0;i<m;i++){
        int v1,v2,wt;  cin >> v1 >> v2 >> wt;
        graph.push_back({wt,{v1,v2}});
    }
    sort(graph.begin(),graph.end());
    for(int i=1;i<=n;i++) make(i);
    int total_cost = 0;
    for(auto it:graph){
        int wt = it.first;
        int v1 = it.second.first;
        int v2 = it.second.second;
        if(find(v1) == find(v2)) continue;
        Union(v1,v2);
        total_cost +=wt;
        cout << v1 << " " << v2 << endl;
    }
    cout << total_cost << endl;
}

/*
input
6 9
1 5 4
5 4 9
1 4 1
1 2 2
4 3 5
3 2 3
4 2 3
2 6 7
3 6 8

Connected Edges are!!
1 4
1 2
3 2
1 5
2 6
Total Cost: 17
*/
