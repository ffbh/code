#include <iostream>
#include <string>
#include <fstream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;
struct Node{
	int l, len;
	bool operator<(const Node& p)const{
		return l < p.l;
	}
	Node(int _l, int _r){
		l = _l;
		len = _r;
	}
	Node(){}
};

struct Memory{
	Node data[2010];
	int size;
	Node vn[2][2010];
	int del, M, flag, block;
	Memory(int m){
		M = m;
		del = size = 1;
		flag = block = 0;
		vn[flag][block++] = Node(0, M);
	}

	int Alloc(int length){
		int start = 999999999;
		int index = 2010;
		for (int i = 0; i < block; ++i){
			if (vn[flag][i].len >= length&&start > vn[flag][i].l){
				start = vn[flag][i].l;
				index = i;
			}
		}
		if (start == 999999999){
			return -1;
		}
		else if (vn[flag][index].len == length){
			for (int i = index; i < block; ++i)
				vn[flag][i] = vn[flag][i + 1];
			block--;
		}
		else{
			vn[flag][index].l += length;
			vn[flag][index].len -= length;
		}
		return start;
	}
	void deAlloc(int length){
		while (1){
			int nextflag = (flag + 1) % 2;
			int tblock = 0;
			int l = data[del].l;
			int len = data[del].len;
			del++;
			for (int i = 0; i < block; ++i){
				bool f = 0;
				if (l == vn[flag][i].l + vn[flag][i].len){
					f = 1;
					l = vn[flag][i].l;
					len += vn[flag][i].len;
				}
				if (vn[flag][i].l == l + len){
					f = 1;
					len += vn[flag][i].len;
				}
				if (!f)
					vn[nextflag][tblock++] = vn[flag][i];
			}
			vn[nextflag][tblock++] = Node(l, len);
			flag = nextflag;
			block = tblock;
			if (len >= length)
				return;
		}
	}

	void push(int length){
		int start;
		while ((start = Alloc(length)) == -1)
			deAlloc(length);
		data[size].l = start;
		data[size].len = length;
		size++;
	}

	void show(){
		for (int i = del; i < size; ++i)
			printf("%d %d\n", i,data[i].l);
	}
};

int main(){
	scanf("%d %d", &N, &M);
	Memory memory(M);
	for (int i = 1; i <= N; ++i){
		int length;
		scanf("%d", &length);
		memory.push(length);
	}
	memory.show();
	return 0;
}