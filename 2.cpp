#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string &row1, string &row2) {
    int n = row1.length();
    int m = count(row1.begin(), row1.end(), '?') + count(row2.begin(), row2.end(), '?');

    if (m % 2 != 0) {
        // If the total number of '?' characters is odd, it's not possible to balance the board.
        return -1;
    }

    // Calculate the difference between the counts of 'R' and 'W' in each row.
    int diff_row1 = count(row1.begin(), row1.end(), 'R') - count(row1.begin(), row1.end(), 'W');
    int diff_row2 = count(row2.begin(), row2.end(), 'R') - count(row2.begin(), row2.end(), 'W');

    // Initialize the difference between the counts of 'R' and 'W' in each column.
    vector<int> diff_col(n, 0);

    for (int i = 0; i < n; i++) {
        // Calculate the initial difference in each column.
        if (row1[i] == 'R') {
            diff_col[i]++;
        } else if (row1[i] == 'W') {
            diff_col[i]--;
        }
        if (row2[i] == 'R') {
            diff_col[i]++;
        } else if (row2[i] == 'W') {
            diff_col[i]--;
        }
    }

    int min_replacements = m / 2; // Initialize with the maximum possible replacements.

    for (int i = 0; i < n; i++) {
        // Update the differences after inserting 's' character at position C[i].
        if (row1[i] == '?' && row2[i] == '?') {
            // Inserting 's' in both rows.
            diff_col[i] += 2;
            diff_row1 += 2;
            diff_row2 += 2;
        } else if (row1[i] == '?') {
            // Inserting 's' in row1.
            diff_col[i]++;
            diff_row1++;
        } else if (row2[i] == '?') {
            // Inserting 's' in row2.
            diff_col[i]++;
            diff_row2++;
        }

        // Check if the board becomes balanced after the current insertion.
        if ((diff_row1 + diff_row2) % 2 == 0 && all_of(diff_col.begin(), diff_col.end(), [](int x) { return x == 0; })) {
            min_replacements = min(min_replacements, m / 2);
        }
    }

    return min_replacements;
}

int main() {
    string row1 = "?RW?WR";
    string row2 = "?WR?RW";

    int min_replacements = solution(row1, row2);
    cout << "Minimum number of replacements needed: " << min_replacements << endl;
    
    return 0;
}