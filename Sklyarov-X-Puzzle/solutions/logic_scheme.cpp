#include <stdio.h>
#include <vector>

using namespace std;

class Block {
public:
	int number;
	char actionChar;
	int actionBinary;

	Block(int num, char ac, int binaryValue) {
		number = num;
		// action = [x -- xor / a -- and / o -- or]
		actionChar = ac;
		actionBinary = binaryValue;
		printf("Number: %d, action: %c\n", number, ac);

	}

	~Block() {
		printf("Finished block %d\n", number);
	}

	// int* actAction(int values[]){
	// 	int *res;
	// 	int size = *(&values + 1) - values;
	// 	for (int i = 0; i < size; i++){
	// 		res[i] = oneAction(*(values + i));
	// 	}
	//
	// 	return res;
	// }

	int action(int val) {
		if (actionChar == 'a') {
			return val & actionBinary;
		} else if (actionChar == 'o') {
			return val | actionBinary;
		} else if (actionChar == 'x') {
			return val ^ actionBinary;
		} else {
			printf("Unknown action: %c\n", actionChar);
			return -999;
		}
	}
};

class Node : public Block {
public:
		std::vector<Block> blocks;

		Node(int num, char ac, int binaryValue) :
			Block(num, ac, binaryValue) {};

		void initChildren(Block nblocks[], int size) {
			printf("%d\n", size);
			for (int i = 0; i < size; i++){
				printf("here\n");
				blocks.push_back(nblocks[i]);
			}
		}

		void printBlocks() {
			for (int i = 0; i < (int)blocks.size(); i++) {
				printf("Block %d : num %d act %c\n", i, blocks[i].number, blocks[i].actionChar);
			}
		}
};

int main() {
	Node block1 = Node(1, 'a', 0b110100);
	Node block2 = Node(2, 'x', 0b110100);
	Node block3 = Node(3, 'o', 0b110100);
	Node block4 = Node(4, 'o', 0b111111);
	Block childBlocksLevel1[] = {block1, block2, block3};
	block4.initChildren(childBlocksLevel1, 3);
	block4.printBlocks();

	return 0;
}
