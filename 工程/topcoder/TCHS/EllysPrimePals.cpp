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
using namespace std;
#define DEBUG (0)
#define MMAX (int(1e5) + 10)
bool vis[MMAX];
vector<int> prime;
vector<int> t;
vector<char> ans;
vector <string> NUMBER;
set<long long> pr;
int LEN;
void Init(){
	for (int i = 2; i < MMAX; ++i){
		if (!vis[i]){
			prime.push_back(i);
			for (int j = i + i; j < MMAX; j += i)
				vis[j] = 1;
		}
	}
}

bool judgeP(long long p){
	if (p < 2)
		return 0;
	if (pr.count(p))
		return 1;
	for (int i = 0; i<prime.size() && p>prime[i]; ++i){
		if (p%prime[i] == 0)
			return 0;
	}
	pr.insert(p);
	return 1;
}

bool dfs(int l, int r){
	if (l>r){

		for (int i = 0; i < NUMBER.size(); ++i){
			long long num = 0;
			string& p = NUMBER[i];
			for (int j = 0; j < p.length(); ++j){
				num = num * 10 + (p[j] + 10 - ans[j]) % 10;
				if (j == 0 && (p[j] + 10 - ans[j]) % 10 == 0)
					return 0;
			}
			if (!judgeP(num))
				return 0;
		}
		return 1;
	}
	else{
		int start = 0;
		if (l == 0 && LEN != 1)
			start = 1;
		for (int i = start; i <= 9; ++i){
			ans[l] = i + '0';
			ans[r] = (i + t[l]) % 10 + '0';
			if (dfs(l + 1, r - 1))
				return 1;
		}
		return 0;
	}

}

bool judge(vector <string>& numbers){
	t.clear();
	int len = numbers[0].length();
	int l = 0, r = len - 1;
	while (l < r){
		int a = numbers[0][l] - '0';
		int b = numbers[0][r] - '0';
		t.push_back((b + 10 - a) % 10);
		l++;
		r--;
	}
	for (int k = 1; k < numbers.size(); ++k){
		int pos = 0;
		int l = 0, r = len - 1;
		while (l < r){
			int a = numbers[k][l] - '0';
			int b = numbers[k][r] - '0';
			if (t[pos++] != (b + 10 - a) % 10)
				return 0;
			l++;
			r--;
		}
	}
	if (LEN % 2 == 1)
		t.push_back(0);
	return 1;
}



class EllysPrimePals {
public:
	string getKey(vector <string> numbers) {
		NUMBER = numbers;
		LEN = numbers[0].size();
		if (!judge(numbers)){
			return "No solution";
		}
		pr.clear();
		ans.clear();
		ans.resize(LEN);

		for (int i = 0; i < ans.size(); ++i){
			ans[i] = '0';
		}
		Init();
		if (dfs(0, LEN - 1)){
			string X = "";
			for (int i = 0; i < ans.size(); ++i)
				X += ans[i];
			return X;
		}
		else{
			return "No solution";
		}







	}
};



#if 0
int main(){
	vector<string> p({ { "540171848", "757252550", "750909850", "781090980", "318494616", "927939522", "591474998", "782131080", "792939090", "910171812", "944030242", "739525730", "572494078", "779505770", "941626942", "948707642", "374494276", "794060290", "329565726", "739707730", "981505982", "906909402", "787535580", "307909506", "770040870", "940555842", "351282956", "702878000", "330424836", "788242680", "997636592", "567191568", "527424528", "997636592", "758313650", "754545250", "736727430", "334090236", "350313856", "548252648", "334101236", "544151248", "312575016", "377979576", "363424166", "386494486", "349010746", "927505522", "954313252", "706838400", "950848852", "502414008", "733989130", "748717640", "546010448", "303484106", "913636112", "716595410", "310565816", "579929778", "301040906", "931989932", "502484008", "943606142", "971222972", "705555300", "763838160", "710929810", "343111146", "727717520", "535131338", "717333510", "968909662", "538959638", "787020580" } });
	EllysPrimePals so;
	cout << so.getKey(p) << endl;















	return 0;
}
#endif



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
