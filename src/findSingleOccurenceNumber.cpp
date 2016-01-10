/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/
#include<malloc.h>

typedef struct occTab{

	int number;
	int occ;
	}occTab;

void addToTab(occTab * occurrences, int num,int len);
int getSingleOcc(occTab * occurrences, int len);

int findSingleOccurenceNumber(int *A, int len) {

	if (A == 0)
		return -1;

	occTab *occurrences = (occTab *)calloc(len / 2, sizeof(occTab));


	int i;

	for (i = 0; i < len; i++){

		addToTab(occurrences, A[i],len/2);

		}

	int res = getSingleOcc(occurrences, len / 2);

	return res;

}


void addToTab(occTab * occurrences, int num, int len){

	int i;

	for (i = 0; i < len; i++){
		if (occurrences[i].number == 0 && occurrences[i].occ == 0){
			occurrences[i].number = num;
			occurrences[i].occ = 1;
			break;
			}
		else if (occurrences[i].number == num){
			occurrences[i].occ += 1;
			break;
			}

		}
	}

int getSingleOcc(occTab * occurrences, int len){

	int i;

	for (i = 0; i < len; i++){
		if (occurrences[i].occ == 1)
			return occurrences[i].number;

		}
	}