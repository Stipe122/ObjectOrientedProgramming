#include "Point.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>




int main() {
    //1
    std::string filename = "words.txt";
    std::string targetWord = "kamion";
    std::string substringToRemove = "auto";

    processWordsFile(filename, targetWord, substringToRemove);

    //2
  /*  std::string filename = "points.txt";
    double circleRadius = 8.0;

    processPointsFile(filename, circleRadius);*/

    return 0;
}

























