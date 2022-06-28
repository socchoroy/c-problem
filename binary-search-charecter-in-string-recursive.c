#include <stdio.h>
#include <string.h>
#define size 100
int search(char know[], int start, int highest, char want);
int main()
{
    int len, pos, start = 0, i, j;
    char a[size], ch, temp;
    printf("Please Enter a string : ");
    gets(a);
    len = strlen(a);
    printf("Please Enter which charecter you want to search : ");
    scanf("%c", &ch);
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
    int high=len-1;

    pos = search(a, start, high, ch);
    if (pos == -1)
        printf("sorry! we didn't found it!");
    else
        printf("yes!we found it at %d position", pos + 1);

    return 0;
}
int search(char know[], int start, int highest, char want)
{
    
    int mid = (start + highest) / 2;
    if(start>highest)
    {
        return -1;
    }
    else if(know[mid] == want)
        return mid;
    else if (know[mid] < want)
       start=mid-1;
    else
        highest = mid +1;

  

    return search(know, start + 1, highest - 1, want);
}