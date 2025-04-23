#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;


struct Billionaire {
    string name;
    int age;
    double net_worth;
    string country;
    bool self_made;
};

bool parse(const string& value) {
    return value == "True" || value == "true";
}

// Function to read CSV and add to vector
bool readCSV(const string& filename, vector<Billionaire>& data) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open the file." << endl;
        return false;
    }

    string line;
    getline(file, line); // Skip header
    while (getline(file, line)) {
        stringstream ss(line);
        string name, ageStr, netWorthStr, country, selfMadeStr;

        getline(ss, name, ',');
        getline(ss, ageStr, ',');
        getline(ss, netWorthStr, ',');
        getline(ss, country, ',');
        getline(ss, selfMadeStr, ',');

        Billionaire b;
        b.name = name;
        b.age = stoi(ageStr);
        b.net_worth = stod(netWorthStr);
        b.country = country;
        b.self_made = parse(selfMadeStr);

        data.push_back(b);
    }
    file.close();
    return true;
}

// Merge Sort
void merge(vector<Billionaire>& arr, int left, int mid, int right, int sort_option) {
    vector<Billionaire> leftVec(arr.begin() + left, arr.begin() + mid + 1);
    vector<Billionaire> rightVec(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;
    while (i < leftVec.size() && j < rightVec.size()) {
        bool condition = false;
        switch (sort_option) {
            case 1: condition = leftVec[i].net_worth < rightVec[j].net_worth; break;
            case 2: condition = leftVec[i].age < rightVec[j].age; break;
            case 3: condition = leftVec[i].name < rightVec[j].name; break;
        }
        if (condition) arr[k++] = leftVec[i++];
        else arr[k++] = rightVec[j++];
    }
    while (i < leftVec.size()) arr[k++] = leftVec[i++];
    while (j < rightVec.size()) arr[k++] = rightVec[j++];
}

void mergeSort(vector<Billionaire>& arr, int left, int right, int sort_option) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, sort_option);
        mergeSort(arr, mid + 1, right, sort_option);
        merge(arr, left, mid, right, sort_option);
    }
}

// Quick Sort
int partition(vector<Billionaire>& arr, int low, int high, int sort_option) {
    Billionaire pivot = arr[high];
    int i = low - 1;


    auto compare = [&](const Billionaire& a, const Billionaire& b) {
        if (sort_option == 1) return a.net_worth < b.net_worth;
        if (sort_option == 2) return a.age < b.age;
        return a.name < b.name; // default to name if not 1 or 2
    };

    for (int j = low; j < high; j++) {
        if (compare(arr[j], pivot)) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quickSort(vector<Billionaire>& arr, int low, int high, int sort_option) {
    if (low < high) {
        int pi = partition(arr, low, high, sort_option);
        quickSort(arr, low, pi - 1, sort_option);
        quickSort(arr, pi + 1, high, sort_option);
    }
}



int main() {
    vector<Billionaire> data;
    if (!readCSV("billionaires.csv", data)) return 1;

    cout << "Choose sorting algorithm:\n1. Merge Sort\n2. Quick Sort\n ";
    int algo_choice;
    cin >> algo_choice;

    cout << "\nChoose attribute to sort by:\n1. Net Worth\n2. Age\n3. Name\n ";
    int attr_choice;
    cin >> attr_choice;

    auto start = chrono::high_resolution_clock::now();

    if (algo_choice == 1)
        mergeSort(data, 0, data.size() - 1, attr_choice);
    else
        quickSort(data, 0, data.size() - 1, attr_choice);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;


    cout << "\nTime taken: " << duration.count() << " seconds." << endl;
    ofstream out("sorted_output.csv");
    out << "name,age,net_worth,country,self_made\n";
    for (const auto& b : data) {
        out << b.name << "," << b.age << "," << b.net_worth << "," << b.country << ","
            << (b.self_made ? "True" : "False") << "\n";
    }
    out.close();
    cout << "\nSorted data written to sorted_output.csv\n";

    return 0;
}
