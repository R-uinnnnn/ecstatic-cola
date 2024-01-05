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
        out << time.hours << "ʱ" << time.minutes << "��" << time.seconds << "��";
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
    stack<Car> temp_stack; // ���ڸ�Ҫ��ȥ��������·����ʱջ
    queue<Car> waiting_queue;

public:
    ParkingLot(int n) : capacity(n) {}

    // ��������
    void arrive(string plate, const Time& arrival_time) {
        Car new_car(plate, arrival_time);

        if (in_stack.size() < capacity) {
            in_stack.push(new_car);
            cout << "���ƺ� " << plate << " �ĳ�����ͣ�����ڵ�λ��Ϊ " << in_stack.size() << endl;
        }
        else {
            waiting_queue.push(new_car);
            cout << "���ƺ� " << plate << " �ĳ����ڱ���ϵȴ�" << endl;
        }
    }

    // ������ȥ
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
            cout << "���ƺ� " << next_car.license_plate << " �ĳ����ӱ��ʻ��ͣ����" << endl;
        }
    }

private:
    // ���㲢��ӡ����
    void calculateAndPrintFee(Car car) {
        int duration = car.departure_time.hours * 3600 + car.departure_time.minutes * 60 + car.departure_time.seconds -
            (car.arrival_time.hours * 3600 + car.arrival_time.minutes * 60 + car.arrival_time.seconds);
        int fee = duration * 10; // ���������ÿʱ�䵥λ10��λ
        cout << "���ƺ� " << car.license_plate << " �ĳ���ͣ��ʱ��Ϊ " << Time(duration / 3600, (duration % 3600) / 60, duration % 60)
            << "��Ӧ�ɷ���Ϊ " << fee << "Ԫ" << endl;
    }
};

void printMenu() {
    cout << "\nͣ��������ϵͳ�˵�\n";
    cout << "1. ��������\n";
    cout << "2. ������ȥ\n";
    cout << "3. �˳�����\n";
    cout << "��ѡ�������������Ӧ���֣���";
}

int main() {
    ParkingLot parking_lot(5); // ͣ��������Ϊ5

    while (true) {
        printMenu();

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "�����복�ƺţ�" << endl;
            string plate;
            cin >> plate;

            cout << "�����뵽��ʱ�䣨ʱ �� �룬�ո�ָ�����" << endl;
            int h, m, s;
            cin >> h >> m >> s;

            parking_lot.arrive(plate, Time(h, m, s));
            break;
        }
        case 2: {
            cout << "��������ȥʱ�䣨ʱ �� �룬�ո�ָ�����" << endl;
            int h, m, s;
            cin >> h >> m >> s;

            parking_lot.depart(Time(h, m, s));
            break;
        }
        case 3:
            cout << "�����˳���" << endl;
            return 0;
        default:
            cout << "��Ч��ѡ�����������롣\n";
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
//        out << time.hours << "ʱ" << time.minutes << "��" << time.seconds << "��";
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
//    stack<Car> temp_stack; // ���ڸ�Ҫ��ȥ��������·����ʱջ
//    queue<Car> waiting_queue;
//
//public:
//    ParkingLot(int n) : capacity(n) {}
//
//    // ��������
//    void arrive(string plate, const Time& arrival_time) {
//        Car new_car(plate, arrival_time);
//
//        if (in_stack.size() < capacity) {
//            in_stack.push(new_car);
//            cout << "���ƺ� " << plate << " �ĳ�����ͣ�����ڵ�λ��Ϊ " << in_stack.size() << endl;
//        }
//        else {
//            waiting_queue.push(new_car);
//            cout << "���ƺ� " << plate << " �ĳ����ڱ���ϵȴ�" << endl;
//        }
//    }
//
//    // ������ȥ
//    void depart(const Time& departure_time) {
//        int position = 0; // ����λ��
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
//            cout << "���ƺ� " << next_car.license_plate << " �ĳ����ӱ��ʻ��ͣ����" << endl;
//        }
//    }
//
//private:
//    // ���㲢��ӡ��Ϣ
//    void calculateAndPrintInfo(Car car, int position) {
//        int duration = car.departure_time.hours * 3600 + car.departure_time.minutes * 60 + car.departure_time.seconds -
//            (car.arrival_time.hours * 3600 + car.arrival_time.minutes * 60 + car.arrival_time.seconds);
//        int fee = duration * 10; // ���������ÿʱ�䵥λ10��λ
//        cout << "���ƺ� " << car.license_plate << " �ĳ�����ͣ�����ڵ�λ��Ϊ " << position
//            << "��ͣ��ʱ��Ϊ " << Time(duration / 3600, (duration % 3600) / 60, duration % 60)
//            << "��Ӧ�ɷ���Ϊ " << fee << "Ԫ" << endl;
//    }
//};
//
//void printMenu() {
//    cout << "\nͣ��������ϵͳ�˵�\n";
//    cout << "1. ��������\n";
//    cout << "2. ������ȥ\n";
//    cout << "3. �˳�����\n";
//    cout << "��ѡ�������������Ӧ���֣���";
//}
//
//int main() {
//    ParkingLot parking_lot(5); // ͣ��������Ϊ5
//
//    while (true) {
//        printMenu();
//
//        int choice;
//        cin >> choice;
//
//        switch (choice) {
//        case 1: {
//            cout << "�����복�ƺţ�" << endl;
//            string plate;
//            cin >> plate;
//
//            cout << "�����뵽��ʱ�䣨ʱ �� �룬�ո�ָ�����" << endl;
//            int h, m, s;
//            cin >> h >> m >> s;
//
//            parking_lot.arrive(plate, Time(h, m, s));
//            break;
//        }
//        case 2: {
//            cout << "��������ȥʱ�䣨ʱ �� �룬�ո�ָ�����" << endl;
//            int h, m, s;
//            cin >> h >> m >> s;
//
//            parking_lot.depart(Time(h, m, s));
//            break;
//        }
//        case 3:
//            cout << "�����˳���" << endl;
//            return 0;
//        default:
//            cout << "��Ч��ѡ�����������롣\n";
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
        out << time.hours << "ʱ" << time.minutes << "��" << time.seconds << "��";
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
    stack<Car> temp_stack; // ���ڸ�Ҫ��ȥ��������·����ʱջ
    queue<Car> waiting_queue;

public:
    ParkingLot(int n) : capacity(n) {}

    // ��������
    void arrive(string plate, const Time& arrival_time) {
        Car new_car(plate, arrival_time);

        if (in_stack.size() < capacity) {
            in_stack.push(new_car);
            cout << "���ƺ� " << plate << " �ĳ�����ͣ�����ڵ�λ��Ϊ " << in_stack.size() << endl;
        }
        else {
            waiting_queue.push(new_car);
            cout << "���ƺ� " << plate << " �ĳ����ڱ���ϵȴ�" << endl;
        }
    }

    // ������ȥ
    void depart(const Time& departure_time) {
        if (in_stack.empty()) {
            cout << "ͣ������Ϊ�գ��޳�����ȥ��" << endl;
            return;
        }

        Car leaving_car = in_stack.top();
        in_stack.pop();

        if (!waiting_queue.empty()) {
            Car next_car = waiting_queue.front();
            waiting_queue.pop();
            in_stack.push(next_car);
            cout << "���ƺ� " << next_car.license_plate << " �ĳ����ӱ��ʻ��ͣ����" << endl;
        }

        leaving_car.departure_time = departure_time;
        calculateAndPrintInfo(leaving_car);


    }

private:
    // ���㲢��ӡ��Ϣ
    void calculateAndPrintInfo(Car car) {
        long long duration = car.departure_time.hours * 3600 + car.departure_time.minutes * 60 + car.departure_time.seconds -
            (car.arrival_time.hours * 3600 + car.arrival_time.minutes * 60 + car.arrival_time.seconds);
        double fee = duration * 0.01; // ���������ÿʱ�䵥λ10��λ
        cout << "���ƺ� " << car.license_plate << " �ĳ�����ͣ�����ڵ�λ��Ϊ " << in_stack.size() << "��ͣ��ʱ��Ϊ "
            << Time(duration / 3600, (duration % 3600) / 60, duration % 60) << "��Ӧ�ɷ���Ϊ " << fee << "Ԫ" << endl;
    }
};

void printMenu() {
    cout << "-------------------------\n";
    cout << "-----ͣ��������ϵͳ----\n";
    cout << "------1. ��������-------\n";
    cout << "------2. ������ȥ-------\n";
    cout << "------3. �˳�����-------\n";
    cout << "------��ѡ�������-----\n";
    cout << "-------------------------\n";
}

int main() {
    ParkingLot parking_lot(2); // ͣ��������Ϊ5

    while (true) {
        printMenu();

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "�����복�ƺţ�" << endl;
            string plate;
            cin >> plate;

            cout << "�����뵽��ʱ�䣨ʱ �� �룬�ո�ָ�����" << endl;
            int h, m, s;
            cin >> h >> m >> s;

            parking_lot.arrive(plate, Time(h, m, s));
            break;
        }
        case 2: {
            cout << "��������ȥʱ�䣨ʱ �� �룬�ո�ָ�����" << endl;
            int h, m, s;
            cin >> h >> m >> s;

            parking_lot.depart(Time(h, m, s));
            break;
        }
        case 3:
            cout << "�����˳���" << endl;
            return 0;
        default:
            cout << "���������롣\n";
        }
    }

    return 0;
}
