#include "Dateee.h"
#include <iostream>
#include <ostream>
using namespace std;
void Test1() {
    //Date d1(2023, 2, 28);
    //d1.Print();

    //// Date tmp = d1 + 100;
    //// d1 = d1 + 100;
    //d1 += 100;
    //d1.Print();
    //// tmp.Print();
    ////
    //Date d2(2023, 2, 1);
    //// std::cout << "day: " << Date::GetMonthDay(2023, 1) << std::endl;
    //d2--;

    //d2.Print();
    //std::cout << d2 << std::endl;
    Date d4(2022, 10, 28);
    Date d5(2022, 10, 28);
    Date d6(2023, 7, 30);
    int sub3 = (d4--) - d6;
    int sub4 = (--d4) - d6;
    cout << sub3 << endl;
    cout << sub4 << endl;
}

void DateAddDay() {
    int flags = 0;
    do {
        Date d;
        long long day = 0;
        std::cout << "��������ʼ����: ";
        std::cin >> d;
        std::cout << "����������: ";
        std::cin >> day;
        d += day;
        std::cout << d << std::endl;
        long long day_tmp = day;
        long long year_tmp = day_tmp / 365;
        day_tmp %= 365;

        short month_tmp = day_tmp / 30;
        day_tmp %= 30;
        // printf("���: %ld �� == %d ������ == %d����%d�� == %ld��%d����%d��\n",
        // day,
        //        day / 7, day / 30, day % 30, year_tmp, month_tmp, day_tmp);

        Date::Print(day);

    } while (flags);
}
void DateSubDay() {
    int flags = 0;
    do {
        Date d;
        long long day = 0;
        std::cout << "��������ʼ����: ";
        std::cin >> d;
        std::cout << "����������: ";
        std::cin >> day;
        d -= day;
        std::cout << d << std::endl;
        long long day_tmp = day;
        long long year_tmp = day_tmp / 365;
        day_tmp %= 365;

        short month_tmp = day_tmp / 30;
        day_tmp %= 30;

        // printf("���: %ld �� == %d ������ == %d����%d�� == %ld��%d����%d��\n",
        // day,
        //        day / 7, day / 30, day % 30, year_tmp, month_tmp, day_tmp);
        Date::Print(day);

    } while (flags);
}

void DateSubDate() {

    int flags = 0;
    do {
        Date d;
        Date d2;
        std::cout << "��������ʼ����: ";
        std::cin >> d;
        std::cout << "����������: ";
        std::cin >> d2;

        long long day = d - d2;
        long long day_tmp = day;
        long long year_tmp = day_tmp / 365;
        day_tmp %= 365;

        short month_tmp = (short)day_tmp / 30;
        day_tmp %= 30;

        // printf("���: %ld �� == %d ������ == %d����%d�� == %ld��%d����%d��\n",
        // day,
        //        day / 7, day / 30, day % 30, year_tmp, month_tmp, day_tmp);

        Date::Print(day);

    } while (flags);
}

void Test2() {
    int flags = 0;
    do {
        printf("************************\n");
        printf("*    1. ����������     *\n");
        printf("*    2. ����������     *\n");
        printf("*    3. ���ڼ����ڲ��� *\n");
        printf("*    0. �˳�����       *\n");
        printf("************************\n");
        std::cout << "��ѡ��: ";
        std::cin >> flags;
        if (flags == 1) {
            DateAddDay();
        }
        else if (flags == 2) {
            DateSubDay();
        }
        else if (flags == 3) {
            DateSubDate();
        }
        std::cout << "�����˳�..." << std::endl;
    } while (flags);
}

int main(int argc, char* argv[]) {
    //Test2();
     Test1();

    return 0;
}