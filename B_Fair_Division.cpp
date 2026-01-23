#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int w[n];
		long long sum = 0;
		for (int i = 0; i < n; i++){
			cin >> w[i] ;
			sum += w[i];
		}
		if (sum % 2 != 0) {cout << "NO" << endl;}
		else{
			bool dp[sum + 1] = {false};
		
			dp[0] = true;

			for (int i = 0; i < n; i++){
				for (int j = sum/2; j >= w[i]; j--){
					dp[j] = (dp[j] || dp[j - w[i]]);
				}
			}
			if (dp[sum/2]){
				cout << "YES" << endl;
			}else	
				cout << "NO" << endl;
		}
		
	}
	return 0;
}