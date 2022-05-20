/*!
 * @file main.cpp
 * @author Ianco Soares Oliveira and Lucas Vinícius Gois Nogueira
 * @brief Tests sorting algorithms for time complexity. Nomely,
 * we are testing the time complexity of the following algorithms:
 * insertion sort, selection sort, bubble sort, merge sort, quick sort, radix sort and shell sort.
 * @date 2022-05-19
*/
#include <chrono> // for mensure time.
#include <iostream> // std::cout 
#include <algorithm> //std::shuffle
#include <array> // for std::array
#include <string> // std::string
#include <fstream> // for file input
#include <numeric> // std::iota
#include <random> // std::default_random_engine

#include "lib/sorting.h"

#define N_SCENARIOS 6
#define N_ALGORITHMS 7
#define MAX_ARRAY_SIZE 1000
#define MIN_ARRAY_SIZE 100
#define N_SAMPLES 25
#define N_RUNS 5
#define JUMP (MAX_ARRAY_SIZE-MIN_ARRAY_SIZE)/N_SAMPLES

enum scenario {
    SORTED = 1,
    REVERSE_SORTED,
    RANDOM,
    RANDOM25,
    RANDOM50,
    RANDOM75
};

inline double measure_time(unsigned int* first, unsigned int* last, std::function<void(unsigned int*, unsigned int*)> sort_algorithm) {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    sort_algorithm(first, last);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = end - begin;
    return std::chrono::duration <double, std::milli> (diff).count();
}

inline double test_sort_algorithm ( unsigned int* first, unsigned int* last,
                                    int i, enum scenario sc, 
                                    std::function<void(unsigned int*, unsigned int*)> sort_algorithm) {
    std::array<unsigned int, MAX_ARRAY_SIZE> array;
    std::copy(first, last, array.begin());

    std::array<unsigned int, MAX_ARRAY_SIZE> I;

    for (unsigned int i = 0; i < I.size(); i++) I[i] = i;
    std::shuffle(I.begin(), I.end(), std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count()));
    
    switch (sc) {
        case SORTED:
            break;
        case REVERSE_SORTED:
            std::reverse(array.begin(), array.end());
            break;
        case RANDOM:
            std::shuffle(array.begin(), array.end(), std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count()));
            break;
        case RANDOM25:
            for (unsigned int i = 0; i < array.size()*0.25; i+=2) array[I[i]] = array[I[i+1]];
            break;
        case RANDOM50:
            for (unsigned int i = 0; i < array.size()*0.5; i+=2) array[I[i]] = array[I[i+1]];
            break;
        case RANDOM75:
            for (unsigned int i = 0; i < array.size()*0.75; i +=2) array[I[i]] = array[I[i+1]];
            break;
        default:
            break;
    }
    return measure_time(array.begin(), array.begin()+MIN_ARRAY_SIZE+JUMP*i, sort_algorithm);
}

int main (void) {
    double average = 0.0;
    //create array
    std::array<unsigned int, MAX_ARRAY_SIZE> a;
    std::iota(a.begin(), a.end(), 0); //initialize array with 0,1,2,3,...,MAX_ARRAY_SIZE-1
    std::ofstream fw("output.txt", std::ofstream::out);

    if (!fw.is_open()) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }

    std::array<std::function<void(unsigned int*, unsigned int*)>, N_ALGORITHMS> sort_algorithms = {
        sort::selection_sort,
        sort::bubble_sort,
        sort::insertion_sort,
        sort::merge_sort,
        sort::quick_sort,
        sort::radix_sort,
        sort::shell_sort
    };
    
    fw<< "#N\t\t";
    for (int i = 0; i < N_SCENARIOS; i++)
        for (int j = 0; j < N_ALGORITHMS; j++)
            fw << "S:"+std::to_string(i+1) << "-" << "A:"+std::to_string(j+1) << "\t\t";
    fw << "\n";

    for (int i = 0; i < N_SAMPLES; i++) {
        fw << MIN_ARRAY_SIZE+JUMP*i << "\t\t";
        for (int j = 0; j < N_SCENARIOS; j++) {
            for (auto& s : sort_algorithms) {
                average = 0.0;
                for (int k = 1; k <= N_RUNS; k++) {
                    average = average + (test_sort_algorithm(a.begin(), a.end(), i, (scenario)(j+1), s)-average)/k;
                }
                fw << average << "\t\t";
            }
        }
        fw << "\n";
    }

    fw.close();

    return 0;
}