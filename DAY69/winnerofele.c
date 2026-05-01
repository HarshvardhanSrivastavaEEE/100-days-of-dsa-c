#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;

    map<string, int> votes;

    for(int i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        votes[name]++;
    }

    string winner = "";
    int maxVotes = 0;

    for(auto it : votes)
    {
        if(it.second > maxVotes)
        {
            maxVotes = it.second;
            winner = it.first;
        }
    }

    cout << winner << " " << maxVotes;

    return 0;
}