/*
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void addCurrentNode(int n1, int n2, ListNode *ln){
    int sum = n1 + n2;
    if(sum < 10){
        int val = ln->val + sum;
        if(val < 10) {
            ln->val = val;
            ln->next = new ListNode(0);
        } else {
            ln->val = val % 10;
            ln->next = new ListNode(1);
        }
    } else {
        int val = (ln->val + sum) % 10;
        ln->val = val;
        ln->next = new ListNode(1);
    }
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *currentNode = new ListNode(0);
        ListNode *rootNode = currentNode;

        while(l1 != NULL and l2 != NULL){
            addCurrentNode(l1->val, l2->val, currentNode);
            l1 = l1->next;
            l2 = l2->next;
            currentNode = currentNode->next;
        }

        if(l1 != NULL){
            while (l1 != NULL){
                addCurrentNode(l1->val, 0, currentNode);
                l1 = l1->next;
                currentNode = currentNode->next;
            }
        }

        if(l2 != NULL){
            while (l2 != NULL){
                addCurrentNode(0, l2->val, currentNode);
                l2 = l2->next;
                currentNode = currentNode->next;
            }
        }

        if(currentNode->val == 0){
            ListNode *temp = rootNode;
            while(temp != NULL){
                if(temp->next != nullptr and temp->next->val == 0 and temp->next->next == nullptr){
                    temp->next = NULL;
                }
                temp = temp->next;
            }
        }
        return rootNode;
    };
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* l1 = stringToListNode(line);
        getline(cin, line);
        ListNode* l2 = stringToListNode(line);

        ListNode* ret = Solution().addTwoNumbers(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}