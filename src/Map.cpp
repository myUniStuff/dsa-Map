#include "Map.h"
#include "MapIterator.h"
#include <cstdlib>
#include <cstring>

Map::Map() {
  capacity = 10;
  mapSize = 0;
  elements = new TElem[capacity];
}

Map::~Map() {
	delete[] elements;
}

TValue Map::add(TKey c, TValue v){
	for (int i = 0; i < mapSize; i += 1) {
    if (elements[i].first == c) {
      TValue old_value = elements[i].second;
      elements[i] = TElem(c, v);
      return old_value;
    }
  }

  if (mapSize == capacity) {
    capacity *= 2;
    TElem* new_elements = new TElem[capacity];
    // memcpy(new_elements, elements, sizeof(TElem) * mapSize);
    // CPP is gay and compiler complains about memcopy :'
    for (int i = 0; i < mapSize; i += 1) {
      new_elements[i] = elements[i];
    }
    delete[] elements;
    elements = new_elements;
  }

  elements[mapSize] = TElem(c, v);
  mapSize += 1;

	return NULL_TVALUE;
}

TValue Map::search(TKey c) const{
	for (int i = 0; i < mapSize; i += 1) {
    if (elements[i].first == c) {
      return elements[i].second;
    }
  }
	return NULL_TVALUE;
}

TValue Map::remove(TKey c){
	for (int i = 0; i < mapSize; i += 1) {
    if (elements[i].first == c) {
      TValue old_value = elements[i].second;
      elements[i] = elements[mapSize - 1];
      mapSize -= 1;
      return old_value;
    }
  }
	return NULL_TVALUE;
}


int Map::size() const {
	return mapSize;
}

bool Map::isEmpty() const{
	return mapSize == 0;
}

MapIterator Map::iterator() const {
	return MapIterator(*this);
}



