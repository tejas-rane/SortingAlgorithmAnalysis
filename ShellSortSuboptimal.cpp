#include "ShellSortSuboptimal.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
ShellSortSuboptimal::ShellSortSuboptimal(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
ShellSortSuboptimal::~ShellSortSuboptimal() {}

/**
 * Run the suboptimal shellsort algorithm.
 * @throws an exception if an error occurred.
 */
void ShellSortSuboptimal::run_sort_algorithm() throw (string)
{
    /***** Complete this member function. *****/
	// Halve the diminishing increment h during each pass.
	// http://www.cplusplus.com/forum/general/123961/
	    for (int hop = size/2; hop >= 1; hop /= 2)
	    {
	        // Perform an insertion sort with elements that are h apart.
	        for (int i = hop; i < size; i++)
	        {
	            int tmp = data[i].get_value();
	            int j = i;

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
	            if (i != j) {
	                data[j] = tmp;
	                move_count++;
	            }
	        }
	    }
}
