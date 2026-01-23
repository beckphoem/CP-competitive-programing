#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while (t -- ){
		int n;
		cin >> n;
		if (n > 3){
			if (n % 2==0){
				cout << 2<< endl;
			}else{
				cout << 3 << endl;
			}
		}else{
			if (n == 1) cout << 0 << endl;
			if (n == 2)  cout << 1 << endl;
			if (n == 3) cout << 2 << endl;
		}
	}
	return 0;
}