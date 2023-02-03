#include<stdio.h>

void BucketSort(int array[], int n)
{
int bucktCount[10],buckt[10][10];
int large,digCount,i,j,k,p,div,rem;
large=array[i];
// Search Largest Element from Array
for(i=0; i<n; i++)
{
if(array[i]>large)
large=array[i];
}
// Find out No. of Digit in the Largest Number
digCount=0;
while(large>0)
{
digCount++;
large=large/10;
}

div=1;
for(i=1; i<=digCount; i++)
{
// Creating No. of Bucket and Initialize with zero
for(j=0; j<10; j++)
bucktCount[j]=0;
for(j=0; j<n; j++)
{
rem=(array[j] / div) % 10;
buckt[rem][bucktCount[rem]]=array[j];
bucktCount[rem]++;
}
// Merge all Bucket in order
p=0;
for(j=0; j<10; j++)
{
k=0;
while(k<bucktCount[j])
{
array[p]=buckt[j][k];
p++;
k++;
}
}
div=div*10;
}
}
void main()
{
int array[100],n,i;

printf("\nEnter No. of Element : ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\nEnter value of element [%d] : ",i);
scanf("%d",&array[i]);
}
BucketSort(array, n);
printf("\nSorted Elements:");
for(i=0;i<n;i++)
printf("\t%d",array[i]);

}
