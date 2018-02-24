#include <iostream>
//#include <fstream>
#include <set>
using namespace std;
int M, N;
int user[100010];
set<int> preson[1010];



int main(){
	//ifstream in("C:\\temp.txt");
	set<int>::iterator it;
	int C;
	int u,b;
	char cmd;
	while (cin >> N >> M){/////
		for (int i = 0; i <= N; ++i)
			preson[i].clear();
		memset(user, 0, sizeof(user));
		cin >> C;//////
		for (int k = 0; k < C; ++k){
		//	in >> cmd;///////
			while ((cmd = getchar()) == '\n');
			if (cmd == 'B'){
				//in >> u >> b;///////
				scanf("%d%d", &u, &b);
				if (user[b] == 0){
					if (preson[u].size() < 9){
						user[b] = u;
						preson[u].insert(b);
						printf("Borrow success\n");
					}
					else
						printf("You are not allowed to borrow any more\n");
				}
				else
					printf("The book is not in the library now\n");
			}
			else if (cmd == 'R'){
			//	in >> b;/////////
				scanf("%d", &b);
				if (user[b] == 0)
					printf("The book is already in the library\n");
				else{
					int uuser = user[b];
					it = preson[uuser].find(b);
					preson[uuser].erase(it);
					user[b] = 0;
					printf("Return success\n");
				}
			}
			else{
			//	in >> u;///////
				scanf("%d", &u);
				int size = preson[u].size();
				if (size == 0)
					printf("Empty\n");
				else{
					it = preson[u].begin();
					for (int i = 0; i < size - 1; ++i)
						printf("%d ", *it++);
					printf("%d\n", *it);
				}
			}
		}
		printf("\n");
	}

	return 0;
}