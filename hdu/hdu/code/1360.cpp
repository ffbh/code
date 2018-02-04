#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main(){
	ifstream in("C:\\temp.txt");
	bool word, sentence;
	int error = 0;
	char c;
	word = sentence = 1;
	while ((c = getchar())!=-1){
		if (c == '\n')
			continue;
		if (c == '.' || c == '?' || c == '!'){
			word = sentence = 1;
			continue;
		}
		else if (c == ' ' || c == ',' || c == ':' || c == ';'||c=='-'){
			word = 1;
			continue;
		}
		if (!word){
			if (c >= 'A'&&c <= 'Z')
				error++;
		}
		else{
			word = 0;
		}
		if (sentence){
			sentence = 0;
			if (c >= 'a'&&c <= 'z')
				error++;
		}

	}
	printf("%d\n", error);
	return 0;
}