#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int INF = 1e9+10;
vector<pair<int,int>> graph[N];
void dijkstra(int source, int vertex){
    vector<int> distance(N,INF);
    vector<int> visited(N,0);
    set<pair<int,int>> st;
    st.insert({0,source});
    distance[source] = 0;
    while(st.size()>0){
        auto node = *st.begin();
        int v = node.second;
        int dist = node.first;
        st.erase(st.begin());
        if(visited[v] == 1) continue;
        visited[v] = 1;
        for(auto child: graph[v]){
            int child_v = child.first;
            int wt = child.second;
            if(wt+distance[v] < distance[child_v]){
                distance[child_v] = wt+distance[v];
                st.insert({distance[child_v],child_v});
            }
        }
    }
    cout << "DISTANCE\n";
    for(int i = 0; i < vertex; ++i){
        cout << i <<" : "<< distance[i] <<endl;
    }
}
int main(){
    int vertex,edges;
    cin >> vertex >> edges;
    for(int i = 0; i < edges; ++i){
        int v1,v2,wt;
        cin >> v1 >> v2 >> wt;
        graph[v1].push_back({v2,wt});
        graph[v2].push_back({v1,wt});
    }
    dijkstra(0,vertex);
}