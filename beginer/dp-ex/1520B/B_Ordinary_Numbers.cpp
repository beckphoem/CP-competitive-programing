#include<bits/stdc++.h>
using namespace std;
int countTheLength(int n){
	int l = 0;
	while (n){
		l++;
		n /= 10;
	}
	return l;
}
	
int theFrist(int n){
	while (n > 9){
		n /= 10;
	}
	return n;
}

int createTheNum(int n, int l){
	int res = 0;
	while (l){
		l--;
		res += n * pow(10, l);
	}
	return res;
}
int main(){
	int t;
	cin >> t;
	while (t --){
		int n;
		cin >> n;
		int l = countTheLength(n);
		int numFrist = theFrist(n);
		int theNum = createTheNum(numFrist, l);
		if (theNum <= n){
			cout << 9*(l-1) + numFrist << endl;
		}else{
			cout << 9*(l-1) + numFrist - 1 << endl;
		}
	}
	return 0;
}