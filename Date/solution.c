#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct date{
    int day,month,year;
    };
int main() {
    int n;
    scanf("%d",&n);
    struct date input[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d",&input[i].day);
        scanf("%d",&input[i].month);
        scanf("%d",&input[i].year);

    }
    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if (input[i].year > input[j].year)
            {
                struct date temp = input[i];
                input[i] = input[j];
                input[j] = temp;
            }
            else if (input[i].year == input[j].year && input[i].month > input[j].month)
            {
                struct date temp = input[i];
                input[i] = input[j];
                input[j] = temp;
            }
            else if (input[i].year == input[j].year && input[i].month == input[j].month && input[i].day > input[j].day)
            {
                struct date temp = input[i];
                input[i] = input[j];
                input[j] = temp;
            }

        }
    }
    for(int i=0; i<n; i++)
    {
        printf("%d %d %d\n",input[i].day,input[i].month,input[i].year);
    }
    return 0;
}
