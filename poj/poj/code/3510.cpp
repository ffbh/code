#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
string src, tran;



int main(){
	ifstream in("C:\\input.txt");
	bool eof = 0;
	while (getline(cin, src)&&!eof){
		tran = "";
		for (int i = 0; i < src.length(); ++i){
			if (src[i] == 'd'&&i + 1 < src.length() && src[i + 1] == 'd'){
				tran += 'p';
				i++;
			}
			else if (src[i] == 'e'&&i + 1<src.length() && src[i + 1] == 'i'&&(i>0&&src[i-1]!='c'||i==0)){
				tran += "ie";
				i++;
			}
			else if (src[i] == 'E'&&i + 2 < src.length() && src[i + 1] == 'O'&&src[i + 2] == 'F'){
				eof = 1;
				break;
			}
			else if (src[i] == 'p'&&i + 3 < src.length() && src[i + 1] == 'i'&&src[i + 2] == 'n'&&src[i + 3] == 'k'){
				tran += "floyd";
				i += 3;
			}
			else if (src[i] >= 'a'&&src[i] <= 'z' ||src[i]==' '){
				tran += src[i];
			}
		}
	/*	for (int i = 0; i < tran.length(); ++i){
			if (i + 3 < tran.length() && tran[i] == 'p'&&tran[i + 1] == 'i'&&tran[i + 2] == 'n'&&tran[i + 3] == 'k'){
				printf("floyd");
				i += 3;
			}
			else{
				putchar(tran[i]);
			}
		
		}	putchar('\n');*/
		
		printf("%s\n", tran.c_str());
	}

	return 0;
}