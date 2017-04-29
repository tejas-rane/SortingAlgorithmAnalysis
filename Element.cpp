#include <iostream>
#include "Element.h"

using namespace std;

/***** Complete this class. *****/
long Element::constructor_count;
long Element::copy_count;
long Element::destructor_count;

/**
 * Default constructor.
 */
Element::Element() : value(0) {}

/**
 * Constructor.
 * @param val the element's value.
 */
Element::Element(long val) : value(val) {
	constructor_count++;
}

/**
 * Copy constructor.
 * @param other the other element to be copied.
 */
Element::Element(const Element& other)
{
    /***** Complete this class. *****/
	value= other.value;
	copy_count++;
}

/**
 * Destructor.
 */
Element::~Element()
{
    /***** Complete this class. *****/
	destructor_count++;
}

/**
 * Getter.
 * @return the value.
 */
long Element::get_value() const { return value; }

void Element:: reset(){
	constructor_count=0;copy_count=0;destructor_count=0;
}
long Element:: get_constructor_count(){
	return constructor_count;
}
long  Element ::get_copy_count(){
	return copy_count;
}
long  Element ::get_destructor_count(){
	return destructor_count;
}
/*
 * friend function declaration to compare two elements
 */
bool operator>(const Element e1, const Element e2)
{
    bool greater = false;
    if((e1.get_value() > e2.get_value())) greater=true;
    return    greater;
}
/*
 * friend function declaration to compare two elements
 */
bool operator<(const Element e1, const Element e2)
{
    bool smaller = false;
    if((e1.get_value() < e2.get_value())) smaller=true;
    return    smaller;
}
ostream& operator <<(ostream& outs, const Element& element)
{
        outs << element.value;
    return outs;
}
