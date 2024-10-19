#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int array[] = { 1, 2, 5,  6, 10,     15,       19,  30 };



int array2[] = { 0, 2, 5,   6, 10, 12,   15,  19, 30,  45, 104, 120,  150, 300, 400,  450, 453, 460 };

// 0, 2, 5,  6, 10


bool existLinear(int volue, int* a, int c)
{
    for (int i = 0; i < c; ++i) {
        std::cout << "cicle lin\n";

        if (a[i] == volue) {
            return true;
        }
    }
    return false;
}
//O(n)


bool existBin(int value, int* a, int c)
{
    while (c > 0) {
        std::cout << "cicle bin\n";
        int i = c / 2;
        int e = a[i];

        if (e == value)
        {
            return true;
        }
        else if (e > value)
        {
            c = i;
        }
        else {
            c = c - i - 1;
            a = a + i + 1;
        }
    }

    return false;
}
//O(log(n))




struct Node
{
    int value;

    Node* next;

};

struct List
{
    Node* head = nullptr;
    Node* tail = nullptr;
    int count = 0;

    void push(int v) {
        
        count = count + 1;
        Node* n = new Node;
        n->value = v;
        n->next = nullptr;

        if (head == nullptr) {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;

        }

    }
   
};

Node* getNext(Node* n) {
    return n->next;
}


int ar[10] = { 3, 5, 1,  6, 2,8, 9, 0 };
int down[10];

int* merge_sort(int* up, int* down, unsigned int left, unsigned int right)
{
    if (left == right)
    {
        down[left] = up[left];
        return down;
    }

    unsigned int middle = left + (right - left) / 2;

    // разделяй и сортируй
    int* l_buff = merge_sort(up, down, left, middle);
    int* r_buff = merge_sort(up, down, middle + 1, right);

    // слияние двух отсортированных половин
    int* target = l_buff == up ? down : up;

    unsigned int l_cur = left, r_cur = middle + 1;
    for (unsigned int i = left; i <= right; i++)
    {
        if (l_cur <= middle && r_cur <= right)
        {
            if (l_buff[l_cur] < r_buff[r_cur])
            {
                target[i] = l_buff[l_cur];
                l_cur++;
            }
            else
            {
                target[i] = r_buff[r_cur];
                r_cur++;
            }
        }
        else if (l_cur <= middle)
        {
            target[i] = l_buff[l_cur];
            l_cur++;
        }
        else
        {
            target[i] = r_buff[r_cur];
            r_cur++;
        }
    }
    return target;
}


int main() {


    std::cout << existLinear(105, array2, 18);
    int *result =  merge_sort(ar, down, 0, 10);



}


/// 100 34, 5,       2, 56, 25

//100 34 , 5,      2, 25 56
// 2 5 25 34 56 100  
