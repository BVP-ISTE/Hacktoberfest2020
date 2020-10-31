//Appending in a Array
#include<stdio.h>
struct Array
{
 int A[10];
 int size;
 int length;
};
 void Display(struct Array arr)
 {
 int i;
 printf("\nElements are\n");
 for(i=0;i<arr.length;i++)
 printf("%d ",arr.A[i]);
 }
 //error in the below segment
//-------------
 void Append(struct Array *arr,int x)
 {
 if(arr->length<arr->size)
 arr->A[arr->length++]=x;
 }
//--------------
int main()
{
struct Array arr1={{2,3,4,5,6},10,5};


Append(&arr1,15);


Display(arr1);
 return 0;
}
