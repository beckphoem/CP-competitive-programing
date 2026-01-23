#include<bits/stdc++.h>
using namespace std;
bool checkNumber(int n){
	vector<bool> a(10, true);
	while (n > 0){
		int num = n%10;
		if (a[num]){
			a[num] = false;
		} else{
			return false;
		}
		n /= 10;
	}
	return true;
}
int main(){
	int l, r;
	cin >> l >> r;
	bool find = false;
	for (int i = l; i <= r; i++){
		if (checkNumber(i)){
			cout << i;
			find = true;
			break;
		}
	}
	if (!find){
		cout << - 1 << endl;
	}

	
	return 0;
}