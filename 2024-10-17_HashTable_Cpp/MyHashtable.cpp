#include "MyHashtable.h"

using namespace Hashtable;

template<typename TKey, typename TValue>
size_t MyHashtable<TKey, TValue>::getHashIndex(const TKey& key) const
{
    // This method is provided for you to get the hash index of a key
    return std::hash<TKey>{}(key) % capacity;
}

// Constructor
//MyHashtable();
template <typename TKey, typename TValue>
MyHashtable<TKey, TValue>::MyHashtable() :
    MyHashtable(DEFAULT_CAPACITY)
{}

// Non-Default Constructor
//MyHashtable(size_t capacity);
template <typename TKey, typename TValue>
MyHashtable<TKey, TValue>::MyHashtable(size_t capacity)
{
    this->capacity = capacity;
    count = 0;
    buckets = new std::vector<std::tuple<TKey, TValue>>[capacity];
}

template <typename TKey, typename TValue>
MyHashtable<TKey, TValue>::~MyHashtable()
{
    delete[] buckets;
}


template <typename TKey, typename TValue>
size_t MyHashtable<TKey, TValue>::getCount() const
{
    return count;
}

template <typename TKey, typename TValue>
size_t MyHashtable<TKey, TValue>::getCapacity() const
{
    return capacity;
}

// Overriding the indexer
//TValue& operator[](TKey key);
template<typename TKey, typename TValue>
TValue& MyHashtable<TKey, TValue>::operator[](const TKey& key)
{
    int index = getHashIndex(key);

    for(int i = 0; i < buckets[index].size(); i++)
    {
        if(get<0>(buckets[index][i]) == key)
        {
            return get<1>(buckets[index][i]);
        }
    }
    throw std::out_of_range("index out of range");
}

// add()
//void add(const TKey& key, const TValue& value);
template <typename TKey, typename TValue>
void MyHashtable<TKey, TValue>::add(const TKey& key, const TValue& value)
{
    int index = getHashIndex(key);
    if(buckets[index].empty())
    {
        buckets[index] =  std::vector<std::tuple<TKey, TValue>>();
    }
    for(int i = 0 ; i < buckets[index].size(); i++)
    {
        if(get<0>(buckets[index][i]) == key)
        {
            throw std::invalid_argument("Key already exists");
        }
    }

    buckets[index].push_back(std::tuple<TKey, TValue>(key, value));
    count++;
}

// remove()
//bool remove(const TKey& key);
template <typename TKey, typename TValue>
bool MyHashtable<TKey, TValue>::remove(const TKey& key)
{
    int index = getHashIndex(key);
    if(!buckets[index].empty())
    {
        for(int i = 0 ; i < buckets[index].size(); i++)
        {
            if(get<0>(buckets[index][i]) == key)
            {
                buckets[index].erase(buckets[index].begin() +i);
                count--;
                return true;
            }
        }
    }
    return false;
}

// clear()
//void clear();
template <typename TKey, typename TValue>
void MyHashtable<TKey, TValue>::clear()
{
    delete[] buckets;
    buckets = new std::vector<std::tuple<TKey, TValue>>[DEFAULT_CAPACITY];
    count = 0;
}

// toString()
//std::string toString() const;
template <typename TKey, typename TValue>
std::string MyHashtable<TKey, TValue>::toString() const
{
    std::string x;
    for(int i = 0 ; i < capacity ; i++)
    {
        for(int j = 0; j < buckets[i].size(); j++)
        {
            auto t = buckets[i][j];
            x += get<0>(buckets[i][j]) + ", " + std::to_string(get<1>(buckets[i][j])) + "\n";

        }
    }
    return x;
}

// containsKey()
//bool containsKey(const TKey& key) const;
template <typename TKey, typename TValue>
bool MyHashtable<TKey, TValue>::containsKey(const TKey& key) const
{
    return(getHashIndex(key) != -1);
    // hashtable itself does not handle key existence.
}

template class MyHashtable<std::string, float>;