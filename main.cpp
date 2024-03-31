#include <iostream>
#include <thread>
#include <mutex>
#include <deque>
#include <unistd.h>
#include <vector>
#include <string>
std::mutex m;
bool svetafor = 0;
// A - 0
// B - 1
void turnGreen(int roadId)
{
    char roadName;
    if(roadId == 0)roadName = 'A';
    else roadName = 'B';

    if(svetafor != roadId)std::cout << "Turn Green for road" << roadName << std::endl;
    svetafor = roadId;
}
void carArrived(int carId, int roadId, int direction)
{
    char roadName;
    if(roadId == 0)roadName = 'A';
    else roadName = 'B';

    std::lock_guard<std::mutex>guard(m);
    std::cout << "Car = " << carId << " passed road "
     << roadName << " in direction " << direction << std::endl;
}
int main()
{
    std::deque  <int> cars = {2, 5, 1, 3, 4, 6, 7, 8, 9 , 10, 11};
    std::deque  <int> directions = {2, 3, 1, 3, 4, 1, 1, 2, 2, 2, 2};
    std::deque  <int> time = {10, 20, 30, 40, 40, 50, 50, 50, 50, 50, 50};

    std::vector<std::thread>threads;

    int kol[5] = {0, 0, 0, 0, 0};
    // kol[i] = number of cars moving at the same time in direction i
    int lim[5] = {0, 2, 2, 1, 1};
    // lim[i] = limit on number of cars that can move
    //in the direction i at the same time
    try{
    for(int i = 0; i < cars.size(); i++)
    {
        if(i == 0)
        {
            usleep(time[i] * 100000); // 1000000ms = 1s;
            kol[directions[i]]++;
        }
        else
        {
            usleep((time[i] - time[i - 1]) * 100000); // 1000000ms = 1s

            if(time[i] != time[i - 1])
            {
                kol[1] = 0;kol[2] = 0;kol[3] = 0;kol[4] = 0;
            }
            kol[directions[i]]++;
        }

        if(kol[directions[i]] > lim[directions[i]])
        {
            throw std::runtime_error("Accident on the road, too many cars in the direction " +
                                     std::to_string(directions[i]));
        }

        int roadId;

        if(directions[i] <= 2)roadId = 0; // road A
        else roadId = 1; // road B

        turnGreen(roadId);

        threads.emplace_back(carArrived, cars[i], roadId, directions[i]);
    }
    } catch (const std::runtime_error& e) {
        std::lock_guard<std::mutex>guard(m);
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    for (auto& thread : threads) {
        thread.join();
    }
    return 0;
}

