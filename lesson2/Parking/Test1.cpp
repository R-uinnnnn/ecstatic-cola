#include <iostream>
#include <stack>
#include <queue>

using namespace std;
/*
class Time {
public:
    int hours;
    int minutes;
    int seconds;
    Time()
    {
    }
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    friend ostream& operator<<(ostream& out, const Time& time) {
        out << time.hours << "时" << time.minutes << "分" << time.seconds << "秒";
        return out;
    }
};

class Car {
public:
    string license_plate;
    Time arrival_time;
    Time departure_time;

    Car(string plate, const Time& arrival) : license_plate(plate), arrival_time(arrival) {}
};

class ParkingLot {
private:
    int capacity;
    stack<Car> in_stack;
    stack<Car> temp_stack; // 用于给要离去的汽车让路的临时栈
    queue<Car> waiting_queue;

public:
    ParkingLot(int n) : capacity(n) {}

    // 车辆到达
    void arrive(string plate, const Time& arrival_time) {
        Car new_car(plate, arrival_time);

        if (in_stack.size() < capacity) {
            in_stack.push(new_car);
            cout << "车牌号 " << plate << " 的车辆在停车场内的位置为 " << in_stack.size() << endl;
        }
        else {
            waiting_queue.push(new_car);
            cout << "车牌号 " << plate << " 的车辆在便道上等待" << endl;
        }
    }

    // 车辆离去
    void depart(const Time& departure_time) {
        while (!in_stack.empty()) {
            Car current_car = in_stack.top();
            in_stack.pop();
            temp_stack.push(current_car);

            if (current_car.departure_time.hours == 0 &&
                current_car.departure_time.minutes == 0 &&
                current_car.departure_time.seconds == 0) {
                current_car.departure_time = departure_time;
                calculateAndPrintFee(current_car);
            }
        }

        while (!temp_stack.empty()) {
            Car returning_car = temp_stack.top();
            temp_stack.pop();
            in_stack.push(returning_car);
        }

        if (!waiting_queue.empty()) {
            Car next_car = waiting_queue.front();
            waiting_queue.pop();
            in_stack.push(next_car);
            cout << "车牌号 " << next_car.license_plate << " 的车辆从便道驶入停车场" << endl;
        }
    }

private:
    // 计算并打印费用
    void calculateAndPrintFee(Car car) {
        int duration = car.departure_time.hours * 3600 + car.departure_time.minutes * 60 + car.departure_time.seconds -
            (car.arrival_time.hours * 3600 + car.arrival_time.minutes * 60 + car.arrival_time.seconds);
        int fee = duration * 10; // 假设费用是每时间单位10单位
        cout << "车牌号 " << car.license_plate << " 的车辆停留时间为 " << Time(duration / 3600, (duration % 3600) / 60, duration % 60)
            << "，应缴费用为 " << fee << "元" << endl;
    }
};

void printMenu() {
    cout << "\n停车场管理系统菜单\n";
    cout << "1. 车辆到达\n";
    cout << "2. 车辆离去\n";
    cout << "3. 退出程序\n";
    cout << "请选择操作（输入相应数字）：";
}

int main() {
    ParkingLot parking_lot(5); // 停车场容量为5

    while (true) {
        printMenu();

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "请输入车牌号：" << endl;
            string plate;
            cin >> plate;

            cout << "请输入到达时间（时 分 秒，空格分隔）：" << endl;
            int h, m, s;
            cin >> h >> m >> s;

            parking_lot.arrive(plate, Time(h, m, s));
            break;
        }
        case 2: {
            cout << "请输入离去时间（时 分 秒，空格分隔）：" << endl;
            int h, m, s;
            cin >> h >> m >> s;

            parking_lot.depart(Time(h, m, s));
            break;
        }
        case 3:
            cout << "程序退出。" << endl;
            return 0;
        default:
            cout << "无效的选择。请重新输入。\n";
        }
    }

    return 0;
}

*/

//#include <iostream>
//#include <stack>
//#include <queue>
//
//using namespace std;
//
//class Time {
//public:
//    int hours;
//    int minutes;
//    int seconds;
//    Time(){}
//    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}
//
//    friend ostream& operator<<(ostream& out, const Time& time) {
//        out << time.hours << "时" << time.minutes << "分" << time.seconds << "秒";
//        return out;
//    }
//};
//
//class Car {
//public:
//    string license_plate;
//    Time arrival_time;
//    Time departure_time;
//
//    Car(string plate, const Time& arrival) : license_plate(plate), arrival_time(arrival) {}
//};
//
//class ParkingLot {
//private:
//    int capacity;
//    stack<Car> in_stack;
//    stack<Car> temp_stack; // 用于给要离去的汽车让路的临时栈
//    queue<Car> waiting_queue;
//
//public:
//    ParkingLot(int n) : capacity(n) {}
//
//    // 车辆到达
//    void arrive(string plate, const Time& arrival_time) {
//        Car new_car(plate, arrival_time);
//
//        if (in_stack.size() < capacity) {
//            in_stack.push(new_car);
//            cout << "车牌号 " << plate << " 的车辆在停车场内的位置为 " << in_stack.size() << endl;
//        }
//        else {
//            waiting_queue.push(new_car);
//            cout << "车牌号 " << plate << " 的车辆在便道上等待" << endl;
//        }
//    }
//
//    // 车辆离去
//    void depart(const Time& departure_time) {
//        int position = 0; // 车辆位置
//
//        while (!in_stack.empty()) {
//            Car current_car = in_stack.top();
//            in_stack.pop();
//            temp_stack.push(current_car);
//
//            if (current_car.departure_time.hours == 0 &&
//                current_car.departure_time.minutes == 0 &&
//                current_car.departure_time.seconds == 0) {
//                current_car.departure_time = departure_time;
//                calculateAndPrintInfo(current_car, position++);
//            }
//        }
//
//        while (!temp_stack.empty()) {
//            Car returning_car = temp_stack.top();
//            temp_stack.pop();
//            in_stack.push(returning_car);
//        }
//
//        if (!waiting_queue.empty()) {
//            Car next_car = waiting_queue.front();
//            waiting_queue.pop();
//            in_stack.push(next_car);
//            cout << "车牌号 " << next_car.license_plate << " 的车辆从便道驶入停车场" << endl;
//        }
//    }
//
//private:
//    // 计算并打印信息
//    void calculateAndPrintInfo(Car car, int position) {
//        int duration = car.departure_time.hours * 3600 + car.departure_time.minutes * 60 + car.departure_time.seconds -
//            (car.arrival_time.hours * 3600 + car.arrival_time.minutes * 60 + car.arrival_time.seconds);
//        int fee = duration * 10; // 假设费用是每时间单位10单位
//        cout << "车牌号 " << car.license_plate << " 的车辆在停车场内的位置为 " << position
//            << "，停留时间为 " << Time(duration / 3600, (duration % 3600) / 60, duration % 60)
//            << "，应缴费用为 " << fee << "元" << endl;
//    }
//};
//
//void printMenu() {
//    cout << "\n停车场管理系统菜单\n";
//    cout << "1. 车辆到达\n";
//    cout << "2. 车辆离去\n";
//    cout << "3. 退出程序\n";
//    cout << "请选择操作（输入相应数字）：";
//}
//
//int main() {
//    ParkingLot parking_lot(5); // 停车场容量为5
//
//    while (true) {
//        printMenu();
//
//        int choice;
//        cin >> choice;
//
//        switch (choice) {
//        case 1: {
//            cout << "请输入车牌号：" << endl;
//            string plate;
//            cin >> plate;
//
//            cout << "请输入到达时间（时 分 秒，空格分隔）：" << endl;
//            int h, m, s;
//            cin >> h >> m >> s;
//
//            parking_lot.arrive(plate, Time(h, m, s));
//            break;
//        }
//        case 2: {
//            cout << "请输入离去时间（时 分 秒，空格分隔）：" << endl;
//            int h, m, s;
//            cin >> h >> m >> s;
//
//            parking_lot.depart(Time(h, m, s));
//            break;
//        }
//        case 3:
//            cout << "程序退出。" << endl;
//            return 0;
//        default:
//            cout << "无效的选择。请重新输入。\n";
//        }
//    }
//
//    return 0;
//}
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Time {
public:
    int hours;
    int minutes;
    int seconds;
    Time()
    {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    friend ostream& operator<<(ostream& out, const Time& time) {
        out << time.hours << "时" << time.minutes << "分" << time.seconds << "秒";
        return out;
    }
};

class Car {
public:
    string license_plate;
    Time arrival_time;
    Time departure_time;

    Car(string plate, const Time& arrival) : license_plate(plate), arrival_time(arrival) {}
};

class ParkingLot {
private:
    int capacity;
    stack<Car> in_stack;
    stack<Car> temp_stack; // 用于给要离去的汽车让路的临时栈
    queue<Car> waiting_queue;

public:
    ParkingLot(int n) : capacity(n) {}

    // 车辆到达
    void arrive(string plate, const Time& arrival_time) {
        Car new_car(plate, arrival_time);

        if (in_stack.size() < capacity) {
            in_stack.push(new_car);
            cout << "车牌号 " << plate << " 的车辆在停车场内的位置为 " << in_stack.size() << endl;
        }
        else {
            waiting_queue.push(new_car);
            cout << "车牌号 " << plate << " 的车辆在便道上等待" << endl;
        }
    }

    // 车辆离去
    void depart(const Time& departure_time) {
        if (in_stack.empty()) {
            cout << "停车场已为空，无车辆离去。" << endl;
            return;
        }

        Car leaving_car = in_stack.top();
        in_stack.pop();

        if (!waiting_queue.empty()) {
            Car next_car = waiting_queue.front();
            waiting_queue.pop();
            in_stack.push(next_car);
            cout << "车牌号 " << next_car.license_plate << " 的车辆从便道驶入停车场" << endl;
        }

        leaving_car.departure_time = departure_time;
        calculateAndPrintInfo(leaving_car);


    }

private:
    // 计算并打印信息
    void calculateAndPrintInfo(Car car) {
        long long duration = car.departure_time.hours * 3600 + car.departure_time.minutes * 60 + car.departure_time.seconds -
            (car.arrival_time.hours * 3600 + car.arrival_time.minutes * 60 + car.arrival_time.seconds);
        double fee = duration * 0.01; // 假设费用是每时间单位10单位
        cout << "车牌号 " << car.license_plate << " 的车辆在停车场内的位置为 " << in_stack.size() << "，停留时间为 "
            << Time(duration / 3600, (duration % 3600) / 60, duration % 60) << "，应缴费用为 " << fee << "元" << endl;
    }
};

void printMenu() {
    cout << "-------------------------\n";
    cout << "-----停车场管理系统----\n";
    cout << "------1. 车辆到达-------\n";
    cout << "------2. 车辆离去-------\n";
    cout << "------3. 退出程序-------\n";
    cout << "------请选择操作：-----\n";
    cout << "-------------------------\n";
}

int main() {
    ParkingLot parking_lot(2); // 停车场容量为5

    while (true) {
        printMenu();

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "请输入车牌号：" << endl;
            string plate;
            cin >> plate;

            cout << "请输入到达时间（时 分 秒，空格分隔）：" << endl;
            int h, m, s;
            cin >> h >> m >> s;

            parking_lot.arrive(plate, Time(h, m, s));
            break;
        }
        case 2: {
            cout << "请输入离去时间（时 分 秒，空格分隔）：" << endl;
            int h, m, s;
            cin >> h >> m >> s;

            parking_lot.depart(Time(h, m, s));
            break;
        }
        case 3:
            cout << "程序退出。" << endl;
            return 0;
        default:
            cout << "请重新输入。\n";
        }
    }

    return 0;
}
