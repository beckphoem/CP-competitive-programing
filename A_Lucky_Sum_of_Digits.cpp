// #include<bits/stdc++.h>
// using namespace std;
// int main(){
// 	int n;
// 	cin >> n;
// 	int four, seven ;
// 	seven = n/7;
// 	four = (n % 7) / 4;
// 	while( (seven * 7 + four * 4 != n) && (seven >= 0) ){
// 		seven --;
// 		int remainder = n - seven * 7;
// 		four = remainder / 4;
// 	}
// 	if (seven >= 0){
// 		for (int i = 0; i< four; i++){
// 			cout << 4;
// 		}
// 		for (int i = 0; i < seven; i++){
// 			cout << 7;
// 		}
// 	}else{
// 		cout << -1;
// 	}
// 	return 0;
// }


#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int seven = n/7;
	int four = (n % 7) / 4;
	while ( (seven * 7 + four * 4 != n) && (seven >= 0)){
		seven --;
		int remainder = n - (seven * 7);
		four = remainder / 4;
	}
	if (seven >= 0){
		for (int i = 0; i < four; i++){
			cout << 4;
		}
		for (int i = 0; i < seven ;i ++){
			cout << 7;
		}
	}else{
		cout << - 1;
	}
	return 0;
}