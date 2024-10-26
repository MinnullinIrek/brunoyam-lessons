
#include <iostream>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <forward_list>
#include <string>
#include "List.h"
#include <unordered_map>



struct Data {
    std::string telephon;
    std::string adres;
};

struct Coord {
    int x = 0; // max = 9
    int y = 0; // max = 9
};

uint32_t hash(const Coord& c) {
    return c.x * 10 + c.y;
}

class HashFunctionCoord
{
public:
    size_t operator()(const Coord& c) const
    {
        return c.x * 10 + c.y;
    }
};

class HashFunction
{
public:
    size_t operator()(const std::string& name) const
    {
        size_t  h = 0;

        for (auto ch : name) {
            h = h * 32 + (uint32_t)ch;
        }
        return h;
    }
};


int main()
{


    std::unordered_map<std::string, Data, HashFunction> sprav;

    sprav.emplace("rob", Data{ "123", "Mosk" });
    sprav["alex"] = Data{ "432", "Barnaul" };
    sprav.insert({ "Timur", Data{ "432", "Barnaul" } });

    std::unordered_map<Coord, bool, HashFunctionCoord> karta;

    

    HashFunction h;
    std::cout << h("rob") << std::endl;
    std::cout << h("alex") << std::endl;
    std::cout << h("Timur") << std::endl;
    int i = 0;
    std::cin >> i;
    //{
    //    List list;
    //    list.push_back("asdgg");
    //    list.push_back("adfsd");
    //    list.push_back("gfsd");
    //    bool res = list.exist("gfsd");
    //    int sz = list.size();
    //   // list.clear();
    //    sz = list.size();
    //}
    //
    //int i = 0;

    //std::list<std::string> s;

    //s.size();
    //s.clear();
    //s.push_back("sassa");
   


   /*
    std::cout << "Hello World!\n";

    char* ch = new char[10];
    char arr[10];

    std::array<char, 10> chStd;

    chStd[3] = 's';
    arr[2] = 's';

    arr[20] ='s';

    chStd[20] = 's';

    chStd.at(4) = 'd';
    chStd.at(30) = 'd';


    std::vector<char> v;
    v.reserve(1000);
    //v.capacity() == 1000
    //v.size() == 0

    v.push_back('s');
    v.push_back('s');
    v.push_back('s');
    v.push_back('s');
    //v.capacity() == 1000
    //v.size() == 4


    v.at(20);
    v[13];

    int cap = v.capacity();
    int size = v.size();

    std::stack<int> st;
    st.push(5);
    st.push(10);
    st.push(53);
    //st.top() == 53
    //st.pop();
    //st.top() == 10

    std::deque<char> d;

    d.push_back('d');
    //d[23];


    std::list<float> list;
    std::forward_list<float> flist;

    //for (auto it = flist.rend(); it != flist.rbegin(); --it) {
    //}

    v.insert(v.begin() + 5, 'f'); //O(n)
    
    
    
    auto it = list.begin();
    it++;
    it++;
    it++;
    it++;
    it++;
    it++;
    list.insert(it, 'd'); //O(1)

    */

}
