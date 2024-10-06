#include "HashTableQuad.h"

template <typename HashedObj>
HashTableQuad<HashedObj>::HashTableQuad(int size) : array(nextPrime(size))
{
	makeEmpty();
}

template<typename HashedObj>
void HashTableQuad<HashedObj>::makeEmpty()
{
	currentSize = 0;
	for (auto& entry : array)
		entry.info = EMPTY;
}

template<typename HashedObj>
bool HashTableQuad<HashedObj>::contains(const HashedObj& x) const
{
	return isActive(findPos(x));
}

template<typename HashedObj>
int HashTableQuad<HashedObj>::findPos(const HashedObj& x) const
{
	int offset = 1;
	int currentPos = myHash(x);

	while (array[currentPos].info != EMPTY && array[currentPos].element != x)
	{
		currentPos += offset;	// Compute the ith probe
		offset += 2;

		if (currentPos >= array.size())
		{
			currentPos -= array.size();
		}
	}
}

template<typename HashedObj>
bool HashTableQuad<HashedObj>::isActive(int currentPos) const
{
	return array[currentPos].info == ACTIVE;
}

template<typename HashedObj>
bool HashTableQuad<HashedObj>::insert(const HashedObj& x)
{
	// Insert x as active
	int currentPos = findPos(x);
	if (isActive(currentPos))
	{
		return false;
	}

	array[currentPos].element = x;
	array[currentPos].info = ACTIVE;

	// Rehash
	if (++currentSize > array.size() / 2)
	{
		rehash();
	}

	return true;
}

template<typename HashedObj>
bool HashTableQuad<HashedObj>::remove(const HashedObj& x)
{
	int currentPos = findPos(x);
	if (!isActive(currentPos))
	{
		return false;
	}

	array[currentPos].info = DELETED;
	return true;
}

template<typename HashedObj>
bool HashTableQuad<HashedObj>::isPrime(int n)
{
	if (n <= 1)  return false;
	if (n <= 3)  return true;

	if (n % 2 == 0 || n % 3 == 0) return false;

	for (int i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}

template<typename HashedObj>
int HashTableQuad<HashedObj>::nextPrime(int N)
{
	if (N <= 1)
		return 2;

	int prime = N;
	bool found = false;

	while (!found) {
		prime++;

		if (isPrime(prime))
			found = true;
	}

	return prime;
}

template<typename HashedObj>
void HashTableQuad<HashedObj>::rehash()
{
	vector<HashEntry> oldArray = array;

	// Create new double-sized, empty table
	array.resize(nextPrime(2 * oldArray.size()));
	for (auto& entry : oldArray)
	{
		if (entry.info == ACTIVE)
			insert(move(entry.element));
	}
}