#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int sum = 0;
	do {
		sum = 0;
		int num = n;
		while (num > 0){
			sum += num % 10;
			num /= 10;
		}
		n++;
	}while(sum % 4 != 0);
	cout << n << endl;
	return 0;
}