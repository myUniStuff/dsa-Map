#include "ExtendedTest.h"
#include "ShortTest.h"

#include "Map.h"
#include "myShortTest.h"


#include <iostream>
using namespace std;


int main() {
  testAll();
	testAllExtended();
  myTestAll();

	cout << "That's all!" << endl;
	// system("pause");
	return 0;
}


