#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include "NutrientClass.h"

using namespace std;

// Function to remove all quotes and commas from a string
string cleanField(const string& field) {
    string result;
    for (char c : field) {
        if (c != ',' && c != '"') result += c;
    }
    return result;
}

int main() {
    NutrientClass nutrientClass;

    ifstream nutrientCSVFile("Nutrients_Info.csv");
    if (!nutrientCSVFile.is_open()) {
        cout << "Failed to open file." << endl;
        return 1;
    }

    string line, header;
    getline(nutrientCSVFile, header); // Skip the header line

    while (getline(nutrientCSVFile, line)) {
        stringstream ss(line);
        string field;
        string food, measure, category;
        string grams, calories, protein, fat, sat_fat, fibre, carbs;

        // Process each field in the line
        for (int fieldCount = 0; getline(ss, field, ','); ++fieldCount) {
            switch (fieldCount) {
                case 0: food = field; break;
                case 1: measure = field; break;
                case 2: grams = cleanField(field); break;
                case 3: calories = cleanField(field); break;
                case 4: protein = cleanField(field); break;
                case 5: fat = cleanField(field); break;
                case 6: sat_fat = cleanField(field); break;
                case 7: fibre = cleanField(field); break;
                case 8: carbs = cleanField(field); break;
                case 9: category = field; break;
            }
        }

        // Insert into the linked list
        nutrientClass.InserttoFront(food, measure, stoi(grams), stoi(calories), stoi(protein), stoi(fat), stoi(sat_fat), stod(fibre), stod(carbs), category);
    }

    nutrientClass.DisplayLinkedList();

    return 0;
}
