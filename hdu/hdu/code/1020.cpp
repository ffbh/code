#include <iostream>
#include <string>
using namespace std;

int main(){
	int count;
	string s;
	int length;
	char old;
	int num ;
	int index;
	scanf("%d", &count);
	while (count-- > 0){
		cin >> s;
		old = s[0];
		index = 1;
		num = 1;
		int length = s.size();
		while (index<length){
			if (s[index] == old) num++;
			else {
				if (num!=1)
					printf("%d%c", num, old);
				else 
					printf("%c",  old);
				num = 1;
				old = s[index];
			}
			index++;
		}
		if (num != 1)
				printf("%d%c\n", num, old);
			else
				printf("%c\n", old);
	}
	return 0;
}