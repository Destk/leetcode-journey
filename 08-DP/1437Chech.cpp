#include <iostream>
#include <vector>
#include <limits>

class Solution {
private:
    std::vector<int> nums;
    int k{};
public:
    void reset() {          
        nums.clear();
        k = 0;
    }

    void SetN() {
        bool ok = false;
        while (!ok) {
            std::cout << "Введите кол-во элементов в nums: ";
            int x{};
            std::cin >> x;
            if (std::cin.fail() || x <= 0) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\nОшибка ввода, попробуйте ещё раз\n";
                continue;
            }

            nums.clear();          

            for (int i = 0; i < x; ++i) {
                while (true) {
                    std::cout << "\nВведите число (0/1): ";
                    int y{};
                    std::cin >> y;
                    if (std::cin.fail() || (y != 0 && y != 1)) {  
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "\nОшибка ввода, введите 0 или 1\n";
                        continue;  
                    }
                    nums.push_back(y);
                    break;
                }
            }

            std::cout << "\nВведите расстояние k: ";
            std::cin >> k;
            if (std::cin.fail() || k < 0) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\nОшибка ввода, попробуйте ещё раз\n";
                continue;
            }
            ok = true;
        }
    }

    bool kLengthApart() {
        int c = k;  // счётчик расстояния с последней единицы
        for (std::size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                if (c < k) {
                    return false;
                }
                c = 0;
            } else {
                ++c;
            }
        }
        return true;
    }

    void out(bool r) {
        if (r) {
            std::cout << "\nВсе единицы находятся на нужном расстоянии\n";
        } else {
            std::cout << "\nЕсть единицы, находящиеся ближе чем на k позиций\n";
        }
    }
};

int main() {
    std::cout << "Программа: проверка, находятся ли все единицы на расстоянии не менее k позиций друг от друга.\n";
    Solution l;
    char c{};
    do {
        l.reset();             
        l.SetN();
        bool r = l.kLengthApart();
        l.out(r);
        std::cout << "Продолжить? (y/n): ";
        std::cin >> c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << '\n';
    } while (c == 'y' || c == 'Y');
}
