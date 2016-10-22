# lab1
Лабораторная работа №1. Управление процессами в ОС GNU/Linux

Цель работы:
Изучение особенностей программной реализации многозадачных приложений в ОС GNU/Linux.

Ход работы:

    Ознакомиться с краткими теоретическими сведениями по управлению процессами в ОС GNU/Linux.
    Получить у преподавателя индивидуальный вариант задания, который предусматривает разработку программы, являющеся дочерним процессом, которая запускается родительским процессом (вторая разрабатываемая программа) с обязательным использованием концепции fork-and-exec.
    Используя изученные механизмы, разработать и отладить программный код для родительского и дочернего процессов.
    Произвести разработку юнит-тестов основных функциональных блоков код дочернего процесса. Рекомендуется использование фреймворка CUnit, но студент по согласованию с преподавателем вправе воспользоваться альтернативными решениями (в качестве такового не будет рассматриваться исключительное использование стандартного макроса assert).
    Написать отчет и представить его к защите с исходными текстами программы. Исходные тексты программ должны содержать комментарии в стиле системы doxygen и включать юнит-тесты основных функционпльных блоков программного кода.

Ход защиты:

    Продемонстрировать преподавателю программы, решающие поставленную задачу.
    Пояснить исходный код программ, по требованию преподавателя (при необходимости) внося в него изменения. 

Содержание отчета:

    Титульный лист.
    Цель работы с постановкой задачи.
    Исходные тексты программ (с комментариями в стиле системы doxygen).
    Тестовые примеры работы программ (не менее трех).
    
Общая постановка задачи.
Требуется: разработать программу в виде Linux-приложения, которая
представляет собой родительский процесс. Результат выполнения выводится на
терминал/консоль. Программа должна быть устойчива к некорректному
пользовательскому вводу. В следующих вариантах заданий оговаривается
только функционал программы, представляющей собой дочерний процесс.

Вариант 15. Программа принимает от пользователя три строки, (первая и
третья строки – это правильные рациональные или десятичные дроби вида
«1/3» или «0,5», вторая строка – это знак арифметической операции вида «+»,
«-», «*», «/» либо операции сравнения «<», «>», «=», «!=», «>=», «<=»),
выполняет требуемую операцию над полученными операндами, и выводит
результат на экран. Обеспечить также сокращение дроби при необходимости.
Если оба операнда арифметической операции являются рациональными
дробями, результатом тоже должна быть рациональная дробь. Для операций
сравнения достаточно результата «Истина» или «Ложь».
