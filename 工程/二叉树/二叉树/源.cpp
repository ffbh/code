#include <iostream>
#include <string>
using namespace std;
typedef char elemtype;
struct node{
	node* left;
	node* right;
	elemtype value;
};
class BitTree{
	node* head;
	string PreS;
	string InS;
	string PostS;
	int p;
	void _TreeToIn(node*);
	void _TreeToPost(node*);
public:
	void create(node*&);
	void Init(const string& s);
	bool operator==( BitTree& b){
		TreeToIn();
		TreeToPost();
		b.TreeToIn();
		b.TreeToPost();
		return InS == b.InS&&PostS == b.PostS;
	}
	pair<string, string> simiple();
	void TreeToIn(){
		InS = "";
		_TreeToIn(head);
		//cout << InS << endl;
	}
	void TreeToPost(){
		PostS = "";
		_TreeToPost(head);
		//cout << PostS << endl;
	}
	void PreOrder(){
		cout << "前序遍历如下：";
		cout << PreS << endl;
		
	}
	void InOrder() { 
		cout << "中序遍历如下：";
		_TreeToIn(head);
		cout << InS << endl;
		
	}
	void PostOrder() { 
		cout << "后序遍历如下：";
		_TreeToPost(head);
		cout << PostS << endl;
		
	}
	
	
};
pair<string, string> BitTree::simiple(){
	TreeToIn();
	TreeToPost();
	for (int i = 0; i < InS.length();++i)
	if (InS[i] != '#')InS[i] = 0;
	for (int i = 0; i < PostS.length(); ++i)
	if (PostS[i] != '#')PostS[i] = 0;
	return make_pair(InS, PostS);
}
void BitTree::create(node*& pi){
	if (p < PreS.length()){
		if (PreS[p] == '#'){
			pi = NULL;
			p++;
		}
		else{
			pi = new node();
			pi->value = PreS[p++];
			create(pi->left);
			create(pi->right);
		}
	}
}

void BitTree::Init(const string& s){
	PreS = s;
	p = 1;
	head = new node();
	head->value = PreS[0];
	create(head->left);
	create(head->right);
}

void BitTree::_TreeToIn(node* T){
	if (T){
		_TreeToIn(T->left);
		InS += T->value;
		_TreeToIn(T->right);
	}
	else InS += "#";
}

void BitTree::_TreeToPost(node* T){
	if (T){
		_TreeToPost(T->left);
		_TreeToPost(T->right);
		PostS += T->value;
	}
	else PostS += "#";
}
int main(){
	BitTree tree1,tree2;
	string s1, s2;
//	tree1.Init("AB##CD###");//前序
//	tree2.Init("AB##CE###");//前序
	cout << "please input tree1 PreOrder:";
	cin >> s1;
	cout << "please input tree2 PreOrder:";
	cin >> s2;
	tree1.Init(s1);
	tree2.Init(s2);
	cout << "tree1"; tree1.PreOrder();
	cout << "tree1"; tree1.InOrder();
	cout << "tree1"; tree1.PostOrder();
	cout << "tree2"; tree2.PreOrder();
	cout << "tree2"; tree2.InOrder();
	cout << "tree2"; tree2.PostOrder();
	printf("tree1 is %sequal to tree2\n", (tree1 == tree2) ? "" : "not ");
	printf("tree1 is %ssimiple to tree2\n", (tree1.simiple() == tree2.simiple()) ? "" : "not ");

	return 0;
}