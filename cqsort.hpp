//ECE  3574 Project 4
//purpose of the program is apply cuccurent  sorting
//By Pranav Rao

#ifndef CQSORT_HPP
#define CQSORT_HPP
#include <algorithm>
#include <thread>
#include <future>
#include <atomic>
#include <iostream>

template <typename T>//CQsort
class CQSort {
private:
    int nThread; //private variable
public:
	CQSort(int mthr) 
	{
     // TODO: your code here
		nThread = mthr;
	}
    //pation funciton not swithc variable
	int partition(T& A, int p, unsigned long q)
	{
		auto x = A[p];
		int j = p;
		int i = p+1;

		while(i<q) //whle loop to swap variable
		{
            if(A[i]<=x)
			{
				j = j + 1;
				std::swap(A[j], A[i]);
			}
			i++;
		}
        
		std::swap(A[j], A[p]);
		return j;
	}
    //function for quick sort
	void qSort(T& A, int p, unsigned long q)
	{
		int x;
		if(p<q) //if case for p great than q
		{
			x = partition(A, p, q);
			qSort(A, p, x);
			qSort(A, x+1, q);
		}
	}
   //opperator funciton
	void operator()(T &vec) 
	{
        qSort(vec, 0, 4);
	}
};

#include "cqsort.tpp"
#endif // CQSORT_HPP
