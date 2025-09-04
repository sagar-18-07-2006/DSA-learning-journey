#include <stdio.h>
#include <stdlib.h>
struct array
{
    int *Address;
    int size;
    int length;
};
// void swap(int *x, int *y)
// {
//     if (x == y)
//         return; // avoid self-swap issue

//     *x = *x ^ *y;
//     *y = *x ^ *y;
//     *x = *x ^ *y;
// }
void initalise(struct array *arr)
{
    int size;
    printf("enter the size of array");
    scanf("%d", &size);
    arr->size = size;
    arr->length = 0;
    arr->Address = (int *)malloc(arr->size * (sizeof(int)));
    if (arr->Address == NULL)
    {
        printf("memory allocation failed!\n");
        exit(1);
    }
    else
    {
        printf("The array of size %d is created (index ranging from  0 to %d ). \n ", arr->size, ((arr->size) - 1));
    }
}
void display(struct array *arr)
{
    if (arr->length == 0)
    {
        printf("The array is empty\n");
    }
    else
    {
        for (int i = 0; i < arr->length; i++)
        {
            printf("The %dth element is %d\n", i + 1, arr->Address[i]);
        }
    }
}
void append(struct array *arr)
{
    int val;
    printf("Enter the value you want to append");
    scanf("%d", &val);

    if (arr->length < arr->size)
    {
        arr->Address[arr->length++] = val;
        printf("appended %d to the array.\n", val);
    }
    else
    {
        printf("append failed: Adt is Full (max ind: %d).\n", arr->size - 1);
    }
}
void insert(struct array *arr)
{
    int value;
    printf("Enter the value you want to value");
    scanf("%d", &value);
    int pos;
    printf("Enter the position where you want to insert");
    scanf("%d", &pos);
    if (pos > arr->length || pos < 0)
    {
        printf("invalid index to add element in array");
    }
    else if (arr->length >= arr->size)
    {
        printf("array is full cannot accomodate more elements");
    }
    else
    {
        for (int i = arr->length; i > pos; i--)
        {
            arr->Address[i] = arr->Address[i - 1]; // shift right
        }
        arr->Address[pos] = value;
        arr->length++;
    }
}
void append_multiple_in_one_go(struct array *arr)
{
    int count;
    printf("Enter the number of elements you want to append\n");
    scanf("%d", &count);
    if (((arr->length) + count) < arr->size && count > 0)
    {
        for (int i = 0; i < count; i++)
        {
            printf("Enter the %dth element: ", i + 1);
            scanf("%d", &arr->Address[arr->length++]);
        }
    }
    else if (arr->length + count > arr->size)
    {
        printf("array size cannot  allow that much number of element to be apended");
    }
    else if (count <= 0)
    {
        printf("number of elements you want to add cannot be negitive or zero");
    }
    else if (arr->length == arr->size)
    {
        printf("array is full");
    }
}
void delete_at_last(struct array *arr)
{
    if (arr->length <= 0)
    {
        printf("No element to be deleted in array\n");
    }
    if (arr->length > 0)
    {
        arr->length--;
    }
}
void delete_at_pos(struct array *arr)
{
    int pos;
    printf("Enter the position where you want to delete");
    scanf("%d", &pos);
    if (pos >= 0 && pos < arr->length)
    {
        for (int i = pos; i < arr->length - 1; i++)
        {
            arr->Address[i] = arr->Address[i + 1]; // shift left
        }
        arr->length--;
    }
    else
    {
        printf("Invalid position for deletion\n");
    }
}
int main()
{
    struct array arr;
    // initalise(&arrr, 6);
    // append(&arrr, 6);
    // append(&arrr, 3);
    // append(&arrr, 1);
    // append(&arrr, 5);
    // append(&arrr, 9);
    // display(&arrr);
    // insert(&arrr, 100, 3);
    // insert(&arrr, 100, 23);
    // display(&arrr);
    int n = 0;
    while (n != 7)
    {
        printf("Enter the option from the menu you want:\n");

        printf("1) Initalise an array \n2)Appendthe array\n3)insert at any position\n4)delete at last\n5)delete at any position\n6)append multiple in one go\n7)display the array\n8)exit\n ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            initalise(&arr);
            break;
        case 2:
            append(&arr);
            break;
        case 3:
            insert(&arr);
            break;
        case 4:
            delete_at_last(&arr);
            break;
        case 5:
            delete_at_pos(&arr);
            break;
        case 6:
            append_multiple_in_one_go(&arr);
            break;
        case 7:
            display(&arr);
            break;
        case 8:
            n=7;
            break;
        default:
            printf("Invalid input");
            break;
        }
    }

    free(arr.Address);
}