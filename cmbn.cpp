//
//  main.cpp
//  Classic Secretary Problem
//
//  Created by Ivan Feng Jun Kai on 4/8/15.
//  Copyright (c) 2015 Ivan Feng Jun Kai. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

/* This function tells you if the trial was successful.
 * k -> Number of elements to drop.
 * m -> Number of elements that can be chosen.
 * n -> Worst grade allowed.
 * xs -> List of elements. The element with the best grade should be 1 and the
 * element with the worst grade should be N.
 */
bool cmbn(int k, int m, int n, std::vector<int> xs)
{
    auto N = xs.size();

    // find best out of first k elements
    int best_choice = xs[0];
    for (int i = 0; i < k; ++i)
        if (xs[i] < best_choice) best_choice = xs[i];

    // select any element better than first k till no vacancies are left or till
    // remaining elements must be picked to fill up vacancies
    for (int i = k; i < N - m && m > 0; ++i)
    {
        if (xs[i] < best_choice)
        {
            --m;
            best_choice = xs[i];
            if (xs[i] <= n) return true;
        }
    }

    // go through last few elements if there are still vacancies
    for (int i = N - m; i < N; ++i)
    {
        --m;
        if (xs[i] <= n) return true;
    }

    return false;
}

int main()
{
    int N;
    std::cout << "Range from 1? ";
    std::cin >> N;

    int m;
    std::cout << "How many choice(s)? ";
    std::cin >> m;

    int n;
    std::cout << "What is the worst grade allowed? ";
    std::cin >> n;

    int trials;
    std::cout << "Number of trial(s)? ";
    std::cin >> trials;

    std::vector<int> xs(N);
    for (int i = 0; i < N; ++i)
        xs[i] = i + 1;

    std::default_random_engine g;
    std::random_device rd;
    g.seed(rd());

    std::vector<int> record(N - m + 1);
    for (int temp = 0; temp < trials; ++temp)
    {
        std::shuffle(xs.begin(), xs.end(), g);
        for (int k = 1; k <= N - m; ++k)
            if (cmbn(k, m, n, xs)) ++record[k];
    }

    int best_k = 0, best = 0;
    for (int k = 1; k <= N - m; ++k)
    {
        double probability = (double) record[k] / (double) trials;
        std::cout << "k = " << k << ", probability = " << probability << std::endl;
        if (record[k] > best)
        {
            best_k = k;
            best = record[k];
        }
    }

    double chance = (double) best / (double) trials;
    std::cout << "Optimal strategy is to drop " << best_k << " elements with a chance of " << chance << "." << std::endl;

    return 0;
}
