#include<bits/stdc++.h>
using namespace std;
void solve(string str,vector<string> &vec,int idx){
	if(idx>=str.size()){
		vec.push_back(str);
		return;
	}
	for(int i=idx;i<str.size();i++){
		swap(str[idx],str[i]);
		solve(str,vec,idx+1);
		swap(str[idx],str[i]);
	}
}
int main(){
	string str;	cin >> str;
	int idx = 0;
	vector<string> vec;
	solve(str,vec,idx);
	for(auto it:vec){
		cout << it << " ";
	}
	cout <<"\nTotal Permutation: "<< vec.size() << endl;
}
