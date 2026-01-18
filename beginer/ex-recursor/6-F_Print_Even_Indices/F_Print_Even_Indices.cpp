#include<bits/stdc++.h>
using namespace std;
void evenIndice(vector<int> & a, int index){
	if (index >= a.size()) return;
	evenIndice(a, index + 2);
	cout << a[index] << " ";
}
int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	evenIndice(a, 0);
	return 0;
}