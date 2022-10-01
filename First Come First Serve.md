#include<stdio.h>
#include<conio.h>
#define max 30

void  main(){
    int bt[max],wt[max],tat[max],n;
    float awt,atat;

    printf("Enter the no of process-- ");
    scanf("%d",&n);

    printf("Enter burst time of process-\n ");
    for(int i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }
    
    printf("Process\tBurst time\tWaiting Time\tTurn Around Time\n");

    for(int i=0;i<n;i++){
        wt[i]=0;
        tat[i]=0;
        for(int j=0;j<i;j++){
            wt[i]=wt[i]+bt[j];
        }
        tat[i]=wt[i]+bt[i];
        awt=awt+wt[i];
        atat=atat+tat[i];
        printf("%d\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],tat[i]);

    }
    awt=awt/n;
    atat=atat/n;
    printf("Arerage Wating time is %f\n",awt);
    printf("Arerage Turn around time is %f",atat);
    getchar();

}
