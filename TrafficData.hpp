#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>

std::map<std::string, int> loadTrafficData(const std::string& filename) {
  std::map<std::string,int> return_map;

  std::ifstream file("filename");

  if(!file.is_open()){
    std::cout << -1;
    return return_map;
  }

  std::string line_string;
  std::string name;
  std::string number;
  while ( getline(file, line_string, '\n')){
    std::stringstream streamed_string(line_string);

    getline(streamed_string, name, ',');
    getline(streamed_string, number, '\n');

    return_map[name] = stoi(number);
  
  }

  return return_map;


}

void updateTrafficData(const std::string& filename, std::map<std::string, int>& dataMap) {
  std::map<std::string, int> file_map = loadTrafficData(filename);

  for(auto it = file_map.begin(); it != file_map.end(); it++){
    dataMap[it->first] = it->second;
  }

}