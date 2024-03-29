#include <assert.h>

/* Quick sort
 */
void mqsort(int arr[], int start, int end) {
    int i = start;
    int j = end;
    int sentinel = arr[j];
    while (i<j) {
        while(i<j && arr[i]<=sentinel) { i++; cnt_inc_comp(); }
        arr[j] = arr[i];

        while(i<j && arr[j]>=sentinel) { j--; cnt_inc_comp(); }
        arr[i] = arr[j];
    }
    assert(i==j);
    arr[i] = sentinel;

    // Left
    if(i-start>0)
        mqsort(arr, start, i-1);

    // Right
    if(end-i>0)
        mqsort(arr, i+1, end);
}

void mqsort2(int arr[], int start, int end) {
    if(end<=start) {
        return;
    }
    
    int sentinel = arr[start];
    int i = start+1;
    int j = end;
    while(i<=j) {
        cnt_inc_comp();
        if( arr[i]<sentinel ) {
            i++;
            continue;
        }

        swap(arr, i, j);
        j--;       
    }

    // Now i==j+1
    swap(arr, start, j);

    mqsort2(arr, start, j-1);
    mqsort2(arr, j+1, end);
}

