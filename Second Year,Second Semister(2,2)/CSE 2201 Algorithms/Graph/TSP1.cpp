#include<bits/stdc++.h>
using namespace std;
void code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
#define V 4
int TSP(int graph[][V], int s){
    vector<int> vertex;
    for (int i = 0; i < V; i++){
        if (i != s)
            vertex.push_back(i);
    }
    int min_path = INT_MAX;
    do {
        int current_pathweight = 0;
        int k = s;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];
        min_path = min(min_path, current_pathweight);
 
    } while (next_permutation(vertex.begin(), vertex.end()));
 
    return min_path;
}
int main(){
    code();
    int graph[][V] ={ {0,4,1,3},
                      {4,0,1,1},
                      {1,2,0,5},
                      {3,1,5,0} };

    int s = 0;
    cout << TSP(graph, s) << endl;
}