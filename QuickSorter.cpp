#include <iostream>
#include "QuickSorter.h"
using namespace std;

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
QuickSorter::QuickSorter(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
QuickSorter::~QuickSorter() {}

/**
 * Run the quicksort algorithm.
 * @throws an exception if an error occurred.
 */
void QuickSorter::run_sort_algorithm() throw (string)
{
	quicksort(0, size-1);
}

/**
 * The quicksort algorithm recursively sorts data subranges.
 * @param left the left index of the subrange to sort.
 * @param right the right index of the subrange to sort.
 */
void QuickSorter::quicksort(const int left, const int right)
{
	/***** Complete this member function. *****/
	//http://quiz.geeksforgeeks.org/quick-sort/
	if (left <= right)
	{
		// Choose the pivot and partition .
		int pivot = choose_pivot(left, right).get_value();
		int p = partition(left, right, pivot);
		quicksort(left, p-1);  // if elements <  pivot
		quicksort(p+1, right); // if elements >= pivot
	}
}

/**
 * Choose the pivot according to a pivot strategy.
 * The chosen pivot will be moved temporarily to the right end.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @return the pivot value.
 */
Element& QuickSorter::choose_pivot(const int left, const int right)
{
	return choose_pivot_strategy(left, right);
}

/**
 * Partition the subrange by moving data elements < pivot to the left
 * and data elements > pivot to the right.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @param pivot the pivot value.
 */
int QuickSorter::partition(const int left, const int right, const Element& pivot)
{
	/***** Complete this member function. *****/
	//http://quiz.geeksforgeeks.org/quick-sort/
	//http://codereview.stackexchange.com/questions/77782/quick-sort-implementation
	//http://www.java2s.com/Code/Java/Collections-Data-Structure/Quicksortwithmedianofthreepartitioning.htm
	int i = left-1;  // index of the left side, moves to the right
	int j = right;   // index of the right side, moves to the left.
	// Loop until the indexes cross.
	while (i < j) {
		// Move i to the right as long as data[i] < pivot.
		do
		{
			i++;
			compare_count++;
		} while ((i <= right) && (data[i] < pivot));
		// Move j to the left as long as data[j] > pivot.
		do
		{
			j--;
			compare_count++;
		} while ((j >= left) && (data[j] > pivot));

		// Swap values if necessary after both i and j stop moving.
		if (i < j) swap(i, j);
	}
	swap(i, right);  // restore the pivot
	return i;
}
