#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;

	while (t --){
		int n;
		cin >> n;
		if (n % 7 == 0){
			cout << n << endl;
		}else{
			int l,  r;
			l = (n/10) * 10;
			r = l + 9;
			for (int i = l; i <= r; i++){
				if (i % 7 == 0){
					cout << i << endl;
					break;
				}
			}	
		}

	}
	return 0;
}