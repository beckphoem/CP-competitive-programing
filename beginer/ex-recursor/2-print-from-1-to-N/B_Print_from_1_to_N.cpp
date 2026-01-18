#include<bits/stdc++.h>
using namespace std;
void printN(int n){
	if (n == 1) {
		cout << n << endl;
	}else {
		printN(n- 1);
		cout << n << endl;
	}

}
int main(){
	int n;
	cin >> n;
	printN(n);

	return 0;
}