#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

int mini_steps(string& S,vector<int>& C) {
    int n = S.length();
    int m = C.size();
    int steps = 0;
    unordered_map<char, int> pos_last;

    for (int i = 0; i < m; i++) {
        char letter_pos = S[C[i] -1]; // Letter at the position specified by C[i]
        int insert_pos = C[i] + steps; // Position to insert the '$' character

        // Calculate the minimum steps needed to satisfy the condition
        if (pos_last.find(letter_pos) != pos_last.end()) {
            int required_steps = insert_pos - pos_last[letter_pos];
            steps = max(steps, required_steps);
        }

        // Update the last position of the letter
        pos_last[letter_pos] = insert_pos;
    }

    return steps;
}
int main() {
    string S = "aabcba";
    vector<int> C = {1, 3, 2};
    int min_steps_needed = mini_steps(S, C);
    cout << "Minimum number of steps needed: " << min_steps_needed << endl;
    return 0;
}