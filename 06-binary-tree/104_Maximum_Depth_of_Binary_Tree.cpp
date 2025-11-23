#include<iostream>
#include<vector>
#include<string>
#include<limits>
#include<algorithm>
//биинарное дерево
struct TreeNode{
    int data{};
    TreeNode* right;
    TreeNode* left;
    TreeNode() : data(0), right(nullptr), left(nullptr) {};
    TreeNode(int x) : data(x), right(nullptr), left(nullptr) {};
    TreeNode(int x,TreeNode* r, TreeNode* l) : data(x), right(r), left(l) {};
};

TreeNode* createTree(){
        // 1. Приветствие
    std::cout << "Программа для поиска максимальной глубины бинарного дерева\n";

    // 2. Запрос количества элементов
    int n;
    do{
    std::cout << "Введите количество элементов: ";
    std::cin >> n;
    if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    }while(std::cin.fail());
    // 3. Создание вектора
    std::vector<std::string> values;

    // 4. Цикл ввода
    for (int i = 0; i < n; i++) {
        std::string element;
        std::cout << "Элемент " << i << ": ";
        std::cin >> element;
        values.push_back(element);
    }
    //5. связывваем и строим дерево
    std::vector<TreeNode*> Trees;
    for(int i = 0; i < values.size(); i++){
        if(values[i] != "null"){
            Trees.push_back(new TreeNode(stoi(values[i])));
        }else{
            Trees.push_back(nullptr);
        }
    }
    for (int i = 0; i < Trees.size(); i++) {
        if (Trees[i] != nullptr) {
            int leftIndex = 2*i + 1;
            int rightIndex = 2*i + 2;
            
            if (leftIndex < Trees.size()) {
                Trees[i]->left = Trees[leftIndex];
            }
            if (rightIndex < Trees.size()) {
                Trees[i]->right = Trees[rightIndex];
            }
        }
    }
    return Trees[0];
}
int maxDepth(TreeNode* root) {
    //инициализирую счетчики максимальный, для левого, для правого
    int maxCount{0}, Countl{0}, Countr{0};
    //реализую алгоритм обхода в глубину
    if(root == nullptr){
        return 0;
    }
    //считаем для левого
    Countl = maxDepth(root->left);
    //сичтаем для правого
    Countr = maxDepth(root->right);
    //находим максимум
    maxCount = std::max(Countl,Countr);
    //возвращаем результат
    return maxCount + 1;    
}
void OutputR(int r){
    std::cout << "Максимальная глубина: " << r << '\n';
}
void deleteTree(TreeNode* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}
int main(){
    char c{};
    do{
        TreeNode* root = createTree();
        int r = maxDepth(root);
        OutputR(r);
        deleteTree(root);
        //go
        std::cout<<"Продолжить? (y/n)\n";
        std::cin >> c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(c == 'y' || c == 'Y');
    return 0;
}