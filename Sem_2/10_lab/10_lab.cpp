#include <iostream>
using namespace std;

int main() {
    int size, del, nl, add;
    
    cout << "Введите размер массива: ";
    cin >> size;
    
    int* arr = new int[size];
    
    cout << "Введите элементы массива:\n";
    for (int i = 0; i < size; i++) 
    {
        cin >> arr[i];
    }
    
    cout << "Исходный массив: ";
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    cout << "Введите номер элемента для удаления: ";
    cin >> del;
    del--;
    
    int* tmp = new int[size - 1];
    
    for (int i = 0; i < del; i++) 
    {
        tmp[i] = arr[i];
    }
    
    for (int i = del + 1; i < size; i++) 
    {
        tmp[i - 1] = arr[i];
    }
    
    delete[] arr;
    arr = tmp;
    size--;
    
    cout << "Массив после удаления: ";
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    cout << "Введите новый элемент для добавления: ";
    cin >> nl;
    
    cout << "Введите позицию для добавления: ";
    cin >> add;
    add--;
     
    tmp = new int[size + 1];
    
    for (int i = 0; i < add; i++) 
    {
        tmp[i] = arr[i];
    }
    
    tmp[add] = nl;
    
    for (int i = add; i < size; i++) 
    {
        tmp[i + 1] = arr[i];
    }
    
    delete[] arr;
    arr = tmp;
    size++;
    
    cout << "Итоговый массив: ";
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    delete[] arr;  
    return 0;
}