#include "prochead.cc"

int main() {
    int n;Process p[20];
    cout<<"This code is for FCFS Scheduling\n";
    cout<<"Enter the number of processes: ";
    cin>>n;
    get_input(p,n);
    cout<<"The processes are :\n";
    print_table(p,n);
    sort_by_ar(p,n);
    cout<<"The execution order is as follows:\n";
    calc_tot_and_print(p,n);
}