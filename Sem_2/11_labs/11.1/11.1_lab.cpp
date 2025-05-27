// Однонаправленный список
// Записи в линейном списке содержат ключевое поле типа int
// Удалить из него элемент с заданным номером
// добавить элемент с заданным номером

#include <iostream>

struct Node {
    int  data;
    Node* next;
    explicit Node(int d) : data(d), next(nullptr) {}
};

class LinkedList {
    Node* head = nullptr;

public:
    ~LinkedList() {
        while (head) {
            Node* tmp = head;
            head      = head->next;
            delete tmp;
        }
    }


    void push_back(int value) {
        if (!head) {
            head = new Node(value);
            return;
        }
        Node* p = head;
        while (p->next) p = p->next;
        p->next = new Node(value);
    }

    // Вставка элемента по номеру
    void insertAt(int index, int value) {
        if (index <= 0 || !head) {
            Node* n = new Node(value);
            n->next = head;
            head    = n;
            return;
        }
        Node* p = head;
        while (p->next && --index) p = p->next;
        Node* n = new Node(value);
        n->next = p->next;
        p->next = n;
    }

    // Удаление элемента по номеру
    void removeAt(int index) {
        if (!head || index < 0) return;
        if (index == 0) {
            Node* tmp = head;
            head      = head->next;
            delete tmp;
            return;
        }
        Node* p = head;
        while (p->next && --index) p = p->next;
        if (p->next) {
            Node* tmp = p->next;
            p->next   = tmp->next;
            delete tmp;
        }
    }

    void print(const char* prefix = "") const {
        std::cout << prefix;
        for (Node* p = head; p; p = p->next) {
            std::cout << p->data;
            if (p->next) std::cout << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    LinkedList lst;
    int n, t, tv;
    std::cout << "Сколько элементов в списке?: ";
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cout << "Элемент номер " << i << " = ";
        std::cin >> t;
        lst.push_back(t);
    }
    lst.print("Список: ");
    std::cout << "Индекс элемента для удаления(от 0): ";
    std::cin >> t;
    lst.removeAt(t);
    std::cout << "Индекс элемента для добавления(от 0): ";
    std::cin >> t;
    std::cout << "Значение элемента для добавления: ";
    std::cin >> tv;
    lst.insertAt(t, tv);
    lst.print("Список: ");
    return 0;
}
