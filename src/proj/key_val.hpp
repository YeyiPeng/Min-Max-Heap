#pragma once

namespace proj
{
    
    template <class K, class V>
    struct pair {
        K key;
        V value;
    };
    
    template <class K, class V>
    bool operator< (pair<K, V> l, pair<K, V> r)
    {
        return l.key < r.key;
    }
    
    template <class K, class V>
    bool operator<= (pair<K, V> l, pair<K, V> r)
    {
        return l.key <= r.key;
    }
    
    template <class K, class V>
    bool operator> (pair<K, V> l, pair<K, V> r)
    {
        return l.key > r.key;
    }
    
    template <class K, class V>
    bool operator>= (pair<K, V> l, pair<K, V> r)
    {
        return l.key >= r.key;
    }
    
    template <class K, class V>
    bool operator== (pair<K, V> l, pair<K, V> r)
    {
        return l.key == r.key && l.value == r.value;
    }
    
}