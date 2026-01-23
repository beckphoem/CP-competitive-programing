#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while (t --){
		int n;
		cin >> n;
		int size = 1;
		while (n > 9){
			n/=10;
			size++;
		}
		cout << n + (size - 1) * 9 << endl;
	}
	return 0;
}