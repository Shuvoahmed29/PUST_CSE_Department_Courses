// Depth and Height of TREE
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int>tree[N];
int depth[N],height[N];
void dfs(int src,int parent){
    for(auto child:tree[src]){
        if(child==parent) continue;
        depth[child] = depth[src]+1;
        dfs(child,src);
        height[src] = max(height[src],height[child]+1);
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
    cout << "Depth" << "   " << "Height\n";
    for(int i=1;i<=n;i++){
        cout << depth[i] << "        " << height[i] <<endl;
    }
}