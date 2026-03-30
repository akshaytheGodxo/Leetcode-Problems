#include <bits/stdc++.h>
using namespace std;

class EventManager
{
public:
    map<int, set<int>> nmap;
    unordered_map<int, int> eventToPriority;
    EventManager(vector<vector<int>> &events)
    {
        for (auto i : events)
        {
            nmap[i[1]].insert(i[0]);
            eventToPriority[i[0]] = i[1];
        }
    }

    void updatePriority(int eventId, int newPriority)
    {
        if (eventToPriority.count(eventId))
        {
            int oldPriority = eventToPriority[eventId];

            nmap[oldPriority].erase(eventId);
            if (nmap[oldPriority].empty())
                nmap.erase(oldPriority);
        }

        nmap[newPriority].insert(eventId);
        eventToPriority[eventId] = newPriority;
    }

    int pollHighest()
    {
        if (nmap.empty())
            return -1;

        auto itMap = prev(nmap.end());
        int maxKey = itMap->first;
        auto &st = itMap->second;

        int mini = *st.begin();
        st.erase(st.begin());

        eventToPriority.erase(mini);

        if (st.empty())
            nmap.erase(itMap);

        return mini;
    }
};
