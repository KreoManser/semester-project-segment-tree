# Segments tree

[![Build Status](../../actions/workflows/cmake.yml/badge.svg)](../../actions/workflows/cmake.yml)

_Краткое описание проекта:_

- _Дерево отрезков - это структура данных для реализации следующих операций: нахождение суммы элементов массива, нахождение минимума элементов отрезкв на заданном отрезке, во время самой операции можно также менять значение элементов на ходу._
- _Дерево отрезков представляет собой корневое дерево, листьями этого дерева являются элементы исходного массива, последующие вершины имеют по 2 ребенка. У каждой вершины в соответствие поставлен интервал, который является объединением интервалов ее детей (если у вершины есть дети), либо интервал, содержащий конкретный элемент массива (для листьев)_
- _Теоретическая сложность зависит от конкретной задачи и варьируется в диапазоне `O(log(n))`, так например, операция запроса суммы, операция запроса минимума, операция запроса обновления, операция изменения отрезка в q раз - `O(log(n))`_
- _В частности, дерево отрезков легко обобщается на большие размерности: например, для решения задачи о поиске суммы/минимума в некотором подпрямоугольнике данной матрицы (правда, уже только за время `O(log^2 (n))`)_

## Команда "USSR"

Группа: 11-109

| Фамилия Имя   | Вклад (%) | Прозвище              |
| :---          |   ---:    |  ---:                 |
| Сергей Бабич   | 20%        |  _хейтер с++_               |
| Сергей Лямкин   | 20%        |  _любитель с++_ |
| Булат Сабирзянов   | 20%        |  _тестировщик_ |
| Вадим Валеев   | 20%        |  _техник_ |
| Рафаэль Шамсутдинов   | 20%        |  _техник_юзер_ |

**Девиз команды**
> _Наши цели ясны. Задачи определены. За работу, товарищи!_

## Структура проекта

_Описание основных частей семестрового проекта._

**Пример**. Проект состоит из следующих частей:

- [`src`](src)/[`include`](include) - реализация структуры данных (исходный код и заголовочные файлы);
- [`benchmark`](benchmark) - контрольные тесты производительности структуры данных (операции добавления, удаления,
  поиска и пр.);
- [`examples`](examples) - примеры работы со структурой данных;
- [`dataset`](dataset) - наборы данных для запуска контрольных тестов и их генерация;

## Требования

_В этом разделе задаются основые требования к программному и аппаратному обеспечению для успешной работы с вашим проектом._

**Пример**. Рекомендуемые требования:

1. С++ компилятор c поддержкой стандарта C++17 (например, _GNU GCC 8.1.x_ и выше).
2. Система автоматизации сборки _CMake_ (версия _3.12.x_ и выше).
3. Интерпретатор _Python_ (версия _3.7.x_ и выше).
4. Рекомендуемый объем оперативной памяти - не менее 8 ГБ.
5. Свободное дисковое пространство объемом ~ 2 ГБ (для входного набора данных).

## Сборка и запуск

_Инструкция по сборке проекта, генерации тестовых данных, запуска контрольных тестов и примеров работы._

#### Сборка проекта

Склонируйте проект к себе на устройство через [Git for Windows](https://gitforwindows.org/) (либо используйте
возможности среды разработки):

```shell
git clone https://github.com/KreoManser/semester-project-segment-tree.git
```

Сборка и запуск проекта осуществляется через среду разработки.

#### Генерация тестовых данных

_Опишите формат хранения (JSON, XML, CSV, YAML и т.д.) и процесс генерации тестовых данных._

_Разрешается использовать собственный формат хранения данных._

Пример. Генерация тестового набора данных

Формат данных: [comma-seperated values (CSV)](https://en.wikipedia.org/wiki/Comma-separated_values).

Инструкции по генерации:
```shell
# переход в папку генерации набора данных
cd dataset

# запуск Python-скрипта
python generate_csv_bench_dataset.py --samples 1000 <output> [args ...]
```

- `--samples` - количество генерируемых элементов;
- `<output>` - выходной файл и т.д.

Тестовые данные представлены в CSV формате (см.
[`dataset/data/dataset-example.csv`](dataset/data/dataset-example.csv)):

```csv
id, full_name
0, "Ramil Safin"
1, "Bulat Abbyasov"
...
```

**Примечание**. Для удобства запуска контрольных тестов рекомендуется организовывать данные в директориях, например:

```shell
dataset/data/
  add/
    01/
      100.csv
      ...
      5000000.csv
    02/ ...
    03/ ...
    ...
    10/ ...
  search/
    01/
      100.csv
      ...
      5000000.csv
    ...
    10/ ...
  ...
```

По названию директории `/dataset/data/add` можно понять, что здесь хранятся наборы данных для контрольных тестов по
**добавлению** элементов в структуру данных. Названия файлов `100.csv`. `5000000.csv` и т.д. хранят информацию о размере набора данных (т.е. количество элементов). 

#### Контрольные тесты (benchmarks)

_Опишите, как запустить контрольные тесты, что они из себя представляют, какие метрики замеряют (время работы,
потребление памяти и пр.)._

Пример. Для запуска контрольных тестов необходимо предварительно сгенерировать или скачать готовый набор тестовых данных.

##### Список контрольных тестов

| Название                  | Описание                                | Метрики         |
| :---                      | ---                                     | :---            |
| `benchmark.cpp`        | Замеры врмени работы основных функций: создание дерева, запрос максимума/минимума, суммы. | _время_         |

##### Примеры запуска

```shell
./benchmark <input> <output> --trials 50
```

- `<input>` - входной файл с набором данных в формате CSV;
- `<output>` - выходной файл с результатами контрольного теста;
- `--trials` - количество прогонов на наборе данных и т.д.

Добавление 10000 случайных элементов в структуру данных (повторить операцию 50 раз и вычислить среднее время работы и
потребляемую память):

```
./add_benchmark.exe ../dataset/data/add/10000.csv metrics.txt --trials 50
``` 

где `<input> = ../dataset/data/add/10000.csv` и `<output> = metrics.txt`.

## Источники

_Список использованных при реализации структуры данных источников._
- _`https://habr.com/ru/company/otus/blog/485194/`_
- _`https://algorithmica.org/ru/segtree`_
- _`https://e-maxx.ru/algo/segment_tree`_
- _`https://en.wikipedia.org/wiki/Segment_tree`_
- _`https://ejudge.lksh.ru/archive/2015/08/B/lectures/segments-tree.ru.pdf`_
- _`https://proglib.io/p/algoritmy-i-struktury-dannyh-na-c-derevya-otrezkov-2019-10-11`_

_**Это не плагиат, это уважение чужого труда и помощь своим сокурсникам более подробно разобраться в теме.**_
