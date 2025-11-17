#include<stdio.h>
void swap(int *x,int*y){
    int temp =*x;
    *x=*y;
    *y=temp;
}

void bubble_sort(int list[], int size){
    int i,j;
    for(i=size-1;i>0;i--){
        j=i;
        for(j=0;j<i;j++){
            if(list[j]>list[j+1]) swap(&list[j+1],&list[j]);
        }
    }
}
int main() {
    int arr[] = {10, 5, 0, 4, 3, 8, 2, 6};

    bubble_sort(arr, 8);

    for (int i = 0; i < 8; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}
