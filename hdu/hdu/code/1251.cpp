#include <iostream>
#include <string>
//#include <fstream>
using namespace std;
#define KK 30

struct node{
	int count;
	node* next[KK];
};
node* root;

node* MALLOC(){
	node* p = (node*)malloc(sizeof(node));
	if (!p)exit(0);
	p->count = 1;//刚开始就将该节点的count赋值为1
	for (int i = 0; i < KK; ++i)
		p->next[i] = 0;
	return p;
}

void Insert(const string& s){
	int len = s.length();
	node* p = root;
	for (int i = 0; i < len; ++i){
		if (p->next[s[i] - 'a'] == NULL){
			p->next[s[i] - 'a'] = MALLOC();
		}
		else
			p->next[s[i] - 'a']->count++ ;
		p = p->next[s[i] - 'a'];
			
	}
}

int query(const string& s){
	int len = s.length();
	node* pp = root;
	for (int i = 0; i < len; ++i){
		if (pp->next[s[i] - 'a'] == NULL)
			return 0;
		else
			pp = pp->next[s[i] - 'a'];
	}
	if (pp != NULL)
		return pp->count;
	return 0;



}
int main(){
	//ifstream in("C:\\temp.txt");
	string s;
	root = MALLOC();
	while (getline(cin, s)&&s != "")
		Insert(s);
	while (cin >> s)
		cout << query(s) << endl;
	
	






	return 0;
}