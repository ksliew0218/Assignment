#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include "NutrientClass.h"  // Assuming this is your class header

using namespace std;

int main() {
    NutrientClass nutrientClass;
    
    ifstream nutrientCSVFile("Nutrients_Info.csv");
    if (!nutrientCSVFile.is_open()) {
        cout << "Failed to open file." << endl;
        return 1;
    }


    string header;
    getline(nutrientCSVFile, header);

    string food, measure, category;
    string grams, protein, fat, sat_fat, carbs, fibre;

    while (getline(nutrientCSVFile, food, ',')) {
        getline(nutrientCSVFile, measure, ',');
        getline(nutrientCSVFile, grams, ',');
        getline(nutrientCSVFile, protein, ',');
        getline(nutrientCSVFile, fat, ',');
        getline(nutrientCSVFile, sat_fat, ',');
        getline(nutrientCSVFile, fibre, ',');
        getline(nutrientCSVFile, carbs, ',');
        getline(nutrientCSVFile, category);

        // Add error checking for stoi and stod
        nutrientClass.InserttoFront(food, measure, stoi(grams), stoi(protein), stoi(fat), stoi(sat_fat), stod(fibre), stod(carbs), category);
    }
    
    nutrientClass.DisplayLinkedList();

    return 0;
}
