#include<bits/stdc++.h>
using namespace std;
bool fairNum(long long n){
	long long num = n;
	while (num > 0){
		int tail = num % 10;
		if (tail != 0){
			if (n % tail != 0){
				return false;
			}
		}
		num /= 10;
	}
	return true;
}
int main(){
	int t;
	cin >> t;
	while (t--){
		long long n;
		cin >> n;
		while (!fairNum(n)){
			n++;
		}
		cout << n << endl;
	}
	return 0;
}