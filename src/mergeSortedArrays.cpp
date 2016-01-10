/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int cmpDates2(char date1[], char date2[]);
int convInt2(int *inp, int len);

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {

	if (A==NULL || B==NULL)
		return NULL;

	int i=0, j=0;
	int flag;

	struct transaction *res = (struct transaction*)calloc(ALen + BLen,sizeof(struct transaction));

	int res_iter = 0;

	while (i < ALen && j < BLen){
		flag = cmpDates2(A[i].date, B[j].date);

		if (flag == 0){
			res[res_iter] = A[i];
			res_iter++;
			res[res_iter] = B[j];
			res_iter++;
			i++;
			j++;
			}
		else if (flag>0){
			res[res_iter] = B[j];
			j++;
			res_iter++;

			}
		else{
			res[res_iter] = A[i];
			res_iter++;
			i++;

			}

		}

	while (i < ALen){
		res[res_iter] = A[i];
		i++;
		res_iter++;

		}

	while (j < BLen){
		res[res_iter] = B[j];
		j++;
		res_iter++;

		}


	return res;


}


int cmpDates2(char date1[], char date2[]){

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
	yr1 = convInt2(dat1[2], 4);
	yr2 = convInt2(dat2[2], 4);


	if (yr1 != yr2)
		return yr1 > yr2 ? 1 : -1;
	else{

		int mn1, mn2;
		mn1 = convInt2(dat1[1], 2);
		mn2 = convInt2(dat2[1], 2);

		if (mn1 != mn2)
			return mn1 > mn2 ? 1 : -1;
		else{
			int day1, day2;
			day1 = convInt2(dat1[0], 2);
			day2 = convInt2(dat2[0], 2);

			if (day1 != day2)
				return day1 > day2 ? 1 : -1;
			else
				return 0;

			}

		}



	}

int convInt2(int inp[], int len){

	int num = 0, i = 0;

	while (i<len && inp[i] >= 0){
		num = num * 10 + inp[i];
		i++;
		}

	return num;
	}