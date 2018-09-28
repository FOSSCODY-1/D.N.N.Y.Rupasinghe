#include <stdio.h>
#include <stdlib.h>

int insertion_sort(int *flag);
int selection_sort(int *flag);
int bubble_sort(int *flag);

//Used a flag here in-order to avoid duplicate codes (otherwise will have to have seperate code sets for each ascending and descending)

int n; //number of inputs (number of elements in the set of numbers)
int num[100]; //the set of numbers (Array) 

int main()
{
	int opt1, opt2,i;
	printf("\t\t\t\tSorterPlus\n\n");
	do
	{
	    //Menu to select the sorting method and the sorting order
	    printf("\n***Please select the sorting method***\n");
	    printf("1. Insertion Sort\n");
	    printf("2. Selection Sort\n");
	    printf("3. Bubble Sort\n");
	    printf("4. Exit\n");
	    printf("\n***Plese select the sorting order***\n");
	    printf("1. Ascending\n");
	    printf("2. Descending\n");
	    printf("3. Exit\n");
	    printf("\nPlease enter the sorting method and order seperated by a space:");
	    scanf("%d %d",&opt1,&opt2);
	    
	    switch(opt1) //switch to perform the actions according to the user's selected option(opt1)
	    {
	    	case 1:
	    		insertion_sort(&opt2);
	    		break;
	    	case 2:
	    		selection_sort(&opt2);
	    		break;
	    	case 3:
	    		bubble_sort(&opt2);
	    		break;
		case 4:
	    		printf("\nThank you for using SorterPlus! Have a nice day!\n");
	    		break;
		default:
	    		printf("\nInvalid option!!!\n");
	     }
	}
	while(opt1!=4 && opt2!=3);
	return 0;
}

/*Algorithm for insertion sort
step 1 - Set the marker for the unsorted elements (Initially to the index 1 (not 0) as because array with only 1 element is already sorted
step 2 - Select the first unsorted number
step 3 - Swap that unsorted number with the left side until that number is in its proper place (in the sorted array)
step 4 - Repeat step 2 & step 3 until there are no any unsorted elements*/

int insertion_sort(int *flag)
{
	//int *flag=&opt2
	int i,j,k;
	int temp;
	printf("\nPlease enter number of inputs you wish to add:");
	scanf("%d",&n);
	printf("Please enter %d numbers:\n",n);
	for(i=0;i<n;i++)
	{
	    scanf("%d",&num[i]);
	}
	printf("\nThe inserted set of numbers are:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",num[i]);
	}
	printf("\n\n\nThe step by step visualization:\n");
	for(i=1;i<n;i++) 
	{
		temp=num[i];
		if(*flag==1) //*flag=opt2=1 -> Ascending order
		{
		    for(j=i;j>0 && temp<num[j-1];j--) 
		    {
		    	num[j]=num[j-1];
			}
	    }
		else if(*flag==2) //*flag=opt2=2 -> Descending order
		{
		for(j=i;j>0 && temp>num[j-1];j--)
		    {
			    num[j]=num[j-1];
		    }
	    }
	    else 
	    printf("\nInvalid option!!!");
		
		num[j]=temp;
		
		//visualization of the sorting
		printf("\n\n");
		printf("\tStep %d:\n\t",i);
		for(k=0;k<n;k++)
		printf("%d\t",num[k]);
		printf("\n");
	}
	printf("\n\nThe sorted set of numbers:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",num[i]);
	}
		printf("\n\n");
		return 0;
}

/*Algorithm for selection sort (considering ascending order)
step 1 - Set the marker MIN for the first element of the array(initially index 0)
step 2 - Set the marker for the rest of the array starting at index MIN+1
step 3 - Find the minimum value of the array and swap it with the value at the marker MIN
step 4 - Increment the MIN marker to the next element
step 5 - Repeat step 2, step 3 & step 4 until the end of the array is reached*/

int selection_sort(int *flag)
{
	//int *flag=&opt2
	int i,j,k,minmax,temp;
	printf("\nPlease enter number of inputs you wish to add:");
	scanf("%d",&n);
	printf("Please enter %d numbers:\n",n);
	for(i=0;i<n;i++)
	{
	    scanf("%d",&num[i]);
	}
	printf("\nThe inserted set of numbers are:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",num[i]);
	}
	printf("\n\n\nThe step by step visualization:\n");
	for(i=0;i<n;i++)
	{
		for(j=i+1,minmax=i;j<n;j++)
		{
			if(*flag==1) //*flag=opt2=1 -> Ascending order
			{
			    if(num[j]<num[minmax])
			    {
				    minmax=j;
			    }
		    }
		    else if(*flag==2) //*flag=opt2=2 -> Descending order
		    {
		    	if(num[j]>num[minmax])
			    {
				    minmax=j;
			    }
			}
			else
			printf("\nInvalid option!!!");
		}
		temp=num[minmax];
		num[minmax]=num[i];
		num[i]=temp;
		
		//visualization of the sorting
		printf("\n\n");
		printf("\tStep %d:\n\t",i+1);
		for(k=0;k<n;k++)
		printf("%d\t",num[k]);
		printf("\n");
	}
	printf("\n\nThe sorted set of numbers:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",num[i]);
	}
	printf("\n\n");
	return 0;
}

/*Algorithm for bubble sort (considering ascending order)
step 1 - Set the marker to the last element of the unsorted array
step 2 - Swap with the previous adjacent element if they are unsorted(not in the required order)
step 3 - Decrease the marker by one index
step 4 - Repeat step 2 & step 3 until the marker reached the first element of the unsorted array
(now the first index of the array is sorted and the rest of the array is unsorted)
step 5 - Repeat step 1, step 2, step 3 & step 4 until the array is sorted */

int bubble_sort(int *flag)
{
	//int *flag=&opt2
	int i,j,k,temp;
	printf("\nPlease enter number of inputs you wish to add:");
	scanf("%d",&n);
	printf("Please enter %d numbers:\n",n);
	for(i=0;i<n;i++)
	{
	    scanf("%d",&num[i]);
	}
	printf("\nThe inserted set of numbers are:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",num[i]);
	}
	printf("\n\n\nThe step by step visualization:\n");
	for(i=0;i<n;i++)
	{
		for(j=n-1;j>i;--j)
		{
			if(*flag==1) //*flag=opt2=1 -> Ascending order
			{
			    if(num[j]<num[j-1])
			    {
				    temp=num[j-1];
				    num[j-1]=num[j];
					num[j]=temp;
				}
		    }
		    else if(*flag==2) //*flag=opt2=2 -> Descending order
		    {
		    	if(num[j]>num[j-1])
			    {
				    temp=num[j-1];
				    num[j-1]=num[j];
					num[j]=temp;
				}
			}
			else
			printf("\nInvalid option!!!");
		}
		
		//visualization of the sorting
		printf("\n\n");
		printf("\tStep %d:\n\t",i+1);
		for(k=0;k<n;k++)
		printf("%d\t",num[k]);
		printf("\n");
	}
	printf("\n\nThe sorted set of numbers:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",num[i]);
	}
	printf("\n\n");
	return 0;
}


