#include "stdio.h"
#include "stdlib.h"

#define LEN 30000

int cmp(const void *pa, const void *pb){
    const int *a = *(const int **)pa;
    const int *b = *(const int **)pb;
    return b[1] - a[1];
}

int main() {
    int n, m, **ary, *pAry, i, max;
    ary = malloc(LEN*sizeof(int *) + LEN*2*sizeof(int));
    for (i=0, pAry=(int *)(ary+LEN); i<LEN; i++, pAry+=2) {
        ary[i] = pAry;
        ary[i][0] = i+1;
        ary[i][1] = 0;
    }
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &m);
        ary[m-1][1]++;
    }
    
    qsort(ary, LEN, sizeof(int *), cmp);
    i = 0;
    max = ary[i][1];
    while (ary[i][1]==max) {
        printf("%d %d\n", ary[i][0], ary[i][1]);
        i++;
    }
    free(ary);
    return 0;
}
