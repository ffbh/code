#include <iostream>
#include <string>
//#include <fstream>
using namespace std;
struct node{
	bool ok;
	int left, right;
};
int size;
node num[100010];


bool Insert(const string& s){
	int len = s.length();
	int index = 0;
	for (int i = 0; i < len; ++i)
		if (s[i] == '0'){
			if (num[index].left == -1)
				num[index].left = size++;
			index = num[index].left;
			if (num[index].ok)return 0;
		}
		else{
			if (num[index].right == -1)
				num[index].right = size++;
			index = num[index].right;
			if (num[index].ok)return 0;
		}
		num[index].ok = 1;
		return num[index].left == -1 && num[index].right == -1;
}


int main(){
	//ifstream in("C:\\temp.txt");
	string s;
	int root;
	int CASE = 1;
	while (cin >> s){
		memset(num, -1, sizeof(num));
		for (int i = 0; i < 100010; ++i)
			num[i].ok = 0;
		size = 0;
		root = size++;
		Insert(s);
		int ans = 1;
		while (cin >> s&&s != "9"){
			if (ans)
			if (Insert(s) == 0)
				ans = 0;
		}
		if (ans)printf("Set %d is immediately decodable\n", CASE++);
		else
			printf("Set %d is not immediately decodable\n", CASE++);
	}

	return 0;
}