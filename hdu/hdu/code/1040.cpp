#include <iostream>
#include <set>
using namespace std;

int main(){
	multiset<int> s;
	int n;
	cin >> n;
	int count,t;
	while (n-- > 0){
		scanf("%d", &count);
		while (count-- > 0){
			scanf("%d", &t);
			s.insert(t);
		}
		multiset<int>::iterator it = s.begin();
		while (1){
			cout << *it++;
			if (it == s.end())break;
			cout << " ";
		}
		cout << endl;
		s.clear();
	}
	return 0;
}