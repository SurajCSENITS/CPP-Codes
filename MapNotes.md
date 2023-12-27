-> STL container that stores key-value pairs/elements
-> The elements are stored in asc/desc order wrt the keys
-> Maps cannot have duplicate keys
-> implemented through Binary Search Tree
-> erase(): similar as that of sets
-> swap(): swaps two maps(should be of same type)
-> empty() -> size()
-> find(key) -> count(key)
-> upper_bound() & lower_bound() similar to that of sets (wrt key)
# unordered map
-> Stores key-value pairs
-> elements are not ordered (SOME Random order)
-> keys will be unique
# multimap
-> map_name[key]=value is not valid, compilation error
-> map_name.equal_range(key)-> returns bounds of range of elements with key passed ->returns a pair-> pair.first= start_itr, pair.second-> end_itr
eg. auto a= m.equal_range(4);
    for(auto it=a.first;it!=a.second;it++)
        cout<< it->first<< " " << it->second;