/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
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
int compare(char *, char *);
void to_date_values(char *, int *, int*, int*);

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || ALen < 0 || B == NULL || BLen < 0){			//validating.
		return NULL;
	}
	int A_ind, B_ind, ind,value,f=0;
	struct transaction *res = (struct transaction *)malloc(ALen*sizeof(struct transaction));
	for (ind = A_ind = B_ind = 0; A_ind < ALen&&B_ind < BLen;){		 //moving up till any one transaction reaches to end.
		value = compare(A[A_ind].date, B[B_ind].date);				//comparing the dates.
		if (value == 0){											//if dates are same.
			f = 1;
			res[ind] = A[A_ind];
			ind++;
			A_ind++;
			B_ind++;
		}
		else if (value == 1){									//if first one is smaller.
			A_ind++;
		}
		else if (value == 2){								   //if second one is smaller.
			B_ind++;
		}
	}
	if (f){							//if atleast one common elements present.
		return res;
	}
	return NULL;					//if no common elements present.
}

int compare(char *str1, char *str2){			//comparision body.
	if (str1 == NULL || str2 == NULL){
		return -1;
	}
	int d1, m1, y1, d2, m2, y2,res=0;
	to_date_values(str1, &d1, &m1, &y1);     //converting to values.
	to_date_values(str2, &d2, &m2, &y2);
	if (y1 < y2){				//comparision.
		res = 1;
	}
	else if (y1>y2){
		res = 2;
	}
	else{
		if (m1 < m2){
			res = 1;
		}
		else if (m1>m2){
			res = 2;
		}
		else{
			if (d1 < d2){
				res = 1;
			}
			else if(d1>d2){
				res = 2;
			}
			else{
				res = 0;
			}
		}
	}
	return res;
}

void to_date_values(char *str, int *d, int *m, int *y){		//converting to int values.
	int ind, count = 0;
	for (ind = 0; str[ind] != '\0'; ind++){
		if (str[ind] >= '0'&&str[ind] <= '9'){
			count = count * 10 + (str[ind] - '0');
		}
		else if (str[ind] == '-'){
			if (ind == 2){
				*d = count;
				count = 0;
			}
			else if (ind == 5){
				*m = count;
				count = 0;
			}
		}
	}
	*y = count;
}