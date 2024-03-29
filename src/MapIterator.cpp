#include "Map.h"
#include "MapIterator.h"
#include <exception>
using namespace std;


MapIterator::MapIterator(const Map& d) : map(d)
{
	currentPosition = 0;
}
// BC == WC == TC: Theta(1)

void MapIterator::first() {
	currentPosition = 0;
}
// BC = WC = TC: Theta(1)

void MapIterator::next() {
	if (currentPosition == map.mapSize) {
    throw exception();
  }
  currentPosition += 1;
}
// BC = WC = TC: Theta(1)


TElem MapIterator::getCurrent(){
	if (currentPosition == map.mapSize) {
    throw exception();
  }
  return map.elements[currentPosition];
}
// BC = WC = TC: Theta(1)


bool MapIterator::valid() const {
  return (currentPosition < map.mapSize && currentPosition >= 0);
}
// BC = WC = TC: Theta(1)

void MapIterator::jumpBackward(int k) {
  if (k <= 0 || !valid()) {
    throw exception();
  }

  currentPosition -= k;
}
// BC = WC = TC: Theta(1)

