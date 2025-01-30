#include <iostream>
#include <vector>
#include <stdexcept>

class MinHeap {
private:
    std::vector<int> heap;

    void heapify(int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heap.size() && heap[left] < heap[smallest]) {
            smallest = left;
        }
        if (right < heap.size() && heap[right] < heap[smallest]) {
            smallest = right;
        }
        if (smallest != i) {
            std::swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        int i = heap.size() - 1;
        while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
            std::swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    int extractMin() {
        if (heap.size() == 0) {
            throw std::out_of_range("Heap is empty");
        }
        int min = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
        return min;
    }

    int getMin() const {
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
    MinHeap minHeap;

    minHeap.insert(10);
    minHeap.insert(20);
    minHeap.insert(15);
    minHeap.insert(30);
    minHeap.insert(5);

    std::cout << "Min Value: " << minHeap.getMin() << std::endl;

    std::cout << "Extract Min: " << minHeap.extractMin() << std::endl;
    std::cout << "Extract Min: " << minHeap.extractMin() << std::endl;

    std::cout << "Min Value after extraction: " << minHeap.getMin() << std::endl;

    return 0;
}
