#include "BPlusTree.cpp"

int main()
{
	BPlusTree bt = BPlusTree();
	bt.insert(1);
	bt.insert(2);
	bt.insert(3);
	bt.insert(4);
	bt.insert(5);
	bt.insert(6);
	bt.insert(7);
	bt.printTree();
	bt.remove(1);
	bt.remove(2);
	bt.printTree();
	
	return 0;
}



