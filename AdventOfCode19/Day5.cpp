#include "Functions.h"


void day_five1(){
    vector<string> vs = read_input(path_to_file, "test.txt");
    vector<int> v = build_vector(split(vs[0], ','));
    for(size_t i = 0; i < v.size(); ++i){
        vector<int> pos_mode_imm_mode = {v[i]/10000, v[i] % 10000 / 1000, v[i] % 1000 / 100};   // F: position, T:immediate
        int op_code = v[i] % 100;

        if(op_code == 99)
            return;

        int *op3, *op2, *op1;
        if(not pos_mode_imm_mode[2])
            op1 = &v[v[i + 1]];
        else
            op1 = &v[i + 1];

        if(not pos_mode_imm_mode[1])
            op2 = &v[v[i + 2]];
        else
            op2 = &v[i + 2];

        if(not pos_mode_imm_mode[0])
            op3 = &v[v[i + 3]];
        else
            op3 = &v[i + 3];

        if(op_code == 1){
            *op3 = *op2 + *op1;
            i += 3;
        }

        else if(op_code == 2){
            *op3 = *op2 * *op1;
            i += 3;
        }

        else if(op_code == 3){
            std::cin >> *op1;
            i += 1;
        }

        else if(op_code == 4){
            std::cout << v[v[i + 1]];
            break;
        }
    }
}