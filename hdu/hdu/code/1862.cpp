#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
struct Stu{
	int num;
	string name;
	int score;
};
Stu data[100010];

bool cmpA(const Stu& s1, const Stu& s2){
	return s1.num < s2.num;
}


bool cmpB(const Stu& s1, const Stu& s2){
	if (s1.name != s2.name)
		return s1.name < s2.name;
	return cmpA(s1, s2);
}

bool cmpC(const Stu& s1, const Stu& s2){
	if (s1.score != s2.score)
		return s1.score < s2.score;
	return cmpA(s1, s2);
}




int main(){
	ifstream in("C:\\temp.txt");
	int N, M;
	int CASE = 1;
	while (cin >> N >> M&&N+M){
		for (int i = 0; i < N; ++i){
			cin >> data[i].num >> data[i].name >> data[i].score;
		}
		if (M == 1)
			sort(data, data + N, cmpA);
		else if (M == 2)
			sort(data, data + N, cmpB);
		else
			sort(data, data + N, cmpC);
		printf("Case %d:\n", CASE++);
		for (int i = 0; i < N; ++i)
			printf("%06d %s %d\n", data[i].num, data[i].name.c_str(), data[i].score);

	}

	return 0;
}