# Вопрос 1
a)
```cpp
double& max(const double& a, const double& b);
```

b)
```cpp
void swap(int& a, int& b);
```

c)
```cpp
template <typename T>
T& getLargestElement(T* arr, int length);
```

# Вопрос 2

a) Возвращает ссылку на локальную переменную, которая будет уничтожена.

b) Рекурсия, программа работает бесконечно.

c) Конфликт прототипов функций: компилятор не будет знать какую вызывать.

d) Слишком большой массив для стека.

e) Аргумент может не существовать.

# Вопрос 3

[код](/tasks/11/src/main.cpp)