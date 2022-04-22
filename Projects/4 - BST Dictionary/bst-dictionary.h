//
// Created by Robert Kramer on 4/11/22.
//

#ifndef _BST_DICTIONARY_H
#define _BST_DICTIONARY_H

#include <cstdint>
#include <stdexcept>

// these are macros... like functions, but they are copied and pasted into place where they are used
#define GET_COUNT(n) (((n) == NULL_INDEX) ? 0 : counts[n])
#define GET_HEIGHT(n) (((n) == NULL_INDEX) ? 0 : heights[n])

static const uint32_t
    NULL_INDEX = 0xffffffff,    // sentinel value for null index
    DEFAULT_INIT_SIZE = 16;     // default size for initial shared pool

template <typename KeyType,typename ValueType>
class BSTDictionary {
public:
    //=========================================================================
    // explicit BSTDictionary(uint32_t _cap = DEFAULT_INIT_SIZE)
    //   constructor
    //
    // parameter
    //   _cap - initial capacity of the shared data pool, if the pool is
    //          currently unallocated
    //

    explicit BSTDictionary(uint32_t _cap = DEFAULT_INIT_SIZE) {

        // if this is the first tree

            // allocate space for the shared data pool

            // set capacity to _cap

            // generate the free list

        // increment tree count

        // set root to null
    }

    //=========================================================================
    // ~BSTDictionary()
    //   destructor
    //

    ~BSTDictionary() {

        // decrement tree count

        // if this is the last tree

            // delete the shared data pool

        // else

            // use prvClear to delete the nodes
    }

    //=========================================================================
    // void clear()
    //   remove all nodes from the tree
    //

    void clear() {

        // use prvClear to delete nodes

        // set root to null
    }

    //=========================================================================
    // uint32_t size()
    //   return number of nodes in the tree
    //

    uint32_t size() {
        // this is the same as regular bst
    }

    //=========================================================================
    // uint32_t height()
    //   return height of the tree
    //
    // Note: This is largely a diagnostic function, and has little purpose in
    //       regular usage of the class
    //

    uint32_t height() {
        // this is the same as regular bst
    }

    //=========================================================================
    // bool isEmpty()
    //   return true if the tree is empty, false otherwise
    //

    bool isEmpty() {
        // this is the same as regular bst
    }

    //=========================================================================
    // ValueType &search(const KeyType & k)
    //   search for the given key
    //
    // parameter
    //   k - key to search for
    //
    // returns
    //   reference to key's corresponding value, if k exists in the tree
    //
    // throws
    //   domain_error if k is not in the tree
    //

    ValueType &search(const KeyType & k) {

        // n = root

        // while n is not null

            // if k == keys[n]

                // return values[n]

            // else if k < keys[n]

                // n = left[n]

            // else

                // n = right[n]

        // loop is over, no return... k is not in tree
        // throw domain_error
    }

    //=========================================================================
    // ValueType &operator[](const KeyType &k)
    //   access (read or write) the value for a given key
    //
    // parameter
    //   k - key to insert or update
    //
    // returns
    //   reference to the value corresponding to k
    //
    // Notes:
    // - If k does not already exist in the tree, it is inserted
    // - If k is inserted, its initial value is undefined
    // - This can be used as an lvalue (left side of =) to set the value
    //

    ValueType &operator[](const KeyType &k) {

        // use prvAllocate() to get a new node from the pool, store in tmp

        // n = tmp

        // use prvInsert() to search for k, inserting if necessary

        // if n != tmp

            // new node wasn't used; use prvFree to deallocate it

        // return values[n]
    }

    //=========================================================================
    // void remove(const KeyType &k)
    //   remove a key and its value from the tree
    //
    // parameter
    //   k - key to be removed
    //
    // throws
    //   domain_error if k is not in the tree
    //

    void remove(const KeyType &k) {
        // this is the same as for regular binary search trees
    }

private:
    //=========================================================================
    // void prvClear(uint32_t r)
    //   recursively remove nodes from the tree
    //
    // parameter
    //   r - subtree to be deleted
    //

    void prvClear(uint32_t r) {
        // this is the same as for regular binary search trees
    }

    //=========================================================================
    // uint32_t prvAllocate()
    //   get an unused node from the shared data pool
    //
    // returns
    //   index of a previously unused node
    //
    // Note: this will double the size of the pool if no space is currently
    //       available
    //

    uint32_t prvAllocate() {

        // if no space is available

            // allocate new arrays with twice as much space

            // copy data from old arrays to new arrays

            // delete the old arrays

            // point to the new arrays

            // regenerate the free list

            // double capacity

        // remove the head of the free list, store index in tmp

        // initialize left, right, counts, height

        // return tmp
    }

    //=========================================================================
    // void prvFree(uint32_t r)
    //   deallocate a node
    //
    // parameter
    //   r - node to be deallocated (returned to shared pool)
    //

    void prvFree(uint32_t r) {

        // add r to head of free list
    }

    //=========================================================================
    // void prvAdjust(uint32_t r)
    //   adjust height and count information after insert / remove
    //
    // parameter
    //   r - node whose information needs to be adjusted
    //

    void prvAdjust(uint32_t r) {

        // counts[r] = 1 + GET_COUNT(left[r]) + GET_COUNT(right[r])

        // heights[r] = 1 + max(GET_HEIGHT(left[r]),GET_HEIGHT(right[r]))
    }

    //=========================================================================
    // uint32_t prvInsert(uint32_t r,uint32_t &n,const KeyType &k)
    //   insert key into tree, or find it if it's already there
    //
    // parameters
    //   r - root of tree that should contain k
    //   n - at start: index of new node to hold k if necessary
    //       at finish: index of new or old node that holds k
    //   k - key to add or find
    //
    // returns
    //   root of resulting tree after finding or inserting k
    //

    uint32_t prvInsert(uint32_t r,uint32_t &n,const KeyType &k) {

        // if r is null, k is not in the tree. use the new node

            // keys[n] = k

            // return n

        // if k == keys[r]

            // n = r... this node already has k

        // else if k < keys[r]

            // left[r] = prvInsert(left[r],n,k)

        // else

            // right[r] = prvInsert(right[r],n,k)

        // prvAdjust(r)

        // return r
    }

    //=========================================================================
    // uint32_t prvRemove(uint32_t r,uint32_t &ntbd,const KeyType &k)
    //   recursively remove a key from the tree
    //
    // parameters
    //   r    - root of subtree that should contain k
    //   ntbd - when finished, this holds the index of the node to be deleted
    //   k    - key to be removed
    //
    // returns
    //   root of subtree after k is removed
    //

    uint32_t prvRemove(uint32_t r,uint32_t &ntbd,const KeyType &k) {

        // if r == null

            // throw domain_error since k is not in the tree


        // if k < keys[r]

            // left[r] = prvRemove(left[r],ntbd,k)

        // else if k > keys[r]

            // right[r] = prvRemove(right[r],ntbd,k)

        // else {

            // r holds k, this is the node we want

            // ntbd = r... this is (possibly) the node to be deleted

            // if left[r] is null

                // if right[r] is null

                    // r = null since r is a leaf that we're removing

                // else

                    // r = right[r] since r has a right child that is not being deleted

            // else

                // if right[r] is null

                    // r = left[r] since r has a left child that is not being deleted

                // else r has two children...

                    // if right height > left height

                        // tmp = right[r]

                        // go left as far as possible in right tree
                        // while left[tmp] is not null

                            // tmp = left[tmp]

                        // swap keys[r] and keys[tmp]

                        // swap values[r] and values[tmp]

                        // two-child case is now a one-child (at most) case
                        // recursively delete from the right
                        // right[r] = prvRemove(right[r],ntbd,k)

                    // else... left height >= right height

                        // tmp = left[r]

                        // go right as far as possible in left tree
                        // while right[tmp] is not null

                            // tmp = right[tmp]

                        // swap keys[r] and keys[tmp]

                        // swap values[r] and values[tmp]

                        // two-child case is now a one-child (at most) case
                        // recursively delete from the left
                        // left[r] = prvRemove(left[r],ntbd,k)

        // } ... from far above

        // if r is not null (if we haven't deleted it)

            // adjust height and count info for r

        // return r
    }

    // all data (shared and otherwise) goes here
};

// initialization of shared data values goes here... here's an example:
// template <typename KeyType,typename ValueType>
// uint32_t *BSTDictionary<KeyType,ValueType>::counts = nullptr;

#endif //_BST_DICTIONARY_H
