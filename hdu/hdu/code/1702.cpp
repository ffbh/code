#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <stack>
using namespace std;



int main(){
	//ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	int M;
	string cmd;
	int n;
	while (T--){
		cin >> M >> cmd;
		queue<int> qi;
		stack<int> si;
		if (cmd == "FIFO"){
			while (M--){
				cin >> cmd;
				if (cmd == "IN"){
					cin >> n;
					qi.push(n);
				}
				else{
					if (!qi.empty()){
						printf("%d\n", qi.front());
						qi.pop();
					}
					else
						printf("None\n");
				}
			}
		}
		else{
			while (M--){
				cin >> cmd;
				if (cmd == "IN"){
					cin >> n;
					si.push(n);
				}
				else{
					if (!si.empty()){
						printf("%d\n", si.top());
						si.pop();
					}
					else
						printf("None\n");
				}
			}
		}
	}

	return 0;
}