#include <iostream>
#include <queue.h>

// need linear list

using namespace std;

const uint32_t
    N_WORDS = 5757,
    SENTINEL = 0xffffffff;

struct WordInfo {
    char
        word[6];
    uint32_t
        ptr;
    // need linear list of uint32_t
};

uint32_t hamming(char *s1,char *s2) {
    // compute number of positions in s1 and s2 that are different
}

void genLadder(WordInfo *wordList,uint32_t w1,uint32_t w2) {
    // add w2 to queue Q

    // while Q is not empty {

        // w = Q.dequeue

        // for each word v in w.list {

            // if v.ptr == nullptr and v != w2 {

                // v.ptr = w

                // Q.enqueue(v)

            // }

        // }

    // }

    // if w1.ptr != nullptr {

        // output w1.word

        // w = w1.ptr

        // while w != nullptr {

            // output w.word

            // w = w.ptr

        // }

    // } else

        // output no ladder exists
}

int main() {
    WordInfo
        wordList[N_WORDS];

    // read word list from file

    // generate adjacent word lists (adjacency lists)

    // read two words from keyboard

    // find both words in word list

    // if they're both found, generate ladder

    return 0;
}
