#include<stdio.h>//use for standard input output
#include<conio.h>
int min(int a,int b)
{
    if(a<b)
    return a;
    else
    return b;
}

int main()
{ int c=4,v,i,j,z,k=0;

    printf("enter value:");
    scanf("%d",&v);
    int value[v];
    int table [c+1][v+2];
    table[1][0]=1;
    table[2][0]=2;
    table[3][0]=5;
    table[4][0]=10;

    for(i=0;i<=v;i++)
    table[0][i+1]=i;

    for(i=0;i<c;i++)
    table[i+1][1]=0;

    for(i=2;i<v+2;i++)
    table[1][i]=i-1;

    for(i=1;i<c+1;i++)
    {
        for(j=2;j<v+2;j++)
        {
        if(table[i][0]>table[0][j])
        table[i][j]=table[i-1][j];
        else
        table[i][j]=min(table[i-1][j],1+table[i][table[0][j]-table[i][0]+1]);
    }
}
i=c;
j=v+1;
int w=v;
while(w!=0)
{
    while (table[i][j]==table[i-1][j] && i>1)
    {
        i--;
    }
    w-=table[i][0];
    value[k]=table[i][0];
    k++;
    j=w+1;    
    
}
printf("total %d coins are required\n",table[c][v+1]);
printf("value of coins is:");
printf(" ");
for(i=0;i<k;i++)
printf("%d ",value[i]);
getch();

}
