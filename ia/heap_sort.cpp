#include <iostream>
using namespace std;


int arr[] = {1, 4, 2, 1};


void make_heap(int *p, int k, int n) {
	if(2*k+1 < n && p[k] > p[2*k+1] 
		&& (2*k+2>=n || p[2*k+1] <= p[2*k+2])) {
		swap(p[k],p[2*k+1]);
		make_heap(p,2*k+1,n);
	} else if(2*k+2 < n && p[k] > p[2*k+2]
		&& p[2*k+2] <= p[2*k+1]){
		swap(p[k],p[2*k+2]);
		make_heap(p,2*k+2,n);
	}
}

void heap_sort(int *p,int n) {
	for(int i = n / 2; i >= 0; --i) {
		make_heap(p,i,n);
	}
	for(int i = 0; i < n; ++i) {
		swap(p[0], p[n-1-i]);
		make_heap(p,0,n-i-1);
	}
}

int main() {
	int sz = sizeof(arr) / sizeof(arr[0]);
	
	heap_sort(arr,sz);
	
	for(int i=0;i<sz;++i) {
		printf("%d\n",arr[i]);
	}	

	return 0;
}
