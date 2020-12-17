include "List.h"

int main()
{
	List<int> myList;
	myList.push_back(0);
	myList.push_back(1);
	myList.push_back(2);
	myList.print();

	--myList;
	myList.print();

	myList.clear();
	myList.print();
  
	myList + 101;
	myList.print();

	List<int> list2;
	list2 + 101;

	std::cout << "myList " << (myList == list2 ? "==" : "!=") << " list2" << std::endl;

	list2 + 2;
	std::cout << "myList " << (myList == list2 ? "==" : "!=") << " list2" << std::endl;
	return 0;
}
