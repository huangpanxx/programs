#include <iostream>
using namespace std;

int arr[] = {2, 3, 1, 9, 0};

void swap(int *a, int *b) {
	if(a != b) {
		int c = *a;
		*a = *b;
		*b = c;
	}
}

void qsort(int *left, int *right) {
	if (left >= right) return;
	int mid = *left, *pleft = left, *pright = right;
	while(*pright > mid && pright > left) pright--;
	while(*pleft < mid && pleft < right) pleft++;
	swap(pright, pleft);
	qsort(left,pright - 1);
	qsort(pleft + 1,right);
}


int main() {
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, arr + sz - 1);
	for(int i = 0; i < sz; ++i) {
		printf("%d\n",arr[i]);
	}
	return 0;
}

