#include "Node.h"
#include "Element.h"

/***** Complete this class. *****/


Node:: Node() {
	//constructor_count++;
	element = Element();
	next = nullptr ;
}
Node::Node(int value) {
	//constructor_count++;
	element= Element(value);
	next = nullptr ;
}

Node::Node(const Element& other){
	//copy_count++;
	element = other;
	next = nullptr ;
}
 Node::~Node() {
	//destructor_count++;
};

