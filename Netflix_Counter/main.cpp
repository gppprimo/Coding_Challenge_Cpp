

/*
 * Netflix vende il suo abbonamento familiare ad un prezzo P. Un numero arbitrario N di membri può entrare
 * come parte della famiglia, per cui ciascuno di loro pagherebbe una cifra mensile di P/N.
 * Alcuni di questi membri però capiscono di poter risparmiare dividendo a loro volta la loro quota con nuovi membri.
 * Inoltre alcuni degli N membri originari che non ha nessuno di nuovo da invitare,
 * chiede a qualcuno degli altri (N-1) membri originari che divide la sua quota con altre persone di poter entrare
 * nel suo gruppo, raddoppiando però la quota complessiva che quel gruppo deve pagare.
 * Definire una struttura dati che descriva il problema.
 * Definire i metodi su questa struttura che calcoli per ciascun membro che ne fa parte,
 * la sua spesa mensile, nota la spesa mensile complessiva P.
 * */


#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;


unordered_map<unsigned int, vector<string>> build_map(const vector<string> & m){
    int id = 0;
    unordered_map<unsigned int, vector<string>> mappina;
    for(string s : m){
        vector<string> ss = {s};
        mappina.insert({++id, ss});
    }

    return mappina;
}

vector<int> associa_quote(float n, float p, const unordered_map<unsigned int, vector<string>> & m){

}

void add_pezzente(unordered_map<unsigned int, vector<string>> &map, string s){
    for(auto i : map){

    }
}


int main() {

//    build map
//    calcola spesa mensile specificando un membro;

    float N, P;
    cout << "P: ";
    cin >> P;
    cout << endl << "N: ";
    cin >> N;
    cout << "Inserisci i membri del gruppo" << endl;
    vector<string> membri;
    string s;
    for(int i = 0; i < N; ++i){
        std::getline(cin, s);
        membri.push_back(s);
    }

    auto map = build_map(membri);
    auto map_quote = associa_quote(N, P, map);

    cout << "Inserisci il nome del pezzente da aggiungere ad uno dei gruppi esistenti" << endl;
    std::getline(cin, s);
    add_pezzente(map, s);



    return 0;
}