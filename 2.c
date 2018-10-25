#include<stdio.h>


int f=0,r=0,i,y;

void push(int a[],int x)
{
    if(r==5)
    {
        printf("queue is overflowed:\n");
        return;
    }



    else
    {
        r=r+1;
        printf("r= %d ",r);

        a[r]=x;
    }

    if(f==0)
    {
        f=1;
    }

    printf("f= %d ",f);


}

void pop(int a[])
{
    if(f==0)
    {
        printf("queue is underflowed:\n");
        return;
    }

    y=a[f];

    if(f==r)
    {


    printf("queue is empty:\n");

    f=0;
    r=0;
    }

    else
    {
        f=f+1;
    }



}

void display(int a[])
{
     for(i=f;i<=r;i++)
    {
        printf("%d\n",a[i]);
    }

}


main()
{


int a[5],x;

while(x!=0)
{

printf("enter the operation: 1. insert 2.delete 3.display\n");
scanf("%d",&x);

switch(x)
{
case 1:
    {
        int z;
        printf("enter the element u want to enter:\n");
        scanf("%d",&z);
        push(a,z);
        break;
    }


    case 2:
        {
            pop(a);
            break;
        }


    case 3:
            {
              display(a);
              break;  }

}

}

}


