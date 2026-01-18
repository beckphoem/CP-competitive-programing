#include<bits/stdc++.h>
using namespace std;
void printN(int n){
	if (n == 1) {
		cout << n;
	}else{
		cout << n << " ";
		printN(n-1);
	}
}
int main(){
	int n;
	cin >> n;
	printN(n);
	return 0;
}