//Adjacency List Representation
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;
vector<int> graph[N];
vector<pair<int,int>> graph1[N]; // for weighted graph
int main(){
    int n,m;    cin >> n >> m;
    for(int i=0;i<m;i++){
        // int v1,v2;  cin >> v1 >> v2;
        // graph[v1].push_back(v2);
        // graph[v2].push_back(v1);

        //weighted graph
        int v1,v2,wt;   cin >> v1 >> v2 >> wt;
        graph1[v1].push_back({v1,wt});
        graph1[v2].push_back({v1,wt});
    }
    //Unweighted graph 
    // for(int i=0;i<n;i++){
    //     for(auto child:graph[i]){
    //         cout << child << " ";
    //     }
    //     cout << endl;
    // }

    //weighted graph
    for(int i=0;i<n;i++){
        for(auto child:graph1[i]){
            cout << child.first << " " << child.second << endl;
        }
    }

    //Space Complexity O(V+E)
}