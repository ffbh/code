#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
ofstream out("C:\\output.txt");
struct Node{
	int num;
	char c;
}data[10];
int dig[] = { 0, 8, 88, 888, 8888, 88888, 888888, 8888888, 88888888 };
string ddd[] = { "0", "8", "88", "888", "8888", "88888", "888888", "8888888", "88888888" };
int aim;

unordered_map<int, string> M;



//bool DFS(long long pre, int k, int d){
//	/*if (k == 8){
//		string s = "";
//		for (int i = 0; i < d; ++i){
//			if (s.length() != 0)
//				s = '(' + s + ')' + data[i].c + IntToString(data[i].num);
//			else{
//				if (data[i].c == '-')
//					s = data[i].c + IntToString(data[i].num);
//				else
//					s = IntToString(data[i].num);
//			}
//		}
//		out << s+'='+ IntToString(pre) << endl;
//	}*/
//	if (pre == aim && k == 8){
//		string s = "";
//		for (int i = 0; i < d; ++i){
//			if (s.length() != 0)
//				s = '(' + s + ')' + data[i].c + IntToString(data[i].num);
//			else{
//				if (data[i].c == '-')
//					s = data[i].c + IntToString(data[i].num);
//				else
//					s = IntToString(data[i].num);
//			}
//		}
//		cout << s << endl;
//		return 1;
//	}
//	
//	for (int i = k + 1; i <= 8; ++i){
//		if (d != 0){
//			data[d].c = '*';
//			data[d].num = dig[i - k];
//			if (DFS(pre * dig[i - k], i, d + 1))
//				return 1;
//
//			data[d].c = '/';
//			data[d].num = dig[i - k];
//			if (DFS(pre / dig[i - k], i, d + 1))
//				return 1;
//		}
//		data[d].c = '+';
//		data[d].num = dig[i - k];
//		if (DFS(pre + dig[i - k], i, d + 1))
//			return 1;
//
//		data[d].c = '-';
//		data[d].num = dig[i - k];
//		if (DFS(pre - dig[i - k], i, d + 1))
//			return 1;
//	}
//	return 0;
//}

unordered_set<int> vis[10];
//
//void DFS(int pre, int k, int d){
//	if (vis[k].count(pre))
//		return;
//	vis[k].insert(pre);
//	/*if (k == 8){
//	string s = "";
//	for (int i = 0; i < d; ++i){
//	if (s.length() != 0)
//	s = '(' + s + ')' + data[i].c + IntToString(data[i].num);
//	else{
//	if (data[i].c == '-')
//	s = data[i].c + IntToString(data[i].num);
//	else
//	s = IntToString(data[i].num);
//	}
//	}
//	out << s+'='+ IntToString(pre) << endl;
//	}*/
//	if (k == 8){
//		if (M.count(pre))
//			return;
//		string s = "";
//		
//		for (int i = 0; i < d; ++i){
//			if (s.length() != 0)
//				s = '(' + s + ')' + data[i].c + ddd[data[i].num];
//			else{
//				if (data[i].c == '-')
//					s = data[i].c + ddd[data[i].num];
//				else
//					s = ddd[data[i].num];
//			}
//		}
//		M[pre] = s;
//		return;
//	}
//
//	for (int i = k + 1; i <= 8; ++i){
//		if (d != 0){
//			data[d].c = '*';
//			data[d].num = i-k;
//			DFS(pre * dig[i - k], i, d + 1);
//		
//
//			data[d].c = '/';
//			data[d].num = i-k;
//			DFS(pre / dig[i - k], i, d + 1);
//
//			data[d].c = '-';
//			data[d].num = i-k;
//			DFS(pre - dig[i - k], i, d + 1);
//
//		}
//		data[d].c = '+';
//		data[d].num = i-k;
//		DFS(pre + dig[i - k], i, d + 1);
//			
//
//		
//		
//	}
//}



void DFS(int pre, int k, string& s){
	if (vis[k].count(pre))
		return;
	vis[k].insert(pre);
	/*if (k == 8){
	string s = "";
	for (int i = 0; i < d; ++i){
	if (s.length() != 0)
	s = '(' + s + ')' + data[i].c + IntToString(data[i].num);
	else{
	if (data[i].c == '-')
	s = data[i].c + IntToString(data[i].num);
	else
	s = IntToString(data[i].num);
	}
	}
	out << s+'='+ IntToString(pre) << endl;
	}*/
	if (k == 8){
		M[pre] = s;
		return;
	}

	for (int i = k + 1; i <= 8; ++i){
		string tmp;
		if (s.length() != 0){
			tmp = "(" + s + ")" + "*" + ddd[i - k];
			DFS(pre * dig[i - k], i, tmp);

			tmp = "(" + s + ")" + "/" + ddd[i - k];
			DFS(pre / dig[i - k], i, tmp);

			tmp = "(" + s + ")" + "-" + ddd[i - k];
			DFS(pre - dig[i - k], i, tmp);

		}
		if (s.length() == 0){
			tmp = ddd[i - k];
		}
		else{
			tmp = "(" + s + ")" + "+" + ddd[i - k];
		}
		
		DFS(pre + dig[i - k], i, tmp);

	}
}


int main(){
	ifstream in("C:\\input.txt");
	string s="";

	DFS(0, 0, s);

	int k;
	while (scanf("%d", &k)){
		if (M.count(k)){
			printf("%s\n", M[k].c_str());
		
		}
		else{
			printf("Impossible\n");
		}

	}
















	return 0;
}