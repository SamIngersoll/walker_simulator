// this program publishes commands to joint controllers
// #include <ros/ros.h>
// #include <std_msgs/Float64.h>
#include "read_trajectory.h"

#include <stdlib.h> // For rand() and RAND_MAX
#include <string.h>

// for reading from csv
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <boost/tokenizer.hpp>

using namespace std;
using namespace boost;

// THIS SHOULD TAKE IN A POINTER TO A VECTOR AND A FILENAME AND FILL THE VECTOR WITH THE DATA FROM THE FILE
// IN ORDER TO MAKE THIS WORK, TRY IT IN ITS OWN FILE FIRST SO THAT YOU CAN SEE STD::OUT
int read_trajectory ( vector<vector<double>>& trajectory, string filename ) {
    // vector<vector<double>> trajectory;

    // filename = "./../trajectories/trajectory.csv";
    cout << "[read_file] attempting to read "+filename+"..." << endl;
    string data(filename);

    ifstream in(data.c_str());

    // check if file "in" is open
    if (!in.is_open()) {
        cout << "[read_file] failed to open file" << endl;
        return 1;    
    } else {
        cout << "[read_file] succesfully opened file" << endl;

    }

    typedef tokenizer <escaped_list_separator<char>> Tokenizer;
    vector<string> vec;
    string line;
    vector<double> row;
    while(getline(in,line)) {
        Tokenizer tok(line);    // read line
        vec.assign(tok.begin(), tok.end());     // read from the tokenizer

        // vector now contain strings from one row
        row.clear();
        for (int i = 0; i<vec.size()-1 ; i++) {
            row.push_back(stod(vec[i]));
        }
        trajectory.push_back(row);

    }

    return 0;
}
