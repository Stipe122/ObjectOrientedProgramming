#include "Point.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>

void processWordsFile(const std::string& filename, const std::string& targetWord, const std::string& substringToRemove) {
    // 1. Napuni vektor stringova riječima iz datoteke koristeći istream iterator.
    std::ifstream inputFile(filename);
    std::istream_iterator<std::string> inputIterator(inputFile);
    std::istream_iterator<std::string> endIterator;

    //std::vector<std::string> words(inputIterator, endIterator);

    // 2. Nađe sva pojavljivanja određene riječi i njihovu poziciju u vektoru koristeći find.
    //std::vector<size_t> positions;
    //for (size_t i = 0; i < words.size(); ++i) {
    //    if (words[i] == targetWord) {
    //        positions.push_back(i);
    //    }
    //}

    //// 3. Izbaci sve stringove koji sadrže određeni podstring koristeći remove_if i erase.
    //words.erase(std::remove_if(words.begin(), words.end(), [&](const std::string& s) {
    //    return s.find(substringToRemove) != std::string::npos;
    //    }), words.end());

    //// 4. Koristi transform, promijeni sva slova u stringovima u velika slova.
    //std::transform(words.begin(), words.end(), words.begin(), [](std::string& s) {
    //    std::transform(s.begin(), s.end(), s.begin(), ::toupper);
    //    return s;
    //    });

    // 5. Ispiši stringove iz vektora koristeći copy.
    std::ostream_iterator<std::string> outputIterator(std::cout, "\n");
    //std::copy(words.begin(), words.end(), outputIterator);
}






double distanceFromOrigin(const Point& p) {
    return std::sqrt(p.x * p.x + p.y * p.y);
}

void processPointsFile(const std::string& filename, double circleRadius) {
    // 1. Napuni vektor točaka koristeći istream iterator.
    std::ifstream inputFile(filename);
    std::istream_iterator<const Point&> inputIterator(inputFile);
    std::istream_iterator<const Point&> endIterator;

    std::vector<Point> points(inputIterator, endIterator);

    // 2. Sortira točke prema udaljenosti od ishodišta koristeći sort.
    std::sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        return distanceFromOrigin(a) < distanceFromOrigin(b);
        });

    // 3. Prebroji koliko točaka leži unutar određenog kruga s centrom u ishodištu koristeći count_if.
    size_t pointsInsideCircle = std::count_if(points.begin(), points.end(), [&](const Point& p) {
        return distanceFromOrigin(p) < circleRadius;
        });

    // 4. Zamijeni sve točke koje su točno na određenoj udaljenosti od ishodišta s novom točkom koristeći replace_if.
    double targetDistance = 5.0;  
    std::replace_if(points.begin(), points.end(), [&](const Point& p) {
        return std::abs(distanceFromOrigin(p) - targetDistance) < 1e-6;
        }, Point{ 10.0, 10.0 }); 

    // 5. Ispiši točke iz vektora u obrnutom redoslijedu koristeći reverse i copy.
    std::reverse(points.begin(), points.end());
    std::ostream_iterator<const Point> outputIterator(std::cout, "\n");
    //std::copy(points.begin(), points.end(), outputIterator);

    // Ispis broja točaka unutar kruga
    std::cout << "Broj točaka unutar kruga: " << pointsInsideCircle << std::endl;
}
