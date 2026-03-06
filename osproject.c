#include <stdio.h>
#include <string.h>

int main()
{
    int n,i,time=0,completed=0,highest;
    
    int at[10],bt[10],pr[10];
    int rt[10],ct[10],tat[10],wt[10];
    char pid[10][5];

    printf("Enter number of processes:\n");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%s %d %d %d",pid[i],&at[i],&bt[i],&pr[i]);
        rt[i]=bt[i];
    }

    while(completed<n)
    {
        highest=-1;

        for(i=0;i<n;i++)
        {
            if(at[i]<=time && rt[i]>0)
            {
                if(highest==-1 || pr[i]>pr[highest])
                highest=i;
            }
        }

        if(highest==-1)
        {
            time++;
            continue;
        }

        rt[highest]--;
        time++;

        if(rt[highest]==0)
        {
            completed++;

            ct[highest]=time;
            tat[highest]=ct[highest]-at[highest];
            wt[highest]=tat[highest]-bt[highest];
        }
    }

    float avgwt=0,avgtat=0;

    printf("\nWaiting Time:\n");
    for(i=0;i<n;i++)
    {
        printf("%s %d\n",pid[i],wt[i]);
        avgwt+=wt[i];
    }

    printf("\nTurnaround Time:\n");
    for(i=0;i<n;i++)
    {
        printf("%s %d\n",pid[i],tat[i]);
        avgtat+=tat[i];
    }

    printf("\nAverage Waiting Time: %.2f\n",avgwt/n);
    printf("Average Turnaround Time: %.2f\n",avgtat/n);

    return 0;
}
