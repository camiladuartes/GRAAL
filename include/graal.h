/*!
 * \file int_ranges.h
 * \author Camila
 * \date March, 24th
 */
#ifndef GRAAL_H
#define GRAAL_H

#include <iterator> // distance
#include <algorithm> // swap
#include <cstdlib>
#include <array>

namespace graal {
    using byte = unsigned char;
    //===Function prototypes.

    // Min
    /*!
        * Returns a pointer to the first occurrency of the smallest
        * element in the range.
        * \return A pointer to the smallest element of the range.
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
    * Copy the content in range [first;last) to another range, in another vector, beginning at "d_first".
    * \return An iterator point to the element past the last element copied from the source range.
    */
    void *copy(const void *first, const void *last, const void *d_first, size_t size);

    ///Clone
    /*!
    * Receives a range defined over an array and returns a
    * pointer to a new array containing a copy of the 
    * original range.
    * \return A pointer to the memory area that contains the copy of the original range.
    */
    void *clone(const void *first, const void *last, size_t size);

    ///Find_if
    /*!
    * Search for the first element equal to the predicate.
    * \return A pointer to the first element that is equal to 
    * a predicate, or, if the element is not found, return the last.
    */
    using Predicate = bool(*)(const void*);
    const void *find_if(const void *first, const void *last, size_t size, Predicate p);


    ///Find
    /*!
    * Search for the first element in the range that is equal
    * to the value passed to the function.
    * \return A pointer to the first element equal to the value
    * or, if the element was not found, the last.
    */
    using Equal = bool(*)(const void *, const void *);
    const void *find(const void *first, const void *last, size_t size, const void *value, Equal eq);

    ///all_of
    /*!
    * Receive a generic range [first, last] and a predicate p
    * \return True if the predicate return true for all
    * elements in the range.
    */
    bool all_of(const void *first, const void *last, size_t size, Predicate p);
    ///any_of
    /*!
    * Receive a generic range [first, last] and a predicate p 
    * \return True if the predicate return true for at least
    * one element in the range.
    */
    bool any_of(const void *first, const void *last, size_t size, Predicate p);

    ///none_of
    /*!
    * Receive a generic range [first, last] and a predicate p
    * \return True if the predicate return true for none
    * of elements in the range.
    */
    bool none_of(const void *first, const void *last, size_t size, Predicate p);

    ///equalFirstVersion
    /*!
    * Receive a range [first1;last1] and a pointer to other range first2
    * \return True if the first range is equal to the range
    * [first2;first2+(last1-first1)]
    */
    bool equal(const void *first1, const void *last1, const void *first2, size_t size, Equal eq);

    ///equalSecondVersion
    /*!
    * Receive two ranges: [first1;last1] and [first2;last2]
    * \return True if the elements in the ranges are equal
    */
    bool equal(const void *first1, const void *last1, const void *first2, const void *last2, size_t size, Equal eq);

    /// Unique
    /*!
    * Eliminates element repetitions in range [first;last)
    * \return A pointer to the adress just past the last element of
    * the range with unique elements
    */
    void *unique(void *first, void *last, size_t size, Equal eq);

    // /// Partition
    // /*!
    //  * Put the vector in order by a pivot. Elements smaller than the 
    //  * pivot appear before, elements equal to the pivot in the middle 
    //  * and the largest in the end.
    //  */
    // void partition(value_type *first, value_type *last, value_type *pivot);
}

#endif
