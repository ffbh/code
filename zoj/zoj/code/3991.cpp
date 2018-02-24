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

//ifstream in("C:\\input.txt");
istream& in = cin;


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back





int n, m, a[100010];
bool vis[100010];

bool cmpa(pii& p1, pii& p2){
	if (p1.first != p2.first)
		return p1.first < p2.first;
	else
		return p1.second < p2.second;
}

bool cmpb(pii& p1, pii& p2){
	if (p1.first != p2.first)
		return p1.first > p2.first;
	else
		return p1.second < p2.second;
}



int main(){


	int T;
	in >> T;
	while (T-- > 0){
	//	in >> n >> m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i){
			//in >> a[i];
			scanf("%d", &a[i]);
			vis[i] = 0;
		}

		int K = n - m;
		if (K == 1){
			printf("1\n");
		}
		else{
			vector<pii> A, B;
			for (int i = 1; i <= n; ++i){
				A.push_back(mp(a[i], i));
				B.push_back(mp(a[i], i));
			}
			sort(A.begin(), A.end(), cmpa);
			sort(B.begin(), B.end(), cmpb);

			vector<int> ans;
			int apos, bpos;
			double sum;
			apos = bpos = sum = 0;

			while (vis[A[apos].second])
				apos++;
			ans.push_back(A[apos].second);
			sum += A[apos].first;
			vis[A[apos].second] = 1;
			while (vis[B[bpos].second])
				bpos++;
			ans.push_back(B[bpos].second);
			sum += B[bpos].first;
			vis[B[bpos].second] = 1;

			K -= 2;
			for (int k = 1; k <= K; ++k){
				while (vis[A[apos].second])
					apos++;
				while (vis[B[bpos].second])
					bpos++;
				pii& aval = A[apos];
				pii& bval = B[bpos];
				double diffa = fabs(sum / (k + 1) - aval.first);
				double diffb = fabs(sum / (k + 1) - bval.first);
				char status;
				if (fabs(diffa - diffb) < 1e-7){
					if (aval.second < bval.second){
						status = 'A';
					}
					else{
						status = 'B';
					}
				}
				else if(diffa > diffb){
					status = 'A';
				}
				else{
					status = 'B';
				}

				if (status == 'A'){
					ans.push_back(A[apos].second);
					sum += A[apos].first;
					vis[A[apos].second] = 1;
				}
				else{
					ans.push_back(B[bpos].second);
					sum += B[bpos].first;
					vis[B[bpos].second] = 1;
				}
			}



			sort(ans.begin(), ans.end());
			for (int i = 0; i < ans.size() - 1; ++i)
				printf("%d ", ans[i]);
			printf("%d\n", ans.back());



		}







	}





	return 0;
}




