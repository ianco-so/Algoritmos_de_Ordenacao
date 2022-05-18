/*!
 * @file main.cpp
 * @author Ianco Soares Oliveira and Lucas Vinícius Gois Nogueira
 * @brief Tests sorting algorithms for time complexity. Nomely,
 * we are testing the time complexity of the following algorithms:
 * insertion sort, selection sort, bubble sort, merge sort, quick sort, radix sort and shell sort.
 * @date 2022-05-19
*/
#include <chrono>
#include <iostream>
#include <algorithm>
#include <array>
#include <string>
#include <fstream>
#include <numeric> // std::iota
#include <random> // std::default_random_engine

#include "lib/sorting.h"

#define MAX_ARRAY_SIZE 100000
#define MIN_ARRAY_SIZE 100
#define N_SAMPLES 25
#define N_RUNS 5
#define JUMP (MAX_ARRAY_SIZE-MIN_ARRAY_SIZE)/N_SAMPLES

/*inline bool check_sort(unsigned int * first, unsigned int * last) {
    for (unsigned int i = 0; i < last-first-1; ++i) if (*(first+i) > *(first+i+1)) return false;
    return true;
}*/
inline void print_test() {
}
/*!
 * @brief Tests the time complexity of the selection sort algorithm.
 * @param array The array to be sorted.
 * @param size The size of the array.
 * @return The time complexity of the selection sort algorithm.
*/
inline double test_selection_sort (unsigned int* first, unsigned int* last) {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    sort::selection_sort(first, last);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = end - begin;
    return std::chrono::duration <double, std::milli> (diff).count();
}
/*!
 * @brief Tests the bubble sort algorithm.
 * @param first The first element of the array.
 * @param last The last element of the array.
 * @return The time of the bubble sort algorithm.
*/
inline double test_bubble_sort (unsigned int* first, unsigned int* last) {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    sort::bubble_sort(first, last);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = end - begin;
    return std::chrono::duration <double, std::milli> (diff).count();
}
/*! 
 * @brief Tests the insertion sort algorithm.
 * @param first The first element of the array.
 * @param last The last element of the array.
 * @return The time it took to sort the array.
*/
inline double test_inserction_sort (unsigned int* first, unsigned int* last) {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    sort::insertion_sort(first, last);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = end - begin;
    return std::chrono::duration <double, std::milli> (diff).count();
}
/*! @brief Tests the merge sort algorithm.
 * @param first The first element of the array.
 * @param last The last element of the array.
 * @return The time it took to sort the array.
*/
inline double test_merge_sort (unsigned int* first, unsigned int* last) {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    sort::merge_sort(first, last);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = end - begin;
    return std::chrono::duration <double, std::milli> (diff).count();
}
/*! @brief Tests the quick sort algorithm.
 * @param first The first element of the array.
 * @param last The last element of the array.
 * @return The time it took to sort the array.
*/
inline double test_quick_sort (unsigned int* first, unsigned int* last) {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    sort::quick_sort(first, last);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = end - begin;
    return std::chrono::duration <double, std::milli> (diff).count();
}
/*! @brief Tests the radix sort algorithm.
 * @param first The first element of the array.
 * @param last The last element of the array.
 * @return The time it took to sort the array.
*/
inline double test_radix_sort (unsigned int* first, unsigned int* last) {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    sort::radix_sort(first, last);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = end - begin;
    return std::chrono::duration <double, std::milli> (diff).count();
}
/*! @brief Tests the shell sort algorithm.
 * @param first The first element of the array.
 * @param last The last element of the array.
 * @return The time it took to sort the array.
*/
inline double test_shell_sort (unsigned int* first, unsigned int* last) {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    sort::shell_sort(first, last);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = end - begin;
    return std::chrono::duration <double, std::milli> (diff).count();
}

int main (void) {
    double average = 0.0;
    //create array
    std::array<unsigned int, MAX_ARRAY_SIZE> a;
    std::ofstream fw("output.csv", std::ofstream::out);
    if (!fw.is_open()) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }
    fw << "#n;";
    for (int i = MIN_ARRAY_SIZE; i <MAX_ARRAY_SIZE; i +=JUMP) {
        fw << i << ";";
    }
    fw << "\n";

    /*

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //===========================================================SCENARIO 1: increasing order===============================================================================
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



    std::iota(a.begin(), a.end(), 0);
    fw << "#SE;";
    for (int i = 1; i <= N_SAMPLES; i++) {   
        for (unsigned int j = 1; j <= N_RUNS; j++) {
            average = average + (test_selection_sort(a.begin(), a.begin() + MIN_ARRAY_SIZE + JUMP*i) - average)/j;
        }
        fw << average << ";";
    }
    fw << "\n";

    //=====================================================================================================================================================================

    std::iota(a.begin(), a.end(), 0);
    fw << "#BU;";
    for (int i = 1; i <= N_SAMPLES; i++) {   
        for (unsigned int j = 1; j <= N_RUNS; j++) {
            average = average + (test_bubble_sort(a.begin(), a.begin() + MIN_ARRAY_SIZE + JUMP*i) - average)/j;
        }
        fw<< average << ";";
    }
    fw << "\n";

    //=====================================================================================================================================================================

    std::iota(a.begin(), a.end(), 0); //fill array with numbers from 0 to ARRAY_SIZE-1
    fw << "#IN;";
    for (int i = 1; i <= N_SAMPLES; i++) {   
        for (unsigned int j = 1; j <= N_RUNS; j++) {
            average = average + (test_inserction_sort(a.begin(), a.begin() + MIN_ARRAY_SIZE + JUMP*i) - average)/j;
        }
        fw << average << ";";
    }
    fw << "\n";

    //=====================================================================================================================================================================

    std::iota(a.begin(), a.end(), 0); //fill array with numbers from 0 to ARRAY_SIZE-1
    fw << "#ME;";
    for (int i = 1; i <= N_SAMPLES; i++) {   
        for (unsigned int j = 1; j <= N_RUNS; j++) {
            average = average + (test_merge_sort(a.begin(), a.begin() + MIN_ARRAY_SIZE + JUMP*i) - average)/j;
        }
        fw << average << ";";
    }
    fw << "\n";
    */
    //=====================================================================================================================================================================

    std::iota(a.begin(), a.end(), 0); //fill array with numbers from 0 to ARRAY_SIZE-1
    std::shuffle(a.begin(), a.end(), std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count()));
    fw << "#QU;";
    for (int i = 1; i <= N_SAMPLES; i++) {   
        for (unsigned int j = 1; j <= N_RUNS; j++) {
            average = average + (test_quick_sort(a.begin(), a.begin() + MIN_ARRAY_SIZE + JUMP*i) - average)/j;
        }
        fw << average << ";";
    }
    fw << "\n";

    //=====================================================================================================================================================================
    /*
    std::iota(a.begin(), a.end(), 0); //fill array with numbers from 0 to ARRAY_SIZE-1
    fw << "#RA;";
    for (int i = 1; i <= N_SAMPLES; i++) {   
        for (unsigned int j = 1; j <= N_RUNS; j++) {
            average = average + (test_radix_sort(a.begin(), a.begin() + MIN_ARRAY_SIZE + JUMP*i) - average)/j;
        }
        fw << average << ";";
    }
    fw << "\n";

    //=====================================================================================================================================================================

    std::iota(a.begin(), a.end(), 0); //fill array with numbers from 0 to ARRAY_SIZE-1 
    fw << "#SH;";
    for (int i = 1; i <= N_SAMPLES; i++) {   
        for (unsigned int j = 1; j <= N_RUNS; j++) {
            average = average + (test_shell_sort(a.begin(), a.begin() + MIN_ARRAY_SIZE + JUMP*i) - average)/j;
        }
        fw << average << ";";
    }
    fw << "\n";
    */
    return 0;
}