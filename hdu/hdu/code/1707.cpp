#include <iostream>
#include <string>
#include <fstream>
#include <set>
using namespace std;
struct Stu{
	bool ok[8][12];
	string name;
	
};
Stu stu[220];
int N;

int main(){
	//ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	set<string> ss;
	while (T--){
		cin >> N;
		memset(stu, 0, sizeof(stu));
		for (int i = 0; i < N; ++i){
			cin >> stu[i].name;
			int M;
			cin >> M;
			for (int j = 0; j < M; ++j){
				int day, b, e;
			//	cin >> day >> b >> e;
				scanf("%d%d%d", &day, &b, &e);
				for (int k = b; k <= e; ++k)
					stu[i].ok[day][k] = 1;
			}

		}
		int K;
		cin >> K;
		while (K--){
			ss.clear();
			int day, b, e;
			//cin >> day >> b >> e;
			scanf("%d%d%d", &day, &b, &e);
			for (int i = 0; i < N;++i)
				for (int k = b; k <= e; ++k)
				if (stu[i].ok[day][k]){
					ss.insert(stu[i].name);
					break;
				}
				if (ss.empty())
					cout << "None" << endl; 
				else{
					bool sign = 0;
					set<string>::iterator it = ss.begin();
					while (it != ss.end()){
						if (sign == 0){
							sign = 1;
							cout << *it;
						}
						else
							cout << " " << *it;
						it++;
					}
					cout << endl;
				}



		}
	}

	return 0;
}