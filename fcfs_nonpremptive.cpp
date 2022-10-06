#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"enter the total no. of process"<<endl;
    int n;
    cin>>n;
    int p_name[n];
    for(int i=0;i<=n;i++)
    {
        p_name[i]=i+1;//for assinging the process name like p1,p2......
    }
    int A_time[n];
    int B_time[n];
    cout<<"enter the arrival time of processes"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>A_time[i];//for assinging arrival time of process
    }
    cout<<"enter the burst time of process"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>B_time[i]; //for assinging burst time of process
    }


    // put arrival time and process name in multimap
    multimap<int,int>pmp;
    for(int i=0;i<n;i++)
    {
        pmp.insert({A_time[i],p_name[i]});//process name is sorted w.r.t arrival time
    }

    multimap<int,int>mp;//for arrival time and burst time
    for(int i=0;i<n;i++)
    {
    
        mp.insert({A_time[i],B_time[i]});//all the element become sorted order w.r.t arrival time due to multimap

    }

    int C_time[n+1];     //for assinging value of complition time
    C_time[0]=0;
    int i=0;
    int T_A_T[n];     //for assigning value of turn around time
    int W_time[n];     // for waiting time
    float tat=0;
    float wt=0;
    for(auto it=mp.begin();it!=mp.end();it++)//now calculate the completion time
    {

        if(C_time[i]<(*it).first)
        {
            C_time[i+1]=(*it).first-C_time[i]+(*it).second+C_time[i];
        }
        else
        {
            C_time[i+1]=C_time[i]+(*it).second;
        }
        T_A_T[i]=C_time[i+1]-(*it).first;
        W_time[i]=T_A_T[i]-(*it).second;
        tat=T_A_T[i]+tat;
        wt=W_time[i]+wt;
        i++;
    }

    //for printing output in tabular form of all process
    i=0;
    cout<<"P.NO.\t"<<"At\t"<<"Bt\t"<<"Ct\t"<<"TAT\t"<<"Wt\t"<<endl;
    auto it1=pmp.begin();
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        cout<<"P"<<(*it1).second<<"\t"<<(*it).first<<"\t"<<(*it).second<<"\t"<<C_time[i+1]<<"\t"<<T_A_T[i]<<"\t"<<W_time[i]<<endl;
        i++;
        it1++;
    }
    
    //calculate avg tat and avg wt
    tat=tat/n;
    wt=wt/n;
    printf("\nAverage TAT:- %0.2f",tat);
    printf("\nAverage Wt:-  %0.2f",wt);

    cout<<endl;
    return 0;
}
