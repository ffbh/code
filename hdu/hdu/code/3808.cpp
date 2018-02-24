#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string data[] = {
	"Yu Jian",
	"Tin O O",
	"I Missed",
	"Stefanie",
	"The Same",
	"About",
	"Honey Honey",
	"Unfinished",
	"Hey Jude",
	"When Winter Fades"
};

int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	printf("Best wishes to Stefanie\n\n");
	while (T--){
		int N;
		cin >> N;
		if (N % 7 == 0){
			printf("DotA Games\n");
			continue;
		}
		else if (N % 7 == 6){
			printf("SanGuoSha\n");
			continue;
		}
		N -= 2 * (N / 7);
		cout << data[(N - 1) % 10] << endl;

	}



	return 0;
}