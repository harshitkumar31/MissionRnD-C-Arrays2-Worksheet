/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int cmpDates(char date1[],char date2[]);
int convInt(int *inp,int len);
int binSearch(struct transaction *Arr, int st, int end, char *date);


struct date{

	int day;
	int month;
	int year;
	};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	

	int res =binSearch(Arr, 0, len - 1, date);

	if (res < 0)
		return 0;
	
	return len-res-1;
}

int binSearch(struct transaction *Arr, int st, int end, char *date){
	
	
	if (st > end)
		return -1;

	int mid = (st + end) / 2;
	int flag = (cmpDates(Arr[mid].date, date));
	if (flag == 0){

		int flag2= binSearch(Arr, mid+1, end, date);
		
		if (flag2 > 0)
			return flag2;
		else
			return mid;

		}
	else  if (flag > 0)
		return binSearch(Arr, st, mid - 1, date);
	else
		return binSearch(Arr, mid+1, end, date);
	
	}

int cmpDates(char date1[], char date2[]){

	int dat1[3][4], dat2[3][4];

	int i, j = 0, k = 0;

	for (i = 0; date1[i] != '\0' && date2[i] != '\0';i++){
		
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
	yr1 = convInt(dat1[2],4);
	yr2 = convInt(dat2[2],4);


	if (yr1 != yr2)
		return yr1 > yr2 ? 1 : -1;
	else{

		int mn1, mn2;
		mn1 = convInt(dat1[1], 2);
		mn2 = convInt(dat2[1], 2);

		if (mn1 != mn2)
			return mn1 > mn2 ? 1 : -1;
		else{
			int day1, day2;
			day1 = convInt(dat1[0], 2);
			day2 = convInt(dat2[0], 2);

			if (day1 != day2)
				return day1 > day2 ? 1 : -1;
			else
				return 0;

			}

		}



	}

int convInt(int inp[], int len){

	int num=0, i=0;

	while (i<len && inp[i] >= 0){
		num = num * 10 + inp[i];
		i++;
		}

	return num;
	}