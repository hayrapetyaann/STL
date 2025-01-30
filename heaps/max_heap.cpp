#include <iostream>
#include <vector>
#include <stdexcept>

class MaxHeap {
private:
    std::vector<int> heap;

    void heapify(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }
        if (largest != i) {
            std::swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        int i = heap.size() - 1;
        while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
            std::swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    int extractMax() {
        if (heap.size() == 0) {
            throw std::out_of_range("Heap is empty");
        }
        int max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
        return max;
    }

    int getMax() const {
        if (heap.size() == 0) {
            throw std::out_of_range("Heap is empty");
        }
        return heap[0];
    }

    bool isEmpty() const {
        return heap.empty();
    }

    size_t size() const {
        return heap.size();
    }
};

int main() {
    MaxHeap maxHeap;
    
    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(15);
    maxHeap.insert(30);
    maxHeap.insert(5);
    
    std::cout << "Max Value: " << maxHeap.getMax() << std::endl;

    std::cout << "Extract Max: " << maxHeap.extractMax() << std::endl;
    std::cout << "Extract Max: " << maxHeap.extractMax() << std::endl;

    std::cout << "Max Value after extraction: " << maxHeap.getMax() << std::endl;

    return 0;
}
