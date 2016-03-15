#include <iostream>
#include <climits>

using namespace std;
#define MAX 150

class subset {
public:
	//int arr[MAX];
	int *arr;
	int N;
	int position;
	//int input[MAX];
	int *input;
	int finished;
	int min;
	int lmin;
	int rmin;
//	int solution[MAX];
public:
	subset() {};
	~subset();
	subset(int n) { N = n; }
	void init();
	//void addinput;
	void backtrack(int a[], int k, int n,int *selected);
	void make_move(int a[], int k, int i,int *selected);
	void unmake_move(int a[], int k, int i,int *selected);
	int is_a_solution(int a[], int k, int n,int *selected);
	void process_solution(int a[], int k, int n,int *selected);
	void construct_candidates(int a[], int k, int c[], int *n);
	void get_subset();
};

subset::~subset() {
	delete[] input;
	delete[] arr;

}
void subset::init() {
	int i = 0;
	arr = new int[N + 2]();
	input = new int[N + 2]();
/*	for (i = 0; i <= N; i++) {
		arr[i] = 0;
		input[i] = 0;
	}
	*/
	lmin = 0;
	rmin = 0;
	//input[i] = 
	//input[10] = { 23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4 };
	finished = 0;
	min = INT_MAX;
}

int subset::is_a_solution(int a[], int k, int n,int *selected) {
	//printf("is_a sol %d %d \n", k, n);
	if (k >= N)
		return 1;
	if (N % 2 == 0) {
		if (*selected == N / 2)
			return 1;
	} else {
		if (*selected == (N+1) / 2)
			return 1;

	}

	return 0;
}

void subset::process_solution(int a[], int k, int n,int *selected) {
	int i;
	//cout << "{";
	int lcount = 0;
	int rcount = 0;
	/*for (i = 1; i <= n; i++) {
		cout << " " << a[i] ;
	}*/
	int dif = *selected - (N - *selected);
	if (abs(dif) > 1) {
		cout << "unbalanaced team " << endl;
		return;
	}
	cout << endl;
	int l[MAX],lpos = 0;
	int r[MAX], rpos = 0;;
	for (i = 1; i <= N; i++) {
		if (a[i] == 1) {
			//cout << i << " in L ";
			l[lpos++] = i;
			lcount = lcount + input[i-1];
		}
		else {
			//cout << i << " int R ";
			rcount = rcount + input[i-1];
			r[rpos++] = i;
		}
	}
	//cout << "}";
	//c/out << endl;
	for (int i = 0; i< lpos; i++) {
		cout << " " << l[i];

	}
	cout << endl;

	for (int i = 0; i< rpos; i++) {
		cout << " " << r[i];

	}
	cout << endl;


	cout << "left tug is " << lcount << endl;
	cout << "right tug is " << rcount << endl;
	int temp = min;
	if (lcount > rcount) {
		temp = lcount - rcount;
	} else {
		temp = rcount - lcount;
	}

	if (temp < min) {
		min = temp;
		lmin = lcount;
		rmin = rcount;
		cout << "chaing min " <<min <<" "<<temp<< endl;
	}
}

void subset::construct_candidates(int a[], int k, int c[], int *n) {
	*n = 2;
	c[0] = 1;
	c[1] = 0;

}

void subset::make_move(int a[], int k, int i,int *selected) {
	if (a[k] == 1) {
		*selected = *selected + 1;//a[k] = 1;
		cout << "making " << k << " as selected " <<*selected<< endl;
	}
}

void subset::unmake_move(int a[], int k, int i,int *selected) {
	//cout << "unmake move " << endl;
	if (a[k] == 1) {
		*selected = *selected - 1;//a[k] = 1;
		cout << "making " << k << " as not selected " << *selected << endl;
	}

}

void subset::backtrack(int a[], int k, int n,int *selected) {
	int c[MAX];
	int nC;
	int i;
	if (is_a_solution(a, k, n,selected)) {
		process_solution(a, k, n,selected);
	}
	else {
		k = k + 1;
		construct_candidates(a, k, c, &nC);
		for (i = 0; i < nC; i++) {
			a[k] = c[i];
			make_move(a, k, n,selected);
			backtrack(a, k, n,selected);
			unmake_move(a, k, n,selected);
			if (finished)
				return;
		}
	}
}

void subset::get_subset() {
	int selected = 0;
	backtrack(arr, 0, N,&selected);
	//cout << "min diff is " << min<< endl;
	//cout << "lmin is " << lmin << endl;
	//cout << "rmin diff is " << rmin << endl;

	if (lmin < rmin) {
		cout << lmin << " " << rmin << endl;
	}
	else {
		cout << rmin << " " << lmin << endl;
	}
}


int main() {
	int N ;
	//cin >> N;
///	setbuf(stdout, NULL);
	for (int tc = 0; tc < 1; tc++) {
		int n;
		cin >> n;
		subset *s1 = new subset(n);
		s1->init();
		for (int i = 0; i < n; i++) {
			cin >> s1->input[i];
		}
		cout << endl;
		s1->get_subset();
		delete s1;
	}

	return 0;
}

