#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
struct Map{
	string s1, s2;
};
Map map[100010];
int data1[100010];
int data2[100010];
int size;
bool cmp1(int m1, int m2){
	return map[m1].s1 < map[m2].s1;
}

bool cmp2(int m1, int m2){
	return map[m1].s2 < map[m2].s2;
}
int bs1(const string& s){
	int low = 0;
	int high = size - 1;
	int mid;
	while (low <= high){
		mid = (low + high) / 2;
		if (map[data1[mid]].s1 == s)
			return data1[mid];
		else if (map[data1[mid]].s1 < s)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}

int bs2(const string& s){
	int low = 0;
	int high = size - 1;
	int mid;
	while (low <= high){
		mid = (low + high) / 2;
		if (map[data2[mid]].s2 == s)
			return data2[mid];
		else if (map[data2[mid]].s2 < s)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}


int main(){
	//    ifstream in("C:\\temp.txt");
	size = 0;
	for (int i = 0; i < 100010; ++i)
		data1[i] = data2[i] = i;

	while (cin >> map[size].s1&&map[size].s1 != "@END@"){
		cin.get();
		getline(cin, map[size].s2);
		map[size].s1 = map[size].s1.substr(1, map[size].s1.length() - 2);
		size++;
	}
	sort(data1, data1 + size, cmp1);
	sort(data2, data2 + size, cmp2);
	int N;
	cin >> N;
	cin.get();
	while (N--){
		string s;
		getline(cin, s);
		if (s[0] == '['){
			s = s.substr(1, s.length() - 2);
			int ans = bs1(s);
			if (ans >= 0)
				cout << map[ans].s2 << endl;
			else
				cout << "what?" << endl;
		}
		else{
			int ans = bs2(s);
			if (ans >= 0)
				cout << map[ans].s1 << endl;
			else
				cout << "what?" << endl;
		}
	}
	return 0;
}