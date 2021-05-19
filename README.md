	Пирамида(куча).
В качестве первого аргумента шаблонный класс принимает тип хранимых элементов, в качестве второго - 
ссылку на логическую функцию сравнения двух элементов заданного типа. Пирамида позваляет оптимизировать
те алгоритмы, где неоднократно необходимо искать минимум или максимум в изменяющейся последовательности данных.
Постройка пирамиды требует O(N * log N): для N элементов проводим вставку.

add
  Реализация вставки нового элемента с сохранением сбалансированности за O(log N):
    Добавить элемент в конец списка.
    1. Найти базовую вершину (indexRoot = (indexCurrent - 1) / 2)
    2. Сравниваем значение базовой вершины, если новое значение не лучше имеющегося, балансировка завершена,
       если значение лучше - меняем значение базовой и производной вершины.
    3. Повторяем, пока не дойдём до корня или пока дерево не сбалансируется.
  Такой алгоритм позваляет в худшем случае совершить кол-во операций равное высоте дерева (log N с огруглением
  вверх) от сюда и O(log N)

eraseTop
  реализация удаления корня с сохранением сбалансированности за O(log N):
    удаляем корень, и на его место ставим последнюю вершину.
    1. Из трёх вершин (базовой и двух производных) выбираем наиболее подходящую.
    2. Если лучший вариант - базовая вершина, то балансировка завершается, если нет, 
       продолжаем балансировать дерево.
  Если мы будем выбирать из трёх вариантов сможем добиться дихотомии и логарифмической сложности.
