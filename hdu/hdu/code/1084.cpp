#include <iostream>
//#include <fstream>
#include <algorithm>
using namespace std;
struct time{
	int pro;
	int h, m, s;
	int index;
	int score;
	bool operator<(const time&t)const{
		if (pro != t.pro)
			return pro>t.pro;
		else if (h != t.h)
			return h < t.h;
		else if (m != t.m)
			return m < t.m;
		else
			return s < t.s;
	}
};
time stu[101];
bool cmp(const time& t1, const time&t2){
	return t1.index < t2.index;
}
int fun(int n){
	if (n == 1)return 1;
	return n / 2;

}
int main(){
	//ifstream in("C:\\temp.txt");
	int N;
	int slove[6];
	int score[6][2] = { 50, 50, 60, 65, 70, 75, 80, 85, 90, 95, 100, 100 };
	int nnn = 0;
	while (cin >> N){
		if (nnn == 1)
			cout << endl;
		nnn = 1;
		memset(stu, 0, sizeof(stu));
		memset(slove, 0, sizeof(slove));
		for (int i = 0; i < N; ++i){
			scanf("%d %d:%d:%d", &stu[i].pro, &stu[i].h, &stu[i].m, &stu[i].s);
			slove[stu[i].pro]++;
			stu[i].index = i;
		}
		sort(stu, stu + N);
		int index = 0;
		for (int i = 5; i >= 0; --i)
		for (int j = 1; j <= slove[i]; ++j){
			if (j <= fun(slove[i]))
				stu[index++].score = score[i][1];
			else
				stu[index++].score = score[i][0];
		}
		sort(stu, stu + N, cmp);
		for (int i = 0; i < N; ++i)
			printf("%d\n", stu[i].score);

	}


	return 0;
}