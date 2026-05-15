#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <fstream>
#include <algorithm>
#include <sys/time.h>
#include <cmath>
#include <climits>
#include <stdexcept>

// ---------------------------------------------------------
// TESTER UTILITIES
// ---------------------------------------------------------

template <typename ForwardIterator>
bool isSorted(ForwardIterator first, ForwardIterator last)
{
    if (first == last)
        return true;
    ForwardIterator next = first;
    ++next;
    while (next != last)
    {
        // Compare the actual values to verify sorting
        if (next->winner < first->winner)
        {
            return false;
        }
        ++first;
        ++next;
    }
    return true;
}

void LogNumsToFile(const Node& node)
{
    std::string fileName = "file.log";
    std::ofstream os(fileName.c_str(), std::ios::app);
    os << node.winner << " ";
    os.close();
}

void logFile(std::vector<Node> &nums, std::vector<Node> &nums1, std::vector<Node> &nums2)
{
    std::string fileName = "file.log";
    std::ofstream os(fileName.c_str());
    os << "Origin nums\n";
    os.close();
    std::for_each(nums.begin(), nums.end(), LogNumsToFile);

    os.open(fileName.c_str(), std::ios::app);
    os << "\n\nAfter MergeInsert\n";
    os.close();
    std::for_each(nums1.begin(), nums1.end(), LogNumsToFile);
    
    os.open(fileName.c_str(), std::ios::app);
    os << "\n\nSorted nums\n";
    os.close();
    std::for_each(nums2.begin(), nums2.end(), LogNumsToFile);
    
    os.open(fileName.c_str(), std::ios::app);
    os << "\n";
    os.close();
}

int computeSum(int n)
{
    int sum = 0;
    for (int k = 1; k <= n; ++k)
    {
        double value = log2((3.0 / 4.0) * k);
        sum += static_cast<int>(std::ceil(value));
    }
    return sum;
}

// ---------------------------------------------------------
// MAIN TESTER FUNCTION
// ---------------------------------------------------------

void GeneralTest(int numberOfItems, int numberOfTests = 1000000, int skip = 0)
{
    PmergeMe obj;
    std::vector<Node> list, numsToSort, originalNums, numsSortedByCpp;

    for(int i = 1; i <= numberOfItems; i++)
    {
        list.push_back(Node(i));
    }

    bool var = true;

    for (int i = 0; i < numberOfTests && var; i++)
    {
        numsToSort = list;
        originalNums = numsToSort;
        numsSortedByCpp = numsToSort;
        
        struct timeval tv, tv2;
        
        // Reset counters before sorting
        Node::counter = 0;
        obj.comparison = 0; 

        gettimeofday(&tv, NULL);
        
        // Use your implementation's sort function
        obj.sortRecursion(numsToSort);
        
        gettimeofday(&tv2, NULL);

        long mcs1 = (long)tv.tv_sec * 1000000 + tv.tv_usec;
        long mcs2 = (long)tv2.tv_sec * 1000000 + tv2.tv_usec;
        long time = mcs2 - mcs1;

        int NumberOfComparisons = Node::counter;
        int maxNumberOfComparisons = computeSum(numberOfItems);

        std::cout << "Test: " << i + 1 << '\n';
        std::cout << "Max number of Comparisons: " << maxNumberOfComparisons << "\n";
        std::cout << "Algorithm Comparisons: " << NumberOfComparisons << "\n";
        
        std::string s = isSorted(numsToSort.begin(), numsToSort.end()) ? "true\n" : "false\n";
        std::cout << "isSorted: " << s << "Time: " << time << " us\n"; // Switched to microseconds (us) for precision

        if (numsToSort.size() != originalNums.size())
            std::cout << "numsToSort has wrong size: " << numsToSort.size() << " should be: " << originalNums.size() << '\n';
        
        // Sort the C++ vector using a lambda to prevent inflating Node::counter
        std::sort(numsSortedByCpp.begin(), numsSortedByCpp.end(), [](const Node& a, const Node& b) {
            return a.winner < b.winner;
        });

        if (s == "false\n" || numsToSort.size() != originalNums.size() || NumberOfComparisons > maxNumberOfComparisons)
        {
            logFile(originalNums, numsToSort, numsSortedByCpp);
            exit(0);
        }
        
        for (int j = 0; j < (int)numsToSort.size(); j++)
        {
            if (numsToSort[j].winner != numsSortedByCpp[j].winner)
            {
                std::cout << "Corrupted output\n";
                logFile(originalNums, numsToSort, numsSortedByCpp);
                exit(0);
            }
        }
        std::cout << "\n";
        
        for(int k = 0; k <= skip; k++)
        {
            // Use a lambda here as well to avoid inflating Node::counter
            var = std::next_permutation(list.begin(), list.end(), [](const Node& a, const Node& b) {
                return a.winner < b.winner;
            });
            if (!var)
                break;
        }
    }
}

// ---------------------------------------------------------
// PRINT UTILITIES & ARG PARSING
// ---------------------------------------------------------

void printResult(std::deque<Node>& _dq_nums, std::string str)
{
    std::cout << str << ": " ;
    for (size_t i = 0; i < _dq_nums.size(); i++)
    {
        std::cout << _dq_nums[i].winner << " " ;
    }
    std::cout << std::endl;
}

void printResult(std::vector<Node>& _v_nums, std::string str)
{
    std::cout << str << ": " ;
    for (size_t i = 0; i < _v_nums.size(); i++)
    {
        std::cout << _v_nums[i].winner << " " ;
    }
    std::cout << std::endl;
}

int StringToInt(const char *str) {
    char *endPtr;
    long val = std::strtol(str, &endPtr, 10);

    if (*endPtr != '\0') {
        throw std::runtime_error("Invalid Character");
    }

    if (val > INT_MAX || val < 0) {
        throw std::runtime_error("Invalid Number");
    }

    return static_cast<int>(val);
}

// ---------------------------------------------------------
// MAIN
// ---------------------------------------------------------

int main(int argc, char const *argv[])
{
    // Fix: check argc instead of ac
    if (argc <= 1)
    {
        std::cout << "There are no numbers to sort!!\n";
        // Optionally run GeneralTest if no arguments are provided to see the algorithm work natively
        try {
            std::cout << "Running automated GeneralTest for n=21...\n";
            GeneralTest(21, 10000, 0); // Reduced iterations for quick default test
        } catch(const std::exception& e) {
            std::cerr << "Error:\n" << e.what() << std::endl;
        }
        return 0;
    }

    std::vector<Node> pairs;
    try
    {
        // Fix: iterate using argc and argv
        for (int i = 1; i < argc; i++) {
            int n = StringToInt(argv[i]);
            pairs.push_back(Node(n));
        }
        
        PmergeMe sorter;
        std::cout << "Testing with provided arguments:\n";
        sorter.VectorTest(pairs);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error:\n" << e.what() << std::endl;
    }

    return 0;
}



// #include "PmergeMe.hpp"
//
// int StringToInt(const char *str) {
//   char *endPtr;
//   long val = std::strtol(str, &endPtr, 10);
//
//   if (*endPtr != '\0') {
//     throw std::runtime_error("Invalid Character");
//   }
//
//   if (val > INT_MAX || val < 0) {
//     throw std::runtime_error("Invalid Number");
//   }
//
//   return static_cast<int>(val);
// }
//
//
//
// int main(int ac, char *av[]) {
//
//   if (ac < 2) {
//     std::cout << "Error: Enter some number" << std::endl;
//     return 1;
//   }
//
//   std::vector<Node> pairs;
//   std::vector<int> input;
//   PmergeMe merge;
//   try {
//     int n = 0;
//     for (int i = 1; i < ac; i++) {
//       n = StringToInt(av[i]);
//       pairs.push_back(Node(n));
//     }
//   } catch (std::exception &e) {
//     std::cout << "Error: " << e.what() << std::endl;
//     return 1;
//   }
//
//   merge.VectorTest(pairs);
//   std::cout << "comparison: " << merge.comparison << std::endl;
//
//   return 0;
// }
