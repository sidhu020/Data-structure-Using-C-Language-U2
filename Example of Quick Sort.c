#include<stdio.h>
void quick(int list[],int first,int last)
{ int t,low,high,pivot;
low=first;
high=last;
pivot=list[(first+last)/2.0];
do
{ while (list [low]<pivot)

low++;
while (list [high]>pivot)
high--;
if (low<=high)
{ t=list [low];
list [low++]=list[high];
list [high--]=t;
}
} while (low<=high);

if (first<high)
quick (list,first,high);
if (low<last)
quick (list,low,last);

}
void main()
{ int list[100],i,n;
printf("\nHowmany elements do you want?");
scanf("%d",&n);
for(i=0;i<n;i++)
{ printf("\nEnter the No[%d]:",i+1);
scanf("%d",&list[i]);
}
quick(list,0,n-1);
printf("\nAfter Sorting:\n");
for(i=0;i<n;i++)
printf("\t %d",list[i]);
}
