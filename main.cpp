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

    //todays_date -= (date::weekday{ todays_date } - date::Monday);
    //date::year_month_day mondayDate = date::year_month_day{todays_date};
    //std::cout << "Monday: " << date::format("%F", mondayDate) << " \n";

    //// the below calculation needs 'todays_date' to be Monday to work correctly
    //todays_date += date::Sunday - date::Monday; // go forward to Sunday's date
    //std::cout << "Sunday: " << date::format("%F", todays_date) << " \n";

    //// calculate range
    //todays_date = date::floor<date::days>(std::chrono::system_clock::now());
    //do
    //{
    //	std::cout << "Future Date: " << date::format("%F", ++todays_date) << " \n";
    //} while (date::weekday{ todays_date } != date::Sunday);

    std::cin.get();
    return 0;
}
