

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <functional>
#include <map>

template <typename T>
void printContainer(T& cont)
{
    for (auto it = cont.begin(); it != cont.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
}

void func(int element) {
    std::cout << element << std::endl;
}

template <typename TIterator, typename TFunc >
void for_each(  TIterator start,
                TIterator end,
                TFunc  func) {

    for (auto it = start; it != end; ++it) {
        func(*it);
    }
}

//template <typename T>
//void printAnyType(const T& cont)
//{
//    for (auto it = cont.begin(); it != cont.end(); ++it)
//    {
//        std::cout << *it << std::endl;
//    }
//}


class Sorter {

    Sorter(const std::function<void (int element)>& predicate) : m_predicate(predicate){}

    template <typename Iter>
    void sort(Iter begin, Iter end) {
        std::sort(begin, end, m_predicate);
    }
    
    void setPredicte(const std::function<void(int element)>& predicate) {
        m_predicate = predicate;
    }

    std::function<void(int element)> m_predicate
};

int main()
{

    auto fn = [](auto element) {
        std::cout << element << std::endl;
        };

    std::vector<int> vi = { 1,2,3,4,-56,7,89,0 };
    std::list<int> li = { 1,2,5,-4,56,7,89,0 };

    //printContainer(vi);
    //printContainer(li);

    /*int six = 6;
    printContainer(six);*/

    //std::function<void(auto)>


    //for (auto it = vi.begin(); it != vi.end(); ++it)
    //{
    //    fn(*it);
    //}




    //std::vector<int>::iterator itStart = vi.begin();
    //std::vector<int>::iterator itEnd = vi.end();

    auto fn_10 = [](auto element) {
        if (element > 10) {
            std::cout << element << std::endl;
        }
        };

    //for_each(vi.begin(), vi.end(), fn_10);

    //std::map<int, std::string> m = { {1, "marina"} ,
    //    {2, "alexey"},
    //    {37, "vasiliy"}
    //};

    //for_each(li.begin(), li.end(), func);


    auto cnt = std::count_if(li.begin(), li.end(), [](auto el) { return el > 0; });

    auto it = std::find(li.begin(), li.end(), 5);

    if (it == li.end()) {
        std::cout << "no element 5" << std::endl;
    }


    //auto remove_it = std::remove_if(vi.begin(), vi.end(), 
    //    [](auto el)
    //    {return el < 7; }
    //);
    //
    //vi.erase(remove_it, vi.end());

    bool result = std::all_of(vi.begin(), vi.end(), [](auto el) {return el > 0; });
    result = std::any_of(vi.begin(), vi.end(), [](auto el) {return el < 0; });

    printContainer(vi);

    std::cout << "Hello World!\n";


    //printAnyType(7);
    //printAnyType("errr");
    //printAnyType({"adsads","asdad", "sada"});
    //printAnyType(std::map<int, std::string>{ {1, "adsads"}, { 25, "adsads" }, { 3, "adsads" }, });




}
