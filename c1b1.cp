//
//  main.cpp
//  Classic Secretary Problem
//
//  Created by Ivan Feng Jun Kai on 4/8/15.
//  Copyright (c) 2015 Ivan Feng Jun Kai. All rights reserved.
//

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <vector>
#include <random>

using namespace std;

float percentage (float a, float b){
    //cout << "a is "<<a<<"b is "<<b;
    float r=0;
    r=(a*100)/b;
    return r;
}

int main()
{
    srand(time(nullptr));
    
    int N;
    cout << "Range from 1? ";
    cin >> N;
    
    vector<int>record(N);
    vector<int> elements (N);
    std::default_random_engine generator;
    
    
    int times;
    cout << "Need to check for how many times? ";
    cin >> times;
    for (int temp=0; temp<times; temp++) {
        //shuffles
        for (int i = 0; i<N; i++) {
            elements[i]=1+i;
        }
        auto currentIndexCounter = elements.size();
        
        
        for (auto iter = elements.rbegin(); iter != elements.rend();
             iter++, --currentIndexCounter)
        {
            std::uniform_real_distribution<double> distribution(0,currentIndexCounter);
            int number = distribution(generator);
            int randomIndex = number;
            
            if (*iter != elements.at(randomIndex))
            {
                std::swap(elements.at(randomIndex), *iter);
            }
        }
        
        int min = elements[0];
        int learning;
        int success = 0;
        
        for (learning = 0; learning<N; learning++) {
            success=0;
            int one=1;
            for (; one <= learning;one++)
            {
                if (elements[one]<min)
                {
                    min = elements[one];
                }
            }
            for (int temp = learning; temp <= N; temp++)
            {
                if (elements[temp]<min && elements[temp]==1)
                {
                    success++;
                    break;
                }
                else if (elements[temp]<min) {break;}
                else if (temp == N-1){break;}
            }
            record[learning]=success+record [learning];
        }
        
    }
    int max = record[0];
    for (int temp=0; temp<N; temp++) {
        if (record[temp]>max) {
            max = record [temp];
        }
    }
    vector<int>pos(N);
    
    for (int temp=0; temp<N; temp++) {
        pos[record[temp]]=temp;
    }
    float answer=percentage(max,times);
    cout << "At position "<<pos[max]+1<< " with a chance of "<<answer<<"%.";
    
    return 0;
}