#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int start;
    int finish;
    int index;
    
    Activity(int s, int f, int i) : start(s), finish(f), index(i) {}
};

bool compareActivities(const Activity &a, const Activity &b) {
    return a.finish < b.finish;
}

void activitySelection(vector<Activity> &activities) {
    sort(activities.begin(), activities.end(), compareActivities);
    
    cout << "Selected activities: " << activities[0].index << " ";
    
    int lastFinishTime = activities[0].finish;
    
    for (int i = 1; i < activities.size(); i++) {
        if (activities[i].start >= lastFinishTime) {
            cout << activities[i].index << " ";
            lastFinishTime = activities[i].finish;
        }
    }
    cout << endl;
}

void printActivities(const vector<Activity> &activities) {
    cout << "Activities (Start, Finish, Index):" << endl;
    for (int i = 0; i < activities.size(); i++) {
        cout << "(" << activities[i].start << ", " << activities[i].finish << ", " << activities[i].index << ")" << endl;
    }
    cout << endl;
}

int main() {
    vector<Activity> activities = {
        Activity(1, 4, 1),
        Activity(3, 5, 2),
        Activity(0, 6, 3),
        Activity(5, 7, 4),
        Activity(3, 9, 5),
        Activity(5, 9, 6),
        Activity(6, 10, 7),
        Activity(8, 11, 8),
        Activity(8, 12, 9),
        Activity(2, 14, 10),
        Activity(12, 16, 11)
    };
    
    cout << "Activity Selection Problem - Greedy Algorithm" << endl;
    cout << "=============================================" << endl;
    
    printActivities(activities);
    
    cout << "Maximum number of activities that can be performed: ";
    activitySelection(activities);
    
    return 0;
}