#include <bits/stdc++.h>
using namespace std;

class Job {
public:
    string job_id;
    int deadline;
    int profit;

    Job(string id, int d, int p) {
        job_id = id;
        deadline = d;
        profit = p;
    }
};

// Comparison function to sort jobs by profit (descending)
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

pair<vector<string>, int> jobSequencing(vector<Job> &jobs) {
    // Sort jobs by descending profit
    sort(jobs.begin(), jobs.end(), compare);

    // Find maximum deadline
    int max_deadline = 0;
    for (auto &job : jobs)
        max_deadline = max(max_deadline, job.deadline);

    // Create result slots
    vector<string> result(max_deadline + 1, "-1");
    int total_profit = 0;
    vector<string> job_sequence;

    // Schedule jobs greedily
    for (auto &job : jobs) {
        for (int t = job.deadline; t > 0; t--) {
            if (result[t] == "-1") {
                result[t] = job.job_id;
                total_profit += job.profit;
                job_sequence.push_back(job.job_id);
                break;
            }
        }
    }

    return {job_sequence, total_profit};
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    vector<Job> jobs;
    for (int i = 0; i < n; i++) {
        string job_id;
        int deadline, profit;
        cout << "\nEnter Job ID for Job " << i + 1 << ": ";
        cin >> job_id;
        cout << "Enter deadline for Job " << job_id << ": ";
        cin >> deadline;
        cout << "Enter profit for Job " << job_id << ": ";
        cin >> profit;
        jobs.push_back(Job(job_id, deadline, profit));
    }

    auto [sequence, profit] = jobSequencing(jobs);

    cout << "\n--- Job Sequencing Result ---\n";
    cout << "Job Sequence: ";
    for (auto &id : sequence)
        cout << id << " ";
    cout << "\nTotal Profit: " << profit << endl;

    return 0;
}
