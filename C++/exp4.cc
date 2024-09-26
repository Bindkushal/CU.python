#include <iostream>
#include <iomanip>
using namespace std;

class Time {
private:
    int hours, minutes, seconds;

public:
    Time() : hours(0), minutes(0), seconds(0) {}
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    void displayTime() const {
        cout << setw(2) << setfill('0') << hours << ":"
             << setw(2) << setfill('0') << minutes << ":"
             << setw(2) << setfill('0') << seconds << endl;
    }

    void addTime(const Time& t1, const Time& t2) {
        seconds = t1.seconds + t2.seconds;
        minutes = t1.minutes + t2.minutes + seconds / 60;
        hours = t1.hours + t2.hours + minutes / 60;
        seconds %= 60;
        minutes %= 60;
        hours %= 24;
    }
};

int main() {
    const Time t1(5, 45, 30), t2(3, 20, 40);
    Time t3;
    t3.addTime(t1, t2);

    cout << "Time 1: "; t1.displayTime();
    cout << "Time 2: "; t2.displayTime();
    cout << "Time 3 (Sum): "; t3.displayTime();

    return 0;
}
