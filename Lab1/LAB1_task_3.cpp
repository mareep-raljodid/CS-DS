// This program produces a sales report for DLC, Inc.
#include <iostream>
#include <iomanip>
using namespace std;

#define NUM_PRODS 9

struct arrSt{
    int id[NUM_PRODS] = {914, 915, 916, 917, 918, 919, 920, 921, 922};
    int units[NUM_PRODS] = {842, 416, 127, 514, 437, 269, 97, 492, 212};
    double prices[NUM_PRODS] = {12.95, 14.95, 18.95, 16.95, 21.95, 31.95, 14.95, 14.95, 16.95};
    double sales[NUM_PRODS];
};


// Function prototypes
void calcSales(arrSt &, int);
void showOrder(arrSt &, int);
void dualSort(arrSt &, int);
void showTotals(arrSt &, int);

// NUM_PRODS is the number of products produced.
//const int NUM_PRODS = 9;

int main()
{
    arrSt as; 

   // Calculate each product's sales.
   calcSales(as, NUM_PRODS);

   // Sort the elements in the sales array in descending
   // order and shuffle the ID numbers in the id array to
   // keep them in parallel.
   dualSort(as, NUM_PRODS);

   // Set the numeric output formatting.
   cout << setprecision(2) << fixed << showpoint;

   // Display the products and sales amounts.
   showOrder(as, NUM_PRODS);

   // Display total units sold and total sales.
   showTotals(as, NUM_PRODS);
   return 0;
}

//****************************************************************
// Definition of calcSales. Accepts units, prices, and sales     *
// arrays as arguments. The size of these arrays is passed       *
// into the num paramter. This function calculates each         *
// product's sales by multiplying its units sold by each unit's  *
// price. The result is stored in the sales array.               *
//****************************************************************

void calcSales(arrSt &as, int num)
{
   for (int index = 0; index < num; index++)
      as.sales[index] = as.units[index] * as.prices[index];
}

//***************************************************************
// Definition of function dualSort. Accepts id and sales arrays *
// as arguments. The size of these arrays is passed into size.  *
// This function performs a descending order selection sort on  *
// the sales array. The elements of the id array are exchanged  *
// identically as those of the sales array. size is the number  *
// of elements in each array.                                   *
//***************************************************************

void dualSort(arrSt &as, int size)
{
   int startScan, maxIndex, tempid;
   double maxValue;

   for (startScan = 0; startScan < (size - 1); startScan++)
   {
      maxIndex = startScan;
      maxValue = as.sales[startScan];
      tempid = as.id[startScan];
      for(int index = startScan + 1; index < size; index++)
      {
         if (as.sales[index] > maxValue)
         {
            maxValue = as.sales[index];
            tempid = as.id[index];
            maxIndex = index;
         }
      }
     as.sales[maxIndex] = as.sales[startScan];
     as.id[maxIndex] = as.id[startScan];
     as.sales[startScan] = maxValue;
     as.id[startScan] = tempid;
   }
}

//****************************************************************
// Definition of showOrder function. Accepts sales and id arrays *
// as arguments. The size of these arrays is passed into num.    *
// The function first displays a heading, then the sorted list   *
// of product numbers and sales.                                 *
//****************************************************************

void showOrder(arrSt &as, int num)
{
   cout << "Product Number\tSales\n";
   cout << "----------------------------------\n";
   for (int index = 0; index < num; index++)
   {
     
      cout << as.id[index] << "\t\t$";
      cout << setw(8) << as.sales[index] << endl;
   }
   cout << endl;
}

//*****************************************************************
// Definition of showTotals function. Accepts sales and id arrays *
// as arguments. The size of these arrays is passed into num.     *
// The function first calculates the total units (of all          *
// products) sold and the total sales. It then displays these     *
// amounts.                                                       *
//*****************************************************************

void showTotals(arrSt &as, int num)
{
   int totalUnits = 0;
   double totalSales = 0.0;

   for (int index = 0; index < num; index++)
   {
      totalUnits += as.units[index];
      totalSales += as.sales[index];
   }
   cout << "Total units Sold:  " << totalUnits << endl;
   cout << "Total sales:      $" << totalSales << endl;
}
