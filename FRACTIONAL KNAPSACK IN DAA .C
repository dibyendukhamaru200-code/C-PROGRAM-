#include <stdio.h>

int main()
{
    int n = 7;
    float weight[] = {2,5,7,3,1,4,6};
    float profit[] = {10,25,35,15,8,20,30};
    float ratio[7];
    float capacity = 15;
    float totalProfit = 0;

    int i,j;

    for(i=0;i<n;i++)
        ratio[i] = profit[i]/weight[i];

    // sorting according to ratio (descending)
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(ratio[i] < ratio[j])
            {
                float temp;

                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        if(capacity >= weight[i])
        {
            capacity = capacity - weight[i];
            totalProfit = totalProfit + profit[i];
        }
        else
        {
            totalProfit = totalProfit + ratio[i] * capacity;
            break;
        }
    }

    printf("Maximum Profit = %.2f", totalProfit);

    return 0;
}
