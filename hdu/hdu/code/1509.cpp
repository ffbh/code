#include <iostream>
#include <string>
#include <fstream>
#include<queue>
using namespace std;
struct MSG{
	string msg;
	int prame;
	int prior;
	int index;
	bool operator<(const MSG& m)const{
		if (prior != m.prior)
			return prior>m.prior; 
		return index > m.index;
	}
};



int main(){
	//ifstream in("C:\\temp.txt");
	int cnt = 0;
	string s;
	MSG mm;
	priority_queue<MSG> pm;
	while (cin >> s){
		if (s == "PUT"){
			cin >> mm.msg;
			//in >> mm.prame >> mm.prior;
			scanf("%d%d", &mm.prame, &mm.prior);
			mm.index = cnt++;
			pm.push(mm);
		}
		else{
			if (!pm.empty()){
				mm = pm.top();
				pm.pop();
				printf("%s %d\n", mm.msg.c_str(), mm.prame);
			}
			else
				printf("EMPTY QUEUE!\n");
		}
	
	}


	return 0;
}