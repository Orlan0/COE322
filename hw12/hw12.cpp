//Name: Orlan Oconer
//UTEID: ojo366
//TACC Username: orlan 

#include <iostream>
#include <variant>
#include <tuple>
#include <cmath>
#include <optional>

using namespace std;

// What does variant do? It takes in anything 
// The answer could be an int, a double, or a pair of doubles
using RootCases = variant<int, double, pair<double, double>>;

RootCases solveQuadratic(double a, double b, double c) {
    //Discriminant - We did part of this in class 
    double discriminant = b * b - 4 * a * c;
    // Case 1: No real roots ( it is imaginary)
    if (discriminant < 0) {
        return 0;  // No roots
    }
    // Case 2: One real root 
    else if (discriminant == 0) {
        double root = -b / (2 * a);
        return root;  // Single root
    }
    // Case 3: Two real roots
    else {
        double sqrt_discriminant = sqrt(discriminant);
        double root1 = (-b + sqrt_discriminant) / (2 * a);
        double root2 = (-b - sqrt_discriminant) / (2 * a);
        return make_pair(root1, root2);  // Two roots
    }
}

void printRoots(const RootCases& root_cases) {
    //Following the given from the problem statement 
    switch (root_cases.index()) {
        case 0:
            cout << "No roots\n";
            break;
        case 1:
            cout << "Single root: " << get<1>(root_cases) << '\n';
            break;
        case 2: {
            auto [root1, root2] = get<2>(root_cases);
            cout << "Roots: " << root1 << ", " << root2 << '\n';
            break;
        }
        default:
            cout << "Unexpected result\n";
            break;
    }
}

int main() {
    // Takes in the coefficients 
    double a, b, c;
    cout << "Enter coefficients a, b, and c for the equation ax^2 + bx + c = 0: ";
    cin >> a >> b >> c;
    // Solve the quadratic equation
    RootCases root_cases = solveQuadratic(a, b, c);
    // Print the roots
    printRoots(root_cases);
    return 0;
}
