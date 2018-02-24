#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
int main_x, main_y, tail_x, tail_y;
deque<string> vs;
deque<string> tmp;

void rarote(){
	tmp.clear();
	int len = vs[0].length();
	for (int k = 0; k < len; ++k){
		string t = "";
		for (int i = vs.size()-1; i >= 0; --i){
			t += vs[i][k];
			if (t.back() == 'T'){
				t.back() = 'S';
			}
			else if (t.back() == 'S'){
				t.back() = '2';
			}
			else if(isdigit(t.back())){
				t.back() = (t.back() - '0' + 1) % 4 + '0';
			}
			if (i == main_x&&k == main_y){
				vs[i][k] = '1';
				tail_x = k;
				tail_y = t.size() - 1;
			}

		}
		tmp.push_back(t);
	}
}

void getMain(){
	for (int i = 0; i < vs.size(); ++i){
		for (int j = 0; j < vs[i].size(); ++j){
			if (vs[i][j] == 'S'){
				main_x = i;
				main_y = j;
				return;
			}
		}
	}
}

int K;

void resize(deque<string>& p){
	
	int n, m;
	int old_n = vs.size();
	int old_m = vs[0].size();
	if (K == 4){
		int t = 0;
	}
	m = max(tail_y + 1 + old_m - main_y, (int)p[0].size());
	n = max(tail_x  + old_n - main_x,(int)p.size());
	
	int upnum = main_x - tail_x;
	if (upnum > 0){
		n += upnum;
	}
	int leftnum = main_y - tail_y - 1;
	if (leftnum > 0){
	//	m += leftnum;
	}

	if (K == 5){
		int t = 0;
	}

	for (int i = 0; i < upnum; ++i){
		p.push_front("");
	}
	
	while (p.size() < n){
		p.push_back("");
	}
	if (K == 5){
		int t = 0;
	}

	for (int i = 0; i < p.size(); ++i){
		while ((int)p[i].size() < m)
			p[i] += ' ';
		if (leftnum>0){
			string temp(leftnum, ' ');
			p[i] = temp + p[i];
		}
	}
	if (K == 7){
		int t = 0;
	}

	int real_x = tail_x;
	int real_y = tail_y + 1;
	real_x -= main_x ;
	if (upnum > 0)
		real_x += upnum;
	real_y -= main_y;
	if (leftnum > 0){
		real_y += leftnum;
	}
	for (int i = 0; i < vs.size();++i)
	for (int j = 0; j < vs[0].size(); ++j){
		if (vs[i][j]!=' ')
			p[real_x + i][real_y + j] = vs[i][j];
	}
	vs = p;
}
ofstream ou("C:\\input2.txt");

vector<string> ans;
int getRight(int i){
	if (i < 0)
		return 1;
	if (vs[i][0] == 'S' || vs[i][0] == '1' || vs[i][0] == '2')
		return 0;
	else
		return 1;
}

void show(){
	ans.clear();
	int size = vs.size();
	int top = 0;
	for (int i = 0; i < vs[0].size(); ++i){
		if (vs[0][i] == '2' || vs[0][i] == '3'){
			size++;
			top = 1;
			break;
		}
	}
	for (int i = 0; i < size; ++i){
		ans.push_back(string(vs[0].size()*2+1, ' '));
	}
	for (int i = 0; i < vs.size(); ++i){
		int right = getRight(i);
		int preright = getRight(i - 1);
		for (int j = 0; j < vs[i].size(); ++j){
			if (vs[i][j] == '0' || vs[i][j] == 'T'){
				ans[top + i][1 + 2 * j] = '_';
				ans[top + i][2 * j+2] = '|';


			}
			else if (vs[i][j] == '1' || vs[i][j] == 'S'){
				ans[top + i][1 + 2 * j] = '_';
				ans[top + i][2 * j] = '|';
			}
			else if (vs[i][j] == '2'){
				ans[top + i-1][1 + 2 * j] = '_';
				ans[top + i][2 * j] = '|';
			}
			else if (vs[i][j] == '3'){
				ans[top + i-1][1 + 2 * j] = '_';
				ans[top + i][2 * j + 2] = '|';

			}
			else{

			}
		}
	}

	for (int i = 0; i < ans.size(); ++i){
		int pos = ans[i].size() - 1;
		while (ans[i][pos] == ' '){
			pos--;
		}
		pos++;
		cout << ans[i].substr(0,pos) << endl;
		ou << ans[i].substr(0,pos) << endl;
	}
	cout << "^" << endl;
	
	ou << "^" << endl;
}



int main(){
//	ifstream in("C:\\input.txt");
	istream& in = cin;
	
	int N;
	while (in >> N&&N){
		if (N == 1){
			cout << "_|" << endl;
			cout << "^" << endl;
			ou << "_|" << endl;
			ou << "^" << endl;
		}
		else{
			vs.clear();
			vs.push_back("S");
			vs.push_back("T");
		
			for (int i = 2; i < N; ++i){
				K = i;
				getMain();
				if (i == 3){
					int t = 0;
				}
				rarote();
				resize(tmp);
			}
			show();
		}
	}



	return 0;
}