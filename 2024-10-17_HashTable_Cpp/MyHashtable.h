#ifndef IT230_HASHTABLE_H
#define IT230_HASHTABLE_H

#include <iostream>
#include <tuple>
#include <vector>

namespace Hashtable
{
    template<typename TKey, typename TValue>
    class MyHashtable
    {
    private:
        static constexpr size_t DEFAULT_CAPACITY = 16;
        std::vector<std::tuple<TKey, TValue>>* buckets; // A vector of tuples
        size_t getHashIndex(const TKey& key) const;
        size_t capacity = 0;
        size_t count = 0;
    public:
        // Getters
        [[nodiscard]] size_t getCapacity() const;
        [[nodiscard]] size_t getCount() const;

        // Constructor
        MyHashtable();

        // Non-Default Constructor
        MyHashtable(size_t capacity);

        // De-constructor
        ~MyHashtable();

        // Overriding the indexer
        TValue& operator[](const TKey& key);

        // add()
        void add(const TKey& key, const TValue& value);

        // remove()
        bool remove(const TKey& key);

        // clear()
        void clear();

        // toString()
        std::string toString() const;

        // containsKey()
        bool containsKey(const TKey& key) const;
    };
}




#endif //IT230_HASHTABLE_H
