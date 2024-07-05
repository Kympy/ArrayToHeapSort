
#include <iostream>

#define endl "\n"

enum HeapType
{
    MaxHeap,
    MinHeap,
};

void SortHeap(int* heap, int length, HeapType type);
void MakeHeap(int* arr, int length, HeapType type);
void DownHeapify(int* arr, int index, int length, HeapType type);
void Swap(int* arr, int index1, int index2);
void PrintArray(int* arr, int count);

int main(int argc, char* argv[])
{
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int count = 0;
    std::cin >> count;
    
    int* numbers = new int[count];
    for (int i = 0; i < count; i++)
    {
        std::cin >> numbers[i];
    }
    MakeHeap(numbers, count, HeapType::MinHeap);
    //PrintArray(numbers, count);
    
    SortHeap(numbers, count, HeapType::MinHeap);
    // PrintArray(numbers, count);
    
    for (int i = 0; i < count; i++)
    {
        std::cout << numbers[i] << endl;
    }
    
    delete[] numbers;
}

void SortHeap(int* heap, int length, HeapType type)
{
    // 루트와 리프를 교환하고, 교환된 루트가 힙에서 삭제되었다고 가정하고 힙 사이즈를 감소
    for(int i = length - 1; i >= 0; i--)
    {
        Swap(heap, 0, i);
        DownHeapify(heap, 0, i, type);
    }
    
    if (type == HeapType::MinHeap)
    {
        for (int i = 0; i < length / 2; i++)
        {
            int temp = heap[i];
            heap[i] = heap[length - 1 - i];
            heap[length - 1 - i] = temp;
        }
    }
}

void MakeHeap(int* arr, int length, HeapType type)
{
    for (int i = length - 1; i >= 0; i--)
    {
        DownHeapify(arr, i, length, type);
    }
}

void DownHeapify(int* arr, int index, int length, HeapType type)
{
    int leftIndex = (index) * 2 + 1;
    int rightIndex = (index) * 2 + 2;
    
    if (leftIndex >= length && rightIndex >= length)
    {
        return;
    }
    
    int targetIndex = index;

    switch (type) 
    {
    case HeapType::MaxHeap:
    {
        if (leftIndex < length && arr[targetIndex] < arr[leftIndex])
            targetIndex = leftIndex;
        if (rightIndex < length && arr[targetIndex] < arr[rightIndex])
            targetIndex = rightIndex;
        break;
    }
    case HeapType::MinHeap:
    {
        if (leftIndex < length && arr[targetIndex] > arr[leftIndex])
                targetIndex = leftIndex;
        if (rightIndex < length && arr[targetIndex] > arr[rightIndex])
                targetIndex = rightIndex;
        break;
    }
    }
    
    if (targetIndex != index)
    {
        Swap(arr, targetIndex, index);
        DownHeapify(arr, targetIndex, length, type);
    }
}

void Swap(int* arr, int index1, int index2)
{
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

void PrintArray(int* arr, int count)
{
    for(int i = 0; i < count; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << endl;
}
