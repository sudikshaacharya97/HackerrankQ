#include <stdio.h>
#include <stdlib.h>
struct node{
int data;
int visited;
int level;
struct node *parent;
};
int front=0,rear=-1;
int q[100000];
int countlevel=0;
void push(int data)
{   rear++;
    q[rear]=data;
}
int pop()
{
    if(front>rear)
        return -1;
    int a=q[front];
    front++;
    return a;
}
int isempty()
{
    if(front>rear)
        return 1;
    return 0;
}
int vertexnumber=1;
int adj[10000][10000];
struct node *arr[100000];
void addvertex(int value)
{
    struct node *p=(struct node*)malloc(sizeof(struct node));
    p->data=value;
    p->visited=0;
    p->parent=NULL;
    p->level=0;
    arr[vertexnumber++]=p;
}
void addedge(int m,int n)
{
    adj[m][n]=1;
    adj[n][m]=1;
}
int adj_node(int number,int y)
{int i;
    for(i=1;i<vertexnumber;i++)
    {
        if(((arr[i]->visited)==0)&&adj[number][i]==1)
        {
            arr[i]->visited=1;
            arr[i]->level=arr[number]->level+1;
            if(arr[i]->level==y)
                countlevel++;
            return i;
        }
    }
    return 0;
}
void BFS(int start,int z)
{
    push(start);
    arr[start]->visited=1;
    while(!isempty())
    {
        int printable=pop();

        int abc=1;
        while(abc!=0)
        {
            abc=adj_node(printable,z);
            if(abc!=0)
            push(abc);
        }

    }
}
int main()
{   int n,i,x,a,b;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        addvertex(i);
        n--;
    while(n--)
    {
        scanf("%d%d",&a,&b);
        addedge(a,b);
    }
    scanf("%d",&x);
BFS(1,x-1);
printf("%d",countlevel);
return 0;
}
