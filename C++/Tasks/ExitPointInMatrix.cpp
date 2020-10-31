//Exit Point in a Matrix

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int st=0,en=0;
    int arr[][3]={{0,0,1},{0,0,0},{0,0,1}};
    endpoint(st,en,arr);

}

void endpoint(int r, int c, int arr[][3])
{
    int m=3,n=3,i=r,j=c;

    for(j=c;j<n;j++)
    {

        if(arr[i][j]!=1)
        {

            if(j==n-1)
            {
                printf("%d %d",i,j);
                exit(0);
            }
            continue;
        }
        else
        {
            for(i=r+1;i<m;i++)
            {
                if(arr[i][j]!=1)
                 {
                     if(i==m-1)
                    {
                        printf("%d %d",i,j);
                        exit(0);
                    }
                    continue;
                 }
                 else{
                    if(j==0)
                      {
                          printf("%d %d",i,j);
                          exit(0);
                      }
                    for(j=j-1;j>=0;j--)
                    {
                        if(arr[i][j]!=1)
                        {
                            if(j==0)
                            {
                                printf("%d %d",i,j);
                                exit(0);
                            }
                            continue;
                        }
                        else
                        {
                            for(i=i-1;i>=0;i--)
                            {
                                if(arr[i][j]!=1)
                               {
                                    if(i==0)
                                    {
                                        printf("%d %d",i,j);
                                        exit(0);
                                    }
                                    continue;
                               }
                               else
                               {

                                   endpoint(i,j+1,arr);
                               }

                            }

                        }
                    }
                 }
            }
        }
    }
}
