## Master DB.

СУБД спроектирована таким образом, чтобы выделить в виде отдельного общего файла 
src/shared.c универсальные функции по работе с таблицей БД с реализацией стандартных операций 
(SELECT, INSERT, UPDATE и DELETE), разместить в отдельные файлы src/[db_name].c конкретные 
реализации по обработке 3-х таблиц рассматриваемой БД, и вынести в общий файл агрегационные 
запросы ко всем таблицам. 

Точку входа и меню управления СУБД размещена в файле в src/modules_db.c. \

Для отладки добавлена возможность просмотра содержимого всех таблиц, добавления и удаления значений. 

Создан файл src/shared.c, в котором реализованы общие операции над таблицами БД (SELECT, INSERT, UPDATE и DELETE) и все необходимые агрегационные запросы (получить все включенные модули, получить все модули на первом уровне памяти и т.д.). \

Создан для каждой таблицы БД файл src/[db_name].c с конкретными реализациями функций по обработке отдельной таблицы рассматриваемой БД. \

Создана программу src/modules_db.c, в которой размещена точка входа и меню управления (считывание базы, вывод и т.д.). \

Добавлена цель build_db в Makefile для сборки приложения. Makefile располагается в директории src. \