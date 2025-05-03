#include <bits/stdc++.h>
using namespace std;

int ranking = 25, stars = 0, consecutive_wins = 0;
int starsToAdvanceRanking() {
    if (ranking >= 21) return 2;
    else if (ranking >= 16) return 3;
    else if (ranking >= 11) return 4;
    else return 5;
}
void solve() {
    string matches;
    cin >> matches;

    for (auto m : matches) {
        if (m == 'W'){
            consecutive_wins++;
            stars += (consecutive_wins >= 3 && ranking >= 6 ? 2 : 1);
            if (stars > starsToAdvanceRanking()){ 
                stars -= starsToAdvanceRanking();
                ranking--;
            }
            if (ranking == 0) break;
        }
        else {
            consecutive_wins = 0;
            if (ranking <= 20) stars--;
            if (stars < 0) {
                if (ranking < 20) {
                    ranking++;
                    stars = starsToAdvanceRanking() - 1;
                }
                else stars = 0;
            }
        }
    }

    if (ranking == 0) cout << "Legend";
    else cout << ranking;
    cout << "\n";
}

int main() {
    solve();
}