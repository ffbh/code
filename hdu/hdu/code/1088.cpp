#include <iostream>
//#include <fstream>
#include <string>
using namespace std;
int pre;
int main(){
	//ifstream in("C:\\temp.txt");
	string s;
	pre = 0;
	while (cin >> s){
		if (s == "<br>"){
			printf("\n");
			pre = 0;
		}
		else if (s == "<hr>"){
			if (pre != 0)
				printf("\n");
			
			for (int i = 0; i < 8; ++i)
				printf("----------");
			printf("\n");
			pre = 0;
		}
		else{
			int len = s.length();
			if (pre == 0){//特殊情况，单词刚好80个字符长
				cout << s;
				pre = len;
			}
			else if (pre + len+1 <= 80){
				pre += len+1;
				printf(" ");
				cout << s;
			}
			else{
				printf("\n");
				pre = 0;
				cout << s;
				pre += len;	
			}
		}
	
	}
	
		cout << endl;
	return 0;
}