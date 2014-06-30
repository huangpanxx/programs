#include "template.h"

int arr[] = {3,2,1,3,5};
int tmp[1000];

void merge_sort(int *p,int n){
    if(n <= 1) return;	
    int *p1 = p, *p2 = p+n/2;
    int np1 = n/2, np2 = n-np1;
    merge_sort(p1, np1);
    merge_sort(p2, np2);
    FO(i,n) {
	if(np1 == 0) {
	    tmp[i] = *p2;
	    p2++;
	    np2--;
	} else if(np2 == 0){
	    tmp[i] = *p1;
	    p1++;
	    np1--;
	}else if(*p1 > *p2) {
	    tmp[i] = *p2;
	    p2++;
	    np2--;
	}else {
	    tmp[i] = *p1;
	    p1++;
	    np1--;
	}
    }
    FO(i,n){
	p[i] = tmp[i];
    }
}

int main() {
    int sz = SIZE(arr);
    merge_sort(arr,sz);
    FO(i,sz) {
	printf("%d\n",arr[i]);
    }
}
