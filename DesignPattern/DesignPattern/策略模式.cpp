#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <iostream>

// ��ӡvector����
void printVector(const std::string prefix, const std::vector<int>& vi) {
    std::cout << prefix;
    for (auto&i : vi) {
        std::cout << " " << i;
    }
    std::cout << std::endl;
}

// ���������: ����
class Sort {
public:
	virtual void sortVector(std::vector<int>& arr) = 0;
};

// ���������: ð������
class BubbleSort : public Sort {
public:
    void sortVector(std::vector<int>& vi) override {
        printVector("ð������ǰ:", vi);
        int len = vi.size();
        // �ִ�: ��1��n-1��
        for (int i = 0; i < len - 1; ++i) {
            // �Ż�: �жϱ����Ƿ��н���Ԫ��, ���û�������ֱ���˳�
            bool is_exchange = false;

            for (int j = 0; j < len - i - 1; ++j) {
                if (vi[j] > vi[j + 1]) {
                    std::swap(vi[j], vi[j + 1]);
                    is_exchange = true;
                }
            }

            // ��������޽���, �����ֱ���˳�
            if (!is_exchange) {
                printVector("ð�������:", vi);
                return;
            }
        }
        printVector("ð�������:", vi);
    }
};

// ���������: ѡ������
class SelectionSort : public Sort {
public:
    void sortVector(std::vector<int>& vi) override {
        printVector("ѡ������ǰ:", vi);
        // ��Ҫ���� n-1 ��
        for (int i = 0; i < vi.size() - 1; ++i) {
            // �ҵ����ֵ���Сֵ�±�
            int min_index = i;
            for (int j = i + 1; j < vi.size(); ++j) {
                if (vi[j] < vi[min_index]) {
                    min_index = j;
                }
            }

            std::swap(vi[i], vi[min_index]);
        }
        printVector("ѡ�������:", vi);
    }
};

// ���������: ��������
class InsertionSort : public Sort {
public:
    void sortVector(std::vector<int>& vi) override {
        printVector("��������ǰ:", vi);
        // ��һ�ֲ���Ҫ����, �ڶ��ֱȽ�һ��, ��n�ֱȽ� n-1 ��
        for (int i = 1; i < vi.size(); ++i) {
            // �洢�������ֵ���±�
            int insert_value = vi[i];
            int j = i - 1;

            while (j >= 0 && vi[j] > insert_value) {
                vi[j + 1] = vi[j];  // �������������Ԫ�ر�Ŀ��ֵ��, ��ô����
                j--;
            }

            // ע������insert_index ��Ҫ+1
            vi[j + 1] = insert_value;
        }
        printVector("���������:", vi);
    }
};

// ������
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
        // ð������
        BubbleSort* bubble_sort = new BubbleSort();
        std::random_shuffle(test_array.begin(), test_array.end());
        array_handler.setSortStrategy(bubble_sort);
        array_handler.sortVector(test_array);
        delete bubble_sort;
    }

    {
        // ѡ������
        SelectionSort* select_sort = new SelectionSort();
        std::random_shuffle(test_array.begin(), test_array.end());
        array_handler.setSortStrategy(select_sort);
        array_handler.sortVector(test_array);
        delete select_sort;
    }

    {
        // ��������
        InsertionSort* insert_sort = new InsertionSort();
        std::random_shuffle(test_array.begin(), test_array.end());
        array_handler.setSortStrategy(insert_sort);
        array_handler.sortVector(test_array);
        delete insert_sort;
    }

    return 0;
}
