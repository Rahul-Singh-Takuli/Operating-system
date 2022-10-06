#include <bits/stdc++.h>
using namespace std;

struct Process {
	int pid; 
	int btime; 
	int atime; 
};

void findWaitingTime(Process proc[], int n, int waitt[])
{
	int rt[n];

	for (int i = 0; i < n; i++)
		rt[i] = proc[i].btime;

	int complete = 0, time = 0, min = INT_MAX;
	int shortest = 0, finish;
	bool check = false;

	while (complete != n) {
		for (int j = 0; j < n; j++) {
			if ((proc[j].atime <= time) &&
			(rt[j] < min) && rt[j] > 0) {
				min = rt[j];
				shortest = j;
				check = true;
			}
		}

		if (check == false) {
			time++;
			continue;
		}
		rt[shortest]--;
		min = rt[shortest];
		if (min == 0)
			min = INT_MAX;
		if (rt[shortest] == 0) {

			complete++;
			finish = time + 1;

	waitt[shortest] = finish - proc[shortest].btime-proc[shortest].atime;

			if (waitt[shortest] < 0)
				waitt[shortest] = 0;
		}
		time++;
	}
}

void findTAT(Process proc[], int n, int waitt[], int tat[])
{
	for (int i = 0; i < n; i++)
		tat[i] = proc[i].btime + waitt[i];
}
void findavgT(Process proc[], int n)
{
	int waitt[n], tat[n], total_wt = 0,total_tat = 0;
	findWaitingTime(proc, n, waitt);
	findTAT(proc, n, waitt, tat);
	cout << "Processes "<< " Burst time "<< " Waiting time "<< " Turn around time\n";


	for (int i = 0; i < n; i++) {
		total_wt = total_wt + waitt[i];
		total_tat = total_tat + tat[i];
		cout << " " << proc[i].pid << "\t\t" << proc[i].btime << "\t\t " << waitt[i] << "\t\t " << tat[i] << endl;
	}

	cout << "\nAverage waiting time = " << (float)total_wt / (float)n;
	cout << "\nAverage turn around time = " << (float)total_tat / (float)n;
}

int main()
{
	Process pro[] = { { 1, 12, 5 }, { 2, 8, 4 }, { 3, 17, 1 }, { 4, 13, 2 } };
	int n = sizeof(pro) / sizeof(pro[0]);

	findavgT(pro, n);
	return 0;
}
