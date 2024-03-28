#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
using namespace std;
mutex m;
void roadA(vector <int> cars, vector <int> directions)
{
    lock_guard<mutex> guard(m);
    cout<<"Green light for road A"<<endl;
    for (int i = 0; i<cars.size();i++)
    {
        if(directions[i] <=2)
        {
            cout<<"Car "<< cars[i] <<" Moving in direction "<< directions[i] << endl;
        }
    }
}
void roadB(vector <int> cars, vector <int> directions)
{
    lock_guard<mutex> guard(m);
    cout<<"Green light for road B"<<endl;
    for (int i = 0; i<cars.size();i++)
    {
        if(directions[i] > 2)
        {
            cout<<"Car "<< cars[i] <<" Moving in direction "<< directions[i] <<endl;
        }
    }
}
int main()
{
    vector <int> cars = {2,5,1,3,4};
    vector <int> directions = {2,1,2,4,3};

    thread A(roadA,cars,directions);
    thread B(roadB,cars,directions);
    if(A.joinable())
        A.join();
    if(B.joinable())
        B.join();

    return 0;
}


