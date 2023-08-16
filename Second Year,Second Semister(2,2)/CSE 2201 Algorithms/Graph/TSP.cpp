#include<bits/stdc++.h>
using namespace std;
void code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
int cost = 0,graph[4][4],visited[4];
int cunt=0;
int p=0;
vector<int>vec,v1;
void takeInput(){
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++)
            cin >> graph[i][j];
    }
}
int find_next_node(int node){
    int nd,Min = INT_MAX,min_index,democost,i;
    for(i=1;i<=4;i++){
        if(visited[i]==0 && graph[node][i]!=0 && graph[node][i]<Min){
            democost = graph[node][i];
            Min = graph[node][i];
            min_index = i;
        }
    }
    nd = min_index;
    cost += democost;
    return nd;
}
void TSP(int node){
    int next_node;
    visited[node] = 1;
    cout << node << " ";
    v1.push_back(cost);
    vec.push_back(node);
    next_node = find_next_node(node);
    if(vec.size()==4){
        cout << 1 << endl;
        p = graph[1][vec[vec.size()-1]];
        return;
    }
    TSP(next_node);
    cout << "\nTotal Cost: " << v1[v1.size()-1]+p << endl;
}
int32_t main(){
    code();
    takeInput();
    for(int i=1;i<=4;i++) visited[i] = 0;
    int start; cin >> start;
    cout << "TSP path: ";
    TSP(start);

}
/*
0 4 1 3
4 0 2 1
1 2 0 5
3 1 5 0
cost: 7(1-3-2-4-1)

0 5 7 3
2 0 4 2
5 2 0 3
4 2 3 0
Cost:10(1-4-3-2-1)
*/
