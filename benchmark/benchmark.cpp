
#include <fstream>
#include <iostream>
#include <string>
#include <string_view>
#include <chrono>
#include "segment_tree.hpp"


using namespace std;
using namespace itis;


static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};
static constexpr auto kProjectPath = string_view{PROJECT_SOURCE_DIR};

long long int *check_sum(string path, int count){
  long long int *time_list = new long long int [10];
  for (int i = 0; i < 10; i++) {
    string line = "1";
    auto input_file = ifstream(path);
    int tmp = 0;
    int *array = new int[count];
    if (input_file) {
      getline(input_file, line);
      while (line != "") {
        array[tmp] = stoi(line);
        getline(input_file, line);
        if (line == "") {
          break;
        }
      }
    }
    SegmentTree sTree = SegmentTree(count, array);

    const auto time_point_before = chrono::steady_clock::now();
    sTree.get_sum(1, 0, sTree.size() - 1, 0, sTree.size() - 1);
    const auto time_point_after = chrono::steady_clock::now();

    input_file.close();
    const auto time_diff = time_point_after - time_point_before;
    const long long time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();
    time_list[i] = time_elapsed_ns/1000000;
  }
  return time_list;
}


long long int *check_max(string path, int count){
  long long int *time_list = new long long int [10];
  for (int i = 0; i < 10; i++) {
    string line = "1";
    auto input_file = ifstream(path);
    int tmp = 0;
    int *array = new int[count];
    if (input_file) {
      getline(input_file, line);
      while (line != "") {
        array[tmp] = stoi(line);
        getline(input_file, line);
        if (line == "") {
          break;
        }}}
    SegmentTree sTree = SegmentTree(count, array);
    const auto time_point_before = chrono::steady_clock::now();
    sTree.get_max(1, 0, sTree.size() - 1, 0, sTree.size() - 1);
    const auto time_point_after = chrono::steady_clock::now();
    input_file.close();
    const auto time_diff = time_point_after - time_point_before;
    const long long time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();
    time_list[i] = time_elapsed_ns;
  }
  return time_list;
}


long long int *check_min(string path, int count){
  long long int *time_list = new long long int [10];
  for (int i = 0; i < 10; i++) {
    string line = "1";
    auto input_file = ifstream(path);
    int tmp = 0;
    int *array = new int[count];
    if (input_file) {
      getline(input_file, line);
      while (line != "") {
        array[tmp] = stoi(line);
        getline(input_file, line);
        if (line == "") {
          break;
        }}}
    SegmentTree sTree = SegmentTree(count, array);
    const auto time_point_before = chrono::steady_clock::now();
    sTree.get_min(1, 0, sTree.size() - 1, 0, sTree.size() - 1);
    const auto time_point_after = chrono::steady_clock::now();
    input_file.close();
    const auto time_diff = time_point_after - time_point_before;
    const long long time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();
    time_list[i] = time_elapsed_ns;
  }
  return time_list;
}


long long int *check_create_tree(string path, int count){
  long long int *time_list = new long long int [10];
  for (int i = 0; i < 10; i++) {
    string line = "1";
    auto input_file = ifstream(path);
    int tmp = 0;
    int *array = new int[count];
    if (input_file) {
      getline(input_file, line);
      while (line != "") {
        array[tmp] = stoi(line);
        getline(input_file, line);
        if (line == "") {
          break;
        }}}
    const auto time_point_before = chrono::steady_clock::now();
    SegmentTree sTree = SegmentTree(count, array);
    const auto time_point_after = chrono::steady_clock::now();
    input_file.close();
    const auto time_diff = time_point_after - time_point_before;
    const long long time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();
    time_list[i] = time_elapsed_ns;
  }
  return time_list;
}


int main() {

  const auto path_inputfile = string(kProjectPath) + "/dataset/data/dataset-example.csv";
  const auto py_path = "python " + string(kProjectPath) + "/dataset/test_data.py";
  const string delimeter = "/";
  cout << "Run data_creator.py" << endl;
  system(py_path.c_str());
  cout << endl << endl;
  cout << "Path to the 'dataset/' folder: " << string(kDatasetPath) << endl;
  cout << "Path to file: " << path_inputfile << endl;
  ofstream file;
  file.open(path_inputfile);
  if (file.is_open()){
    cout << "ok" << endl;
    file << "Function"
         << delimeter << "Set"
         << delimeter << "Set size"
         << delimeter << "Run number"
         << delimeter << "Time" <<  endl;
  }

  int *amount = new int [10] {100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000, 5000000};
  string folders[10] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10"};

  for (int j = 0; j < 10; j++) {
    int count = amount[j];
    for (string file_name : folders) {
      auto data_path = string(kDatasetPath) + "/database/insert/Random_" + file_name + ".csv";
      long long int *time_list = check_create_tree(data_path, count);
      for (int i = 0; i < 10; i++){
        file <<"CreateTree" << delimeter << file_name + delimeter + to_string(count)
                                                 + delimeter
                                                 + to_string(i + 1) + delimeter << to_string(time_list[i]) << endl;
      }
    }
  }

  for (int j = 0; j < 10; j++) {
    int count = amount[j];
    for (string file_name : folders) {
      auto data_path = string(kDatasetPath) + "/database/insert/Random_" + file_name + ".csv";
      long long int *time_list = check_max(data_path, count);
      for (int i = 0; i < 10; i++){
        file <<"Max" << delimeter << file_name + delimeter + to_string(count)
                                          + delimeter
                                          + to_string(i + 1) + delimeter << to_string(time_list[i]) << endl;
      }
    }
  }

  for (int j = 0; j < 10; j++) {
    int count = amount[j];
    for (string file_name : folders) {
      auto data_path = string(kDatasetPath) + "/database/insert/Random_" + file_name + ".csv";
      long long int *time_list = check_sum(data_path, count);
      for (int i = 0; i < 10; i++){
        file <<"Sum" << delimeter << file_name + delimeter + to_string(count)
                                          + delimeter
                                          + to_string(i + 1) + delimeter << to_string(time_list[i]) << endl;
      }
    }
  }

  for (int j = 0; j < 10; j++) {
    int count = amount[j];
    for (string file_name : folders) {
      auto data_path = string(kDatasetPath) + "/database/insert/Random_" + file_name + ".csv";
      long long int *time_list = check_min(data_path, count);
      for (int i = 0; i < 10; i++){
        file <<"Min" << delimeter << file_name + delimeter + to_string(count)
                                          + delimeter
                                          + to_string(i + 1) + delimeter << to_string(time_list[i]) << endl;
      }
    }
  }


  return 0;
}