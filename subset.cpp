#include <iostream>
using namespace std;
#define MAX 1000

class subset {
public:
	int arr[MAX];
	int N;
	int position;
	int input[MAX];
	int finished;
public:
	subset() {};
	subset(int n) { N = n; }
	void init();
	//void addinput;
	void backtrack(int a[], int k, int n);
	void make_move(int a[], int k, int i);
	void unmake_move(int a[], int k, int i);
	int is_a_solution(int a[], int k, int n);
	void process_solution(int a[], int k, int n);
	void construct_candidates(int a[],int k , int c[],int *n);
	void get_subset();
};


void subset::init() {
	int i = 0;
	for (i = 0; i < N; i++) {
		arr[i] = 0;
		input[i] = 0;
	}
	finished = 0;
}

int subset::is_a_solution(int a[], int k, int n) {
	//printf("is_a sol %d %d \n", k, n);
	if (k == n)
		return 1;
	return 0;
}

void subset::process_solution(int a[],int k,int n) {
	int i;
	cout << "{";
	for (i = 1; i <= k; i++) {
		if (a[i] == 1) {
			cout << i << " ";
		}
	}
	cout << "}";
	cout << endl;
}

void subset::construct_candidates(int a[], int k, int c[], int *n) {
	*n = 2;
	c[0] = 1;
	c[1] = 0;
}

void subset::make_move(int a[], int k, int i) {
	//cout << "making move" << endl;
}

void subset::unmake_move(int a[], int k, int i) {
	//cout << "unmake move " << endl;
}

void subset::backtrack(int a[], int k, int n) {
	int c[MAX];
	int nC;
	int i;
	if (is_a_solution(a, k, n)) {
		process_solution(a, k, n);
	} else {
		k = k + 1;
		construct_candidates(a, k, c, &nC);
		for (i = 0; i < nC; i++) {
			a[k] = c[i];
			make_move(a, k, n);
			backtrack(a, k, n);
			unmake_move(a, k, n);
			if (finished)
				return;
		}
	}
}

void subset::get_subset() {
	backtrack(arr, 0, N);
}


int main() {
	int N = 2;
	cout << "subset of " << N << "are " << endl;
	subset *s1 = new subset(N);
	s1->init();
	s1->get_subset();

	return 0;
}

