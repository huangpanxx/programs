#include "template.h"

int arr[] = {0,3,2,1,1};

int kth(int*pl,int *pr,int k){
    if(k==0) return pl[0];
    int *l=pl, *r=pr;
    while(l<r){
	while(*l<=pl[0]&&l<r) ++l;
	while(*r>=pl[0]&&l<r) --r;
	swap(r[0],l[0]);
    }
    if(l[0]<pl[0]) swap(l[0],pl[0]);

    /*要么减少l,要么减少k,因此递归一定会停止*/
    if(l-pl>k) {
	return kth(pl,l-1,k);
    }else{
	return kth(l,pr,k-(l-pl));
    }
}

int main() {
    int d = kth(arr,arr-1+SIZE(arr),3);
    printf("%d\n",d);
    return 0;
}
