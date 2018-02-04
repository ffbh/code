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
#include <map>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <set>
#include <cassert>
using namespace std;




//typedef long long LL;
typedef unsigned long long ULL;
//#define pii pair<int,int>
//#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back



int na, nb, nc;
int ra, rb, rc;
int ANS_A, ANS_B;



const ULL HASH_node = 137845;
const ULL HASH_seed = (ULL)1e9+7;
void  dfs(vector<int> tree[100010], pair<int, ULL> ret[100010], int deep[100010], int p, int d){
	ret[p].first = 1;
	ret[p].second = HASH_node;
	vector<ULL> all;
	deep[p] = d;
	for (int son : tree[p]){
		dfs(tree, ret, deep, son, d + 1);
		ret[p].first += ret[son].first;
		all.push_back(ret[son].second);
		deep[p] = max(deep[p], deep[son]);
	}

	if (!all.empty()){
		sort(all.begin(), all.end());
		for (ULL key : all){
			ret[p].second = ret[p].second * HASH_seed + key;
		}
	}
}



vector<int> A[100010], B[100010], C[100010], X[100010], Y[100010];
pair<int, ULL> ret_a[100010], ret_b[100010], ret_c[100010], ret_x[100010], ret_y[100010];
int deep_a[100010], deep_b[100010], deep_c[100010], deep_x[100010], deep_y[100010];

bool cmp_a(int a, int b){
	if (deep_a[a] != deep_a[b])
		return deep_a[a] > deep_a[b];
	return ret_a[a].first > ret_a[b].first;
}

bool cmp_b(int a, int b){
	if (deep_b[a] != deep_b[b])
		return deep_b[a] > deep_b[b];
	return ret_b[a].first > ret_b[b].first;
}

bool cmp_c(int a, int b){
	if (deep_c[a] != deep_c[b])
		return deep_c[a] > deep_c[b];
	return ret_c[a].first > ret_c[b].first;
}

/** chushihua **/

int tree_id;
bool find_first_struct(vector<int> big[100010], vector<int> small[100010], pair<int, ULL> r_a[100010], pair<int, ULL> r_b[100010], int b, int s){
	//  if (r_a[b].first % r_b[s].first != 0)
	//    return 0;

	//   if (big[b].size() < small[s].size())
	//      return 0;

	if (small[s].empty()){
		tree_id = b;
		return 1;
	}
	else{
		if (big[b].empty())
			return 0;
		return find_first_struct(big, small, r_a, r_b, big[b][0], small[s][0]);
	}
}

ULL slove(vector<int> tree[100010], int T_ID, int p){//maybe too large check with size(X) * size(A)
	vector<ULL> all;
	if (T_ID != -1){
		for (int i = 0; i < C[T_ID].size(); ++i){
			all.push_back(ret_c[C[T_ID][i]].second);
		}
	}
	for (int son : tree[p]){
		all.push_back(slove(tree, T_ID, son));
	}
	sort(all.begin(), all.end());
	ULL ans = HASH_node;
	for (ULL key : all){
		ans = ans * HASH_seed + key;
	}
	return ans;
}

vector<ULL> cale_tree_all_hash(vector<int> tree[100010], int T_ID, int R){
	vector<ULL> ans;
	for (int son : tree[R]){
		ans.push_back(slove(tree, T_ID, son));
	}
	//	sort(ans.begin(), ans.end());//maybe not important
	return ans;
}

bool judge(const vector<ULL>& CHASH, const vector<ULL>& AHASH, const vector<ULL>& BHASH, int X, int Y){
	if (AHASH.size() + BHASH.size() + C[X].size() + C[Y].size() != CHASH.size())
		return 0;
	unordered_map<ULL, int> mmp;
	for (ULL key : CHASH){
		mmp[key]++;
	}

	for (ULL key : AHASH){
		if (mmp[key] >= 1){
			mmp[key]--;
		}
		else{
			return 0;
		}
	}

	for (ULL key : BHASH){
		if (mmp[key] >= 1){
			mmp[key]--;
		}
		else{
			return 0;
		}
	}

	for (int son : C[X]){
		if (mmp[ret_c[son].second] >= 1){
			mmp[ret_c[son].second]--;
		}
		else{
			return 0;
		}

	}

	for (int son : C[Y]){
		if (mmp[ret_c[son].second] >= 1){
			mmp[ret_c[son].second]--;
		}
		else{
			return 0;
		}

	}



	return 1;

}



bool cale(){
	    if (A[ra].size() + B[rb].size()  > C[rc].size())
	        return 0;

	vector<ULL> CHASH = cale_tree_all_hash(C, -1, rc);

	if (find_first_struct(C, A, ret_c, ret_a, C[rc][0], A[ra][0])){
		int X = tree_id;
		vector<ULL> AHASH = cale_tree_all_hash(A, X, ra);
		unordered_map<ULL, int> mmp;
		for (ULL key : AHASH){
			mmp[key]++;
		}
		for (int son : C[X]){
			mmp[ret_c[son].second]++;
		}
		int maybe_b_tree = -1;
		for (int k = 0; k < CHASH.size(); ++k){
			if (mmp[CHASH[k]] >= 1){
				mmp[CHASH[k]]--;
			}
			else{
				maybe_b_tree = k;
				break;
			}

		}



		if (maybe_b_tree != -1 && find_first_struct(C, B, ret_c, ret_b, C[rc][maybe_b_tree], B[rb][0])){
			int Y = tree_id;
			vector<ULL> BHASH = cale_tree_all_hash(B, Y, rb);
			if (judge(CHASH, AHASH, BHASH, X, Y)){
				ANS_A = X;
				ANS_B = Y;
				return 1;
			}
		}
	}

	if (find_first_struct(C, B, ret_c, ret_b, C[rc][0], B[rb][0])){
		int Y = tree_id;
		vector<ULL> BHASH = cale_tree_all_hash(B, Y, rb);
		unordered_map<ULL, int> mmp;
		for (ULL key : BHASH){
			mmp[key]++;
		}
		for (int son : C[Y]){
			mmp[ret_c[son].second]++;
		}
		int maybe_a_tree = -1;
		for (int k = 0; k < CHASH.size(); ++k){
			if (mmp[CHASH[k]] >= 1){
				mmp[CHASH[k]]--;
			}
			else{
				maybe_a_tree = k;
				break;
			}

		}



		if (maybe_a_tree != -1 && find_first_struct(C, A, ret_c, ret_a, C[rc][maybe_a_tree], A[ra][0])){
			int X = tree_id;
			vector<ULL> AHASH = cale_tree_all_hash(A, X, ra);
			if (judge(CHASH, AHASH, BHASH, X, Y)){
				ANS_A = X;
				ANS_B = Y;
				return 1;
			}
		}

	}
	return 0;
}

void Init(){
	for (int i = 0; i <= na; ++i) {
		A[i].clear();
		ret_a[i] = mp(0, 0);
		deep_a[i] = 0;
	}
	for (int i = 0; i <= nb; ++i) {
		B[i].clear();
		ret_b[i] = mp(0, 0);
		deep_b[i] = 0;
	}
	for (int i = 0; i <= nc; ++i) {
		C[i].clear();
		ret_c[i] = mp(0, 0);
		deep_c[i] = 0;
	}

}
int cnt;

void dfs_print(int p, int fa, bool f){
	
	if (f){
		cnt = 1;
		printf("%d", fa);

	}
	else{
		printf(" %d", fa);

	}
	int id = cnt++;
	for (int son : C[p]){
		dfs_print(son, id, 0);
	}
}

vector<int> random_tree(int N){

	vector<int> random;
	for (int i = 1; i <= N; ++i){
		srand(time(0));
		int val = rand() % i;
		if (i != 1 && val == 0)
			val = 1;
		random.push_back(val);
	}
	return random;
}

void add_branch(vector<int>& tar_tree, int root_id, int& start_id, vector<int>& branch_tree){
	unordered_map<int, int> mmp;
	for (int i = 0; i<branch_tree.size(); ++i){
		int v_id = i + 1;
		if (branch_tree[i] == 0){
			mmp[v_id] = root_id;
		}
		else{
			mmp[v_id] = start_id++;
			tar_tree.push_back(mmp[branch_tree[i]]);
		}
	}
}

void construct_tree(int T,int n, int m, int k1, int k2){

	ofstream out("C:\\input.txt");
	out << T << endl;
	while (T-- > 0){
		int SIZEC = n*k1 + m*k2 - 1;
		out << n << " " << m << " " << SIZEC << endl;
		vector<int> treeA = random_tree(n);
		vector<int> treeB = random_tree(m);

		vector<int> treeX = random_tree(k1);
		vector<int> treeY = random_tree(k2);

		vector<int> treeC = { 0 };
		int id = 2;
		add_branch(treeC, 1, id, treeA);
		add_branch(treeC, 1, id, treeB);
		add_branch(treeC, 1, id, treeX);
		add_branch(treeC, 1, id, treeY);
		for (int i = 1; i < treeA.size(); ++i)
			add_branch(treeC, i + 1, id, treeX);
		for (int i = treeA.size(); i < treeA.size() + treeB.size() - 1; ++i)
			add_branch(treeC, i + 1, id, treeY);




		for (int t : treeA){
			out << t << " ";
		}
		out << endl;
		for (int t : treeB){
			out << t << " ";
		}
		out << endl;

		for (int t : treeC){
			out << t << " ";
		}
		out << endl;



	/*	for (int t : treeX){
			out << t << " ";
		}
		out << endl;
		for (int t : treeY){
			out << t << " ";
		}
		out << endl;*/
	}
}




ifstream in("C:\\input.txt");
//istream& in = cin;
int main(){


		construct_tree(1,300, 100, 100, 50);


		int T;
		in >> T;
		while (T-- > 0){
		in >> na >> nb >> nc;
		//	scanf("%d%d%d", &na, &nb, &nc);


			Init();
			for (int i = 1; i <= na; ++i){
				int t;
				in >> t;
			//		scanf("%d", &t);
				if (t == 0){
					ra = i;
				}
				else{
					A[t].push_back(i);
				}
			}

			for (int i = 1; i <= nb; ++i){
				int t;
				in >> t;
			//		scanf("%d", &t);
				if (t == 0){
					rb = i;
				}
				else{
					B[t].push_back(i);
				}
			}

			for (int i = 1; i <= nc; ++i){
				int t;
				in >> t;
			//		scanf("%d", &t);
				if (t == 0){
					rc = i;
				}
				else{
					C[t].push_back(i);
				}
			}

	

			dfs(A, ret_a, deep_a, ra, 0);
			dfs(B, ret_b, deep_b, rb, 0);
			dfs(C, ret_c, deep_c, rc, 0);

			for (int i = 1; i <= na; ++i)
				sort(A[i].begin(), A[i].end(), cmp_a);
			for (int i = 1; i <= nb; ++i)
				sort(B[i].begin(), B[i].end(), cmp_b);
			for (int i = 1; i <= nc; ++i)
				sort(C[i].begin(), C[i].end(), cmp_c);



			if (cale()){
				printf("%d %d\n", ret_c[ANS_A].first, ret_c[ANS_B].first);
	
				dfs_print(ANS_A, 0, 1);
				printf("\n");
			
				dfs_print(ANS_B, 0, 1);
				printf("\n");
			

				

			}
			else{
				printf("Impossible\n");

			}
		}
	
	return 0;
}



