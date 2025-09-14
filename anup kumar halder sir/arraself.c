#include <stdio.h>
#include <stdlib.h>
// array
struct array
{
    int *data;
    int length;
    int size;
};
void initalise(struct array *arr)
{
    int size;
    printf("Enter the Size of an array");
    scanf("%d", &size);
    arr->size = size;
    arr->length = 0;
    arr->data = (int *)malloc(size * (sizeof(int)));
       if (arr->data == NULL)
    {
        printf("memory allocation failed!\n");
        exit(1);
    }
    else
    {
        printf("The array of size %d is created (index ranging from  0 to %d ). \n ", arr->size, ((arr->size) - 1));
    }
}
void display(struct array* arr){
    if(arr->length==0){
        printf("The list is Empty\n");
    }
    for(int i=0;i<arr->length;i++){
        printf("The element at index %d is %d\n",i,arr->data[i]);
    }
}
void append(struct array* arr){
    int value;
    printf("enter the value you want to append ");
    scanf("%d",&value);
    if(arr->length>=arr->size){
        printf("The array is Full");
    }
    else{
        arr->data=value;
        arr->length++;
        printf("The array is appended at last by value %d",value);
    }
}

