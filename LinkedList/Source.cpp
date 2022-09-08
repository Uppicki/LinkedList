#include <iostream>
#include <string>

#include "List.cpp"

#undef I
#undef L



void intbox(List<int>*);
void doublebox(List<double>*);
void strbox(List<char*>*);

int main()
{
	List<int>* listInt = new List<int>();
	List<double>* listDouble = new List<double>();
	List<char*>* listIntArr = new List<char*> ();

	intbox(listInt);
	strbox(listIntArr);
}




void intbox(List<int>* l)
{
	std::cout << "Integer List\n";
	std::cout << "Size: " << l->getSize() << "\n";
	l->add(1);
	l->add(1);
	l->add(66);
	l->add(4);
	l->add(77);
	l->add(-31);
	l->add(14);
	for (int i = 0; i < l->getSize(); i++) std::cout << l->get(i) << "   ";
	std::cout << "\n";
	std::cout << "Size: " << l->getSize() << "\n";
	std::cout << "Delete index 1\n";

	l->removeIndex(1);
	for (int i = 0; i < l->getSize(); i++) std::cout << l->get(i) << "   ";
	std::cout << "\n";
	std::cout << "Delete index 5\n";

	l->removeIndex(5);
	for (int i = 0; i < l->getSize(); i++) std::cout << l->get(i) << "   ";
	std::cout << "\n";
	std::cout << "Size: " << l->getSize() << "\n";
	std::cout << "Contains -31: " << l->contains(-31) << "\n";
	std::cout << "Contains 100: " << l->contains(100) << "\n";
	std::cout << "Delete -31\n";
	for (int i = 0; i < l->getSize(); i++) std::cout << l->get(i) << "   ";
	l->remove(-31);
	std::cout << "\n";
	std::cout << "Size: " << l->getSize() << "\n";
	for (int i = 0; i < l->getSize(); i++) std::cout << l->get(i) << "   ";
	l->clear();
	std::cout << "Size: " << l->getSize() << "\n";

}

void strbox(List<char*>* l)
{
	std::cout << "String List\n";
	std::cout << "Size: " << l->getSize() << "\n";
	l->add((char*)"Hello");
	l->add((char*)"ASdasdad ");
	l->add((char*)"name");
	l->add((char*)"workld");
	l->add((char*)"etc");
	l->add((char*)"ahtasdfa");
	l->add((char*)"end");
	for (int i = 0; i < l->getSize(); i++) std::cout << l->get(i) << "   ";
	std::cout << "\n";
	std::cout << "Size: " << l->getSize() << "\n";
	std::cout << "Delete index 1\n";

	l->removeIndex(1);
	for (int i = 0; i < l->getSize(); i++) std::cout << l->get(i) << "   ";
	std::cout << "\n";
	std::cout << "Delete index 5\n";

	l->removeIndex(5);
	for (int i = 0; i < l->getSize(); i++) std::cout << l->get(i) << "   ";
	std::cout << "\n";
	std::cout << "Size: " << l->getSize() << "\n";
	std::cout << "Contains etc: " << l->contains((char*)"etc") << "\n";
	std::cout << "Contains Hello: " << l->contains((char*)"Hello") << "\n";
	std::cout << "Delete etf\n";
	for (int i = 0; i < l->getSize(); i++) std::cout << l->get(i) << "   ";
	l->remove((char*)"etf");
	std::cout << "\n";
	std::cout << "Size: " << l->getSize() << "\n";
	for (int i = 0; i < l->getSize(); i++) std::cout << l->get(i) << "   ";
	l->clear();
	std::cout << "Size: " << l->getSize() << "\n";

}