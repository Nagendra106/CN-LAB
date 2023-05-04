#include<stdio.h>
struct node{
    int dist[20];
    int from[20];
}rt[10];
void main()
{
    int i,j,k,count=0,n,cost[20][20];
    printf("enterr the number of the nodes\n");
    scanf("%d",&n);
    printf("enter the cost matrix");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
            cost[i][i]=0;
            rt[i].dist[j]=cost[i][j];
            rt[i].from[j]=j;
        }
    }
    do{
        count=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                for(k=0;k<n;k++)
                {
                    if(rt[i].dist[j]>cost[i][k]+rt[k].dist[j])
                    {
                        rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
                        rt[i].from[j]=k;
                        count++;
                    }
                }
            }
        }
    }while(count!=0);
    
    for(i=0;i<n;i++)
    {
        printf("for the node %d\n",i+1);
        for(j=0;j<n;j++)
        {
            printf("the node %d via %d distance is %d",j+1,rt[i].from[j]+1,rt[i].dist[j]);
        }
        printf("\n");
    }
}