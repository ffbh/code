#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int T, N;
struct Node{
	int col, row;
	Node(int c,int r){
		col = c;
		row = r;
	}
	void clear(){
		row = col = -1;
	}
	
};
char s[110][210], ans;
vector<pair<Node, Node> >V;
vector<Node> single;

void changeLine(int k,int row){
	for (int i = row; s[k][i];++i)
	if (s[k][i] >= 'a'&&s[k][i] <= 'z')
		s[k][i] -= 32;
}

void changeMutiLine(pair<Node,Node> pnn){
	Node start = pnn.first;
	Node end = pnn.second;
	for (int i = start.col + 1; i < end.col; ++i)
		changeLine(i,0);
	if (start.col == end.col){
		for (int i = start.row; i <= end.row;++i)
		if (s[start.col][i] >= 'a'&&s[start.col][i] <= 'z')
			s[start.col][i] -= 32;
	}
	else{
		for (int i = start.row; s[start.col][i];++i)
		if (s[start.col][i] >= 'a'&&s[start.col][i] <= 'z')
			s[start.col][i] -= 32;
		for (int i = 0; i <= end.row;++i)
		if (s[end.col][i] >= 'a' && s[end.col][i] <= 'z')
			s[end.col][i] -= 32;
	}
}
bool IN2(pair<Node,Node> pnn,int a, int b){
	Node start = pnn.first;
	Node end = pnn.second;
	for (int i = start.col + 1; i < end.col; ++i)
	if (a == i)
		return 1;
	if (start.col == end.col){
		return start.col == a&&b >= start.row&&b <= end.row+1;
	}
	else{
		return a == start.col && b >= start.row ||
			a == end.col&&b <= end.row+1;
	}


}

bool IN(int col,int row){
	for (int i = 0; i < V.size(); ++i){
		if (IN2(V[i], col, row))
			return 1;
	}
	return 0;

}

int main(){
	ifstream in("C:\\input.txt");
	cin >> T;
	while (T--){
		V.clear();
		single.clear();
		ans = 0;
		cin >> N;
		getchar();
		for (int i = 1; i <= N; ++i)
			gets(s[i]);
		Node start(-1, -1), end(-1, -1);
		bool singlecomment;
		for (int i = 1; i <= N; ++i){
			singlecomment = 0;
			for (int j = 0; s[i][j]; ++j){
				if (s[i][j] == '/' && s[i][j + 1] == '/'){
					if (start.col == -1){
						
						break;
					}
					else{
						singlecomment = 1;
					}
					j++;
				}

				else if (!singlecomment && s[i][j] == '/' && s[i][j + 1] == '*'){
					if (start.col == -1){
						start.col = i;
						start.row = j;
						j++;
					}
					
				}

				else if (s[i][j] == '*' && s[i][j + 1] == '/'){
					if (start.col != -1){
						end.col = i;
						end.row = j;
						V.push_back(make_pair(start, end));
						start.clear();
						j++;
					}
					
				}
			}

		}
		
		for (int i = 1; i <= N; ++i)
		for (int j = 0; s[i][j]; ++j){
			if (s[i][j] == '/'&&s[i][j + 1] == '/'){
				if (!IN(i, j)){
					single.push_back(Node(i, j));
					break;
				}
			}
		}
		for (int i = 0; i < V.size(); ++i){
	//		cout << V[i].first.col << " " << V[i].first.row << "  --->  " << V[i].second.col << " " << V[i].second.row << endl;
			changeMutiLine(V[i]);
		}
	//	cout << endl;
		for (int i = 0; i < single.size(); ++i){
	//		cout << single[i].col << "  " << single[i].row << endl;
			changeLine(single[i].col, single[i].row);
		}
		printf("%d\n", V.size()+single.size());
		for (int i = 1; i <= N; ++i)
			printf("%s\n", s[i]);
		printf("\n");
	}

	return 0;
}