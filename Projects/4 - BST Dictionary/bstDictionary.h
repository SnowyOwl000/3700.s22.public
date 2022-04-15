//
// Created by bob on 4/15/22.
//

#ifndef _BSTDICTIONARY_H
#define _BSTDICTIONARY_H

#include <cstdint>
#include <stdexcept>

#define GET_HEIGHT(n) (((n) == NULL_INDEX) ? 0 : heights[n])
#define GET_COUNT(n) (((n) == NULL_INDEX) ? 0 : counts[n])

const uint32_t
    NULL_INDEX = 0xffffffff,
    DEFAULT_INIT_CAP = 16;

template <typename KeyType,typename ValueType>
class BSTDictionary {
public:
    explicit BSTDictionary(uint32_t _cap=DEFAULT_INIT_CAP) {

    }

    ~BSTDictionary() {

    }

    void clear() { prvClear(root); root = NULL_INDEX; }

    uint32_t size() {

    }

    uint32_t height() {

    }

    bool isEmpty() { return root == NULL_INDEX; }

    ValueType &search(const KeyType &k) {

    }

    ValueType &operator[](const KeyType &k) {

    }

    void remove(const KeyType &k) {
        uint32_t
            ntbd = NULL_INDEX;

        // attempt to remove node with key k from tree
        root = prvRemove(root,ntbd,k);

        // if that worked, add deleted node to free list
        prvFree(ntbd);

        // note: if remove failed, it throws an exception
    }

private:
    void prvClear(uint32_t r) {

    }

    uint32_t prvAllocate() {

    }

    void prvFree(uint32_t n) {

    }

    void prvAdjust(uint32_t r) {

    }

    void prvInsert(uint32_t r,uint32_t &n,const KeyType &k,bool &used) {

    }

    uint32_t prvRemove(uint32_t r,uint32_t &ntbd,const KeyType &k) {
        uint32_t
            tmp;

        // no tree? no key...
        if (r == NULL_INDEX)
            throw std::domain_error("Remove: key not found");

        // this key is too small
        if (k < keys[r])
            left[r] = prvRemove(left[r],ntbd,k);
        // this key is too large
        else if (k > keys[r])
            right[r] = prvRemove(right[r],ntbd,k);
        else {
            // this key is just right...

            // this is the node to be deleted
            ntbd = r;

            if (left[r] == NULL_INDEX) {
                if (right[r] == NULL_INDEX) {
                    // r is a leaf node
                    r = NULL_INDEX;
                } else {
                    // r only has right child
                    r = right[r];
                }
            } else {
                if (right[r] == NULL_INDEX) {
                    // right child only
                    r = left[r];
                } else {
                    // both children
                    if (GET_HEIGHT(right[r]) > GET_HEIGHT(left[r])) {
                        // right child is taller... find smallest element in right tree
                        tmp = right[r];

                        // go left until you can't
                        while (left[tmp] != NULL_INDEX)
                            tmp = left[tmp];

                        // swap key and value for r and tmp
                        KeyType
                            tmpKey = keys[tmp];
                        keys[tmp] = keys[r];
                        keys[r] = tmpKey;

                        ValueType
                            tmpVal = values[tmp];
                        values[tmp] = values[r];
                        values[r] = tmpVal;

                        // search for and remove the key again...
                        // this time it will have 0 or 1 child
                        right[r] = prvRemove(right[r],ntbd,k);
                    } else {
                        // left child is taller... find largest element in left tree
                        tmp = left[r];

                        // go right until you can't
                        while (right[tmp] != NULL_INDEX)
                            tmp = right[tmp];

                        // swap key and value for r and tmp
                        KeyType
                                tmpKey = keys[tmp];
                        keys[tmp] = keys[r];
                        keys[r] = tmpKey;

                        ValueType
                                tmpVal = values[tmp];
                        values[tmp] = values[r];
                        values[r] = tmpVal;

                        // search for and remove the key again...
                        // this time it will have 0 or 1 child
                        left[r] = prvRemove(left[r],ntbd,k);
                    }
                }
            }
        }

        // if tree still exists, adjust height and count
        if (r != NULL_INDEX)
            prvAdjust(r);

        // return root of new tree
        return r;
    }

    uint32_t
        root;

    static uint32_t
        *left,
        *right,
        *counts,
        *heights,
        nTrees,
        freeListHead;
    static KeyType
        *keys;
    static ValueType
        *values;
};

#endif //_BSTDICTIONARY_H
