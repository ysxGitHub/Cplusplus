#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <iostream>

// 打印vector内容
void printVector(const std::string prefix, const std::vector<int>& vi) {
    std::cout << prefix;
    for (auto&i : vi) {
        std::cout << " " << i;
    }
    std::cout << std::endl;
}

// 抽象策略类: 排序
class Sort {
public:
	virtual void sortVector(std::vector<int>& arr) = 0;
};

// 具体策略类: 冒泡排序
class BubbleSort : public Sort {
public:
    void sortVector(std::vector<int>& vi) override {
        printVector("冒泡排序前:", vi);
        int len = vi.size();
        // 轮次: 从1到n-1轮
        for (int i = 0; i < len - 1; ++i) {
            // 优化: 判断本轮是否有交换元素, 如果没交换则可直接退出
            bool is_exchange = false;

            for (int j = 0; j < len - i - 1; ++j) {
                if (vi[j] > vi[j + 1]) {
                    std::swap(vi[j], vi[j + 1]);
                    is_exchange = true;
                }
            }

            // 如果本轮无交换, 则可以直接退出
            if (!is_exchange) {
                printVector("冒泡排序后:", vi);
                return;
            }
        }
        printVector("冒泡排序后:", vi);
    }
};

// 具体策略类: 选择排序
class SelectionSort : public Sort {
public:
    void sortVector(std::vector<int>& vi) override {
        printVector("选择排序前:", vi);
        // 需要进行 n-1 轮
        for (int i = 0; i < vi.size() - 1; ++i) {
            // 找到此轮的最小值下标
            int min_index = i;
            for (int j = i + 1; j < vi.size(); ++j) {
                if (vi[j] < vi[min_index]) {
                    min_index = j;
                }
            }

            std::swap(vi[i], vi[min_index]);
        }
        printVector("选择排序后:", vi);
    }
};

// 具体策略类: 插入排序
class InsertionSort : public Sort {
public:
    void sortVector(std::vector<int>& vi) override {
        printVector("插入排序前:", vi);
        // 第一轮不需要操作, 第二轮比较一次, 第n轮比较 n-1 次
        for (int i = 1; i < vi.size(); ++i) {
            // 存储待插入的值和下标
            int insert_value = vi[i];
            int j = i - 1;

            while (j >= 0 && vi[j] > insert_value) {
                vi[j + 1] = vi[j];  // 如果左侧的已排序元素比目标值大, 那么右移
                j--;
            }

            // 注意这里insert_index 需要+1
            vi[j + 1] = insert_value;
        }
        printVector("插入排序后:", vi);
    }
};

// 上下文
class ArrayHandler {
public:
    void sortVector(std::vector<int>& arr) {
        return sort_->sortVector(arr);
    }
    void setSortStrategy(Sort* sort) {
        sort_ = sort;
    }

private:
    Sort* sort_;
};


std::vector<int> test_array = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25 };

int main() {
    ArrayHandler array_handler;

    {
        // 冒泡排序
        BubbleSort* bubble_sort = new BubbleSort();
        std::random_shuffle(test_array.begin(), test_array.end());
        array_handler.setSortStrategy(bubble_sort);
        array_handler.sortVector(test_array);
        delete bubble_sort;
    }

    {
        // 选择排序
        SelectionSort* select_sort = new SelectionSort();
        std::random_shuffle(test_array.begin(), test_array.end());
        array_handler.setSortStrategy(select_sort);
        array_handler.sortVector(test_array);
        delete select_sort;
    }

    {
        // 插入排序
        InsertionSort* insert_sort = new InsertionSort();
        std::random_shuffle(test_array.begin(), test_array.end());
        array_handler.setSortStrategy(insert_sort);
        array_handler.sortVector(test_array);
        delete insert_sort;
    }

    return 0;
}
