#include<bits/stdc++.h>
using namespace std;
void code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
int main(){
	code();
	int tt;	cin >> tt;
	double fact[26+2];
	fact[0] = fact[1] = 1;
	for(int i=2;i<=26;i++) fact[i] = i*fact[i-1];
	while(tt--){
		string str;	cin >> str;
		double n;	cin >> n;
		n--;
		double total = fact[str.size()];
		string ans = "";
		for(int i=0;i<str.size();i++){
			total = total/(i+1);
			int idx = n/total;
			n = fmod(n,total);
			ans.insert(ans.begin()+idx,str[i]);
		}
		cout << ans << endl;
	}
}