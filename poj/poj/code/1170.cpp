#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;
int N, M;
map<int, int> mii;
struct Node{
	int num, price;
}data[10];
int dp[7000];
int D[6];
int HashCode(int* tmp){
	int code = 0;
	for (int i = 1; i <= 5; ++i)
		code = code * 6 + tmp[i];
	return code;
}



int main(){
	ifstream in("C:\\temp.txt");
	while (in >> N){
		mii.clear();
		memset(D, 0, sizeof(D));
		for (int i = 1; i <= N; ++i){
			int code;
			in >>code>> D[i] >> data[i].price;
			mii[code] = i;
		}
		for (int i = 1; i <= N; ++i){
			int tmp[6] = { 0 };
			tmp[i] = data[i].num;




		}
		in >> M;
		while (M--){
			int tmp[6] = { 0 };
			int K, price;
			in >> K;
			while (K--){
				int a, b;
				in >> a >> b;
				tmp[mii[a]] += b;
			}
			in >> price;
		}
		cout << dp[D[1]][D[2]][D[3]][D[4]][D[5]] << endl;
	}
	return 0;
}