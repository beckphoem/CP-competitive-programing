#include<bits/stdc++.h>
using namespace std;
bool checkNum(int n){
	const int a[] = {4, 7,44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 777};
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++){
		if (n % a[i] == 0){
			return true;
		}
	}
	return false;
}
int main(){
	int n;
	cin >> n;
	if (checkNum(n)){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
	return 0;
}