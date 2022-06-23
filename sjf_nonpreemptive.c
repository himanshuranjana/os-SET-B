#include <stdio.h>
#include<limits.h>
#include<stdbool.h>
struct process_struct
{
    int pid,at,bt,wt,tat,rt,ct,start_time;
}ps[100];
int main()
{
      int n,current_time=0,sum_tat=0,sum_wt=0,sum_rt=0,total_idle_time=0,prev=0,length_cycle,completed=0;
    int max_completion_time,min_arrival_time;
    bool is_completed[100]={false},is_first_process=true;
    printf("enter the number of process:");
    scanf("%d",&n);
    printf("enter the arrival times of:");
    for(int i=0;i<n;i++)
    {  printf("p%d:",i+1);
        scanf("%d",&ps[i].at);
        ps[i].pid=i;
     }
     printf("enter the burst times of:");
    for(int i=0;i<n;i++)
    {  printf("p%d:",i+1);
        scanf("%d",&ps[i].bt);
    }
    while(completed!=n)
    {int min_index=-1;
    int minimum =INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(ps[i].at<=current_time && is_completed[i]==0)
        {
            if(ps[i].bt<minimum)
            {
                minimum=ps[i].bt;
                min_index=i;
            }
            if(ps[i].bt==minimum)
            {
                if(ps[i].at<ps[min_index].at)
                {
                    minimum=ps[i].bt;
                    min_index=i;
                }    
            } 
        }
    }
    if(min_index== -1)
        current_time++;
 
    else
    {
        ps[min_index].start_time=current_time;
        ps[min_index].ct=ps[min_index].start_time+ps[min_index].bt;
        ps[min_index].tat=ps[min_index].ct-ps[min_index].at;
        ps[min_index].wt=ps[min_index].tat-ps[min_index].bt;
        ps[min_index].rt=ps[min_index].wt;
        sum_tat+=ps[min_index].tat; 
        sum_wt+=ps[min_index].wt;
        sum_rt+=ps[min_index].rt;
        total_idle_time+=(is_first_process==true)?0:(ps[min_index].start_time - prev);
        completed++;
        is_completed[min_index]=true;
        current_time=ps[min_index].ct;
        prev=current_time;
        is_first_process=true;
     }
}
    printf("Precess\t AT\tBT\tCT\tTAT\tWT \n");
    for (int i=0;i<n;i++)
        printf("%d     \t %d     \t%d\t%d\t%d\t%d\t\n",ps[i].pid,ps[i].at,ps[i].bt,ps[i].ct,ps[i].tat,ps[i].wt
        );
    printf("\n");
    printf("Average turn aound time:%f\n",(float)sum_tat/n);
    printf("Average waiting time:%f",(float)sum_wt/n);
    printf("sorted process:");
     for (int i=0;i<n;i++)
 {
  int pos=i;
  for(int j=i+1;j<n;j++)
  {
    if(ps[j].at<ps[pos].at)
    pos=j;
  }
  //swap(ps[i].bt,ps[pos].bt); 
   int temp=ps[i].at;
 ps[i].at=ps[pos].at;
 ps[pos].at=temp;
  //swap(ps[i].pid,ps[pos].pid);
   temp=ps[i].pid;
 ps[i].pid=ps[pos].pid;
 ps[pos].pid=temp;
}
 
    return 0;
}
