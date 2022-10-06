#include<iostream>
using namespace std;
int main()
{
    int burstt[20], pid[20], waitt[20], turnat[20], priority[20], i, j, n, total=0, pos, temp,      awt, atat;
cout<<"Enter Total Number of Process:";
    cin>>n;
 
    cout<<"Enter Burst Time and Priority"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<"P["<<i+1<<"]"<<endl;
        cout<<"Burst Time:";
        cin>>burstt[i];
        cout<<"Priority:";
        cin>>priority[i];
        pid[i]=i+1;      
    }
 
    
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(priority[j]<priority[pos])
                pos=j;
        }
 
        temp=priority[i];
        priority[i]=priority[pos];
        priority[pos]=temp;
 
        temp=burstt[i];
        burstt[i]=burstt[pos];
        burstt[pos]=temp;
 
        temp=pid[i];
        pid[i]=pid[pos];
        pid[pos]=temp;
    }
 
    waitt[0]=0;            
 
    
    for(i=1;i<n;i++)
    {
        waitt[i]=0;
        for(j=0;j<i;j++)
            waitt[i]+=burstt[j];
 
        total+=waitt[i];
    }
 
    awt=total/n;      
    total=0;
 
    cout<<"\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";
    for(i=0;i<n;i++)
    {
        turnat[i]=burstt[i]+waitt[i];     
        total+=turnat[i];
        cout<<"\nP["<<pid[i]<<"]\t\t  "<<burstt[i]<<"\t\t    "<<waitt[i]<<"\t\t\t"<<turnat[i];
    }
 
    atat=total/n;     
    cout<<"\n\nAverage Waiting Time="<<awt;
    cout<<"\nAverage Turnaround Time="<<atat;
 
    return 0;
}
