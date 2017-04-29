#ifndef NODE_H_
#define NODE_H_

#include "Element.h"

/**
 * A node of the linked list for mergesort.
 */
class Node
{
public:
	/***** Complete this class. *****/
	Node();
	Node(int value);
	Node(const Element&);
	virtual ~Node();

	Element element;
	//int value;
	Node *next;
};

#endif /* NODE_H_ */
