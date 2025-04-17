#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// function for calculte  average

double calculateAverage(int subject1, int subject2, int subject3)
{
  return (subject1 + subject2 + subject3) / 3.0;
}

// function for calculate grade

char calculateGrade(double average)
{
  if (average >= 90)
  {
    return 'A';
  }
  else if (average >= 80)
  {
    return 'B';
  }
  else if (average >= 70)
  {
    return 'C';
  }
  else if (average >= 60)
  {
    return 'D';
  }
  else
  {
    return 'F';
  }
}

int main()
{
  // display name and student id
  string studentId = "BC240205517";
  string name = "Muhammad Arif";
  cout << "student Id : " << studentId;
  << endl;
  cout << "Name : " << name << endl;

  // get marks for each subject from the user
  int subject1, subject2, subject3;
  cout << "Enter marks for subject 1: ";
  cin >> subject1;
  cout << "Enter marks for subject 2: ";
  cin >> subject2;
  cout << "Enter marks for subject 3:";
  cin << subject3;

  // calculate total marks, highest and lower marks
  int totalmarks = subject1 + subject2 + subject3;
  int highestMarks = max({subject1, subject2, subject3});
  int lowestMarks = min({subject1, subject2, subject3});

  // calculate average and grade
  double average = calculateAverage(subject1, subject2, subject3);
  char grade = calculateGrade(average);

  // display result
  cout << "\nMarks have been entered. Here is the result \n:";
  cout << "Obtained marks out of 300:" << totalmarks << endl;
  cout << "Average Mark: " << average << endl;
  cout << "Grade: " << grade << endl;
  cout << "Highest Mark: " << highestMarks << endl;
  cout << "Lowest Mark: " << lowestMarks << endl;
  return 0;
}