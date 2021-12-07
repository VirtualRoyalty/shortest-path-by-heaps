#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

void write_csv(
    std::string filename,
    std::vector<std::pair<std::string, std::vector<std::string>>> dataset) {

  // Create an output filestream object
  std::ofstream myFile(filename);

  // Send column names to the stream
  for (int j = 0; j < dataset.size(); ++j) {
    myFile << dataset.at(j).first;
    if (j != dataset.size() - 1)
      myFile << ","; // No comma at end of line
  }
  myFile << "\n";

  // Send data to the stream
  for (int i = 0; i < dataset.at(0).second.size(); ++i) {
    for (int j = 0; j < dataset.size(); ++j) {
      myFile << dataset.at(j).second.at(i);
      if (j != dataset.size() - 1)
        myFile << ","; // No comma at end of line
    }
    myFile << "\n";
  }

  // Close the file
  myFile.close();
}

std::vector<std::vector<std::string>>
read_csv(std::string filename) {

  std::vector<std::vector<std::string>> result;

  std::ifstream myFile(filename);

  if (!myFile.is_open())
    throw std::runtime_error("Could not open file");

  // Helper vars
  std::vector<std::string> edge;
  std::string line, colname;
  std::string val;
  if (myFile.good()){
    // Read data, line by line
    while (std::getline(myFile, line)) {
      // Create a stringstream of the current line
      std::stringstream ss(line);
      while (ss >> val) {
        // Add the current integer to the 'colIdx' column's values vector
        edge.push_back(val);
        // If the next token is a comma, ignore it and move on
        if (ss.peek() == ' ')
          ss.ignore();
      }
      result.push_back(edge);
      edge.clear();
    }
  }

  // Close file
  myFile.close();

  return result;
};


std::vector<std::vector<std::pair<int, float>>>
construct_graph_from_csv(std::string filename) {

  std::vector<std::vector<std::pair<int, float>>> result;

  std::ifstream myFile(filename);

  if (!myFile.is_open())
    throw std::runtime_error("Could not open file");

  std::vector<std::pair<int, float>> edgelist;
  std::string line, colname;
  int node;
  float weight;
  if (myFile.good()){
    while (std::getline(myFile, line)) {
      std::stringstream ss(line);
      while (ss >> node && ss >> weight) {
        edgelist.push_back(std::make_pair(node, weight));
        if (ss.peek() == ' ')
          ss.ignore();
      }
      result.push_back(edgelist);
      edgelist.clear();
    }
  }

  myFile.close();

  return result;
};


// std::vector<std::vector<std::pair<int, float>>>
// construct_graph(std::string filename) {
//
//   std::vector<std::vector<std::string>> result;
//
//   std::ifstream myFile(filename);
//
//   if (!myFile.is_open())
//     throw std::runtime_error("Could not open file");
//
//   // Helper vars
//   std::vector<std::string> edge;
//   std::string line, colname;
//   std::string val;
//   if (myFile.good()){
//     // Read data, line by line
//     while (std::getline(myFile, line)) {
//       // Create a stringstream of the current line
//       std::stringstream ss(line);
//       while (ss >> val) {
//         // Add the current integer to the 'colIdx' column's values vector
//         edge.push_back(val);
//         // If the next token is a comma, ignore it and move on
//         if (ss.peek() == ' ')
//           ss.ignore();
//       }
//       result.push_back(edge);
//       edge.clear();
//     }
//   }
//
//   // Close file
//   myFile.close();
//
//   return result;
// };
