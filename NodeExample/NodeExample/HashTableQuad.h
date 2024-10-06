#ifndef HASHTABLEQUAD_
#define HASHTABLEQUAD_

#include <iostream>
#include <vector>

using namespace std;

template <typename HashedObj>
class HashTableQuad
{
public:
	explicit HashTableQuad(int size);

	bool contains(const HashedObj& x) const;

	void makeEmpty();
	bool insert(const HashedObj& x);
	bool insert(HashedObj&& x);
	bool remove(const HashedObj& x);
	bool isPrime(int n);
	int nextPrime(int N);

	enum EntryType { ACTIVE, EMPTY, DELETED };

private:
	struct HashEntry
	{
		HashedObj element;
		EntryType info;

		HashEntry( const HashedObj& e = HashedObj{ }, EntryType i = EMPTY )
			: element{ e }, info{ i } { }
		HashEntry( HashedObj&& e, EntryType i = EMPTY )
			: element{ std::move(e) }, info{ i } { }
	};

	vector<HashEntry> array;
	int currentSize;

	bool isActive(int currentPos) const;
	int findPos(const HashedObj& x) const;
	void rehash();
	size_t myHash(const HashedObj& x) const;
};

#endif // !HASHTABLEQUAD_