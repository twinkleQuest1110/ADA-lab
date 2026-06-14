#include <stdio.h>

int main()
{
    int n;
    printf("Enter no. of students:");
    scanf("%d", &n);
    int arr[n];
    printf("---ENTER STUDENTS MARKS---\n");
    int min = arr[0], max = 0, sum = 0;

    for (int i = 0; i < n; i++)
    {
        printf("Enter %d Student marks:", i + 1);
        scanf("%d", &arr[i]);
        if (min > arr[i])
        {
            min = arr[i];
        }
        if (max < arr[i])
        {
            max = arr[i];
        }
        sum += arr[i];
    }
    int avg = sum / n;
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > avg)
        {
            c++;
        }
    }
    printf("\nMax marks of Student is:%d",max);
    printf("\nMin marks of Student is:%d",min);

    printf("\nThere are %d studends who's marks is above avg marks::",c);
    
    return 0;
    }
