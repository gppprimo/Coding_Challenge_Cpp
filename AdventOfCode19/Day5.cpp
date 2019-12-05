#include "Functions.h"


void day_five1(){
    vector<string> vs = read_input(path_to_file, file_d51);
    vector<int> v = build_vector(split(vs[0], ','));
    for(size_t i = 0; i < v.size(); ++i){
        vector<int> pos_mode_imm_mode = {v[i] % 1000 / 100, v[i] % 10000 / 1000, v[i]/10000};   // F: position, T:immediate
        int op_code = v[i] % 100;

        if(op_code == 99)
            return;

        int *param3, *param2, *param1, *param4 = &v[v[i + 1]];
        if(not pos_mode_imm_mode[0])
            param1 = &v[v[i + 1]];
        else
            param1 = &v[i + 1];

        if(not pos_mode_imm_mode[1])
            param2 = &v[v[i + 2]];
        else
            param2 = &v[i + 2];

        if(not pos_mode_imm_mode[2])
            param3 = &v[v[i + 3]];
        else
            param3 = &v[i + 3];

        if(op_code == 1){
            *param3 = *param2 + *param1;
            i += 3;
        }

        else if(op_code == 2){
            *param3 = *param2 * *param1;
            i += 3;
        }

        else if(op_code == 3){
            std::cin >> *param1;
            i += 1;
        }

        else if(op_code == 4){
            std::cout << *param4 << std::endl;
            i += 1;
        }
    }
}

void day_five2(){
    vector<string> vs = read_input(path_to_file, file_d51);
    vector<int> v = build_vector(split(vs[0], ','));
    for(size_t i = 0; i < v.size(); ++i){
        vector<int> pos_mode_imm_mode = {v[i] % 1000 / 100, v[i] % 10000 / 1000, v[i]/10000};   // F: position, T:immediate
        int op_code = v[i] % 100;

        if(op_code == 99)
            return;

        int *param3, *param2, *param1, *param4 = &v[v[i + 1]];
        if(not pos_mode_imm_mode[0])
            param1 = &v[v[i + 1]];
        else
            param1 = &v[i + 1];

        if(not pos_mode_imm_mode[1])
            param2 = &v[v[i + 2]];
        else
            param2 = &v[i + 2];

        if(not pos_mode_imm_mode[2])
            param3 = &v[v[i + 3]];
        else
            param3 = &v[i + 3];

        if(op_code == 1){
            *param3 = *param2 + *param1;
            i += 3;
        }

        else if(op_code == 2){
            *param3 = *param2 * *param1;
            i += 3;
        }

        else if(op_code == 3){
            std::cin >> *param1;
            i += 1;
        }

        else if(op_code == 4){
            std::cout << *param4 << std::endl;
            i += 1;
        }

        else if(op_code == 5) {
            if(*param1 != 0) i = *param2 - 1;
            else i += 2;
        }
        else if(op_code == 6) {
            if(*param1 == 0) i = *param2 - 1;
            else i += 2;
        }

        else if(op_code == 7){
            (*param1 < *param2) ? (*param3 = 1) : (*param3 = 0);
            i += 3;
        }

        else if(op_code == 8){
            (*param1 == *param2) ? (*param3 = 1) : (*param3 = 0);
            i += 3;
        }
    }
}