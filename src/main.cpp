#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

template <typename T>
void quicksort(T &array, const int &start, const int &end)
{
  if (start >= end)
    return;

  auto partition = [&]() -> int {
    int pivotIndex = start;
    auto pivotValue = array[end];

    for (int i = start; i < end; ++i)
    {
      if (array[i] < pivotValue)
      {
        std::swap(array[i], array[pivotIndex]);
        ++pivotIndex;
      }
    }
    std::swap(array[pivotIndex], array[end]);
    return pivotIndex;
  };

  int currentIndex = partition();
  quicksort(array, start, currentIndex - 1);
  quicksort(array, currentIndex + 1, end);
}

int main()
{
  std::vector<int> std_vector = {5, 2, 8, 7, 2, 9, 10, 18, 29, 3};
  std::array<int, 10> std_array = {5, 2, 8, 7, 2, 9, 10, 18, 29, 3};
  int array[] = {5, 2, 8, 7, 2, 9, 10, 18, 29, 3};

  quicksort(std_vector, 0, std_vector.size() - 1);
  quicksort(std_array, 0, std_array.size() - 1);
  quicksort(array, 0, 9);

  std::cout << "\nstd::vector -> ";
  for (const auto &element : std_vector)
    std::cout << element << " ";

  std::cout << "\nstd::array -> ";
  for (const auto &element : std_array)
    std::cout << element << " ";

  std::cout << "\narray -> ";
  for (const auto &element : array)
    std::cout << element << " ";
}