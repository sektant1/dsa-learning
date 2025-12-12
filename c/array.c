#include <stdio.h>

#define NELEMS(x) (sizeof(x) / sizeof((x)[0]))

int main()
{
    int numbers[5] = {1, 2, 3, 4, 5};

    // Accessing elements using array indexing
    printf("numbers[2] = %d\n", numbers[2]);  // Output: 3

    // Accessing elements using pointers
    printf("*(numbers + 2) = %d\n", *(numbers + 2));  // Output: 3

    // Pointer arithmetic
    int *ptr = numbers;
    printf("Pointer ptr points to numbers[0]: %d\n", *ptr);  // Output: 1
    ptr += 2;
    printf("Pointer ptr points to numbers[2]: %d\n", *ptr);  // Output: 3

    typedef struct Coordinate
    {
        int x;
        int y;
        int z;
    } coordinate_t;

    coordinate_t points[3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    printf("points[1].x = %d, points[1].y = %d, points[1].z = %d\n",
           points[1].x,
           points[1].y,
           points[1].z);
    // points[1].x = 4, points[1].y = 5, points[1].z = 6

    coordinate_t *ptr2 = points;

    printf("ptr2[1].x = %d, ptr2[1].y = %d, ptr2[1].z = %d\n",
           (ptr2 + 1)->x,
           (ptr2 + 1)->y,
           (ptr2 + 1)->z);
    // ptr[1].x = 4, ptr[1].y = 5, ptr[1].z = 6

    int arr[] = {1, 2, 3, 4, 5};

    // Calculate the number of elements
    // sizeof(arr) gives the total size of the array in bytes (e.g., 20)
    // sizeof(arr[0]) gives the size of one element in bytes (e.g., 4)
    size_t length = sizeof(arr) / sizeof(arr[0]);

    printf("Number of elements in the array: %zu\n", length);
    printf("Number of elements in the array: %zu\n", NELEMS(arr));

    return 0;
}
