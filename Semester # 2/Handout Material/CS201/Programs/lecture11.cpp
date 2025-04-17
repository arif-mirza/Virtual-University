// #include <iostream>
// main()
// {
//   int z, i;
//   int a[100];

//   // initializing the array
//   for (int i = 0; i < 100; i++)
//   {
//     /* code */
//     a[i] = i;
//   }

//   cout << "please enter a positive integer number ";
//   cin >> z;
//   int fount = 0;

//   for (int i = 0; i < 100; i++)
//   {
//     /* code */
//     if (z == a[i])
//     {
//       /* code */
//       cout << "your number is present in the array at index " << i << endl;
//       fount = 1;
//       break;
//     }
//   }
//   if (fount == 1)
//   {
//     /* code */
//     cout << "We found the integer at index" << i;
//   }
//   else
//   {
//     /* code */
//     cout << "your number is not present in the array";
//   }
// }

// Sample program 1
#include <iostream>
int main()
{
  int z, i = 0;
  int c[100];

  do
  {
    /* code */
    cout << "Please enter the number (-1 to end input) " << endl;
    cin >> z;

    if (z != -1)
    {
      /* code */
      c[i] = z;
    }
    i++;

  } while (z != -1 && i < 100);

  cout << "The total number of positive integers entered by user is", << i - 1;
}
