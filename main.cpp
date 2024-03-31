#include <iostream>
#include <thread>
#include <mutex>
#include <deque>
#include <unistd.h>
#include <vector>
using namespace std;
mutex m;
bool svetafor = 0;
// A - 0
// B - 1
void turnGreen(int roadId)
{
    char roadName;
    if(roadId == 0)roadName = 'A';
    else roadName = 'B';

    if(svetafor != roadId)cout << "Turn Green for road" << roadName << endl;
    svetafor = roadId;
}
void carArrived(int carId, int roadId, int direction)
{
    char roadName;
    if(roadId == 0)roadName = 'A';
    else roadName = 'B';

    cout << "Car = " << carId << " passed road "
     << roadName << " in direction " << direction << endl;
}
int main()
{
    deque  <int> cars = {2,5,1,3,4};
    deque  <int> directions = {2,3,1,3,4};
    deque  <int> time = {10,20,30,40,40};

    vector<thread>threads;

    for(int i = 0; i < cars.size(); i++)
    {
        if(i == 0)usleep(time[i] * 100000); // 1000000ms = 1s;
        else usleep((time[i] - time[i - 1]) * 100000); // 1000000ms = 1s

        int roadId;

        if(directions[i] <= 2)roadId = 0; // road A
        else roadId = 1; // road B

        turnGreen(roadId);

        threads.emplace_back(carArrived, cars[i], roadId, directions[i]);
    }

    for (auto& thread : threads) {
        thread.join();
    }
    return 0;
}

