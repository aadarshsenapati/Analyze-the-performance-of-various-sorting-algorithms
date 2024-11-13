//quicksort
#include<stdio.h>
#include <time.h>
#define N 100
int split(int a[],int lower, int upper){
int i,p, q,t;
p = lower +1;
q = upper ;
i = a[lower] ;
while (q>=p){
    while ( a[p] <i)
        p++;

    while (a[q] > i)
        q--;

    if(q>p){
        t = a[p]; 
        a[p] = a[q];
        a[q] = t;
    }
    }
    t = a[lower];
    a[lower] = a[q];
    a[q]=t;
    return q;
}


void quicksort (int a[], int lower, int upper ){
    int i;
    if ( upper > lower ){
        i = split ( a, lower, upper ) ;
        quicksort ( a, lower, i-1);
        quicksort (a, i+ 1, upper) ;
    }
}

main(){
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    int a[N],i;
    for(i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    quicksort(a,0,N-1);
    printf("arrays after sorting");
    for (i=0; i<N ;i++){
        printf ("%d\n", a[i] );
    }
    end = clock();
     cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time: ");
    printf("%lf",cpu_time_used);
}