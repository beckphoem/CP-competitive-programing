#include<bits/stdc++.h>
using namespace std;
int sumNum(int n){
	int sum = 0;
	while(n){
		sum += n % 10;
		n /= 10;
	}
	return sum;
}
int main(){
	int t;
	cin >> t;
	while(t --){
		int n, k;
		cin >> n >> k;
		while (sumNum(n) % k != 0){
			n++;
		}
		cout << n << endl;
	}
	return 0;
}