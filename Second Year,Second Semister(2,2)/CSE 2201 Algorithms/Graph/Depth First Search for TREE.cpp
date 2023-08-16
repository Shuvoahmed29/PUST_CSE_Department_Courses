// Depth First Search for TREE
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int>tree[N];

void dfs(int src,int parent){
    cout << src << " ";
    for(auto child:tree[src]){
        if(child==parent) continue;
        dfs(child,src);
    }
}
int main(){
    int n;  cin >> n;
    for(int i=0;i<n-1;i++){
        int v1,v2;  cin >> v1 >> v2;
        tree[v1].push_back(v2);
        tree[v2].push_back(v1);
    }
    dfs(1,0);
}