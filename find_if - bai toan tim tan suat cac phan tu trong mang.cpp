#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cout << "Nhap so phan tu cua mang: ";
    std::cin >> N;

    std::vector<int> A(N);
    std::cout << "Nhap cac phan tu cua mang:\n";
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    // Sử dụng vector và pair để lưu trữ số lần xuất hiện của mỗi phần tử
    std::vector<std::pair<int, int>> countVector;

    for (int i = 0; i < N; ++i) {
        int currentElement = A[i];

        // Kiểm tra xem phần tử đã được đếm chưa
        auto it = std::find_if(countVector.begin(), countVector.end(), 
            [currentElement](const std::pair<int, int>& element) {
                return element.first == currentElement;
            }
        );

        if (it != countVector.end()) {
            // Nếu đã tồn tại trong vector, tăng số lần xuất hiện
            it->second++;
        } else {
            // Nếu chưa tồn tại, thêm vào vector
            countVector.push_back(std::make_pair(currentElement, 1));
        }
    }

    // In ra kết quả
    std::cout << "So lan xuat hien cua cac phan tu:\n";
    for (const auto &pair : countVector) {
        std::cout << "Phan tu " << pair.first << ": " << pair.second << " lan\n";
    }

    return 0;
}
