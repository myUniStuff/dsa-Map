#include "Map.h"
#include "MapIterator.h"
#include <exception>
using namespace std;


MapIterator::MapIterator(const Map& d) : map(d)
{
	currentPosition = 0;
}


void MapIterator::first() {
	currentPosition = 0;
}


void MapIterator::next() {
	if (currentPosition == map.mapSize) {
    throw exception();
  }
  currentPosition += 1;
}


TElem MapIterator::getCurrent(){
	if (currentPosition == map.mapSize) {
    throw exception();
  }
  return map.elements[currentPosition];
}


bool MapIterator::valid() const {
	return currentPosition < map.mapSize;
}



