#include "InsertionSort.h"

/**
 * Constructor.
 * @param name the name of the algorithm.
 */
InsertionSort::InsertionSort(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
InsertionSort::~InsertionSort() {}

/**
 * Run the insertion sort algorithm.
 * @throws an exception if an error occurred.
 */
void InsertionSort::run_sort_algorithm() throw (string)
{
    /***** Complete this member function. *****/
	//http://cforbeginners.com/insertionsort.html
	//https://mathbits.com/MathBits/CompSci/Arrays/Insertion.htm
	    for (int pass = 0; pass < size-1; pass++)
	    {
	        int i = pass + 1;
	        long tmp = data[i].get_value();  // the next data element
	        int j = i;
	        while ((j > 0) && (tmp < data[j-1].get_value()))
	        {
	            data[j] = data[j-1];
	            move_count++;
	            compare_count++;
	            j--;
	        }
	        if (i != j)
	        {
	            data[j] = tmp;
	            move_count++;
	        }
	    }
}
