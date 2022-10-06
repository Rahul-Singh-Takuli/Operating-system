#include<iostream>
using namespace std; 
 
int main() 
{ 

  int count,j,n,time,remain,flag=0, quantum; 
  int wtime=0,tatime=0,atime[10],btime[10],rt[10]; 
    
  cout<<"Enter Total Process:\t "; 
  cin>>n; 
  remain=n; 
  for(count=0;count<n;count++) 
  { 
    cout<<"Enter Arrival Time and Burst Time for Process "<<count+1<<":"; 
    cin>>atime[count];
    cin>>btime[count];
        
    rt[count]=btime[count]; 
  } 
  cout<<"Enter Time Quantum:\t"; 
  cin>> quantum; 
  
  cout<<"\n\n Process \t Turnaround Time \t Waiting Time\n\n"; 
  
  for(int i=0,time=0,count=0;remain!=0,i<70;i++) 
  { 
    if(rt[count]<= quantum && rt[count]>0) 
    { 
      time+=rt[count]; 
      rt[count]=0; 
      flag=1; 
    } 
    else if(rt[count]>0) 
    { 
      rt[count]-=quantum; 
      time+=quantum; 
    } 
    if(rt[count]==0 && flag==1) 
    { 
      remain--; 
      cout<<"p"<<count+1<<"\t|\t"<<time-atime[count]<<"\t|\t"<<time-atime[count]-btime[count]<<"\n"; 
      
      wtime+=time-atime[count]-btime[count]; 
      tatime+=time-atime[count]; 
      flag=0; 
    } 
        
    if(count==n-1) 
      count=0; 
    else if(atime[count+1]<=time) 
      count++; 
    else 
      count=0;
  } 
 cout<<"Avg Waiting Time= "<<wtime*1.0/n<<endl; 
 cout<<"Avg Turnaround Time = "<<tatime*1.0/n<<endl; 
 
  return 0; 
}
