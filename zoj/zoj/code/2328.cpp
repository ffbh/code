#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
struct Budget{
	string s;
	int id;
	double x;
	bool operator<(const Budget& p)const{
		if (s != p.s)
			return s < p.s;
		return id < p.id;
	}
	bool operator==(const Budget& p)const{
		return s == p.s&&id == p.id&&x == p.x;
	}
}data[10100], tmp;

bool vis[10100];

int main(){
//	ifstream in("C:\\temp.txt");
	int size;
	string s;
	double amount;
	int id;
	double x;
	cin >> s;
	while (cin >>amount){
		memset(vis, 0, sizeof(vis));
		size = 0;
		while (cin >> s && s[0] != 'b'){
			cin >>id>> x;
			data[size].s = s;
			data[size].id = id;
			data[size].x = x;
			size++;
		}
		double camount, wamount;
		camount =  amount;
		cin >> x >> wamount;
		sort(data, data + size);
		while (cin >> s){
			double e;
			if (s[0] == 'b')
				break;
			tmp.s = s;
			cin >> tmp.id >> tmp.x >> e;
			int index = lower_bound(data, data + size, tmp) - data;
			if (tmp.s[0] == 'c'){
				wamount -= tmp.x;
				camount -= data[index].x;
			}
			else{
				wamount += tmp.x;
				camount += data[index].x;
			}
			printf("%s %d", tmp.s.c_str(), tmp.id);
			if (!vis[index] && data[index] == tmp && e == wamount&&e == camount){
				printf(" is correct\n");
				vis[index] = 1;
				continue;
			}
			else if (data[index].s != tmp.s || data[index].id != tmp.id){
				printf(" is not in statement");
				printf("\n");
				continue;
			}
			if (vis[index])
				printf(" repeated transaction");
			if (tmp.x != data[index].x){
				printf(" incorrect amount");
				if (camount==e)
					printf(" math uses correct value");
			}
			if (wamount != e&&camount!=e)
				printf(" math mistake");
			vis[index] = 1;
			printf("\n");
			wamount = camount = e;
		}
		for (int i = 0; i < size;++i)
		if (!vis[i]){
			printf("missed %s %d\n", data[i].s.c_str(), data[i].id);
		}
	}






	return 0;
}