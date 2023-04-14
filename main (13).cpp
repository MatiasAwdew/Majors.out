/******************************************************************************
# Author: Yonas Asfaw, Matias Awdew
# Assignment: Week 7 Discussion 7.cpp.
# Date: 12/04/22
# Description: This program will calculate and output the percentage of men and women and what major they are pursuing for the user. 
# Sources:  W3schools, Zybooks
# Contribution: Me and Matias both worked together to code this program.
#******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "valid.h"
using namespace std;

// function prototypes
void calcPercent(ofstream& outFile, int size, string major[], int males[], int females[], int annualSalary[]);
int fillArray(ifstream& inFile, string major[], int males[],
   int females[], int annualSalary[]);

const int MAX = 100;

int main(){
	ifstream inFile;
  ifstream outFile;
	string fileName;
  string inFileName = "stem.txt";
  string outFileName = "majors.out";
  string major[MAX];
  int males[MAX];
  int females[MAX];
  int annualSalary[MAX];
  int size = 0;

	if (!openFile(inFile, "stem.txt")){
		  cout << "file did not open. Program terminating!!!";
		  return 1;
	 }
  
   size = fillArray(inFile, major, males, females, annualSalary);

   if (!openFile(outFile, "majors.out")){
      cout << "output file did not open. Program terminating!";
		  return 1;
   }
  
	 //calcPercent(outFile, size, major, males, females, annualSalary);
  
	 inFile.close();
   outFile.close();
   cout << "Check majors.out for a list of majors, salaries, & more!" << endl;
   cout << "Goodbye!" << endl;
return 0;
}


void calcPercent(ofstream& outFile, int size, string major[], int males[],
  int females[], 
   int annualSalary[]){
   float total = 0.0;
   int max = 0;
   int min = 0;
   int maximum = 0;
   int minimum = 0;
   float maleNum = 0.0;
   float femaleNum = 0.0;
  
   
   string header = "Major's Males and Females chart percentages";
   outFile << header << endl;
   max = annualSalary[0];
   min = annualSalary[0];

   for (int i = 0; i < size; i++) {
      total = males[i] + females[i];
      maleNum = males[i] / total;
      femaleNum = females[i] / total;
      outFile << major[i] << " " << fixed << setprecision(2) 
         << maleNum * 100 << "%" << " " << femaleNum * 100 << "%" << endl;
      if (annualSalary[i] > max) {
          max = annualSalary[i];
          maximum = i;
      }
      if (annualSalary[i] < min) {
         min = annualSalary[i];
         minimum = i;
      }
   }
   outFile << "Maximum salary for majors: " << major[maximum] << " "
      << max << endl;
   outFile << "Minumum salary for majors: " << major[minimum] << " "
      << min;
}


int fillArray(ifstream& inFile, string major[], int males[], int females[], 
   int annualSalary[]) {
      int size = 0; 
      inFile.ignore(50, '\n'); 
      while (getline(inFile, major[size])){
         inFile >> major[size] >> males[size] >> females[size] 
            >> annualSalary[size];
         size++;
      } 
   return size;
}