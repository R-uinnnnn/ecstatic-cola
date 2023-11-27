#include "Date.h"
#include <iostream>
#include <ostream>

void Test1() {
  Date d1(2023, 2, 28);
  d1.Print();

  // Date tmp = d1 + 100;
  // d1 = d1 + 100;
  d1 += 100;
  d1.Print();
  // tmp.Print();
  //
  Date d2(2023, 2, 1);
  // std::cout << "day: " << Date::GetMonthDay(2023, 1) << std::endl;
  d2--;

  d2.Print();
  std::cout << d2 << std::endl;
}

void DateAddDay() {
  int flags = 0;
  do {
    Date d;
    long long day = 0;
    std::cout << "Please enter a start date: ";
    std::cin >> d;
    std::cout << "Please enter the number of days: ";
    std::cin >> day;
    d += day;
    std::cout << d << std::endl;
    long long day_tmp = day;
    long long year_tmp = day_tmp / 365;
    day_tmp %= 365;

    short month_tmp = day_tmp / 30;
    day_tmp %= 30;
    // printf("相差: %ld 天 == %d 个星期 == %d个月%d天 == %ld年%d个月%d天\n",
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
    std::cout << "Please enter a start date: ";
    std::cin >> d;
    std::cout << "Please enter the number of days: ";
    std::cin >> day;
    d -= day;
    std::cout << d << std::endl;
    long long day_tmp = day;
    long long year_tmp = day_tmp / 365;
    day_tmp %= 365;

    short month_tmp = day_tmp / 30;
    day_tmp %= 30;

    // printf("相差: %ld 天 == %d 个星期 == %d个月%d天 == %ld年%d个月%d天\n",
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
    std::cout << "Please enter a start date: ";
    std::cin >> d;
    std::cout << "Please enter the number of days: ";
    std::cin >> d2;

    long long day = d - d2;
    long long day_tmp = day;
    long long year_tmp = day_tmp / 365;
    day_tmp %= 365;

    short month_tmp = day_tmp / 30;
    day_tmp %= 30;

    // printf("相差: %ld 天 == %d 个星期 == %d个月%d天 == %ld年%d个月%d天\n",
    // day,
    //        day / 7, day / 30, day % 30, year_tmp, month_tmp, day_tmp);

    Date::Print(day);

  } while (flags);
}

void Test2() {
  int flags = 0;
  do {
    printf("************************\n");
    printf("*    1. add days       *\n");
    printf("*    2. subtract days  *\n");
    printf("*    3. Date-Date      *\n");
    printf("*    0. exit           *\n");
    printf("************************\n");
    std::cout << "please choose: ";
    std::cin >> flags;
    if (flags == 1) {
      DateAddDay();
    } else if (flags == 2) {
      DateSubDay();
    } else if (flags == 3) {
      DateSubDate();
    }
    std::cout << "exit..." << std::endl;
  } while (flags);
}

int main(int argc, char *argv[]) {
  //Test2();
  Test1();

  return 0;
}