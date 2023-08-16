#include<bits/stdc++.h>
using namespace std;
void code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
#define v 4
int TSP(int graph[v][v],int src,vector<int>&vec){
	vector<int>vertex,ans;
	for(int i=0;i<v;i++){
		if(i != src) vertex.push_back(i);
	}
	int min_path = INT_MAX;
	do{
		int current_wight = 0;
		int k = src;
		ans.push_back(src);
		for(int i=0;i<vertex.size();i++){
			current_wight += graph[k][vertex[i]];
			k = vertex[i];
			ans.push_back(k);
		}
		current_wight += graph[k][src];
		ans.push_back(src);
		if(min_path>current_wight){
			min_path = min(min_path,current_wight);
			vec = ans;
			ans.clear();
		}
		else ans.clear();
	}while(next_permutation(vertex.begin(),vertex.end()));
	
	return min_path;
}
int main(){
	code();
	int graph[v][v];
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++)
			cin >> graph[i][j];
	}
	int src=0;
	vector<int>vec;
	int cost = TSP(graph,src,vec);
	cout << "Minimum Path is:\n";
	for(auto it:vec){
		cout << it+1 << " ";
	}
	cout << "\nTotal Cost: " << cost << endl;
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