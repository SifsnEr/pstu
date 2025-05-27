// Очередь
// Записи в линейном списке содержат ключевое поле типа int
// Удалить из него элемент с заданным номером
// добавить элемент с заданным номером

#include <iostream>

struct Node {
    int  data;
    Node* next;
};

struct Queue {
    Node* front;
    Node* back; 
};

void init(Queue& q)              { q.front = q.back = nullptr; }
bool isEmpty(const Queue& q)     { return q.front == nullptr; }

void enqueue(Queue& q, int value) {
    Node* n = new Node{value, nullptr};
    if (q.back) {
        q.back->next = n;
        q.back = n;
    } else {
        q.front = q.back = n;
    }
}

int dequeue(Queue& q) {
    if (isEmpty(q)) throw std::runtime_error("dequeue from empty queue");
    Node* n = q.front;
    int v   = n->data;
    q.front = n->next;
    if (!q.front) q.back = nullptr;
    delete n;
    return v;
}

void insertAt(Queue& q, int index, int value) {
    if (index <= 0 || isEmpty(q)) {
        Node* n = new Node{value, q.front};
        q.front = n;
        if (!q.back) q.back = n;
        return;
    }
    Node* cur = q.front;
    while (cur->next && --index) cur = cur->next;
    Node* n = new Node{value, cur->next};
    cur->next = n;
    if (cur == q.back) q.back = n;
}

void removeAt(Queue& q, int index) {
    if (isEmpty(q) || index < 0) return;
    if (index == 0) {
        dequeue(q);
        return;
    }
    Node* cur = q.front;
    while (cur->next && --index) cur = cur->next;
    if (!cur->next) return;
    Node* tmp = cur->next;
    cur->next = tmp->next;
    if (tmp == q.back) q.back = cur;
    delete tmp;
}

void print(const Queue& q, const char* prefix = "") {
    std::cout << prefix;
    for (Node* n = q.front; n; n = n->next) {
        std::cout << n->data;
        if (n->next) std::cout << " ";
    }
    std::cout << "\n";
}

void clear(Queue& q) {
    while (!isEmpty(q)) dequeue(q);
}

int main() {
    Queue q; init(q);

    int n, t, tv;
    std::cout << "Сколько элементов в очереди?: ";
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cout << "Элемент номер " << i << " = ";
        std::cin >> t;
        enqueue(q, t);
    }
    print(q, "Очередь: ");
    std::cout << "Индекс элемента для удаления(от 0): ";
    std::cin >> t;
    removeAt(q, t);
    std::cout << "Индекс элемента для добавления(от 0): ";
    std::cin >> t;
    std::cout << "Значение элемента для добавления: ";
    std::cin >> tv;
    insertAt(q, t, tv);
    print(q, "Очередь: ");
    return 0;
}
