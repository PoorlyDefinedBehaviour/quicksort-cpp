#include <iostream>
#include <array>
#include <vector>

auto quicksort = [](auto &array, const int &start, const int &end) -> void {
  if (start >= end)
    return;

  auto swap = [](auto &a, auto &b) -> void {
    auto temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
  };

  int pivotIndex = start;
  auto pivotValue = array[end];

  for (int i = start; i < end; ++i)
  {
    if (array[i] < pivotValue)
    {
      swap(array[i], array[pivotIndex]);
      ++pivotIndex;
    }
  }

  swap(array[pivotIndex], array[end]);

  quicksort(array, start, pivotIndex - 1);
  quicksort(array, pivotIndex + 1, end);
};

int main()
{
  std::vector<int> std_vector = {6, 2, 7, 1, 0, 29, 48, 2, 49, 3};
  std::array<int, 10> std_array = {6, 2, 7, 1, 0, 29, 48, 2, 49, 3};
  int c_array[] = {6, 2, 7, 1, 0, 29, 48, 2, 49, 3};

  quicksort(std_vector, 0, std_vector.size() - 1);
  quicksort(std_array, 0, std_array.size() - 1);
  quicksort(c_array, 0, 9);

  std::cout << "\nstd::vector -> ";
  for (const auto &element : std_vector)
    std::cout << element << " ";

  std::cout << "\nstd::array -> ";
  for (const auto &element : std_array)
    std::cout << element << " ";

  std::cout << "\nc style array -> ";
  for (const auto &element : c_array)
    std::cout << element << " ";
}