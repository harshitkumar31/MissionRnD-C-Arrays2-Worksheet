/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};


int cmpDates1(char date1[], char date2[]);
int convInt1(int *inp, int len);
int binSearch1(struct transaction *Arr, int st, int end, char *date);


struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {

	if ( A==NULL || B==NULL)
		return NULL;

	struct transaction *res = (struct transaction*)calloc(ALen, sizeof(struct transaction));

	int i,j=0;

	for (i = 0; i < ALen; i++){

		int flag = binSearch1(B, 0, BLen - 1, A[i].date);

		if (flag >= 0){
			res[j] = A[i];
			j++;
			}

		}

	if (j > 0)
		return res;
	else
		return NULL;

}


int binSearch1(struct transaction *Arr, int st, int end, char *date){


	if (st > end)
		return -1;

	int mid = (st + end) / 2;
	int flag = (cmpDates1(Arr[mid].date, date));
	if (flag == 0){

		/*int flag2 = binSearch1(Arr, mid + 1, end, date);

		if (flag2 > 0)
			return flag2;
		else*/
			return mid;

		}
	else  if (flag > 0)
		return binSearch1(Arr, st, mid - 1, date);
	else
		return binSearch1(Arr, mid + 1, end, date);

	}

int cmpDates1(char date1[], char date2[]){

	int dat1[3][4], dat2[3][4];

	int i, j = 0, k = 0;

	for (i = 0; date1[i] != '\0' && date2[i] != '\0'; i++){

		if (date1[i] != '-' && date2[i] != '-'){
			dat1[j][k] = (int)date1[i] - '0';
			dat2[j][k] = (int)date2[i] - '0';
			k++;
			}
		else{
			dat1[j][k] = dat2[j][k] = -1;
			k = 0;
			j++;
			}

		}

	int yr1, yr2;
	yr1 = convInt1(dat1[2], 4);
	yr2 = convInt1(dat2[2], 4);


	if (yr1 != yr2)
		return yr1 > yr2 ? 1 : -1;
	else{

		int mn1, mn2;
		mn1 = convInt1(dat1[1], 2);
		mn2 = convInt1(dat2[1], 2);

		if (mn1 != mn2)
			return mn1 > mn2 ? 1 : -1;
		else{
			int day1, day2;
			day1 = convInt1(dat1[0], 2);
			day2 = convInt1(dat2[0], 2);

			if (day1 != day2)
				return day1 > day2 ? 1 : -1;
			else
				return 0;

			}

		}

	

	}

int convInt1(int inp[], int len){

	int num = 0, i = 0;

	while (i<len && inp[i] >= 0){
		num = num * 10 + inp[i];
		i++;
		}

	return num;
	}