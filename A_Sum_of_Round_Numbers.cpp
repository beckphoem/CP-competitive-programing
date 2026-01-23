#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int unit = 1;
		vector<int> a;
		while (n > 0){
			int k = n % 10;
			if (k != 0)
				a.push_back(k * unit);
			n /= 10;
			unit *= 10;
		}
		cout << a.size() << endl;
		for (int i = 0; i < a.size(); i++){
			cout << a[i] << " ";
		}
		cout << endl;
	}
	return 0;
}