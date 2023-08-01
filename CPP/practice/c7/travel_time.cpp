#include <iostream>

using namespace std;

const int MIN_PER_HRS = 60;

struct travel_time
{
        int hours;
        int mins;
};

travel_time sum(travel_time d1, travel_time d2);
void show_time(travel_time t);

int main()
{
        travel_time day1 = {5, 45};
        travel_time day2 = {4, 55};

        travel_time trip = sum(day1, day2);
        cout << "Two days total: ";
        show_time(trip);

        travel_time day3 = {4, 32};
        cout << "Three days total: ";
        show_time(sum(trip, day3));

        return 0;
}

travel_time sum(travel_time d1, travel_time d2)
{
        travel_time total;
        total.hours = (d1.hours + d2.hours) + (d1.mins + d2.mins) / MIN_PER_HRS;
        total.mins = (d1.mins + d2.mins) % MIN_PER_HRS;
        return total;
}

void show_time(travel_time t)
{
        cout << t.hours << " hours, "
             << t.mins << " minutes\n";
}
