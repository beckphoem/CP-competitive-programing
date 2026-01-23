#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while (t--){
		long long n;
		cin >> n;
		long long q;
		if (n % 2050 == 0){
			q = n/2050;
			int sum = 0;
			while (q){
				int num = q%10;
				sum += num;
				q /= 10;
			}
			cout << sum << endl;
		}else{
			cout << - 1 << endl;
		}
	}
	return 0;
}