#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <array>
#include <vector>
#include <list>
#include <iomanip>

using namespace std;

// Data model: map<string, array<list<string>, 3>>
// 0 -> colonists, 1 -> resources, 2 -> structures
using ColonyMap = map<string, array<list<string>, 3>>;

int categoryIndex(const string cate){
    if (cate == "colonist") return 0;
    if (cate == "resource") return 1;
    if (cate == "structure") return 2;
    return -1;
}

bool loadData(const string& path, ColonyMap& colonies){
    ifstream in(path);
    if (!in) return false;

    string line;
    while (getline(in, line)){
        if (line.empty()) continue;

        auto p1 = line.find('|');
        auto p2 = (p1 == string::npos) ? string::npos : line.find('|', p1 + 1);
        if (p1 == string::npos || p2 == string::npos) continue;

        string planet   = line.substr(0, p1);
        string category = line.substr(p1 + 1, p2 - p1 - 1);
        string item     = line.substr(p2 + 1);

        int index = categoryIndex(category);
        if (index >= 0 && index <=2){
            colonies[planet][index].push_back(item);

        }
    }
    return true;

}

void printState(const ColonyMap& colonies, const string& title){
    cout << "\n=== " << title << " ===\n";
    for (const auto& [planet, triple] : colonies){
        cout << "- " << planet << " | colonists =" << triple[0].size()
        << ", resources =" << triple[1].size()
        << ", structures =" << triple[2].size() << "\n";
    }

}



void simulateTick(ColonyMap& colonies) {
    if (colonies.empty()) return;

    vector<string> planets;
    planets.reserve(colonies.size());
    for (auto& kv : colonies) planets.push_back(kv.first);

    


}

// Minimal helper just to show structure compiles
// Print a one-line summary of the net change for this planet for the current year

int main() {
    // Initialize a map<string, array<list<string>, 3>> to store colony data
    ColonyMap colonies;

    if (!loadData("data.txt", colonies)){
        cerr << "ERROR: could not open data.txt\n";
        return 1;
    }

    printState(colonies, "Initial Data Load (Alpha)");

    // Begin a time-based simulation (discrete events)
    // For 30 years:
    for (int year = 1; year <= 30; ++year) {
        // Call pseudocode function (no real changes done here for Lab 29)
        simulateTick(colonies);

        // Optionally print a placeholder yearly summary line
        cout << "Year " << year << ": (pseudocode changes would be summarized here)\n";
    }

    printState(colonies, "Final State (Alpha)");

    return 0;
}
