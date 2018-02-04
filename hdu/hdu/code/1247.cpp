#include <iostream>
#include <string>
//#include <fstream>
#include <set>
using namespace std;
const int KK = 30;
string num[50010];
struct node{
	bool v;
	node* next[KK];
};
node* root;
node* MALLOC(){
	node* p = (node*)malloc(sizeof(node));
	p->v = 0;
	for (int i = 0; i < KK; ++i)
		p->next[i] = 0;
	return p;
}

void Insert(const string& s){
	node* p = root;
	int len = s.length();
	for (int i = 0; i < len; ++i){
		if (p->next[s[i] - 'a'] == NULL)
			p->next[s[i] - 'a'] = MALLOC();
		p = p->next[s[i] - 'a'];
	}
	p->v = 1;
}

bool find(const string& s){
	node* p = root;
	int len = s.length();
	for (int i = 0; i < len; ++i){
		if (p->next[s[i] - 'a'] == NULL)
			return 0;
		p = p->next[s[i] - 'a'];
	}
	return p!=NULL&&p->v;
}


int main(){
	//ifstream in("C:\\temp.txt");
	int k = 0;
	root = MALLOC();
	while (cin >> num[k]){
		Insert(num[k]);
		k++;
	}
	for (int i = 0; i < k; ++i){
		set<string> ss;
		int len = num[i].length();
		for (int j = 1; j < len - 1; ++j){
			string a, b;
			a = num[i].substr(0, j);
			b = num[i].substr(j);
			if (find(a) && find(b))
				ss.insert(num[i]);
		}
		copy(ss.begin(), ss.end(), ostream_iterator<string>(cout, "\n"));
	
	}

	return 0;
}