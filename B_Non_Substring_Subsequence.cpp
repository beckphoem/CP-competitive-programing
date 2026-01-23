#include<bits/stdc++.h>
using namespace std;
bool check(string &s, int l, int r){
	for (int i = 0; i < l; i++){
		if (s[i] == s[l]){
			return true;
		}
	}
	for (int i = r + 1; i < s.size(); i++){
		if (s[r] == s[i]){
			return true;
		}
	}

	return false;
}
int main (){
	int t;
	cin >> t;
	while (t --){
		int n, q;
		cin >> n >> q;
		string s;
		cin >> s;
		while (q --){
			int l, r;
			cin >> l >> r;
			if (check(s, l-1, r-1)){
				cout << "YES" << endl;
			}else{
				cout << "NO" << endl;
			}
		}
	}
	
	return 0;
}