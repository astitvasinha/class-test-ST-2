// Astitva 2010990139 Set 2
#include <bits/stdc++.h>
using namespace std;

void sort_map_on_value(map<int, int> mymap)
{
    //comparator lambda function
    auto comp = [](pair<int, int> a, pair<int, int> b) {
        //comparison logic
        //if value is greater for the first element 
        //no need to swap
        if (a.second > b.second)
            return false;
        //if value is less for the first element 
        //need to swap
        else if (a.second < b.second)
            return true;
        else { // when values are same
            if (a.first < b.first) {
                return false;
            }
            else
                return true;
        }
    };

    priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(comp)> pq(comp);

    for (auto& ij : mymap) {
        pq.push(ij);

    }
    //printing the sorted map
    cout << "key value\n";
    while (!pq.empty()) {
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }
}

void print(map<int, int> mymap)
{
    cout << "key value\n";
    for (auto & [ key, value ] : mymap)
        cout << key << " " << value << endl;
}

int main()
{
    map<int, int> mymap;
 
    mymap[1] = 6;
    mymap[2] = 8;
    mymap[6] = 3;
    mymap[8] = 2;
 
    cout << "before sorting map is:\n";
    print(mymap);
 
    cout << "after sorting based on value map is: \n";
    sort_map_on_value(mymap);

    return 0;
}