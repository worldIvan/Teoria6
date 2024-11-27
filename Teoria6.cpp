#include <iostream>
#include <string>

// Клас, що представляє вузол бінарного дерева
class TreeNode {
public:
    std::string data;   // Дані (рядок) у вузлі
    TreeNode* left;     // Вказівник на лівого та правого нащадка
    TreeNode* right;   

    // Конструктор для створення вузла з вказаними даними
    TreeNode(const std::string& value) : data(value), left(nullptr), right(nullptr) {}
};

// Клас для реалізації бінарного дерева
class BinaryTree {
private:
    TreeNode* root;     // Корінь дерева

    // Рекурсивна функція для підрахунку кількості символів у рядках дерева
    int countCharacters(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        // Сума довжини рядка у поточному вузлі та рекурсивних викликів для лівого та правого нащадків
        return node->data.length() + countCharacters(node->left) + countCharacters(node->right);
    }

public:
    // Конструктор для ініціалізації кореня як nullptr
    BinaryTree() : root(nullptr) {}

    // Метод для вставки нового рядка у дерево
    void insert(const std::string& value) {
        root = insertRecursive(root, value);
    }

    // Метод для отримання загальної кількості символів у рядках дерева
    int getCountCharacters() {
        return countCharacters(root);
    }

private:
    // Рекурсивна функція для вставки нового рядка у дерево
    TreeNode* insertRecursive(TreeNode* node, const std::string& value) {
        if (node == nullptr) {
            // Створення нового вузла з вказаними даними, якщо поточний вузол є nullptr
            return new TreeNode(value);
        }

        // Порівняння рядків для визначення напрямку вставки
        if (value < node->data) {
            node->left = insertRecursive(node->left, value);    // Вставка у лівого нащадка
        }
        else {
            node->right = insertRecursive(node->right, value);  // Вставка у правого нащадка
        }

        return node;
    }
};

int main() {
    BinaryTree tree;  // Створення об'єкту бінарного дерева
    // Вставка рядків у дерево
    tree.insert("hello");
    tree.insert("world");
    tree.insert("Ivan");
    tree.insert("halooo");
    tree.insert("halooo");
    tree.insert("Ivan");

    int characterCount = tree.getCountCharacters();  // Отримання кількості символів у рядках дерева

    // Виведення результату
    std::cout << "Total number of characters in the tree: " << characterCount << std::endl;

    return 0;
}
