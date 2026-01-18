#include<bits/stdc++.h>
using namespace std;
void printN(int n){
	if ( n / 10 == 0) {
		cout << n << " "; 
	}else{
		printN(n/10);
		cout << n % 10 << " ";
	}
	
}
int main(){
	int t;
	cin >> t;
	while (t --){
		int n ;
		cin >> n;
		printN(n);
		cout << endl;
	}
	return 0;
}