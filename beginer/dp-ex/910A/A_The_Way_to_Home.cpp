#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, d;
	
	cin >> n >> d;
	string s;
	cin >> s;
	vector<int> dp(s.size(), 999);

	dp[0]= 0;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '1'){
			for (int j = i - 1; (j >= i - d) && (j >= 0); j--){
				if (s[j] == '1'){
						dp[i] = min(dp[i], dp[j] + 1);
					
				}
			}
		}
	}



	if (dp[n - 1] == 999){
		cout << -1 << endl;
	}else{
		cout << dp[n - 1] << endl;
	}
	return 0;
}