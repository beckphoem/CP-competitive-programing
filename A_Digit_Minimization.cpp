#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		if (s.size() == 2){
			cout << s[1] << endl;
		}else{
			int minNum = 10;
			for(int i = 0; i < s.size(); i++){
				minNum = min(minNum, s[i] - '0');
			}
			cout << minNum << endl;
		}
	}
	return 0;
}