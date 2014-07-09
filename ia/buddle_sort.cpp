#include "template.h"

int arr[] = {4,3,2,1,2,3,5};

void buddle_sort(int* p,int n){
    FO(i,n) FO(j,n-1-i) 
	if(p[j]>p[j+1])
	    swap(p[j],p[j+1]);
}

int main() {
    buddle_sort(arr,SIZE(arr));
    FO(i,SIZE(arr)) {
	printf("%d\n",arr[i]);
    }
    return 0;
}
