#include<bits/stdc++.h>
using namespace std;
const long long N = 1e5+10;
long long INF = 1e12+7;
vector<pair<long long,long long> > graph[N];
 
void dijkstra(long long src, long long n){
    vector<long long>visited(N,0);
    vector<long long>distance(N,INF),parent(n+1);
    distance[src] = 0;
    set<pair<long long,long long> > st;
    st.insert({0,src});
    while(st.size() > 0){
        auto node = *st.begin();
        long long v = node.second;
        long long dist = node.first;
        st.erase(st.begin());
        if(visited[v]==1) continue;
        visited[v] = 1;
        for(auto child : graph[v]){
            long long child_v = child.first;
            long long wt = child.second;
            if(wt+distance[v] < distance[child_v]){
                distance[child_v] = distance[v] + wt;
                st.insert({distance[child_v],child_v});
                parent[child_v] = v;
            }
        }
    }
    if(distance[n] == INF) cout << -1 << endl;
    else{
        vector<long long>path;
        long long node = n;
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        reverse(path.begin(),path.end());
        for(auto ans:path)
            cout << ans << " ";
        cout << endl;
    }
}
int main(){
    long long n,m;  cin >> n >> m;
    for(long long i = 0; i < m; ++i){
        long long v1,v2,w; cin >> v1 >> v2 >> w;
        graph[v1].push_back({v2,w});
        graph[v2].push_back({v1,w});
    }
    dijkstra(1,n);
}