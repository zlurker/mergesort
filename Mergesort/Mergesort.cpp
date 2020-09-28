// Mergesort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int* numbercases = new int[10]{ 300, 2392, 493, 504, 2792, 659, 112, 20, 30, 9 };

int* mergesort(int* arr, int len) {
	//cout << "input: ";
	//for (int i = 0; i < len; i++)
		//cout << arr[i] << " ";

	//cout << endl;
	int halvedLen = len / 2;

	if (len == 2) {

		if (arr[0] < arr[1])
			return arr;

		int fEle = arr[0];
		arr[0] = arr[1];
		arr[1] = fEle;
		return arr;
	}
	else if (len == 1)
		return arr;


	int* firstH = new int[halvedLen];
	int* secH = new int[len - halvedLen];
	//cout <<endl<< "input A0: ";
	for (int i = 0; i < halvedLen; i++) {
		firstH[i] = arr[i];
		//cout << firstH[i] << " ";
	}
	//cout <<endl<< "input A1: ";
	for (int i = halvedLen; i < len; i++) {
		secH[i - halvedLen] = arr[i];
		//cout << secH[i - halvedLen] << " ";
	}

	firstH = mergesort(firstH, halvedLen);
	secH = mergesort(secH, len - halvedLen);

	int fHT = 0;
	int sHT = 0;

	cout << "output: ";
	for (int i = 0; i < len; i++) {

		int type =-1;

		if (fHT >= halvedLen) {
			arr[i] = secH[sHT];
			sHT++;
			continue;
		}

		if (sHT >= len - halvedLen) {
			arr[i] = firstH[fHT];
			fHT++;
			continue;
		}

		if (firstH[fHT] < secH[sHT]) {
			arr[i] = firstH[fHT];
			fHT++;			
		}
		else {
			//cout << secH[sHT] << " ";
			arr[i] = secH[sHT];
			sHT++;
		}
	}
	cout << endl;
	//delete[] firstH;
	//delete[] secH;

	return arr;
}

int main()
{
	numbercases = mergesort(numbercases, 10);

	for (int i = 0; i < 10; i++)
		cout << numbercases[i] << " ";

	cout << endl;
	system("pause");
	return 0;
}

