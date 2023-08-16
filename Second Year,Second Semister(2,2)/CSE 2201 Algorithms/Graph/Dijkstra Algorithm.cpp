#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int INF = 1e9+10;
vector<pair<int, int> > graph[N];
void dijkstra(int source,int v){
    vector<int> distance(N,INF);
    vector<int> visited(N,0);
    set<pair<int, int> > st;
    st.insert({0,source});
    distance[source] = 0;
    while(st.size() > 0){
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
    printf("Vertex \tDistance from Source\n");  
    for (int i = 0; i < v; ++i)
        printf("%d \t\t %d\n", i, distance[i]); 
}
int main(){
    int v,e;    cin >> v >> e;
    for(int i = 0; i < e; i++){
        int v1,v2,wt;   cin >> v1 >> v2 >> wt;
        graph[v1].push_back({v2,wt});
        graph[v2].push_back({v1,wt});
    }
    dijkstra(0,v);
}
/*
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
*/