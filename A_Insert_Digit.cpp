#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while (t --){
		int n, d;
		cin >> n >> d;
		string s;
		cin >> s;
		for (int i = 0; i < n; i++){
			if (d > s[i] - '0'){
				cout << d;
				for (int j = i; j < n; j++){
					cout << s[j];
				}
				break;
			}else{
				cout << s[i];
				if (i == n - 1){
					cout << d;
				}
			}
		}
		cout << endl;
	}


	return 0;
}