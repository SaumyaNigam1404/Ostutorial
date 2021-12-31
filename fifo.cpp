#include<bits/stdc++.h>
using namespace std;
 
int pageFaults(int pages[], int n, int capacity)
{
    unordered_set<int> s;
    queue<int> indexes;
    int page_faults = 0;

    for (int i=0; i<n; i++)
    {
        if (s.size() < capacity)
        {
            if (s.find(pages[i])==s.end())
            {
                s.insert(pages[i]);
                page_faults++;
                indexes.push(pages[i]);
            }
        }
  
        else
        {
            if (s.find(pages[i]) == s.end())
            {
                int val = indexes.front();
                indexes.pop();
                s.erase(val);
                s.insert(pages[i]);
                indexes.push(pages[i]);
                page_faults++;
            }
        }
    }
    return page_faults;
}

int main()
{
    int pages[] = {4, 7, 6, 1, 7, 6, 1, 2, 7, 2, 7, 1};
    int n = sizeof(pages)/sizeof(pages[0]);
    int capacity = 3;
    float miss_per, hit_per;

    cout << pageFaults(pages, n, capacity);
    miss_per = ((pageFaults(pages, n, capacity)*1.0)/n)*100;
    hit_per = 100 - miss_per;
    cout<<"\nMiss ratio = "<<miss_per<<"%";
    cout<<"\nHit ratio = "<<hit_per<<"%";
    return 0;
}
