#include<bits/stdc++.h>
using namespace std;
long long numTransform(string &s){
	long long sum = 0;
	for (int i = 0; i < s.size(); i++){
		sum += s[i] - '0';
	}
	return sum;
}
int main(){
	string n;
	cin >> n;
	int res = 0;
	while (n.size() > 1){
		n = to_string(numTransform(n));
		res ++;
	}
	cout << res << endl;
	return 0;
}