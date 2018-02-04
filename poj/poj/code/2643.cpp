#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;


int main(){
	//	ifstream in("C:\\input.txt");
	int N, M;
	map<string, string> ans;
	map<string, int> vote;
	cin >> N;
	string s1, s2;
	cin.get();
	while (N--){
		getline(cin, s1);
		getline(cin, s2);
		ans[s1] = s2;
		vote[s1] = 0;
	}
	cin >> M;
	cin.get();
	while (M--){
		getline(cin, s1);
		if (vote.count(s1))
			vote[s1]++;
	}
	map<string, int>::iterator it = vote.begin();
	int max = 0;
	bool f = 0;
	while (it != vote.end()){
		if (it->second > max){
			max = it->second;
			s1 = it->first;
			f = 1;
		}
		else if (it->second == max)
			f = 0;
		++it;
	}
	if (f)
		cout << ans[s1] << endl;
	else
		cout << "tie" << endl;



	return 0;
}