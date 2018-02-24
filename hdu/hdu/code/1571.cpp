#include <iostream>
#include <string>
#include <fstream>
#include <deque>
using namespace std;
int map[35][35];



int main(){
//	ifstream in("C:\\temp.txt");
	int N;
	string cmd;
	int id;
	deque<int>::iterator it;
	while (cin >> N&&N){
		deque<int> car;
		for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			//	in >> map[i][j];
			scanf("%d", &map[i][j]);
		int K;
		cin >> K;
		int pre = 0;
		int ans = 0;
		for (int k = 0; k < K; ++k){
			cin >> cmd;
			if (cmd == "UP"){
				//in >> id;
				scanf("%d", &id);
				if (car.size() < 7&&pre!=id)
					car.push_back(id);
			}
			else if(!car.empty()){
				int aim = car.front();
				car.pop_front();
				ans += map[pre][aim];
				pre = aim;
				while (1){
					it = car.begin();
					while (it != car.end() && *it != aim)
						it++;
					if (it == car.end())
						break;
					else
						car.erase(it);
				}
			}
		}
		cout << ans << endl;





	}








	return 0;
}