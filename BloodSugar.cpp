// BloodSugar.cpp
// Trevor Dine
// COSC 2030
// Project 01

#include "BloodSugar.h"

List dailyList;
List weekList;
List finalList;

BigFloat sumsOfDays[14];
BigFloat maxOfDays[14];
BigFloat minOfDays[14];
int countOfDays[14];

BigFloat sumsOfWeeks[2];
BigFloat maxOfWeeks[2];
BigFloat minOfWeeks[2];
int countOfWeeks[2];
int bigDeltaDay[2];

int weeklyPerDayCount[14];

int numDayInputValues = 0;
int numWeekInputValues = 0;
int numTotalInputValues = 0;
int dayTotalCount = 1;

int weekOverflowCount = 0;
int weekTotalCount = 1;

const int SENTINEL_VALUE = -9999;

int main()
{
	bool finished = false;

	while (!finished)
	{
		string stringInput;
		cout << "\nThe Current Day Is: " << dayTotalCount << endl;
		cout << "Input the letter I (or Input) to input blood sugar values, D (or Day) to show the daily summary so far, W (or Week) to show the weekly summary so far, N (or Next) to increment to the next day of data, or E (or Exit) to exit:" << endl;
		cin >> stringInput;

		if (stringInput == "I" || stringInput == "Input")
		{
			bool done = false;

			while (!done)
			{
				BigFloat currInput = 0.0;
				cout << "Current blood sugar level (-9999 to go back): ";
				cin >> currInput;
				if (currInput == SENTINEL_VALUE)
				{
					done = true;
				}
				else if (currInput > 0 && currInput < FLT_MAX)
				{
					dailyList.insertAsFirst(currInput);
					numDayInputValues++;
					numWeekInputValues++;
					sumsOfDays[dayTotalCount - 1] = sumsOfDays[dayTotalCount - 1] + currInput;

					cout << "Value: " << currInput << " has been inserted." << endl;
					cout << " " << endl;
				}
			}
		}
		else if (stringInput == "D" || stringInput == "Day")
		{
			BigFloat daySum = dailyList.sum();
			BigFloat dayMax = dailyList.findMax();
			BigFloat dayMin = dailyList.findMin();

			cout << "Sum of the day values: " << daySum << endl;
			cout << "Max of the day values: " << dayMax << endl;
			cout << "Min of the day values: " << dayMin << endl;
		}
		else if (stringInput == "W" || stringInput == "Week")
		{
			int largestDelta = 0;
			int largestDeltaAt = 0;
			BigFloat weekSum = weekList.sum();
			BigFloat weekMax = weekList.findMax();
			BigFloat weekMin = weekList.findMin();

			cout << "Sum of the week values: " << weekSum << endl;
			cout << "Max of the week values: " << weekMax << endl;
			cout << "Min of the week values: " << weekMin << endl;

			if (dayTotalCount >= 2)
			{
				for (int i = 1; i < dayTotalCount; i++)
				{
					if (largestDelta < abs(weeklyPerDayCount[i] - weeklyPerDayCount[i - 1]))
					{
						largestDelta = abs(weeklyPerDayCount[i] - weeklyPerDayCount[i - 1]);
						largestDeltaAt = i;
					}
				}
				cout << "The largest day to day delta is " << largestDelta << " between day " << largestDeltaAt << " and day " << largestDeltaAt - 1 << endl;
			}
		}
		else if (stringInput == "N" || stringInput == "Next")
		{
			if (dayTotalCount < 14)
			{
				if (dayTotalCount == 8)
				{
					int largestDelta = 0;
					sumsOfWeeks[weekTotalCount - 1] = weekList.sum();
					maxOfWeeks[weekTotalCount - 1] = weekList.findMax();
					minOfWeeks[weekTotalCount - 1] = weekList.findMin();
					countOfWeeks[weekTotalCount - 1] = numWeekInputValues;

					if (dayTotalCount >= 2)
					{
						for (int i = 1; i < 7; i++)
						{
							if (largestDelta < abs(weeklyPerDayCount[i] - weeklyPerDayCount[i - 1]))
							{
								largestDelta = abs(weeklyPerDayCount[i] - weeklyPerDayCount[i - 1]);
								bigDeltaDay[weekTotalCount - 1] = i;
							}
						}
					}

					numWeekInputValues = 0;
					weekList.copyDeleteList(finalList);
				}
				sumsOfDays[dayTotalCount - 1] = dailyList.sum();
				maxOfDays[dayTotalCount - 1] = dailyList.findMax();
				minOfDays[dayTotalCount - 1] = dailyList.findMin();
				countOfDays[dayTotalCount - 1] = numDayInputValues;
				weeklyPerDayCount[dayTotalCount - 1] = numDayInputValues;

				numDayInputValues = 0;
				dayCount();
				dailyList.copyDeleteList(weekList);
			}
			else if (dayTotalCount == 14)
			{
				sumsOfDays[dayTotalCount - 1] = dailyList.sum();
				maxOfDays[dayTotalCount - 1] = dailyList.findMax();
				minOfDays[dayTotalCount - 1] = dailyList.findMin();
				countOfDays[dayTotalCount - 1] = numDayInputValues;

				int largestDelta = 0;
				weekCount();
				sumsOfWeeks[weekTotalCount - 1] = weekList.sum();
				maxOfWeeks[weekTotalCount - 1] = weekList.findMax();
				minOfWeeks[weekTotalCount - 1] = weekList.findMin();
				countOfWeeks[weekTotalCount - 1] = numWeekInputValues;

				if (dayTotalCount >= 2)
				{
					for (int i = 7; i < 14; i++)
					{
						if (largestDelta < abs(weeklyPerDayCount[i] - weeklyPerDayCount[i - 1]))
						{
							largestDelta = abs(weeklyPerDayCount[i] - weeklyPerDayCount[i - 1]);
							bigDeltaDay[weekTotalCount - 1] = i - 1;
						}
					}
				}

				dailyList.copyDeleteList(weekList);
				weekList.copyDeleteList(finalList);
				cout << "End of the two weeks." << endl;
				numTotalInputValues = countOfWeeks[0] + countOfWeeks[1];
				if (!(numTotalInputValues == 0))
				{
					BigFloat twoWeekSum = finalList.sum();
					BigFloat twoWeekMax = finalList.findMax();
					BigFloat twoWeekMin = finalList.findMin();
					
					cout << "Sums of each day over the two weeks: " << endl;
					cout << "[ ";
					for (int i = 0; i < 14; i++)
					{
						cout << sumsOfDays[i] << " ";
					}
					cout << "]" << endl;
					cout << "Sums of each of the two weeks." << endl;
					cout << "[ ";
					for (int i = 0; i < 2; i++)
					{
						cout << sumsOfWeeks[i] << " ";
					}
					cout << "]" << endl;
					cout << "Sum of the two week values: " << twoWeekSum << endl;

					cout << "Maxes of each day over the two weeks: " << endl;
					cout << "[ ";
					for (int i = 0; i < 14; i++)
					{
						cout << maxOfDays[i] << " ";
					}
					cout << "]" << endl;
					cout << "Maxes of the two week values: " << endl;
					cout << "[ ";
					for (int i = 0; i < 2; i++)
					{
						cout << maxOfWeeks[i] << " ";
					}
					cout << "]" << endl;
					cout << "Max of the two week values: " << twoWeekMax << endl;

					cout << "Mins of each day over the two weeks: " << endl;
					cout << "[ ";
					for (int i = 0; i < 14; i++)
					{
						cout << minOfDays[i] << " ";
					}
					cout << "]" << endl;
					cout << "Mins of the two week values: " << endl;
					cout << "[ ";
					for (int i = 0; i < 2; i++)
					{
						cout << minOfWeeks[i] << " ";
					}
					cout << "]" << endl;
					cout << "Min of the two week values: " << twoWeekMin << endl;

					cout << "Counts of each day over the two weeks: " << endl;
					cout << "[ ";
					for (int i = 0; i < 14; i++)
					{
						cout << countOfDays[i] << " ";
					}
					cout << "]" << endl;
					cout << "Counts of the two week values: " << endl;
					cout << "[ ";
					for (int i = 0; i < 2; i++)
					{
						cout << countOfWeeks[i] << " ";
					}
					cout << "]" << endl;

					cout << "Days where Day-To-Day Delta was the largest of the two weeks: " << endl;
					cout << "[ ";
					for (int i = 0; i < 2; i++)
					{
						cout << bigDeltaDay[i] << " ";
					}
					cout << "]" << endl;

					finished = true;
				}
				else
				{
					cout << "No values to display." << endl;

					finished = true;
				}
			}
		}
		else if (stringInput == "E" || stringInput == "Exit")
		{
			finished = true;
		}
		else
		{
			cin.clear();
			cin.ignore();
		}
	}
	
	system("pause");
	return 0;
}

void dayCount() 
{
	dayTotalCount++;
}

void weekCount()
{
	weekTotalCount++;
}
