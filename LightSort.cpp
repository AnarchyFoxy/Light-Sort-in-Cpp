#include <iostream>
#include <vector>
#include <algorithm>

int times(const std::vector<std::pair<int, int>>& persons) {
    struct Event {
        int time;
        int type; // 1 for entry, -1 for exit
    };

    int n = persons.size();
    std::vector<Event> events;

    for (int i = 0; i < n; ++i) {
        events.push_back({persons[i].first, 1});  // Entry event
        events.push_back({persons[i].second, -1}); // Exit event
    }

    // Sort events first by time, then by type (entry before exit)
    std::sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
        return std::tie(a.time, a.type) < std::tie(b.time, b.type);
    });

    int count = 0;
    int room = 0;

    for (const Event& event : events) {
        if (event.type == 1) {
            // Entry event
            if (room == 0) {
                // If the room is empty, switch on the lights
                ++count;
            }
            ++room;
        } else {
            // Exit event
            --room;
        }
    }

    return count;
}

int main() {
    // Przykłady danych wejściowych
    std::vector<std::pair<int, int>> input1 = {{1, 5}, {2, 6}, {3, 7}};
    std::vector<std::pair<int, int>> input2 = {{11, 15}, {1, 10}, {2, 8}, {5, 12}};
    std::vector<std::pair<int, int>> input3 = {{5, 7}, {6, 8}, {9, 10}, {1, 3}, {2, 4}};
    std::vector<std::pair<int, int>> input4 = {{1, 2}, {2, 3}, {3, 4}};

    // Wywołujemy funkcję times i wyświetlamy wynik
    std::cout << "Output 1: " << times(input1) << std::endl;
    std::cout << "Output 2: " << times(input2) << std::endl;
    std::cout << "Output 3: " << times(input3) << std::endl;
    std::cout << "Output 4: " << times(input4) << std::endl;

    return 0;
}
