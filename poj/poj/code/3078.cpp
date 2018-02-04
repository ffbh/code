#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string ans[30];
int index[30];
int N, M;

int main(){
//	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		cin >> N >> M;
		for (int i = 1; i <= N; ++i){
			cin >> ans[i];
			index[i] = i;
		}
		while (M--){
			int a, b;
			cin >> a >> b;
			for (int i = 1; i <= N;++i)
			if (a == index[i]){
				a = i;
				break;
			}
			if (a > b){
				string tmp = ans[a];
				int t = index[a];
				for (int i = a; i > b; i--){
					ans[i] = ans[i - 1];
					index[i] = index[i - 1];
				}
				ans[b] = tmp;
				index[b] = t;
			}
			else{
				string tmp = ans[a];
				int t = index[a];
				for (int i = a; i <= b; ++i){
					ans[i] = ans[i + 1];
					index[i] = index[i + 1];
				}
				ans[b] = tmp;
				index[b] = t;
			}
			
		}
		for (int i = 1; i < N; ++i)
			cout << ans[i] << " ";
		cout <<ans[N] << endl;



	}






	return 0;
}