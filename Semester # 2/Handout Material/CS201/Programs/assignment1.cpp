#include <iostream>
using namespace std;

// function for check leap year
bool isLeapYear(int year)
{
  if (year % 4 == 0)
  {
    if (year % 100 == 0)
    {
      if (year % 400 == 0)
        return true;
      else
        return false;
    }
    else
      return true;
  }
  else
    return false;
}

int main()
{

  // step 1 : ask the name from user
  string name;
  cout << "Enter your name: ";
  cin >> name;

  // step 2 : ask student id from the user
  int studentId;
  cout << "Enter your student ID: ";
  cin >> studentId;

  // step 3 : get the year from the student id
  int numericPart = studentId.substr(2);
  int totalNums = stoi(numericPart);
  int year = totalNums / 10000;

  if (isLeapYear(year))
  {
    cout << "The year" << year << "is a leap year" << endl;
  }
  else
  {
    cout << year << " is not a leap year." << endl;
  }

  // step 4 : get the month from the user
  int days;
  int month;
  cout << "Enter your birth month (1-12) or -1 from exit ";
  cin >> month;

  if (month > 12)
  {
    cout << "Invalid Month" << endl;
    return 0;
  }
  // condition for feb month
  if (month == 2)
  {
    days =
        isLeapYear(year) ? 29 : 28;
  }

  // condition for months having 30 days
  else if (month == 4 || month == 6 || month == 9 || month == 11)
  {
    days = 30;
  }
  else if (month >= 1 && month <= 12)
  {
    days = 31;
  }
  else
  {
    cout << "Invalid Month" << endl;
    return 0;
  }

  // display the months
  string months[] = {"January", "February", "March", "April", "May", "June",
                     "July", "August", "September", "October", "November", "December"};

  cout << "Month: " << month << " - " << months[month - 1] << " has " << days << " days." << endl;

  return 0;
}