# Парсер данных
Код для консольного приложения, принимающего в командной строке название входного файла и название выходного файла.
Входные данные подаются в иерархической структуре с синтаксисом:
имя_узла - строка из букв, цифр, и символа '_', начинающаяся не с цифры 
значение_узла - произвольная строка в двойных кавычках, не содержащая символов перевода строки и двойных кавычек 
узел ::= имя_узла '=' (значение_узла | список ) 
список ::= '{' узел [узел ... ] '}'

По итогам парсинга получаем Document, представляющий древовидное представление данных, где в узлах (Node) хранится id узла, id вышестоящего узла, имя узла и значение узла.
Парсинг убирает лишние пробелы и символы переноса строки для выходных данных.

Для вывода данных в файл используем метод Print объекта Document.
Метод иерархически выводит id узла, id вышестоящего узла, имя узла и его значение.
Для узлов-списков в кач-ве значения выводятся id его потомков.
Для иерархического представления выводятся отступы - по +2 для каждого уровня в глубину.

# Использование
Парсинг данных заданного типа из файла
- использовать файл с валидными входными данными
- сохранить в папку проекта или в консоли передавать директорию
- указать файл выгрузки данных
Использование document.h, loader.h, outer.h как базы для настройки собственного парсера.

# Системные требования
C++ 20 (STL) GCC (MinGW-w64) 11.2.0

# Стек технологий
Visual Studio 22

# Возможные дополнения
- настроить доступ к определенным узлам дерева и их печать
- добавление узлов с преобразованием id
- печать определенной глубины дерева

