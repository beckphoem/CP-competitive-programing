#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int x, r, n;
		cin >> x >> r >> n;
		int res = (n/x)*x + r;
		if (res <= n){
			cout << res << endl;
		}else
			cout << res - x << endl;
	}
	return 0;
}