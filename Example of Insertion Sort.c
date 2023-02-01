#include<stdio.h>
int key;
int ins_sort(int list[])
{
int i=0;
int j,k;
printf("\n\n\nEnter Element: ");
scanf("%d",&key);
printf("\n\n\nSelected Element:%d",key);
while(key!=0)
{ k=i-1;
while((key<list[k])&&(k>=0))
{ list[k+1]=list[k];
--k;
}
list[k+1]=key;
printf("\n\n\nList After Inserting:");
for(j=0;j<=i;j++)
printf("%d",list[j]);
printf("\n\n\nEnter Element:");
scanf("%d",&key); printf("\n\n\nSelectedElement:%d",key); i++;
}
return(i);
}
void display(int list[],int no)
{ int j;
printf("\n\n\n\nAfter Sorted List");
for(j=0;j<no;j++)
printf(" %d" ,list[j]);

}
void main()
{ int list[100];
int n1;

n1=ins_sort(list);
display(list,n1);

}


/* OUTPUT:
Enter Element: 4
Selected Element: 4
After Inserting List: 4
Enter Element: 1
Selected Element: 1
After Inserting List: 1 4
Enter Element: 3
Selected Element: 3
After Inserting List: 1 3 4
Enter Element: 0
After Sorting:
1 3 4 */
