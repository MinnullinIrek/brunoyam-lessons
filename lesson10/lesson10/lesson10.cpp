// lesson10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <unordered_map>
#include <unordered_set>

#include <set>
#include <map>

#include "journal.h"
struct Node
{
    std::string value;

    Node* left = nullptr;
    Node* right = nullptr;
};

struct Tree
{
    Node* head = nullptr;

    void push(const std::string &val)
    {
        Node* n = new Node;
        n->value = val;

        if (head == nullptr) {
            head = n;
        }
        else 
        {
            Node* h = find(head, val);
            if(h->value > val)
            {
                h->left = n;
            }else
            {
                h->right = n;
            }
        }

        

    }

    Node* find(Node* node, const std::string& val) {
        
        if (node->value > val )
        {
            if (node->left == nullptr) {
                return node;
            }
            else
            {
                return find(node->left, val);
            }
        }
        else
        {
            if (node->right == nullptr) {
                return node;
            }
            else
            {
                return find(node->right, val);
            }
        }

        return node;
    }


};

int hash(const std::string & name)
{
    //std::string => int
    //char => int
    int sum = 0;
    for (int i = 0; i < name.size(); ++i) {
        char symb = name[i];
        int ch = symb;
        sum += ch;
    }

    int temp = sum % 20;
    return temp; //0 - 20
}


int find(double v, const  std::vector<double>& arr) {

    int tail = arr.size();
    int head = 0;
    while ( head != tail  )
    {
        int midl = (head + tail) / 2;
        double value = arr[midl];

        if (value == v) {
            return midl;
        }
        else if (v < value) {
            tail = midl;

        }
        else if (v > value) {
            head = midl + 1;
        }



    }

    return -1;

}

int main()
{
    /*
    std::cout << "\nhash Hello World!= " << hash("Hello World!");
    std::cout << "\nhash World= " << hash("HellWo orld!");
    std::cout << "\nhash Hello= " << hash("Hello");
    std::cout << "\nhash $$$$ = " << hash("$$$$");
    std::cout << "\nhash Ivan = " << hash("Ivan");

    //hash
    std::unordered_set<std::string> names;
    names.insert("Ivan");
    names.insert("Aleksey");
    names.insert("Boris");
    names.insert("Ilya");
    names.insert("Boris");
    bool cont = names.contains("boris");


    //tree
    std::set<std::string> names2;
    names2.insert("Ivan");
    names2.insert("Aleksey");
    names2.insert("Boris");
    names2.insert("Ilya");
    names2.insert("Boris");
    bool cont2 = names2.contains("Boris");

    */
    //Journal j;
    //j.push("Alexey", Person{ "Alexey", "Moskov adfg 12", "122455" });
    //j.push("Boris", Person{ "Boris", "Kirov ddfg 12", "3234233" });
    ////....
    //

    //Person alexey = j.get("Alexey");
    //std::cout << alexey.name << std::endl;
    //std::cout << alexey.adres << std::endl;
    //std::cout << alexey.telephon << std::endl;



    std::vector<double> arrDouble = { -10.4, 0.4, 3.4, 5.4, 7.4,     9.4,             14.6,     16.4,     20.4,         40.4, };
    int num = find(12.7, arrDouble);


    std::set<std::string> name;


    for (int i = 0; i < 10; ++i) {
        std::string t;
        std::cin >> t;

        name.insert(t);

    }


    for (auto& t : name) {
        std::cout << t << std::endl;
    }


}
