#include<stdio.h>
 
int main()
{
    int at[20],bt[20],xt[20],ct[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp,count=0;
    float avg_wt,avg_tat,tot_ct;
    printf("Enter number of process:");
    scanf("%d",&n);
    
    printf("\nEnter Arrival Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&at[i]);
        p[i]=i+1;         
    }
    for(i=0;i<n;i++)
    {
    	if(at[i]==0)
    	{
    		printf("Error you have enter 0 as arrival time");
    		break;
		}
	else{
 
    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;         
    }
    for(i=0;i<n;i++)
    {
    	xt[i]=bt[i];
	}
	
	
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(at[j]<at[pos])
                pos=j;
            
            else if(at[j]==at[pos]){
            	if(bt[j]<bt[pos])
            		pos=j;
			}
        }
 
        temp=at[i];
        at[i]=at[pos];
        at[pos]=temp;
        
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    
for(i=0;i<n;i++){
	ct[i]=0;
}
    
    for(i=0;i<n;i++)
    {
    	if(bt[i]>2)
    	{
    		xt[i]=bt[i]-2;
    		count=count+2;
		}
		else{
			ct[i]=bt[i]+count;
			count=count+bt[i];
		}
	}
	for(i=0;i<=n;i++)
	{
		if(ct[i]==0)
		{
			ct[i]=count+xt[i];
			count=ct[i];					
		}
}
	for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        total+=tat[i];
    }
    avg_tat=(float)total/n;     
    total=0;
 
 
    for(i=0;i<n;i++)
    {
        wt[i]=tat[i]-bt[i];
 
        total+=wt[i];
    }
 
    avg_wt=(float)total/n;
    
    total=0;
    
    for(i=0;i<n;i++)
    {
        total+=ct[i];
    }
    tot_ct=(float)total;     
 
    printf("\nProcess\t     Arrival Time	Burst Time	  Completition Time    \tTurnaround Time  Waiting Time");
    for(i=0;i<n;i++)
    {
        printf("\np%d\t\t  %d\t\t  %d\t\t	%d\t\t    %d\t\t\t%d",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
 
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
    printf("\nTotal Completition Time=%f unit\n",tot_ct);
}
}
}
