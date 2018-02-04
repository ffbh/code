#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;
struct Node{
	int day, month, p, daycount;
	string describing;
};
int now_day;

struct PX{
	int day, month, restp, idx, daycount;
	bool operator<(const PX& p)const{

		if (daycount != p.daycount)
			return daycount < p.daycount;
		else{
			if (daycount == now_day){
				return idx < p.idx;
			}
			else if (restp != p.restp){
				return restp > p.restp;
			}
			else
				return idx < p.idx;
		}
	}
};

int year;

vector<Node> data;
vector<PX> ans;
bool leap(){
	return year % 4 == 0;
}

int mm[2][13] = { { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };

int getDayCount(int m, int d){
	int p = leap();
	int sum = 0;
	for (int i = 1; i<m; ++i)
		sum += mm[p][i];
	sum += d;
	return sum;
}


int main(){
	//  ifstream in("C:\\input.txt");
	ofstream ou("C:\\input2.txt");
	istream& in = cin;
	in >> year;
	char code;
	bool b = 0;
	while (in >> code &&code != '#'){
		if (code == 'A'){
			Node tmp;
			in >> tmp.day >> tmp.month >> tmp.p;
			string s;
			getline(in, s);
			int pos = 0;
			while (pos<s.length() && s[pos] == ' ')
				pos++;
			tmp.describing = s.substr(pos);
			tmp.daycount = getDayCount(tmp.month, tmp.day);
			data.push_back(tmp);
		}
		else{
			if (b == 0){
				b = 1;
			}
			else
				cout << endl;
			ans.clear();
			int D, M;
			in >> D >> M;
			int startC = getDayCount(M, D);
			now_day = startC;
			int FullDayCount = getDayCount(12, 31);
			for (int i = 0; i<data.size(); ++i){
				int endC = startC + data[i].p;
				if (endC <= FullDayCount || data[i].month != 1){
					if (data[i].daycount >= startC && data[i].daycount <= endC){
						PX tmp;
						tmp.day = data[i].day;
						tmp.month = data[i].month;
						tmp.daycount = getDayCount(tmp.month, tmp.day);
						tmp.idx = i;
						if (data[i].daycount == startC){
							tmp.restp = data[i].p;
						}
						else
							tmp.restp = data[i].p - (data[i].daycount - startC - 1);
						ans.push_back(tmp);
					}
				}
				else{
					int finalday = endC - FullDayCount;
					if (data[i].day <= finalday){
						PX tmp;
						tmp.day = data[i].day;
						tmp.month = data[i].month;
						tmp.daycount = getDayCount(tmp.month, tmp.day) + FullDayCount;
						tmp.idx = i;
						tmp.restp = data[i].p - (data[i].daycount + FullDayCount - startC - 1);
						ans.push_back(tmp);
					}

				}



			}
			sort(ans.begin(), ans.end());

			printf("Today is:%3d%3d\n", D, M);
			ou << "Today is:";
			ou << setw(3) << D << setw(3) << M << endl;
			for (int i = 0; i<ans.size(); ++i){
				printf("%3d%3d ", ans[i].day, ans[i].month);
				ou << setw(3) << ans[i].day << setw(3) << ans[i].month << " ";
				if (ans[i].day == D&&ans[i].month == M){
					cout << "*TODAY* ";
					ou << "*TODAY* ";
				}
				else{
					for (int j = 0; j<ans[i].restp; ++j){
						cout << '*';
						ou << "*";
					}
					for (int j = 0; j<8 - ans[i].restp; ++j){
						cout << ' ';
						ou << " ";
					}
				}
				cout << data[ans[i].idx].describing << endl;
				ou << data[ans[i].idx].describing << endl;
			}

			ou << endl;



		}

	}



	return 0;
}