#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	char s[100];
	int M;
	while (~scanf("%s%d",s,&M)){
		int len = strlen(s);
		M = (M % 8 + 8) % 8;
		if (M == 0 || M == 4){
			if (M == 0){
				for (int j = 0; j < len; ++j)
					putchar(s[j]);
				putchar('\n');
			}
			else{
				for (int j = len-1; j >= 0; --j)
					putchar(s[j]);
				putchar('\n');
			}
		}
		else if (M == 2 || M == 6){
			if (M == 6){
				for (int i = 0; i < len; ++i){
					for (int j = 0; j < len / 2; ++j)
						putchar(' ');
					putchar(s[i]);
					putchar('\n');
				}
			}
			else{
				for (int i = len-1; i >=0; --i){
					for (int j = 0; j < len / 2; ++j)
						putchar(' ');
					putchar(s[i]);
					putchar('\n');
				}
			}
		}
		else if (M == 1 || M == 5){
			int blank = len - 1;
			if (M == 1){
				for (int i = len - 1; i >= 0; --i){
					for (int j = 0; j < blank; ++j)
						putchar(' ');
					putchar(s[i]);
					putchar('\n');
					blank--;
				}
			}
			else{
				for (int i =0; i <len; ++i){
					for (int j = 0; j < blank; ++j)
						putchar(' ');
					putchar(s[i]);
					putchar('\n');
					blank--;
				}
			}
		}
		else{
			int blank = 0;
			if (M == 3){
				for (int i = len - 1; i >= 0; --i){
					for (int j = 0; j < blank; ++j)
						putchar(' ');
					putchar(s[i]);
					putchar('\n');
					blank++;
				}
			}
			else{
				for (int i = 0; i <len; ++i){
					for (int j = 0; j < blank; ++j)
						putchar(' ');
					putchar(s[i]);
					putchar('\n');
					blank++;
				}
			}
		}
	}

	return 0;
}