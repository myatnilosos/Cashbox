#include <iostream>
#include <stdlib.h>
#include <math.h>
#define CASHBOX 12

using namespace std;

void initArray(double proceeds[]);
void showArray(double proceeds[]);
double calculateDailyProceeds(double proceeds[]);
double calculateAverageProceeds(double proceeds[]);
int findCashboxWithMaxProceeds(double proceeds[]);
int findCashboxWithMinProceeds(double proceeds[]);
int findCashboxWithAverageProceeds(double proceeds[]);

int main()
{
    double proceeds[CASHBOX] = {0.0};
    double dailyProceeds = 0.0, averageProceeds = 0.0;
    int maxProceedsCashbox = 0, minProceedsCashbox = 0, averageProceedsCashbox = 0;
    
    initArray(proceeds);
    
    showArray(proceeds);
    
    dailyProceeds = calculateDailyProceeds(proceeds);
    
	averageProceeds = round(calculateAverageProceeds(proceeds)*100) / 100;
    
    maxProceedsCashbox = findCashboxWithMaxProceeds(proceeds);   
	 
	minProceedsCashbox = findCashboxWithMinProceeds(proceeds);   
	
	averageProceedsCashbox = findCashboxWithAverageProceeds(proceeds);
	
	cout << endl << endl << "Total daily proceeds is " << dailyProceeds << " BYN";
	cout << endl << endl << "Average proceeds per cashbox is " << averageProceeds << " BYN";
	cout << endl << endl << "The best cashier is at Cashbox N " << maxProceedsCashbox;
	cout << endl << endl << "The worth cashier is at Cashbox N " << minProceedsCashbox;
	cout << endl << endl << "The cashier with average proceeds is at Cashbox N " << averageProceedsCashbox;
 
    return 0;
}

void initArray(double proceeds[])
{
	for (int i = 0; i < CASHBOX; i++){
    	proceeds[i] = rand() / 100.00;
    }
}

void showArray(double proceeds[])
{
    for (int i = 0; i < CASHBOX; i++){
    	cout << "Cashbox N " << i+1;
    	cout.width(15);
    	cout << proceeds[i] << " BYN"<< endl; 
	}	
}

double calculateDailyProceeds(double proceeds[])
{
	double sum = 0.0;
	
	for (int i = 0; i < CASHBOX; i++)
	{
		sum += proceeds[i];
	}
	return sum;
}

double calculateAverageProceeds(double proceeds[])
{	
	return calculateDailyProceeds(proceeds) / CASHBOX;
}

int findCashboxWithMaxProceeds(double proceeds[])
{
	int max = 0;
	
	for (int i = 0; i < CASHBOX; i++){
		if(proceeds[max] < proceeds[i]){
			max = i;
		}
	}
	return max + 1;
}

int findCashboxWithMinProceeds(double proceeds[])
{
	int min = 0;
	
	for (int i = 0; i < CASHBOX; i++){
		if(proceeds[min] > proceeds[i]){
			min = i;
		}
	}
	return min + 1;
}

int findCashboxWithAverageProceeds(double proceeds[])
{
	double average = calculateAverageProceeds(proceeds);
	int minDifference = 0;
	
	for(int i = 0; i < CASHBOX; i++){
		if(fabs(average - proceeds[minDifference]) > fabs(average - proceeds[i])){
			minDifference = i;
		}
	} 
	return minDifference + 1;	
}
