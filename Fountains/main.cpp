/*

 Hai un array di N oggetti. Un oggetto può essere una fontana oppure no.
 Ogni oggetto è caratterizzato da un'altezza h.
 Le fontane inondano tutti gli oggetti alla loro destra e
 alla loro sinistra cheabbiano un'altezza <= di quella della fontana.
 Al primo oggetto a destra con altezza maggiore di quella della fontana,
 quella fontana smette di inondare a destra.
 Al primo oggetto a sinistra con altezza maggiore di quella della fontana,
 quella fontana smette di inondare a sinistra.
 Restituire un array di N booleani dove l'elemento i-esimo indica se l'oggetto i-esimo è stato inondato.

 NB: Le fontane sono inondate per definizione.

 input: array di altezze, array delle fontane (indici dell'array di altezze)
 output: array di booleani di inondazione



 es:
 heights: [2, 3, 1, 4, 5, 2];
 fountais: [1, 2, 5];
 output: [1, 1, 1, 1, 1, 1]
 * */

#include <iostream>
#include <vector>

using namespace std;


vector<bool> flooded_fountains(const vector<int> &heights, const vector<int> &fountains) {
    unsigned int h_size = heights.size();
    vector<bool> flooded_f(h_size, false);
    for (int i = 0; i < fountains.size(); ++i){
        int curr_fountain = fountains[i];
        int h_curr_fountain = heights[curr_fountain];
        flooded_f[curr_fountain] = true;

        int _i = curr_fountain;
        while(--_i){
            if(h_curr_fountain < heights[i])
                break;
            flooded_f[i] = true;
        }

        _i = curr_fountain;
        while(++i){
            if(h_curr_fountain < heights[i])
                break;
            flooded_f[i] = true;
        }
    }
    return flooded_f;
}


int main() {
    vector<int> h = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    vector<int> f = {3, 7};
    vector<bool> out = flooded_fountains(h, f);
    return 0;
}