#include <stdio.h>

#define CAPACITY 10

typedef struct
{
    int key;
} Record;

Record hashTable[CAPACITY];

void initHashTable()
{
    for (int i = 0; i < CAPACITY; i++)
        hashTable[i].key = -1;
}

int hashFunction(int key)
{
    return key % CAPACITY;
}

void insertLinearProbing(int key)
{
    int hashVal = hashFunction(key);
    int i = 0;

    while (i < CAPACITY)
    {
        int probeIndex = (hashVal + i) % CAPACITY;

        if (hashTable[probeIndex].key == -1)
        {
            hashTable[probeIndex].key = key;
            printf("Inserted %d at index %d\n", key, probeIndex);
            return;
        }

        i++;
    }

    printf("Hash Table is FULL! Cannot insert %d\n", key);
}

int searchLinearProbing(int key)
{
    int hashVal = hashFunction(key);
    int i = 0;

    while (i < CAPACITY)
    {
        int probeIndex = (hashVal + i) % CAPACITY;

        if (hashTable[probeIndex].key == key)
            return probeIndex;

        if (hashTable[probeIndex].key == -1)
            return -1;

        i++;
    }

    return -1;
}

void deleteKey(int key)
{
    int index = searchLinearProbing(key);

    if (index == -1)
    {
        printf("%d not found! Cannot delete.\n", key);
        return;
    }

    hashTable[index].key = -1;
    printf("Deleted %d from index %d\n", key, index);
}

void displayHashTable()
{
    printf("\nHash Table:\n");
    for (int i = 0; i < CAPACITY; i++)
    {
        if (hashTable[i].key == -1)
            printf("Index %d : EMPTY\n", i);
        else
            printf("Index %d : %d\n", i, hashTable[i].key);
    }
    printf("\n");
}

int main()
{
    initHashTable();

    insertLinearProbing(12);
    insertLinearProbing(22);
    insertLinearProbing(32);
    insertLinearProbing(5);
    insertLinearProbing(15);
    insertLinearProbing(25);

    displayHashTable();

    int key = 22;
    int index = searchLinearProbing(key);
    if (index != -1)
        printf("%d found at index %d\n", key, index);
    else
        printf("%d not found\n", key);

    deleteKey(22);
    displayHashTable();

    return 0;
}
