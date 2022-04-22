#pragma once

// Заголовочный файл с объявлением структуры данных

namespace itis {

  // Tip 1: объявите здесь необходимые структуры, функции, константы и прочее

  // Пример: объявление константы времени компиляции в заголовочном файле
  inline constexpr auto kStringConstant = "Hello, stranger!";

  // Пример: объявление структуры с полями и методами
  struct SegmentTree {
   private:
    int size_ {0};
    int *array_ {nullptr};
    int *tree_ {nullptr};
    int *modification_ {nullptr};

    void build_tree_(int vert, int lp, int rp);

    void push_back_(int vert);

    // Tip 2: На начальном этапе разработки структуры данных можете определения методов задавать в
    // заголовочном файле, как только работа будет завершена, можно будет оставить здесь только объявления.

   public:
    SegmentTree(int size, int *array);

    ~SegmentTree();

    int get_sum(int vertex, int tl, int tr, int lp, int rp);

    int get_min(int l, int r, int vertex, int lp, int rp);

    int get_max(int l, int r, int vertex, int lp, int rp);

    void update(int vertex, int lp, int rp, int idx, int value);

    void assign(int l, int r, int value, int vertex, int lp, int rp);

    int size() const;

  };

}  // namespace itis