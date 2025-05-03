#include <bits/stdc++.h>
using namespace std;

void solve(){
    float n, winner, maxVotes = -1, totalVotes = 0;
    bool hasWinner = false;
    int qtdWinner = 0;
    cin >> n;

    std::vector<float> votes(n);
    winner = 0;

    for (int i = 0; i < n; i++) {
        cin >> votes[i];
        maxVotes = max(votes[i], maxVotes);
        totalVotes += votes[i];
    }
    
    for(int i = 0; i < n; i++)  {
        if (votes[i] == maxVotes) {
            qtdWinner++;
            winner = i;
        }
    }   

    if (qtdWinner > 1) cout << "no winner\n";
    else {
        if (votes[winner] <= totalVotes/2) 
            cout << "minority winner " << winner + 1 << '\n';
        else 
            cout << "majority winner " << winner + 1 << '\n';
    }
}

int main(){
    int t;
    cin >> t;

    for (int i = 0; i < t; i++){
        solve();
    }
}