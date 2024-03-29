#include "myShortTest.h"
#include <assert.h>
#include <exception>
#include "Map.h"
#include "MapIterator.h"
#include <iostream>

using namespace std;

void myTestAll() { //call each function to see if it is implemented
	Map m;
  m.add(1, 1);
  m.add(2, 2);
  m.add(3, 3);
  m.add(4, 4);
  m.add(5, 5);
  m.add(6, 6);
  m.add(7, 7);
  m.add(8, 8);
  m.add(9, 9);
  m.add(10, 10);

	MapIterator id = m.iterator();
	id.first();
	id.jumpBackward(5);
  assert(!id.valid());
  id.first();
  
  for (int i = 0; i < 5; i += 1) {
    id.next();
  }
  id.jumpBackward(3);
  assert(id.getCurrent() == TElem(3, 3));
  
  try {
    id.jumpBackward(-5);
    assert(false);
  } catch (exception& e) {
    assert(true);
  }

  id.first();
  id.jumpBackward(1);
  try {
    id.jumpBackward(1);
    assert(false);
  } catch (exception& e) {
    assert(true);
  }
}


