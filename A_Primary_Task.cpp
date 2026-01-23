#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while (t--){
		
		string s;
		cin >> s;
		if ((s.size() < 3)||(s[0] != '1')||(s[1] != '0')){
			cout << "NO" << endl;
		}else{
			string p_string = s.substr(2, s.size()- 2);
			int num = stoi(p_string);
			if (num < 2){
				cout << "NO" << endl;
			}else{
				if (s[2] == '0'){
					cout << "NO" << endl;
				}else{
					cout << "YES" << endl;
				}
			}
		}

		
	}
	return 0;
}