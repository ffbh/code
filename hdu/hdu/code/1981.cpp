#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string dictonary = "bcdefghijklmnopqrstuvwxyza";


int main(){
	ifstream in("C:\\temp.txt");
	string s;
	int T;
	cin >> T;
	int N, M;
	while (T--){
		cin >> N >> M;
		cin >> s;
		char cmd;
		while (M--){
			int a, b;
			cin >> cmd;
			if (cmd == 'Q'){
			//	cin >> a;
				scanf("%d", &a);
				//cout << s[a - 1] << endl;
				printf("%c\n", s[a - 1]);
			}
			else if (cmd == 'S'){
			//	cin >> a >> b;
				scanf("%d%d", &a, &b);
				if (a > b)
					swap(a, b);
				for (int i = a - 1; i < b; ++i)
					s[i] = dictonary[s[i] - 'a'];
			}
			else{
				//cin >> a >> b;
				scanf("%d%d", &a, &b);
				if (a > b)
					swap(a, b);
				a--;
				b--;
				while (a < b)
					swap(s[a++], s[b--]);
			}
		}
	}
	return 0;
}