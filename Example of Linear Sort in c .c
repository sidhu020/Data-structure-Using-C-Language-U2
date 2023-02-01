#include<stdio.h>
void sort(int a[],int n)
{ int i,j,t;
for(i=0;i<n;i++)
{ for(j=i+1;j<n;j++)
{ if(a[i]>a[j])
{ t=a[i];
a[i]=a[j];
a[j]=t;
}
}
}
printf("\nAfter Sorting\n");
for(i=0;i<n;i++)
{ printf("\t %d",a[i]);
}
}
void main()
{ int a[5],n,i;

printf("\nEnter Total Number of Data\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{ printf("\nEnter the No.");
scanf("%d",&a[i]);
}
printf("\n Before Sorting\n");
for(i=0;i<n;i++)
{ printf("\t%d",a[i]);
}
sort(a,n);

}



*/ *OUTPUT:*
Enter total number of Data: 3
Enter the No. 3
Enter the No. 1
Enter the No. 2
Before Sorting
3 1 2
After Sorting
1 2 3 */


(1) Linear Sort:
 In this sorting, we will check the value via particular index step by step.
 First index value is checking the condition that this number is greater or not means if
found greater smaller number exchange with this number, if not it will staying as it is.
 Then, step-by-step every index value will check with all numbers after this number, and
which number is found smaller it will exchange with this number.
 At last we can see that all numbers are sorted.
 This type of sorting is called as Linear Sorting.
 We will perform this task without UDF and with UDF.
 This sorting performs as an ascending or a descending.
