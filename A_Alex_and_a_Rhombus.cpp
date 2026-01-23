#include<bits/stdc++.h>
using namespace std;
int rhombus(int n){
	if (n == 1){
		return 1;
	}else{
		return 4*(n-1) + rhombus(n-1);
	}
}
int dprhombus(int n){
	vector<int> dp(n + 1, 0);
	dp[1] = 1;
	for (int i = 2; i <= n; i++){
		dp[i] = dp[i - 1] + 4*(i - 1);
	}
	return dp[n];
}
int main(){
	int n;
	cin >> n;
	// cout << 1+ 2*n*(n - 1) << endl;

	// cout << rhombus(n);

	// cout << dprhombus(n);
	return 0;
}