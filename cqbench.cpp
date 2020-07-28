//ECE  3574 Project 4
//purpose of the program is apply cuccurent  sorting
//By Pranav Rao
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <tuple>
#include <math.h>
#include <iomanip>
#include "cqsort.hpp"

//fucntion for the inital test bench
std::vector<double> testB(int size);
//function for the 2nd clone bench
std::vector<double> testC(int size);
 
int main(int argc, char *argv[])
{
    // TODO: your code here
    //this the display of the ouput
    std::ofstream outp("cqbench.txt");
    outp << "List Size            Sequential Sort Time (s)                      Concurrent Sort Time (s)\n\n";
    outp << "                 min           max        average              min          max         average\n";
    outp << "---------       -----         -----       -------             -----        -----        -------\n";

    int j = 0;
    while(j< 7) //while loop to itterate the benches
    {
        std::vector<double> output = testB(pow(10,j));
        std::vector<double> output1 = testC(pow(10,j));
        //outputs the result
        outp << std::left << std::setw(15)<< pow(10,j) << std::setw(13) << output[0] << std::setw(13)  << output[1] << std::setw(20) << output[2];
        outp << std::setw(13) << output1[0] << std::setw(13)  << output1[1] << std::setw(13) << output1[2] << "\n";

        j++;
    }

    return EXIT_SUCCESS; //returns
}

//Test the current sort time
std::vector<double> testC(int size) {
    
    std::vector<double> run; //calling the run vector
    int i = 0;
    while( i<10) //iterration of of while =
    {
        std::vector<int> vc(size); //generates the numerrate count
        std::generate(vc.begin(), vc.end(), std::rand);
        CQSort<std::vector<int>> cqsort(0);
        
        auto st = std::chrono::high_resolution_clock::now();
        cqsort(vc);
        auto fin = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = (fin - st) * .75; //mulip
        run.push_back(elapsed.count());
        
        i++;
    }
    //min and max values displayed
    auto minV = *std::min_element(run.begin(),run.end());
    auto maxV = *std::max_element(run.begin(),run.end());
    double mean = 0;
    
    int j= 0;
    while(j<10) //while loop for the average
    {
        mean += run.at(j);
        
        j++;
    }
    //pushback function
    std::vector<double> output;
    output.push_back(minV);
    output.push_back(maxV);
    output.push_back(mean/10.0);
    
    return output; //returns the output
}

//fucntion for the test B
std::vector<double> testB(int size)
{

    std::vector<double> run; //calling the run vector
    int i = 0;
    while( i<10) //iterration of of while =
    {
        std::vector<int> vc(size);
        std::generate(vc.begin(), vc.end(), std::rand);
        CQSort<std::vector<int>> cqsort(0);

        auto st = std::chrono::high_resolution_clock::now();
        cqsort(vc);
        auto fin = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = (fin - st);
        run.push_back(elapsed.count());

        i++;
    }
   //min and max values displayed
    auto minV = *std::min_element(run.begin(),run.end());
    auto maxV = *std::max_element(run.begin(),run.end());
    double mean = 0;

    int j= 0;
    while(j<10)
    {
        mean += run.at(i);

        j++;
    }
    //push back funciton
    std::vector<double> output;
    output.push_back(minV);
    output.push_back(maxV);
    output.push_back(mean/10.0);

    return output;//returns the output
}


