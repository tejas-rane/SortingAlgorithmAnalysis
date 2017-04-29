#include "ShellSortOptimal.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
ShellSortOptimal::ShellSortOptimal(string name) :VectorSorter(name) {}

/**
 * Destructor.
 */
ShellSortOptimal::~ShellSortOptimal() {}

/**
 * Run the optimal shellsort algorithm.
 * According to Don Knuth:
 * h = 3*i + 1 for i = 0, 1, 2, ... used in reverse.
 * @throws an exception if an error occurred.
 */
void ShellSortOptimal::run_sort_algorithm() throw (string)
{
    /***** Complete this member function. *****/
	// http://www.cplusplus.com/forum/general/123961/
	//http:www.java2s.com/Code/Java/Collections-Data-Structure/Shellsort.htm
	// Compute highest h value.
	    int hop = 1;
	    while (hop < size) hop = 3*hop + 1;

	    // For each value of h ...
	    for (hop = (hop-1)/3; hop >= 1; hop = (hop-1)/3)
	    {
	        // Perform an insertion sort with elements that are h apart.
	        for (int passes = hop; passes < size; passes++) {
	            long tmp = data[passes].get_value();
	            int j = passes;
	            // The next data element drifts into its proper place
	            // by comparing elements that are h apart.
	            while ((j >= hop) && (tmp < data[j-hop].get_value()))
	            {
	                data[j] = data[j-hop];
	                move_count++;
	                compare_count++;
	                j -= hop;
	            }
	            if (j >= hop) compare_count++;
	            // Move the next element into its proper place
	            // if it isn't already there.
	            if (passes != j)
	            {
	                data[j] = tmp;
	                move_count++;
	            }
	        }
	    }
}
