/*!
 * \file graal.h
 * \author Camila
 * \date March, 24th
 */
#ifndef GRAAL_H
#define GRAAL_H

#include <iterator> // distance
#include <algorithm> // swap
#include <cstdlib>

using byte = unsigned char;
//===Function prototypes.

// Min
/*!
    * Returns a pointer to the first occurrency of the smallest
    * element in the range.
*/
using Compare = bool(*)(const void *, const void *);
const void * min( const void *first, const void *last, size_t size, Compare cmp);

/// Reverse
/*!
 * Reverse the order of the elements in range `[first;last)`.
 */
void reverse( void *first, void *last, size_t size );

/// Copy 
/*!
 * Copy the content in range [first;last) to another range, in another vector, beginning at "d_first"
 * \return An iterator point to the element past the last element copied from the source range.
 */
void *copy(const void *first, const void *last, const void *d_first, size_t size);

///Clone
/*!
 * Receives a range defined over an array and returns a
 * pointer to a new array containing a copy of the 
 * original range
 */
void *clone(const void *first, const void *last, size_t size);

///Find_if
/*!
 * 
 */
using Predicate = bool(*)(const void*);
const void *find_if(const void *first, const void *last, size_t size, Predicate p);

#endif
