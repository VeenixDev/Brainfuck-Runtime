#include <iostream>
using namespace std;

/*
Increases the length of an unsigned integer array
*/
unsigned int* increaseValuesLen(unsigned int values[], unsigned int* len) {
	// Creates a new unsigned int array
	unsigned int* ret = new unsigned int[*len + 1];
	
	// copies all values
	for (int i = 0; i < *len; i++) {
		ret[i] = values[i];
	}
	// adds the new entry to the array with the initial value 0
	ret[(*len)++] = 0;

	return ret;
}

int main() {
	const bool DEBUG = false;

	const char* inp = "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++.";
	const size_t len = strlen(inp);

	// The unsinged int array where we store all data
	unsigned int* values = new unsigned int[1]{ 0 };
	unsigned int valLen = 1;

	// pointers
	unsigned int curPtrPos = 0;
	unsigned int* curPtr = &values[curPtrPos];

	// Loop over the input and compute the result
	for (int i = 0; i < len; i++) {
		
		if (DEBUG) {
			cout << "CurPtr: " << curPtr << " Value: " << *curPtr << endl;
		}

		switch (inp[i])
		{
		case '+':
			// Increment the current value
			(*curPtr)++;
			break;
		case '-':
			// Decrement the current value
			(*curPtr)--;
			break;
		case '.':
			// Output the current value as ascii
			cout << (char) *curPtr;
			break;
		case '>':
			// Go to the next cell in storage
			values = increaseValuesLen(values, &valLen);
			curPtr = &values[++curPtrPos];
			break;
		case '<':
			// Go to the last cell in storage
			if (curPtrPos != 0) {
				curPtr = &values[--curPtrPos];
			}
			break;
		default:
			break;
		}
	}

	cout << endl;
	system("pause");
	return 0;
}
