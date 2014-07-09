#include <iostream>
using namespace std;

int arr[] = {2, 3, 1, 9, 0};

void qsort_big_god_ass_fuck_qin(int *left, int *right) {
    if (left >= right) return;
    int mid = *left, *pleft = left, *pright = right;
    while(*pright > mid && pright > left) pright--;
    while(*pleft < mid && pleft < right) pleft++;
    swap(pright[0], pleft[0]);
    qsort_big_god_ass_fuck_qin(left,pright - 1);
    qsort_big_god_ass_fuck_qin(pleft + 1,right);
}

void qsort_ia(int*left,int*right) {
    if(left >= right) return;
    int mid = left[0], *l=left-1;
    for(int*p=left;p<=right;++p)
	if(p[0]<=mid) swap((++l)[0],p[0]);
    swap(left[0],l[0]);
    qsort_ia(left,l-1);
    qsort_ia(l+1,right);
}


int main() {
    int sz = sizeof(arr) / sizeof(arr[0]);
    qsort_ia(arr, arr + sz - 1);
    for(int i = 0; i < sz; ++i) {
	printf("%d\n",arr[i]);
    }
    return 0;
}

