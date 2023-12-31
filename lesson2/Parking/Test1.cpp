#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <ctime>

using namespace std;

// ������
class Car {
public:
    string licensePlate;
    time_t arrivalTime;

    Car(string plate, time_t time) : licensePlate(plate), arrivalTime(time) {}
};

// ͣ����ģ����
class ParkingLotSimulation {
private:
    int capacity;
    stack<Car> parkingLot;
    queue<Car> waitingQueue;

public:
    ParkingLotSimulation(int capacity) : capacity(capacity) {}

    // ��������
    void carArrival(const Car& car) {
        if (parkingLot.size() < static_cast<size_t>(capacity)) {
            // ͣ����δ��������ֱ�ӽ���ͣ����
            parkingLot.push(car);
            cout << "Car " << car.licensePlate << " parked at position " << parkingLot.size() << " in the parking lot." << endl;
        }
        else {
            // ͣ���������������������ȴ�
            waitingQueue.push(car);
            cout << "Car " << car.licensePlate << " arrived and is waiting in the queue." << endl;
        }
    }

    // ������ȥ
    void carDeparture(time_t departureTime) {
        if (!parkingLot.empty()) {
            // ��ͣ�������Ƴ����һ����
            Car departedCar = parkingLot.top();
            parkingLot.pop();
            time_t parkingDuration = departureTime - departedCar.arrivalTime;
            double parkingFee = calculateParkingFee(parkingDuration);

            cout << "Car " << departedCar.licensePlate << " departed from the parking lot." << endl;
            cout << "Parking duration: " << parkingDuration << " seconds" << endl;
            cout << "Parking fee: $" << parkingFee << endl;

            // ��������Ƿ��еȴ��ĳ����������õ�һ��������ͣ����
            if (!waitingQueue.empty()) {
                Car newArrival = waitingQueue.front();
                waitingQueue.pop();
                parkingLot.push(newArrival);
                cout << "Car " << newArrival.licensePlate << " moved from the waiting queue to the parking lot." << endl;
            }
        }
        else {
            cout << "Parking lot is empty." << endl;
        }
    }

    // ��ӡͣ�����ͱ����״̬
    void printStatus() {
        cout << "\nParking Lot Status:" << endl;
        int position = 1;
        stack<Car> tempParkingLot = parkingLot;  // ���ڴ�ӡ״̬�����ı�ԭͣ��������
        while (!tempParkingLot.empty()) {
            Car car = tempParkingLot.top();
            cout << "Position " << position << ": Car " << car.licensePlate
                << " (Arrival Time: " << car.arrivalTime << ")" << endl;
            tempParkingLot.pop();
            position++;
        }

        cout << "\nWaiting Queue Status:" << endl;
        position = 1;
        queue<Car> tempWaitingQueue = waitingQueue;  // ���ڴ�ӡ״̬�����ı�ԭ�������
        while (!tempWaitingQueue.empty()) {
            Car car = tempWaitingQueue.front();
            cout << "Position " << position << ": Car " << car.licensePlate
                << " (Arrival Time: " << car.arrivalTime << ")" << endl;
            tempWaitingQueue.pop();
            position++;
        }
    }

private:
    // ����ͣ�����ã�ʾ���м򵥼��㣩
    double calculateParkingFee(time_t duration) {
        // ����ÿ��ͣ������Ϊ0.1��Ԫ
        const double rate = 0.1;
        return rate * duration;
    }
};

int main() {
    // ʾ���÷�
    const int parkingLotCapacity = 5;
    ParkingLotSimulation simulation(parkingLotCapacity);

    // �������ݣ�����
    time_t currentTime = time(nullptr);
    simulation.carArrival(Car("ABC123", currentTime));
    simulation.carArrival(Car("XYZ789", currentTime + 60));

    // ��ӡ��ǰ״̬
    simulation.printStatus();

    // �������ݣ���ȥ
    simulation.carDeparture(currentTime + 120);

    // ��ӡ��ǰ״̬
    simulation.printStatus();
    getchar();
    return 0;
}