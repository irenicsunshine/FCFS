#include<iostream>
using namespace std;
struct Process
{
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
};
void findCompetionTime(Process proc[],int n){
    proc[0].completion_time=proc[0].burst_time;
    for (int i=1;i<n;i++){
        proc[i].completion_time=proc[i-1].completion_time+proc[i].burst_time;
    }
}
void findTurnAroundTime(Process proc[],int n){
    for(int i=0;i<n;i++){
        proc[i].turn_around_time=proc[i].completion_time-proc[i].arrival_time;
    }
}
void findWaitingTime(Process proc[],int n){
    proc[0].waiting_time=0;
    for(int i=1;i<n;i++){
        proc[i].waiting_time=proc[i].turn_around_time-proc[i].burst_time;
    }
}
void findFCFS(Process proc[], int n){
    findCompetionTime(proc,n);
    findTurnAroundTime(proc,n);
    findWaitingTime(proc,n);
}
void printFCFS(Process proc[],int n){
    cout<<"FCFS Scheduling : "<<endl;
    cout<<"PID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time"<<endl;
}
int main(){
    //size
    const int n=5;
    Process proc[n]={{1,0,5},{2,1,3},{3,2,2},{4,3,4},{5,4,1}};
    
    return 0;
};