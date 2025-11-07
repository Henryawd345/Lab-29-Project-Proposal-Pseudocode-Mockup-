#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <array>
#include <list>

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




void simulateTick(ColonyMap& colonies /*, int year */) {
    // For each planet in the map:
    //     Decide population change (recruit or transfer)
    //     Decide resource change (produce or consume)
    //     Decide structure change (build or decommission)
    //     Print a one-line summary of net deltas for this planet for the current year
}

// Minimal helper just to show structure compiles
// Print a one-line summary of the net change for this planet for the current year

int main() {
    // Initialize a map<string, array<list<string>, 3>> to store colony data
    ColonyMap colonies;

    // Open external file "data.txt" and populate the map
    // If file fails to open, print error and exit
    // PSEUDOCODE ONLY:
    //     For each line "Planet|Category|Item"
    //         Parse planet, category (colonist/resource/structure), and item
    //         Insert into appropriate list for that planet

    // For Lab 29 mockup: insert ONE dummy element so printState shows something
    colonies["Mars"][0].push_back("Recruit-Example");     // colonist
    colonies["Mars"][1].push_back("ResourcePack-Example"); // resource
    colonies["Mars"][2].push_back("Structure-Example");    // structure

    // Print one-line summary

    // Begin a time-based simulation (discrete events)
    // For 30 years:
    for (int year = 1; year <= 30; ++year) {
        // Call pseudocode function (no real changes done here for Lab 29)
        simulateTick(colonies /*, year */);

        // Optionally print a placeholder yearly summary line
        cout << "Year " << year << ": (pseudocode changes would be summarized here)\n";
    }

    // Print final one-line state

    return 0;
}
