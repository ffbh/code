#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
struct Node{
	int index;
	string name;
	int score;
	bool operator<(const Node& p)const{
		if (score != p.score)
			return score>p.score;
		return index < p.index;
	}
};
Node data[310];
Node temp[310];

int main(){
//	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N){
		for (int i = 0; i < N; ++i){
			cin >> data[i].name >> data[i].score;
			data[i].index = i;
		}
		for (int i = 0; i < N; ++i){
			cin >> temp[i].name >> temp[i].score;
		}
		sort(data, data + N);
		bool eflag = 0;
		bool sflag = 0;
		for (int i = 0; i < N;++i)
		if (data[i].score != temp[i].score){
			eflag = 1;
			break;
		}
		else if (data[i].name != temp[i].name){
			sflag = 1;
		}
		if (!eflag&&!sflag)
			cout << "Right" << endl;
		else{
			if (eflag)
				cout << "Error" << endl;
			else
				cout << "Not Stable" << endl;
			for (int i = 0; i < N; ++i)
				printf("%s %d\n", data[i].name.c_str(), data[i].score);
		}
	}
	return 0;
}