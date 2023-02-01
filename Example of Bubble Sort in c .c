#include<stdio.h>
void bubble_sort(int a[],int n)
{ int i,j,t;
for(i=0;i<n;i++)
{ for(j=0;j<n-i-1;j++)
{ if(a[j]>a[j+1])
{ t=a[j];
a[j]=a[j+1];
a[j+1]=t;
}
}
}
printf("\nAfter Sorting:\n");
for(i=0;i<n;i++)
printf("\t %d",a[i]);
}
void main()
{ int a[5],n,i;

printf("\nEnter total number of data:");
scanf("%d",&n);
for(i=0;i<n;i++)
{ printf("\nEnter the value:");
scanf("%d",&a[i]);
}

printf("\nBefore Sorting\n");
for(i=0;i<n;i++)
printf("\t %d",a[i]);
bubble_sort(a,n);

}


/* Enter total number of Data: 6
Enter the No. 3
Enter the No. 1
Enter the No. 2
Enter the No. 6
Enter the No. 5
Enter the No. 4
Before Sorting
3 1 2 6 5 4
After Sorting
1 2 3 4 5 6 */

