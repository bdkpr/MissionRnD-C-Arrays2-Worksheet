/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
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

int compare_dates(char *, char *);
void to_date(char *, int *, int *, int *);
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || ALen <= 0 || B == NULL || BLen <= 0){		//validity
		return NULL;
	}
	int A_ind, B_ind, Res_ind,pos;
	struct transaction *Res_arr = (struct transaction *)malloc((ALen + BLen)*sizeof(struct transaction));	//allocation of resultant array
	for (A_ind = B_ind = Res_ind = 0; A_ind < ALen&&B_ind < BLen; Res_ind++){	//moving up till any one transaction reaches to end.
		pos = compare_dates(A[A_ind].date, B[B_ind].date);						//finding which transaction occures first.
		if (pos == 1){
			Res_arr[Res_ind] = A[A_ind];
			A_ind++;
		}
		else{
			Res_arr[Res_ind] = B[B_ind];
			B_ind++;
		}
	}
	for (; A_ind < ALen;A_ind++,Res_ind++){
		Res_arr[Res_ind] = A[A_ind];
	}
	for (; B_ind < BLen; B_ind++, Res_ind++){
		Res_arr[Res_ind] = B[B_ind];
	}
	return Res_arr;
}

int compare_dates(char *str1, char *str2){				//returns which transaction occures first.
	if (str1 == NULL || str2 == NULL){
		return -1;
	}
	int d1, d2, m1, m2, y1, y2,res=0;
	to_date(str1, &d1, &m1, &y1);					//conversion of srting form to numeric form
	to_date(str2, &d2, &m2, &y2);
	if (y1 < y2){									//checking
		res=1;
	}
	else if (y1>y2){
		res= 2;
	}
	else{
		if (m1 < m2){
			res = 1;
		}
		else if (m1>m2){
			res = 2;
		}
		else{
			if (d1 <= d2){
				res = 1;
			}
			else{
				res = 2;
			}
		}
	}
	return res;
}

void to_date(char *str, int *d, int *m, int *y){  //converts the string to numbers form
	int ind, count=0;
	for (ind = 0; str[ind] != '\0' && (str[ind] >= 0 && str[ind] <= '9'); ind++){
		if (str[ind] != '-' ){
			count = count * 10 + (str[ind] - '0');
		}
		else if(ind==2){
			*d = count;
			count = 0;
		}
		else if (ind == 5){
			*m = count;
			count = 0;
		}
	}
	if (str[ind] == '\0'){
		*y = count;
	}
}