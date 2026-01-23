#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while (t--){
		int k;
		cin >> k;
		int index = 0;
		int num = 1;
		while(index < k){
			if (((num % 3 != 0) && (num % 10 !=3))){
				index ++;
			}
			if (index == k){
				cout << num << endl;
			}
			num ++;
		}
	}
	return 0;
}