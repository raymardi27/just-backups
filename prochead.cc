#include<iostream>
using namespace std;

struct Process {
    int Pid,At,Bt,Tot,Wt,Priority;
}temp;

void get_input(Process p[],int n) {
    char c;
    cout<<"Is there Priority?(y/n): ";
    cin>>c;
    if(c == 'n') {
        cout<<"Input the data in the following order (ID,At,Bt):\n";
        for(int i =0; i < n; i++) {
            cin>>p[i].Pid>>p[i].At>>p[i].Bt;
            p[i].Priority=p[i].Tot=p[i].Wt=0;
        }
    }
    else {
        cout<<"Input the data in the following order (ID,At,Bt,Priority):\n";
        for(int i =0; i < n; i++) {
            cin>>p[i].Pid>>p[i].At>>p[i].Bt>>p[i].Priority;
            p[i].Tot=p[i].Wt=0;
        }
    }
}

void print_table(Process p[],int n) {
    cout<<"PID\tPriority\tArrival\tBurst\tTurnover\tWait\n";
    for(int i = 0; i < n;i++) {
        cout<<p[i].Pid<<"\t "<<p[i].Priority<<"\t\t"<<p[i].At<<"\t "<<p[i].Bt<<"\t "<<p[i].Tot<<"\t\t"<<p[i].Wt<<"\n";
    }
}

void calc_tot_and_print(Process p[],int n) {
    int t_psd=0;float avg_tot=0,avg_wt=0;//t_psd is time passed
    for(int i = 0; i < n; i++) {
        p[i].Wt=t_psd-p[i].At;
        avg_wt+=p[i].Wt;
        p[i].Tot=p[i].Wt+p[i].Bt;
        avg_tot+=p[i].Tot;
        t_psd+=p[i].Bt;
    }
    print_table(p,n);
    avg_tot=avg_tot/float(n);avg_wt=avg_wt/float(n);
    cout<<"\nAverage Wait time is: "<<avg_wt<<" and Turnover Time is: "<<avg_tot<<endl;
}

void sort_by_ar(Process p[],int n) {  
    for (int i = 0; i < n-1; i++)      
        for (int j = 0; j < n-i-1; j++)  
            if (p[j].At > p[j+1].At) 
            {
                temp=p[j];p[j]=p[j+1];p[j+1]=temp;
            } 
}

void sort_by_bu(Process p[],int n) { 
    //burst sorts after priority 
    for (int i = 0; i < n-1; i++)      
        for (int j = 0; j < n-i-1; j++)  
            if(p[j].At == p[j+1].At)
                if(p[j].Priority == p[j+1].Priority)
                if (p[j].Bt > p[j+1].Bt) 
                {
                    temp=p[j];p[j]=p[j+1];p[j+1]=temp;
                } 
}

void sort_by_pr(Process p[],int n) {  
    //Priority sorts after arrival.
    for (int i = 0; i < n-1; i++)      
        for (int j = 0; j < n-i-1; j++)  
            if(p[j].At == p[j+1].At)
                if (p[j].Priority > p[j+1].Priority) 
                {
                    temp=p[j];p[j]=p[j+1];p[j+1]=temp;
                } 
}

// int main() {
    // srand(time(0));
    // Process p[5];
    // for(int i =0; i < 5; i++) {
        // p[i].Pid = i;
        // p[i].Priority = rand() % 5;
        // p[i].At = rand() % 50;
        // p[i].Bt = rand() % 10;
        // p[i].Tot = i;
        // p[i].Wt = i;
        // p[i].Ct = i;
    // }
    // print_table(p,5);
    // cout<<"\nNow sorting by arrival\n";
    // sort_by_ar(p,5);
    // print_table(p,5);
    // cout<<"\nThen by Priority\n";
    // sort_by_pr(p,5);
    // print_table(p,5);
    // cout<<"\nAnd then by Burst\n";
    // sort_by_bu(p,5);
    // print_table(p,5);
// }