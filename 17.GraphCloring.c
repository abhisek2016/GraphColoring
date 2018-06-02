#include<stdio.h>
int x[10],g[10][10],n,i,j,m;
void next_value(int k)
{   int j;
while(1){
    x[k]=(x[k]+1)%(m+1);
    if(x[k]==0)
    {
        return;
    }
    for(j=1;j<=n;j++)
    {
        if(g[k][j]!=0 && (x[k]==x[j]))
        {
            break;
        }
    }
    if(j==n+1)
    return;
}
}
void coloring(int k){
    do
    {
        next_value(k);
        if(x[k]==0)
        return;
        if(k==n)
        {
            for(i=1;i<=n;i++)
            {
                printf("vertex %d,color no %d",i,x[i]);
                printf("\n");
            }
        }
        else
        {
            coloring(k+1);
        }
    }while(k<n+1);
}
int main()
{
    int e,k,l;
    printf("Enter no of Vertices:");
    scanf("%d",&n);
    printf("Enter no of edges:");
    scanf("%d",&e);
    printf("Enter no of color:");
    scanf("%d",&m);
    for(i=0;i<=n;i++)
    for(j=0;j<=n;j++)
    {
        g[i][j]=0;
    }
    printf("\nEnter u and v of an edge:");
    for(i=1;i<=e;i++)
    {
        printf("\nfor edge%d\n",i);
        scanf("%d%d",&k,&l);
        g[k][l]=1;
        g[l][k]=1;
    }
    for(i=0;i<=n;i++)
    {
        x[i]=0;
    }
    printf("The cloring possible are:\n");
    coloring(1);
}
