//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=882&page=show_problem&problem=1329
#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

deque<char> jane, john; // Pilha de cartas viradas para baixo
deque<char> flipped_jane, flipped_john; // Pilha de cartas viradas para cima

void solve();
void snap(char cardJane, char cardJohn);

int main() {
	int t;
	cin >> t;

	for (int test = 0; test < t;) {
		string a,b;
		cin >> a >> b;
		for (int i = 0; i < a.size(); i++) {
			jane.push_back(a.at(i));
			john.push_back(b.at(i));
		}
		solve();
		jane.clear();
		flipped_jane.clear();
		john.clear();
		flipped_john.clear();
		
		//Para ficar sem '\n' no ultimo caso de teste fiz assim
		test++;
		if (test < t) cout << '\n';
	}
}

void solve() {
	int turns = 0;
	while (turns++ < 1000) {
		
		//Verificar se um dos jogadores ganharam
		if (flipped_jane.empty() && jane.empty()) { 
			cout << "John wins.\n"; 
			return;
		}
		else if (flipped_john.empty() && john.empty()) {
			cout << "Jane wins.\n";
			return;
		}
		
		//Se não, seguir o jogo
		else {
			if (jane.empty()) {
				jane.insert(jane.begin(), flipped_jane.rbegin(), flipped_jane.rend());
				flipped_jane.clear();
			}
			if (john.empty()) { 
				john.insert(john.begin(), flipped_john.rbegin(), flipped_john.rend());
				flipped_john.clear();
			}

			char cardJane = jane.front();
			jane.pop_front();
			flipped_jane.push_front(cardJane);

			char cardJohn = john.front();
			john.pop_front();
			flipped_john.push_front(cardJohn);

			if (cardJane == cardJohn)
				snap(cardJane, cardJohn);
		}
	}
	cout << "Keeps going and going ...\n";
}

void snap(char cardJane, char cardJohn) {
	cout << "Snap! ";
	if (rand()/141%2 == 0) { //Jane pega as cartas viradas para cima de John
		flipped_jane.insert(flipped_jane.begin(), flipped_john.begin(), flipped_john.end());
		flipped_john.clear();
		
		cout << "for Jane: ";
		for (auto card : flipped_jane) cout << card;
		cout << '\n';
	}
	else { //John pega as cartas viradas para cima de Jane
		flipped_john.insert(flipped_john.begin(), flipped_jane.begin(), flipped_jane.end());
		flipped_jane.clear();

		cout << "for John: ";
		for (auto card : flipped_john) cout << card;
		cout << '\n';
	}
}