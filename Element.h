#ifndef DATA_H_
#define DATA_H_

#include <iostream>
using namespace std;

/**
 * The class for the data elements that will be sorted.
 */
class Element
{
public:
	Element();
	Element(long val);
	Element(const Element& other);
	virtual ~Element();
	static long get_constructor_count();
	static long get_copy_count();
	static long get_destructor_count();
	static void reset();

	static long constructor_count;
	static long copy_count;
	static long destructor_count;
	long get_value() const;

	/***** Complete this class. *****/
	//overload < and > operator
	 friend bool operator<(const Element e1, const Element e2);
	 friend bool operator>(const Element e1, const Element e2);
	// Overloaded stream output insertion operator.
	friend ostream& operator <<(ostream& outs, const Element& element);

private:
	long value;
};

#endif /* DATA_H_ */
