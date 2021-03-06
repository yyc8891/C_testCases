#include <stdio.h>

void PrintArry(int A[],int num)
{
	int i=0;
	
	for(i=0;i<num;i++)
	{
		printf("%d ",A[i]);
		if(i==num-1)
			printf("\n");
	}
	
}

void insert_sort_shell(int A[],int start,int gap)
{
    int i=0;
    int j=0;
    int k=0;
    int tmp=0;
    
    i = start;
    j = i-gap;
    printf("\n i:%d j:%d gap:%d \n",i,j,gap);
    if(A[i]<A[j] && j>=0)
    {
        k = i;
        while (A[j]>A[k] && j>=0)
        {
            tmp = A[j];
            A[j] = A [k];
            A[k] = tmp;
            j-=gap;
            k-=gap;
        }
        PrintArry(A,10);
    }
    
}

void insert_sort_shell_inhanced(int A[],int start,int gap)
{
    int insert = A[start];
    int i = 0;
    
    for(i=start-gap; i>=0 && A[i]>insert; i-=gap)
    {
        A[i+gap]=A[i];
    }
    A[i+gap]=insert;
    
    PrintArry(A,10);
}

void shell_sort(int A[],int num)
{
    int gap[10]={0};
    int i = 0;
    int j = 0;
    int k = 0;
    int tmp = num;
    int gNum = 0;
    
    while(tmp>0)
    {
        tmp = tmp/2;
        gap[i]=tmp;
        i++;
    }
    gNum = i;
    PrintArry(gap,10);
    
    i=0;
// improve shell sort
    for( i=num/2;i>0;i/=2)
    {
        for(j=i;j<num;j++)
        {
            printf("\n j:%d gap:%d \n",j,i);
            insert_sort_shell_inhanced(A,j,i);
        }
    }
    
#if 0
    while(gap[i]>0)
    {
        for(k=0;k<gNum;k++)
        {
            for(j=k;j<num;j+=gap[i])
            {
                insert_sort_shell(A,j,gap[i]);
            }
        }
        
        i++;
    }
#endif
}

void insert_sort_update(int A[],int num)
{
    int i=0;
    int j=0;
    int k=0;
    int tmp=0;
    
    for(i=1;i<num;i++)
    {
        j=i-1;
        if(A[i]<A[j])
        {
            k = i;
            while (A[j]>A[k] && j>=0)
            {
                tmp = A[j];
                A[j] = A [k];
                A[k] = tmp;
                j--;
                k--;
            }
        }
        PrintArry(A,10);
    }
}
void insert_sort(int A[],int num)
{
    int i = 0;
    int j = 0;
    int k =0;
    int tmp = 0;
    int min = 0;
    
    for(i=1;i<num;i++)
    {
        j=i-1;
        if(A[i]<=A[j])
        {
            while(j>=0)
            {
                if(A[j]<A[i])
                {
                    break;
                }
                j--;
            }
            
            j++;
                
            printf("\n get i:%d j:%d\n",i,j);
            k=i;
            min = A[i];
            while(k>j)
            {
                tmp=A[k];
                A[k]=A[k-1];
                k--;
            }
            A[j]=min;
        }
        
        PrintArry(A,10);
            
    }
    
}

void pop_sort(int A[],int num)
{
	int i = 0;
	int j = 0;
	int pop = num;
	int tmp = 0;
	
	while( pop > 1 )
	{
		pop--;
		i = 0;
		j = 1;
		
		while(j<=pop)
		{
			if(A[i]>A[j])
			{
				tmp=A[i];
				A[i]=A[j];
				A[j]=tmp;
			}	
			i++;
			j++;
		}	
		
	}	
	
}

void select_sort(int A[],int num)
{
	int tmp = 0;
	
	int i = 0;
	int j = 0;
	int k = 0;
		
	for(i=0;i<num;i++)
	{
		tmp=A[i];
		k=i;
		for(j=i+1;j<num;j++)
		{
			if(tmp>A[j])
			{
				tmp=A[j];
				k=j;
			}
		}
		if(k!=i)
		{	
			A[k]=A[i];
			A[i]=tmp;
		}
	}
	
}

int fast_sort(int A[],int top,int end)
{
	int i=0;
	int j=0;
	int temp=0;
	int x=0;

	if(top >= end)
	{
		return 0;
	}
	else
	{
		
		i=top;
		j=end;
		x=A[i];
		
		while(i<=j)
		{	
			if(i==j)
			{
				A[i]=x;
				PrintArry(A,10);
				break;
			}	
			while(j>i)
			{
				if(A[j]<x)
				{	
					temp=A[j];
					break;
				}
				j--;
			}
			A[i]=temp;
			while(i<j)
			{
				i++;
				if(A[i]>x)
				{
					temp=A[i];
					A[j]=temp;
					break;
				}	
			}	
			PrintArry(A,10);
		}
		printf("\n i : %d \n",i);
		printf("\n top : %d \n",top);
		printf("\n end : %d \n",end);
		fast_sort(A,top,i);
		fast_sort(A,i+1,end);
	}
    return 0;
}

int main(void)
{
	int Arry[10]={34,19,234,67,1,111,5,734,58,92};
	int ret = 0;
	
	PrintArry(Arry,10);
	//printf("\n test for fast sort \n");
	//fast_sort(Arry,0,9);
	
	//printf("\n test for select sort \n");
	//select_sort(Arry,10);
	
	//printf("\n test for pop sort \n");
	//pop_sort(Arry,10);
	
    //printf("\n test for insert sort \n");
    //insert_sort_update(Arry,10);
    
    printf("\n test for shell sort \n");
    shell_sort(Arry,10);
    
	//printf("\n ret : %d \n",ret);
	PrintArry(Arry,10);
}
