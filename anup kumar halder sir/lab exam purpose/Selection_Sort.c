#include<stdio.h>
void swap(int *a,int *b){
    int temp =*a;
    *a =*b;
    *b = temp;
}
void Selection_sort(int list[], int size){
    for (int i=0;i<size;i++){
        int min =i;
        for(int j=i; j<size;j++){
            if(list[j]<list[min]) min =j;

        }
        swap(&list[min],&list[i]);
    }
}
int main() {
    int arr[] = {10, 5, 0, 4, 3, 8, 2, 6};

    Selection_sort(arr, 8);

    for (int i = 0; i < 8; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}
