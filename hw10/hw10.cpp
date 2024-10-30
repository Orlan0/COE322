// Name: Orlan Oconer
// eid: ojo366
// TACC username: orlan

#include "zeroclasslib.hpp"
#include <stdexcept>
#include <cmath>
#include <iostream>
using std::cout;

// The polynomial class is da math equation 
// For example, 2x^2 + 3x + 1 can be represented with a vector of {2, 3, 1}.
polynomial::polynomial(std::vector<double> coeffs) {
    // If the first number (highest degree) is zero, it’s not a valid polynomial.
    if (coeffs[0] == 0.0) {
        throw std::invalid_argument("Highest degree coefficient cannot be zero");
    }
    coefficients = coeffs; // Store the numbers that make up the polynomial
}

// Check if the polynomial has an odd degree.
// Odd degree polynomials go from negative to positive or positive to negative.
bool polynomial::is_odd() const {
    return (coefficients.size() - 1) % 2 == 1;
}

// This function calculates the value of the polynomial at a given number (x).
double polynomial::evaluate_at(double point) const {
    double result = coefficients[0];
    for (size_t i = 1; i < coefficients.size(); i++) {
        result = result * point + coefficients[i]; // Keep calculating based on the point
    }
    return result;
}

// This function finds the lower and upper bounds where the polynomial crosses the x-axis.
void find_initial_bounds(const polynomial& poly, double& lower_bound, double& upper_bound) {
    // Make sure the polynomial is odd, or it might not cross the x-axis.
    if (!poly.is_odd()) {
        throw std::invalid_argument("Polynomial must be odd degree");
    }
    // The lower bound must be smaller than the upper bound.
    if (lower_bound >= upper_bound) {
        throw std::invalid_argument("Lower bound must be less than upper bound");
    }

    // Get the values at the lower and upper bound points.
    double lower_value = poly.evaluate_at(lower_bound);
    double upper_value = poly.evaluate_at(upper_bound);
    
    // If one side is positive and the other is negative, we found our bounds.
    if (lower_value * upper_value <= 0) {
        return; // We have the bounds we need, so we’re done here.
    }

    // Start expanding our bounds to find a crossing point.
    double step_size = 100.0;
    int max_steps = 1000;
    int current_step = 0;
    while (lower_value * upper_value > 0 && current_step < max_steps) {
        // Move lower_bound further down, and upper_bound further up.
        lower_bound -= step_size;
        upper_bound += step_size;
        
        // Update the values at the new lower and upper bounds.
        lower_value = poly.evaluate_at(lower_bound);
        upper_value = poly.evaluate_at(upper_bound);

        // Make the step size bigger to speed up the search.
        step_size *= 1.5;
        current_step++; // Count each attempt to make sure we don’t try forever.
    }
    // If we tried too many times and still couldn't find it, we give up.
    if (current_step >= max_steps) {
        throw std::runtime_error("Could not find initial bounds");
    }
}

// This function moves the bounds closer to the point where the polynomial crosses the x-axis.
void move_bounds_closer(const polynomial& poly, double& lower_bound, double& upper_bound, bool enable_trace) {
    // Make sure lower_bound is still less than upper_bound.
    if (lower_bound >= upper_bound) {
        throw std::invalid_argument("Lower bound must be less than upper bound");
    }
    // If lower_bound and upper_bound are the same, we can't move closer.
    if (lower_bound == upper_bound) {
        throw std::invalid_argument("Bounds cannot be equal");
    }

    // Find the midpoint between lower_bound and upper_bound.
    double midpoint = lower_bound + (upper_bound - lower_bound) / 2.0;
    double midpoint_value = poly.evaluate_at(midpoint); // Value of polynomial at the midpoint
    double lower_value = poly.evaluate_at(lower_bound); // Value at the lower bound

    // If tracing is enabled, print the current midpoint and its value.
    if (enable_trace) {
        cout << "Midpoint: " << midpoint << " value: " << midpoint_value << "\n";
    }

    // Check which side of the midpoint has the crossing point.
    if (lower_value * midpoint_value <= 0) {
        // The crossing point is between lower_bound and midpoint, so move upper_bound to midpoint.
        upper_bound = midpoint;
    } else {
        // The crossing point is between midpoint and upper_bound, so move lower_bound to midpoint.
        lower_bound = midpoint;
    }
}

// This function tries to find where the polynomial equals zero (the "root").
double find_zero(const polynomial& poly, double tolerance, bool enable_trace) {
    // Start with an initial guess that the crossing point is between -10 and 10.
    double lower_bound = -10.0;
    double upper_bound = 10.0;
    
    // Keep expanding the bounds until we find a crossing point.
    while (true) {
        try {
            find_initial_bounds(poly, lower_bound, upper_bound);
            break; // We found valid bounds, so stop expanding.
        } catch (const std::runtime_error&) {
            // If we didn't find bounds, make the range bigger and try again.
            lower_bound *= 2;
            upper_bound *= 2;
        }
    }
    
    // Keep narrowing down the interval until we're close enough to the crossing point.
    while (true) {
        // Find the midpoint between lower_bound and upper_bound.
        double midpoint = lower_bound + (upper_bound - lower_bound) / 2.0;
        double midpoint_value = std::abs(poly.evaluate_at(midpoint)); // Value at the midpoint

        // If tracing is on, print the current midpoint and its value.
        if (enable_trace) {
            cout << "Testing x = " << midpoint << ", value = " << midpoint_value << "\n";
        }
        
        // If the midpoint value is smaller than our desired tolerance, we found the root.
        if (midpoint_value < tolerance) {
            return midpoint;
        }

        // If the interval is super small but we haven’t found the exact root,
        // return the closest point to zero.
        if (upper_bound - lower_bound < 1e-14) {
            double lower_value = std::abs(poly.evaluate_at(lower_bound));
            double upper_value = std::abs(poly.evaluate_at(upper_bound));
            return (lower_value < upper_value) ? lower_bound : upper_bound;
        }
        
        // Move the bounds closer to each other.
        move_bounds_closer(poly, lower_bound, upper_bound, enable_trace);
    }
}
