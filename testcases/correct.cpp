#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
#define M_PI  3.14159265358979323
struct Flatlander {
    int x, h;
};

// Function to compute total shadow length
double totalShadowLength(int theta, int n, vector<Flatlander>& flatlanders) {
    // Convert angle to radians for trigonometric calculations
    double theta_rad = theta * M_PI / 180.0;
    double cot_theta = cos(theta_rad) / sin(theta_rad);

    // Sort flatlanders by their positions (x-coordinates)
    sort(flatlanders.begin(), flatlanders.end(), [](const Flatlander &a, const Flatlander &b) {
        return a.x < b.x;
    });

    // Calculate total shadow coverage
    double total_covered_length = 0.0;
    double current_shadow_start = flatlanders[0].x;
    double current_shadow_end = flatlanders[0].x + flatlanders[0].h * cot_theta;

    for (int i = 1; i < n; ++i) {
        double start = flatlanders[i].x;
        double end = flatlanders[i].x + flatlanders[i].h * cot_theta;

        if (start <= current_shadow_end) {
            // Extend the current shadow end if there's an overlap
            current_shadow_end = max(current_shadow_end, end);
        } else {
            // Add the length of the current shadow to the total and start a new shadow
            total_covered_length += current_shadow_end - current_shadow_start;
            current_shadow_start = start;
            current_shadow_end = end;
        }
    }

    // Add the last shadow range to the total
    total_covered_length += current_shadow_end - current_shadow_start;

    return total_covered_length;
}

int main() {
    int theta, n;
    cin >> theta >> n;

    vector<Flatlander> flatlanders(n);
    for (int i = 0; i < n; ++i) {
        cin >> flatlanders[i].x >> flatlanders[i].h;
    }

    double result = totalShadowLength(theta, n, flatlanders);

    // Print the result with precision to 10^-4
    cout.precision(10);
    cout << fixed << result << endl;

    return 0;
}
