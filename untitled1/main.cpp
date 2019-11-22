#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;

struct Student{
    u_long id;
    string p_lang;

    Student(){
        this->id = 0;
        this->p_lang = "";
    }
};

vector<pair<u_long , u_long>> match_students(const vector<Student> &students){
    if(students.empty())
        return {};
    unordered_set<unsigned long> matched_students;
    vector<pair<u_long , u_long>> results;

    for(int i = 0; i < students.size() - 1; ++i){   // O(n)
        if(matched_students.find(students[i].id) != matched_students.end()) // O(log(n))
            continue;
        for(int j = i + 1; j < students.size(); ++j){   // O(n)
            if(students[i].p_lang == students[j].p_lang and matched_students.find(students[j].id) == matched_students.end()){
                matched_students.insert(students[j].id);
                results.emplace_back(students[j].id, students[i].id);
                break;
            } // O(log(n))
        }
    }
    return results;
}

vector<pair<u_long , u_long>> match_students_optimized(const vector<Student> &students){
    if(students.empty())
        return {};

    vector<pair<u_long , u_long>> results;
    unordered_map<string, stack<u_long>> prog_languages_id_list;

    for(const auto & s : students){ // O(n)
        auto it = prog_languages_id_list.find(s.p_lang);
        if(it != prog_languages_id_list.end() and it->second.size() > 1){
            results.emplace_back(pair<u_long , u_long>(it->second.top(), s.id));
            it->second.pop();
        } else if(it != prog_languages_id_list.end())
            it->second.push(s.id);
        else{
            stack<u_long> ss;
            ss.push(s.id);
            prog_languages_id_list.insert(pair<string, stack<u_long>>(s.p_lang, ss));
        }
    }
    return results;
}

vector<pair<u_long , u_long>> match_students_serie(const vector<Student> &students) {

}


int main() {

    vector<Student> vs;
    for(int i = 0; i < 5; ++i){
        Student s;
        s.id = i;
        s.p_lang = "C++";
        vs.push_back(s);
    }

    Student s;
    s.p_lang = "Java";
    s.id = 6;
    vs.push_back(s);

    s.p_lang = "Java";
    s.id = 7;
    vs.push_back(s);

    auto res = match_students_optimized(vs);

    for(const auto & s : res){
        cout << s.first << " " << s.second << endl;
    }
    return 0;
}