-> inding a unique index for all elements to store them is known as hashing
The unique index -> hash value
Function applied to find the hash value->hash function

# Differrent types of Hash functions:
1. Division Method
2. Mid square method -> h(k)=k^2 & extract middle digits
eg. k= 60, k^2= 3600 -> 60 index pe 60 store hoga
    k= 13, k^2= 169 -> 6 index pe 13 store hoga
3. Digit folding Method -> Fold key into equal size parts
eg. k1k2k3k4k5 -> k1k2+k3k4+k5(folding pairs of two) = hash value
    12345 -> 12+34+5 = 51 is the hash value | we can take the parts of three alos i.e., 123+45 = 168 hash value
4. Multiplication Method -> h(k) = floor(M(kA mod 1))
<!-- where, 0<A<1 M= no. of buckets in hash table -->
eg. k= 12345 M= 10 A= 0.01 
    kXA= 123.45, kA mod 1= 123.45 mod 1 = 0.45
    0.45XM= 4.5
    floor(4.5)= 4 = hash value