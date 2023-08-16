#include<bits/stdc++.h>
using namespace std;
void code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
#define n 4
int TSP(int graph[n][n],int src,vector<int> &ans){
	vector<int> vertex,vec;
	for(int i=0;i<n;i++){
		if(src != i)	vertex.push_back(i);
	}
	int min_cost = INT_MAX;
	do{
		int current_weight = 0;
		int k = src;
		vec.push_back(src);
		for(int i=0;i<vertex.size();i++){
			current_weight += graph[k][vertex[i]];
			k = vertex[i];
			vec.push_back(k);
		}
		current_weight  += graph[k][src];
		vec.push_back(src);
		if(min_cost>current_weight){
			min_cost = current_weight;
			ans = vec;
			vec.clear();
		}
		else vec.clear();
	}while(next_permutation(vertex.begin(),vertex.end()));
	return min_cost;
}
int main(){
	code();
	int graph[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cin >> graph[i][j];
	}
	vector<int> ans;
	int cost = TSP(graph,0,ans);
	cout << "Connected Edges!\n";
	for(auto it:ans){
		cout << it+1 << " ";
	}
	cout << "\n\nTotal Cost: " << cost << endl;
}
