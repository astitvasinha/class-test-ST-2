/*
Name - Astitva Sinha
roll No- 2010990139
set - 02
 */

#include <bits/stdc++.h>
using namespace std;

// func for mean
long mean(vector<long> grades){
    return accumulate(begin(grades), end(grades), (long)0)/grades.size();
}

//func for meadian
long median(vector<long> grades, int size){
    sort(begin(grades), end(grades));

    if(size % 2 != 0){
        return grades[size/2];
    }

    int a = size/2;
    int b = a + 1;

    return (grades[a] + grades[b])/2;
}

//function for mode
void mode(vector<string> names, vector<long> grades){
    unordered_map<int, int> freq;

    for(int i=0; i<grades.size(); i++)
        freq[grades[i]]++;

    unordered_map<int, int> modes;
    long highestFreq = 0;
    for(int i=0; i<grades.size(); i++){
        if(freq[grades[i]] > highestFreq){
            highestFreq = freq[grades[i]];
            modes.clear();
            modes[grades[i]]++;
        }
        else if(freq[grades[i]] == highestFreq){
            modes[grades[i]]++;
        }
    }

    cout<<"students list with their mode: ";
    for(int i=0; i<grades.size(); i++){
        if(modes[grades[i]] > 0)
            cout<<names[i]<<" "<<grades[i]<<" ";
    }

}

int main()
{
    vector<string> names; // vector for string
    vector<long> grades; // vector for grades

    int size;  //size
    cin>>size;

    string name;
    int grade;

    for(int i=0; i<size; i++){
        cin>>name>>grade; // input values
        names.push_back(name);
        grades.push_back(grade);
    }

    cout<<"mean: "<<mean(grades)<<endl;
    cout<<"median: "<<median(grades, size)<<endl;

    mode(names, grades);

    return 0;
}
