#include <chrono>
#include <iostream>

#include <date/date.h>

int main()
{
    // get todays date
    auto todays_date = date::floor<date::days>(std::chrono::system_clock::now());
    std::cout << "Current Date: " << date::format("%F", todays_date) << " \n\n";

    // get mondays date
    auto mondays_date = todays_date - (date::weekday{ todays_date } - date::Monday);
    std::cout << "Monday: " << date::format("%F", mondays_date) << " \n\n";

    // get sundays date
    auto sundays_date = mondays_date + (date::Sunday - date::Monday);
    std::cout << "Sunday: " << date::format("%F", sundays_date) << " \n\n";

    // get mondays to sundays dates
    do
    {
        std::cout << "Dates: " << date::format("%F", mondays_date++) << " \n";
    } while (date::weekday{ mondays_date } != date::Sunday);

    std::cout << "Dates: " << date::format("%F", mondays_date++) << " \n\n";

    // get number of days between two arbitrary dates
    todays_date = date::floor<date::days>(std::chrono::system_clock::now());

    auto future_date = todays_date + date::days{ 11 };
    std::cout << "Current Date: " << date::format("%F", todays_date) << " -- "
        << "Future Date: " << date::format("%F", future_date) << " \n\n";

    auto num_days = (date::sys_days{ future_date } - date::sys_days{ todays_date }).count();
    std::cout << "Num Days between dates: " << num_days << "\n\n";

    std::cin.get();
    return 0;
}
