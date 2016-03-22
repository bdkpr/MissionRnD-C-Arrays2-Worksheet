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
#include<stdio.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int comparision(char *, char *);
int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	if (Arr == NULL || len < 0 || date == NULL){			//validating.
		return -1;
	}
	int ind, st_ind, no_dup,count_greater,value;
	for (ind = 0; ind < len; ind++){
		value = comparision(Arr[ind].date, date);			//finding whether date and transaction date is same or not. 
		if (value==1){									//got the position.
			break;
		}
		else if (value == -1){							//for invalid input.
			return -1;
		}
	}
	if (ind == len){									//if date not present in the transaction.
		return 0;
	}
	no_dup = 0; st_ind = ind+1;
	for (ind = ind + 1; (ind < len) && comparision(Arr[ind].date, date); ind++){		//if same date transactions present.
		no_dup++;
	}
	count_greater = len - (st_ind + no_dup);
	return count_greater;
}
int comparision(char *str1, char *str2){		//comparision of the dates.
	if (str1 == NULL, str2 == NULL){
		return -1;
	}
	int i;
	for (i = 0; str1[i] != '\0'&&str2[i] != '\0'; i++){
		if ((str1[i] == '-' || str1[i] >= '0'&&str1[i] <= '9') && (str2[i] == '-' || str2[i] >= '0'&&str2[i] <= '9')){
			if (str1[i] != str2[i]){
				return 0;
			}
		}
		else{
			return -1;
		}
	}
	if (str1[i] == '\0'&&str2[i] == '\0'){
		return 1;
	}
	return 0;
}