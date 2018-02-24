#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main(){
//	ifstream in("C:\\temp.txt");
	string s;
	while (getline(cin, s)){
		int flag = 0;
		int len = s.length();
		for (int i = 0; i < len; ++i){
			string temp = s.substr(i, 2);
			if (temp == "¡±" || temp == "¡°")
				flag = (flag + 1) % 2;
			
			if (s[i] == ',')
				printf("£¬");
			else if (s[i] == '.')
				printf("¡£");
			else if (s[i] == '!')
				printf("£¡");
			else if (s[i] == '<'&&s[i] + 1 == '<'){
				printf("¡¶");
				i++;
			}
			else if (s[i] == '>'&&s[i + 1] == '>'){
				printf("¡·");
				i++;
			}
			else if (s[i] == '"')
			{
				if (flag % 2 == 0)
					printf("¡°");
				else
					printf("¡±");
				flag = (flag + 1) % 2;
			}
			else
				cout << s[i];
		}

		cout << endl;
	}



	return 0;
}