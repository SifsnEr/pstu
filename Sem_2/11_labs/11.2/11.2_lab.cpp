// Двунапраленный список
// Записи в линейном списке содержат ключевое поле типа int
// Удалить из него элемент с заданным номером
// добавить элемент с заданным номером

#include <iostream>

struct Node {
    int   data;
    Node* prev;
    Node* next;
    explicit Node(int d) : data(d), prev(nullptr), next(nullptr) {}
};

class DLinkedList {
    Node* head = nullptr;
    Node* tail = nullptr;

public:
    ~DLinkedList() {
        while (head) {
            Node* tmp = head;
            head      = head->next;
            delete tmp;
        }
    }

    void push_back(int value) {
        Node* n = new Node(value);
        if (!tail) {
            head = tail = n;
        } else {
            tail->next = n;
            n->prev    = tail;
            tail       = n;
        }
    }

    // Вставка
    void insertAt(int index, int value) {
        if (index <= 0 || !head) {
            // вставка в начало
            Node* n = new Node(value);
            n->next = head;
            if (head) head->prev = n; else tail = n;
            head = n;
            return;
        }
        Node* cur = head;
        while (cur->next && index--) cur = cur->next;
        if (index > 0) { // дошли до конца
            push_back(value);
        } else {
            Node* n = new Node(value);
            n->prev = cur->prev;
            n->next = cur;
            cur->prev->next = n;
            cur->prev = n;
        }
    }

    // Удаление
    void removeAt(int index) {
        if (!head || index < 0) return;
        Node* cur = head;
        while (cur && index--) cur = cur->next;
        if (!cur) return;

        if (cur->prev) cur->prev->next = cur->next; else head = cur->next;
        if (cur->next) cur->next->prev = cur->prev; else tail = cur->prev;
        delete cur;
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
    DLinkedList lst;
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
