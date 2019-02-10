//
// Created by user on 2/10/19.
//
#pragma once
#ifndef TEST_01_TEST_H
#define TEST_01_TEST_H

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
interval *merge(interval *intervals, int sz, int *len);
interval *get_intervals(const int *arr, size_t arrLen);
void print_intervals(const interval *is, int isSize);

int isPower(int A);

int trailingZeroes(int A);

#endif //TEST_01_TEST_H
