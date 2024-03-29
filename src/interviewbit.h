//
// Created by user on 2/10/19.
//
#pragma once
#ifndef TEST_01_TEST_H
#define TEST_01_TEST_H

#define __unused __attribute__((unused))
// conflict with test_08
// int *repeatedNumber(const int *A, int n1, int *len1);

char *largestNumber(const int *A, int n1);

int **solve(int A, int *len1, int *len2);

int *plusOne(int *A, int n1, int *len1);

void nextPermutation(int *A, int n1);

void setZeroes(int **A, int n11, int n12);

int repeatedNumber(const int *A, int n1);


struct Interval
{
	int start;
	int end;
};

typedef struct Interval interval;

interval *merge1(interval *intervals, int sz, int *len);

interval *get_intervals(const int *arr, size_t arrLen);

void print_intervals(const interval *is, int isSize);

int isPower(int A);

int trailingZeroes(int A);

int titleToNumber(char *A);

int gcd(int A, int B);

char **fizzBuzz(int A, int *len1);

int uniquePaths(int A, int B);

int isPalindrome(int A);

int reverse1(int A);

int Sqrt(int A);

int powmod(int x, int n, int d);

int searchInsert(int *A, int n1, int B);

int *searchRange(const int *A, int n1, int B, int *len1);

int compareVersion(char *A, char *B);

char *longestCommonPrefix(char **A, int n1);

void reverseWords(char *A);

int power(char *A);

double findMedianSortedArrays(const int *A, int n1, const int *B, int n2);

int removeDuplicates(int *A, int n1);

int removeElement(int *A, int n1, int B);

int *merge(int *A, int n1, int *B, int n2);

int nTriang(int *A, int n1);

int numSetBits(unsigned int A);

unsigned int reverse(unsigned int A);

int singleNumber1(const int* A, int n1);

int singleNumber(const int* A, int n1);

int findMinXor(int* A, int n1);

#endif //TEST_01_TEST_H
