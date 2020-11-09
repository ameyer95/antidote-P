#ifndef INFORMATION_MATH_H
#define INFORMATION_MATH_H

#include "Interval.h"
#include "CategoricalDistribution.hpp"
#include <vector>


// Give them names instead of having to assume a std::pair convention
struct BinarySamples {
    int num_zeros = 0;
    int num_ones = 0;
};

double estimateBernoulli(const BinarySamples &counts);
Interval<double> estimateBernoulli(const BinarySamples &counts, int num_dropout);
Interval<double> estimateBernoulliLabels(const BinarySamples &counts, int labels_to_flip);

// Computes the Gini Impurity
double impurity(const BinarySamples &counts);
double impurityLabels(const BinarySamples &counts);
Interval<double> impurity(const BinarySamples &counts, int num_dropout);
Interval<double> impurityLabels(const BinarySamples &counts, int labels_to_flip);

// These are non-normalized
double jointImpurity(const BinarySamples &counts1, const BinarySamples &counts2);
double jointImpurityLabels(const BinarySamples &counts1, const BinarySamples &counts2);
Interval<double> jointImpurity(const BinarySamples &counts1, int num_dropout1,
                               const BinarySamples &counts2, int num_dropout2);
Interval<double> jointImpurityLabels(const BinarySamples &counts1, int labels_to_flip1,
                                const BinarySamples &counts2, int labels_to_flip2);

CategoricalDistribution<double> estimateCategorical(const std::vector<int> &counts);
CategoricalDistribution<double> estimateCategoricalLabels(const std::vector<int> &counts);
double impurity(const std::vector<int> &counts);
double impurityLabels(const std::vector<int> &counts);
double jointImpurity(const std::vector<int> &counts1, const std::vector<int> &counts2);
double jointImpurityLabels(const std::vector<int> &counts1, const std::vector<int> &counts2);

CategoricalDistribution<Interval<double>> estimateCategorical(const std::vector<int> &counts, int num_dropout);
CategoricalDistribution<Interval<double>> estimateCategoricalLabels(const std::vector<int> &counts, int labels_to_flip);
Interval<double> impurity(const std::vector<int> &counts, int num_dropout);
Interval<double> impurityLabels(const std::vector<int> &counts, int labels_to_flip);
Interval<double> jointImpurity(const std::vector<int> &counts1, int num_dropout1,
                               const std::vector<int> &counts2, int num_dropout2);
Interval<double> jointImpurityLabels(const std::vector<int> &counts1, int labels_to_flip1,
                                    const std::vector<int> &counts2, int labels_to_flip2);

#endif
