#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Data structure to store information about a region
struct Region {
    string name;
    int population;
    double hunger_rate;
    double malnutrition_rate;
};

// Function to find the region with the highest hunger rate
Region find_highest_hunger_rate(vector<Region>& regions)
{
    // initialize maximum hunger rate and corresponding region
    double max_hunger_rate = 0;
    Region max_hunger_region;

    // traverse the regions to find the one with maximum hunger rate
    for (Region& region : regions)
    {
        if (region.hunger_rate > max_hunger_rate)
        {
            max_hunger_rate = region.hunger_rate;
            max_hunger_region = region;
        }
    }

    return max_hunger_region;
}

// Function to allocate resources to regions based on their hunger rate
void allocate_resources(vector<Region>& regions, map<string, int>& resources)
{
    // allocate resources until there are no more available
    while (!resources.empty())
    {
        // find the region with the highest hunger rate
        Region region = find_highest_hunger_rate(regions);

        // allocate all available resources to the region
        for (auto& [name, quantity] : resources)
        {
            region.resources[name] += quantity;
            resources[name] = 0;
        }
    }
}

// Function to print the allocation of resources to regions
void print_allocation(vector<Region>& regions)
{
    for (Region& region : regions)
    {
        cout << region.name << ": " << endl;
        for (auto& [name, quantity] : region.resources)
            cout << "\t" << name << ": " << quantity << endl;
    }
}

int main()
{
    // create a vector of regions
    vector<Region> regions = {
        {"Africa", 1000, 0.3, 0.1},
        {"Asia", 2000, 0.2, 0.2},
        {"Europe", 500, 0.1, 0.1},
        {"North America", 800, 0.4, 0.05},
        {"South America", 600, 0.2, 0.3}
    };

    // create a map of available resources
    map<string, int> resources = {
        {"food", 100},
        {"water", 200},
        {"medical aid", 50}
    };

    // allocate resources to regions
    allocate_resources(regions, resources);

    // print the allocation of resources to regions
    print_allocation(regions);

    return 0;
}
