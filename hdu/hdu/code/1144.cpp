#include <iostream>
#include <string>
#include <fstream>
#include <set>
using namespace std;

int main(){
	//ifstream in("C:\\temp.txt");
	set<string> si;
	int N, M;
	while (cin >> N&&N){
		si.clear();
		cin >> M;
		for (int i = 0; i < N; ++i){
			string s;
			cin >> s;
			si.insert(s);
		}
		bool flag = 1;
		for (int i = 0; i < M; ++i){
			int n, need;
			int num = 0;
			scanf("%d%d", &n, &need);
			//in >> n >> need;
			for (int j = 0; j < n; ++j){
				string s;
				cin >> s;
				if (flag&&si.count(s))
					num++;
			}
			if (num < need)
				flag = 0;
		}
		if (flag)
			cout << "yes" << endl;
		else
			cout << "no" << endl;


	}
		 
	return 0;
}