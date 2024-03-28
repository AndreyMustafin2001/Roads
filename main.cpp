#include <iostream>
#include <thread>
#include <mutex>
#include <deque>
#include <unistd.h>
using namespace std;
mutex m;
void roadA( deque <int> &cars, deque  <int> &directions,deque  <int> &time)
{
    while(true)
    {
        sleep(1);
        lock_guard<mutex> guard(m);
        if(cars.empty()) break;
        cout<<"Green light for road A"<<endl;
        while(!cars.empty() && directions.front() <=2)
        {
            cout<<"Car "<< cars.front() <<" Moving in direction "<< directions.front()
            <<" Time: "<<time.front() << endl;
            cars.pop_front();
            directions.pop_front();
            time.pop_front();
        }
    }
}
void roadB( deque <int> &cars, deque  <int> &directions,deque  <int> &time)
{
    while(true)
    {
        sleep(1);
        lock_guard<mutex> guard(m);
        if(cars.empty()) break;
        cout<<"Green light for road B"<<endl;
        while(!cars.empty() && directions.front() >2)
        {
            cout<<"Car "<< cars.front() <<" Moving in direction "<< directions.front()
            <<" Time: "<<time.front() << endl;
            cars.pop_front();
            directions.pop_front();
            time.pop_front();
        }
    }
}
int main()
{
    deque  <int> cars = {2,5,1,3,4};
    deque  <int> directions = {2,3,1,3,4};
    deque  <int> time = {10,20,30,40,40};

    thread A(roadA,ref(cars),ref(directions),ref(time));
    thread B(roadB,ref(cars),ref(directions),ref(time));
    if(A.joinable())
        A.join();
    if(B.joinable())
        B.join();


    return 0;
}


