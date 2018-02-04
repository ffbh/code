#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;
struct People{
	string name;
	int score;
	bool operator<(const People& p)const{
		if (score != p.score)
			return score < p.score;
		return name > p.name;
	}
};
int grade[20];
int main(){
//	ifstream in("C:\\temp.txt");
	int N, M, G;
	string s;
	int K, sum;
	while (cin >> N >> M >> G){
		if (N == 0)break;
		priority_queue<People> ppp;
		for (int i = 1; i <= M; ++i)
			//in >> grade[i];
			scanf("%d", &grade[i]);

		for (int i = 0; i < N; ++i){
			People p;
			cin >> s;
			//in>>K;
			scanf("%d", &K);
			sum = 0;
			int t;
			for (int k = 0; k < K; ++k){
				//in >> t;
				scanf("%d", &t);
				sum += grade[t];
			}
			if (sum >= G){
				p.name = s;
				p.score = sum;
				ppp.push(p);
			}
		}//for
		cout << ppp.size() << endl;
		while (!ppp.empty()){
			People p = ppp.top();
			ppp.pop();
			cout << p.name << " " << p.score << endl;
		}
	
	}//while




	return 0;
}