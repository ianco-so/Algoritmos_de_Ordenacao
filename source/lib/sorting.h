/*!
 * Several types of sorting algorithms that work on a data range.
 * @author Ianco Soares Oliveira and Lucas Vinícius Gois Nogueira
 * @date July 19th, 2021
 * @file sort.h
*/

#ifndef SORTING_H
#define SORTING_H

#define DIGITS 10
namespace { //Anonymous namespace. Not visible outside this file.
    unsigned int* find_min (unsigned int* first, unsigned int* last) {
        unsigned int* minIndex = first;
        for (unsigned int i = 1; i < last-first; ++i) if (*(first+i) < *minIndex) minIndex = first+i;
        return minIndex;
    }
    unsigned int* find_max(unsigned int* first, unsigned int* last) {
        unsigned int* maxIndex = first;
        for (unsigned int i = 1; i < last-first; i++) if (*(first+i) > *maxIndex) maxIndex = first+i;
        return maxIndex;
    }
    void merge ( const unsigned int* l_start, const unsigned int* l_end, //left side
                 const unsigned int* r_start, const unsigned int* r_end, //right side
                 unsigned int* result) { 
        //We have 3 lists: left, right and result.
        //We will merge the two others list into result.
        //left and right are sorted.
        //result is not sorted.

        //merge the two lists.
        while (l_start != l_end && r_start != r_end) {
            if (*l_start < *r_start) *result++ = *l_start++;
            else *result++ = *r_start++;
        }
        while (l_start != l_end) *result++ = *l_start++;
        while (r_start != r_end) *result++ = *r_start++;
    }       
    unsigned int* partition(unsigned int* first, unsigned int* last, unsigned int* pivot) {
	    if(first == last) return last;
	    auto slow = first;
	    auto fast = first;

	    while(fast != last) {
		    if(*fast < *pivot) {
			    std::iter_swap(slow, fast);
      		    ++slow;
		    }
    	++fast;
	    }
	    std::iter_swap(slow, pivot);
	    return slow;
    }
    void counting_sort(unsigned int* first, unsigned int* last, const unsigned int dPlace) { // Using counting sort to sort the elements in the basis of significant places.
        const unsigned int size = (unsigned int)(last-first);
        unsigned int* output = new unsigned int[size];
        unsigned int count[DIGITS] = {0};

        //count the elements in the basis of significant digits
        for (unsigned int i = 0; i < size; i++) count[(*(first+i)/dPlace) % 10]++;

        //Calculate cumulative count
        for (unsigned int i = 1; i < DIGITS; i++) count[i] += count[i - 1];

        //Place the elements in sorted order
        for (int i = size - 1; i >= 0; i--) {
            output[count[(*(first+i)/ dPlace) % 10] - 1] = *(first+i);
            count[(*(first+i) / dPlace) % 10]--;
        }
        // Copy the sorted elements to the input array
        for (unsigned int i = 0; i < size; i++) *(first+i) = *(output+i);
    }
}
namespace sort {

    /*!
     * @brief Implements the selection sort algorithm. And sort the elements in the range [first, last) in ascending order.
     * @param first The first element in the range to be sorted.
     * @param last The last element in the range to be sorted.
     * @return void
    */
    void selection_sort(unsigned int* first, unsigned int* last) {
        unsigned int *min = nullptr;
        for (int i = 0; i < last-first; i++) {
            min = find_min(first+i, last);
            std::swap(*(first+i), *min);
        }
    }
    /*!
     * @brief Bubble sort algorithm can be used to sort a data range.
     * @param first The first element of the data range.
     * @param last The last element of the data range.
    */
    void bubble_sort(unsigned int * first, unsigned int *last) {
        bool flag = false;
        for (unsigned int i = 0; i < last-first-1; i++) {
            flag = false;
            for (unsigned int j = 0; j < last-first-i-1; j++) { //j < last-first-i-1 makes the function not try to sort the already sorted part
                if (*(first+j) > *(first+j+1)) {
                    std::swap(*(first+j), *(first+j+1));
                    flag = true;
                }
            }
            if (!flag) break;
        }
    }
    /*!
     * @brief Implements the insertion sort algorithm. And sort the elements in the range [first, last) in ascending order.
     * @param first The first element in the range to be sorted.
     * @param last The last element in the range to be sorted.
     * @return void
    */
    void insertion_sort(unsigned int* first, unsigned int* last) {
        unsigned int currentValue = *first;
        unsigned int hole = 0;
        for (int i = 1; i < last-first; i++) {
            currentValue = *(first+i);
            hole = i;
            while (hole > 0 && *(first+hole-1) > currentValue) {
                *(first+hole) = *(first+hole-1);
                hole--;
            }
            *(first+hole) = currentValue;
        }
    }
    /*!
     * @brief Implements the merge sort algorithm. And sort the elements in the range [first, last) in ascending order.
     * @note This algorithm is stable and fast. In the worst case it has the complexity of O(n log n).
     * @param first The first element in the range to be sorted.
     * @param last The last element in the range to be sorted.
     * @return void
    */
    void merge_sort(unsigned int* first, unsigned int* last) {
        if (last-first < 2) return;
        unsigned int mid = (last-first)/2;
        //create a left and right list.
        //left list
        unsigned int* l_start = new unsigned int[mid];
        unsigned int* l_end = l_start + mid;
        for (unsigned int i = 0; i < l_end-l_start; i++) *(l_start+i) = *(first+i);
        //right list
        unsigned int *r_start = new unsigned int[last-first-mid];
        unsigned int *r_end = r_start + (last-first-mid);
        for (unsigned int i = 0; i < r_end-r_start; i++) *(r_start+i) = *(first+(l_end-l_start)+i);

        merge_sort(l_start, l_end);
        merge_sort(r_start, r_end);
        //merge the two lists together.
        merge(l_start, l_end, r_start, r_end, first);
        delete[] l_start;
        delete[] r_start;
    }
    /*!
     * @brief Implements the quick sort algorithm. And sort the elements in the range [first, last) in ascending order.
     * @note This algorithm one of the fastest sorting algorithms. In average case it has the complexity of O(n log n) and it is faster then merge sort algorithm.
     * @param first The first element in the range to be sorted.
     * @param last The last element in the range to be sorted.
     * @return void
    */
    void quick_sort(unsigned int* first, unsigned int* last) { // Recursive version
	    
	    if(std::distance(first, last) < 2) return;
		auto pivot = partition(first, last, (last-1));
		quick_sort(first, pivot);
		quick_sort((pivot+1), last);
    }
    /*!
     * @brief Implements the radix sort algorithm. And sort the elements in the range [first, last) in ascending order.
     * @note Diferentily from the others algorithms, this algorithm not compare the elements in the range, but compare the elements in the basis of significant places.
     * @param first The first element in the range to be sorted.
     * @param last The last element in the range to be sorted.
     * @return void
    */
    void radix_sort(unsigned int* first, unsigned int* last) {
        unsigned int max = *find_max(first, last);
        for (unsigned int dPlace = 1; max/dPlace > 0; dPlace *= 10) counting_sort(first, last, dPlace);
    }
    /*!
     * @brief Implements the shell sort algorithm. And sort the elements in the range [first, last) in ascending order.
     * @param first The first element in the range to be sorted.
     * @param last The last element in the range to be sorted.
     * @return void
    */
    void shell_sort(unsigned int* first, unsigned int* last) { 
        unsigned int size = last-first;
        for (unsigned int gap = size/2; gap > 0; gap /= 2) { 
            for (unsigned int i = gap; i < size; i += 1) { 
                //sort sub lists created by applying gap 
                unsigned int temp = *(first+i);; 
                unsigned int j; 
                for (j = i; j >= gap && *(first+j-gap) > temp; j -= gap) *(first+j) = *(first+j-gap);
               
                *(first+j) = temp; 
            } 
        } 
    }
}
#endif // SORTING_H
