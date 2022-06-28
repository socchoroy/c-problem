#include <stdio.h>
#include <string.h>
#define size 100
int available(char have[], int high, int low, char search);
int main()
{
    int size_word, i, j, low = 0, high;
    char a[size], temp, search_word;
    printf("Please enter a string : ");
    gets(a);
    high = (strlen(a) - 1);
    // this is for comparing capital letter
    for (i = 0; i < strlen(a); i++)
    {
        for (j = i + 1; j < strlen(a); j++)
        {
            if (a[j] >= 65 && a[j] <= 90)
            {
                if (a[j + 1] >= 65 && a[j + 1] <= 90)
                {
                    if (a[j] > a[j + 1])
                    {
                        temp = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = temp;
                    }
                }
            }

            // this is for comparing small letter

            if (a[j] >= 97 && a[j] <= 122)
            {
                if (a[j + 1] >= 97 && a[j + 1] <= 122)
                {
                    if (a[j] > a[j + 1])
                    {
                        temp = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = temp;
                    }
                }
            }
        }
    }

    printf("Please Enter which Word you want to search : ");
    scanf("%c", &search_word);
    int stock;
    stock = available(a, high, low, search_word);
    if (stock == -1)
    {
        printf("sorry we didn't found it!");
    }
    else

    {
        printf("yes! we found it at %d position",stock);
    }
}
// this is function for search a charecter
int available(char have[], int high, int low, char search)
{
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;

        if (have[mid] == search)
            return mid;
        else if (have[mid] < search)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
