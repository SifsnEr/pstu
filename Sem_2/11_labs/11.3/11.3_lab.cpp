// Стек
// Записи в линейном списке содержат ключевое поле типа int
// Удалить из него элемент с заданным номером
// добавить элемент с заданным номером

#include <iostream>

struct Node {
    int  data;
    Node* next;
};

struct Stack {
    Node* top;
};

void init(Stack& s)              { s.top = nullptr; }
bool isEmpty(const Stack& s)     { return s.top == nullptr; }

void push(Stack& s, int value) {
    Node* n = new Node{value, s.top};
    s.top   = n;
}

int pop(Stack& s) {
    if (isEmpty(s)) throw std::runtime_error("pop from empty stack");
    Node* n = s.top;
    int v   = n->data;
    s.top   = n->next;
    delete n;
    return v;
}

void insertAt(Stack& s, int index, int value) {
    if (index <= 0 || isEmpty(s)) {
        push(s, value);
        return;
    }
    Node* cur = s.top;
    while (cur->next && --index) cur = cur->next;
    Node* n   = new Node{value, cur->next};
    cur->next = n;
}

void removeAt(Stack& s, int index) {
    if (isEmpty(s) || index < 0) return;
    if (index == 0) {
        pop(s);
        return;
    }
    Node* cur = s.top;
    while (cur->next && --index) cur = cur->next;
    if (!cur->next) return;
    Node* tmp = cur->next;
    cur->next = tmp->next;
    delete tmp;
}

void print(const Stack& s, const char* prefix = "") {
    std::cout << prefix;
    for (Node* n = s.top; n; n = n->next) {
        std::cout << n->data;
        if (n->next) std::cout << " ";
    }
    std::cout << "\n";
}

void clear(Stack& s) {
    while (!isEmpty(s)) pop(s);
}

int main() {
    Stack st; init(st);
    int n, t, tv;
    std::cout << "Сколько элементов в стеке?: ";
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cout << "Элемент номер " << i << " = ";
        std::cin >> t;
        push(st, t);
    }
    print(st, "Стек: ");
    std::cout << "Индекс элемента для удаления(от 0): ";
    std::cin >> t;
    removeAt(st, t);
    std::cout << "Индекс элемента для добавления(от 0): ";
    std::cin >> t;
    std::cout << "Значение элемента для добавления: ";
    std::cin >> tv;
    insertAt(st, t, tv);
    print(st, "Стек: ");
    return 0;
}
