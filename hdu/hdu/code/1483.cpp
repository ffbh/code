#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int N, M;
struct Node{
	string text;
	int index;
}data[10010];
int minindex, ans;
bool cmp(Node& p1, Node& p2){
	if (p1.text.length() != p2.text.length())
		return p1.text.length() < p2.text.length();
	return p1.index < p2.index;
}
int STlen[2][30];

void Init(){
	memset(STlen, -1, sizeof(STlen));
	int pre = 0;
	for (int i = 0; i < N; ++i)
	if (data[i].text.length() != pre){
		STlen[1][pre] = i - 1;
		pre = data[i].text.length();
		STlen[0][pre] = i;
	}
	STlen[1][pre] = N - 1;
}
string temp;
void Less(){
	int len = temp.length() - 1;
	int sta, end;
	sta = STlen[0][len];
	end = STlen[1][len];
	if (sta == -1)
		return;
	while (sta <= end){
		int pos1, pos2;
		int num = 0;
		for (pos1 = pos2 = 0; pos1 < len&&pos2<len + 1; ++pos1, ++pos2)
		if (data[sta].text[pos1] == temp[pos2])
			num++;
		else
			pos1--;
		if (num >= len){
			if (data[sta].index < minindex){
				minindex = data[sta].index;
				ans = sta;
			}
			return;
		}
		++sta;
	}
}

void Large(){
	int len = temp.length() + 1;
	int sta, end;
	sta = STlen[0][len];
	end = STlen[1][len];
	if (sta == -1)
		return;
	while (sta <= end){
		int pos1, pos2;
		int num = 0;
		for (pos1 = pos2 = 0; pos1 < len + 1 && pos2<len; ++pos1, ++pos2)
		if (data[sta].text[pos1] == temp[pos2])
			num++;
		else
			pos2--;
		if (num >= len - 1){
			if (data[sta].index < minindex){
				minindex = data[sta].index;
				ans = sta;
			}
			return;
		}
		++sta;
	}
}


void Equal(){
	int len = temp.length();
	int sta, end;
	sta = STlen[0][len];
	end = STlen[1][len];
	if (sta == -1)
		return;
	while (sta <= end){
		int pos1, pos2;
		pos1 = 0;
		pos2 = len - 1;
		while (pos1 < len&&temp[pos1] == data[sta].text[pos1])pos1++;
		while (pos2 >= 0 && temp[pos2] == data[sta].text[pos2])pos2--;
		if (pos2 == pos1 || (pos2 == pos1 + 1 && temp[pos1] == data[sta].text[pos2] && temp[pos2] == data[sta].text[pos1])){
			if (data[sta].index < minindex){
				minindex = data[sta].index;
				ans = sta;
			}
			return;
		}
		++sta;
	}

}

int main(){
	//ifstream in("C:\\temp.txt");
	while (cin >> N){
		for (int i = 0; i < N; ++i){
			cin >> data[i].text;
			data[i].index = i;
		}
		sort(data, data + N, cmp);
		Init();
		cin >> M;
		int sta, end;
		bool flag = 0;
		while (M--){
			minindex = INT_MAX;
			flag = 0;
			cin >> temp;
			int len = temp.length();
			sta = STlen[0][len];
			end = STlen[1][len];
			if (sta != -1){
				while (sta <= end){
					if (data[sta].text == temp){
						flag = 1;
						break;
					}
					sta++;
				}
			}
			if (flag){
				printf("%s is correct\n", temp.c_str());
				continue;
			}
			Less();
			Large();
			Equal();
			if (minindex == INT_MAX)
				printf("%s is unknown\n", temp.c_str());
			else
				printf("%s is a misspelling of %s\n", temp.c_str(), data[ans].text.c_str());
		}
	}
	return 0;
}