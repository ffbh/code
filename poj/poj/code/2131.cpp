#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <cmath>
using namespace std;
struct Block{
	int* arr;
	Block* next;
	Block* pre;
	int length;
	Block(int size){
		arr = new int[size];
		for (int i = 0; i < size; ++i)
			arr[i] = 0;
		length = size;
		next = pre = 0;
	}
};
int f[300000];
bool vis[300000];
struct BlockList{
	
	Block* head;
	int blocksize;
	int divtime;
	int find(int x){
		return x == f[x] ? x : f[x] = find(f[x]);
	}
	Block* createBlock(int size){
		return new Block(size);
		
	}
	BlockList(int size){
		for (int i = 0; i < 300000; ++i){
			f[i] = i;
			vis[i] = 0;
		}
		blocksize = size;
		divtime = 0;
		head = createBlock(blocksize);
	}

	void startUnion(){
		Block* p = head;
		while (p->next){
			Block* q = p->next;
			Block *ret;
			if (p->length + q->length <= blocksize){
				ret = Union(p, q);
				if (p == head)
					head = p = ret;
				else
					p = ret;
			}
			p = p->next;
		}
		divtime = 0;
	}

	void del(int pos){
		int nowpos = 0;
		Block* p = head;
		while (p->length + nowpos <= pos){
			nowpos += p->length;
			p = p->next;
			if (p == 0)
				return;
		}
		int index = pos - nowpos;
		for (int i = index; i < p->length - 1; ++i)
			p->arr[i] = p->arr[i + 1];
		p->length--;
	}
	void set(int pos, int val){
		if (divtime == 50)
			startUnion();

		int nowpos = 0;
		Block* p = head;
		while (p->length + nowpos <= pos){
			if (p->next == 0){
				Block* Q = createBlock(blocksize);
				p->next = Q;
				Q->pre = p;
			}
			nowpos += p->length;
			p = p->next;
		}
		int index = pos - nowpos;
		if (p->arr[index] == 0){
			p->arr[index] = val;
			if (vis[pos + 1]){
				f[pos] = f[find(pos + 1)];
			}
			if (pos&&vis[pos - 1]){
				f[pos - 1] = f[find(pos)];
			}
		}
		else{
			int end = f[find(pos)] + 1;
			if (end)
				f[end - 1] = f[end];
			if (vis[end + 1]){
				f[end] = f[find(end + 1)];
			}
			del(end);

			int nozeroindex = -1;
			for (int i = index + 1; i < p->length;++i)
			if (p->arr[i] == 0){
				nozeroindex = i;
				break;
			}
			if (nozeroindex != -1){
				for (int i = nozeroindex; i > index; --i)
					p->arr[i] = p->arr[i - 1];
				p->arr[index] = val;
			}
			else{
				divblock(p, index, val);

			}
		}
	}

	void divblock(Block* p,int index,int val){
		divtime++;
		Block* q = createBlock(p->length - index);
		for (int i = 0; i < q->length; ++i)
			q->arr[i] = p->arr[i + index];
		p->arr[index] = val;
		p->length = index + 1;
		q->next = p->next;
		p->next = q;
		q->pre = p;
		if (q->next)
			q->next->pre = q;
	}

	Block* Union(Block* p,Block* q){
		int len = p->length + q->length;
		Block* Q = createBlock(len);
		for (int i = 0; i < p->length; ++i)
			Q->arr[i] = p->arr[i];
		for (int i = 0; i < q->length; ++i)
			Q->arr[i + p->length] = q->arr[i];
		Q->pre = p->pre;
		if (Q->pre)
			Q->pre->next = Q;
		Q->next = q->next;
		if (Q->next)
			Q->next->pre = Q;
		delete p;
		delete q;
		return Q;
	}

	void show(){
		int num = 0;
		Block* p = head;
		while (p){
			if (p->next)
				num += p->length;
			else{
				int end;
				for (int i = p->length - 1; i >= 0; --i)
				if (p->arr[i] != 0){
					end = i;
					break;
				}
				num += end + 1;
			}
			p = p->next;
		}
		printf("%d\n", num);

		p = head;
		bool sign = 0;
		while (p){
			if (p->next){
				for (int i = 0; i < p->length; ++i){
					if (sign)
						printf(" %d", p->arr[i]);
					else{
						sign = 1;
						printf("%d", p->arr[i]);
					}
				}
			}
			else{
				int end;
				for (int i = p->length - 1; i >= 0; --i)
				if (p->arr[i] != 0){
					end = i;
					break;
				}
				for (int i = 0; i <= end; ++i){
					if (sign)
						printf(" %d", p->arr[i]);
					else{
						sign = 1;
						printf("%d", p->arr[i]);
					}
				}
			}

			p = p->next;
		}
	cout << endl;
	}
	
};






int main(){
	ifstream in("C:\\input.txt");
	int N, M;
	in >> N >> M;
//	scanf("%d%d", &N, &M);
	int val = 1;
	BlockList block(ceil(sqrt(double(N+M+10))) + 1);
	while (N--){
		int pos;
		in >> pos;
	//	scanf("%d", &pos);
		block.set(pos-1, val++);
//		block.show();
	}
	block.show();
	return 0;
}