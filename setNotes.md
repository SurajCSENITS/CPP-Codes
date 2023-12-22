-> STL container used to store unique values
-> Values are stored in ordered state (inc/dec)
-> no indexing, elements are identified by their values
-> once value is inserted in a set, it cannot be modified
-> dynamic size/no overflowing errors
-> cannot access elements using indexing
-> set_name.begin() & set_name.end() same as vector iterators

# SOME MORE FUNCTIONS PRESENT IN SETS
-> size() -> empty() -> clear(): removes all elements from the set
-> find(): returns iterator of element if present otherwise returns end iterator
-> lower_bound(): returns element if present, else returns just greater value
-> upper_bound(): returns the next greater value
# unordered set
-> values are stored IN SOME random order
# multiset
-> it can store duplicate values
-> orderd asc or desc
-> no indexing, elements are identified by their values
-> cannot access elements using indexing
-> count(): can be more than 1, 0 if element is not their
# unordered multiset
-> allows duplicate values
-> values are in some random order