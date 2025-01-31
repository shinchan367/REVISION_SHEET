class Solution {
public:
    // Function to check if a string is a valid integer
    bool isValidInteger(const string& str) {
        if (str.empty()) return false;
        for (char ch : str) {
            if (!isdigit(ch)) return false;
        }
        return true;
    }

    // Comparator function to sort the events based on time and "OFFLINE" status
    static bool compareEvents(vector<string> event1, vector<string> event2) {
        int time1 = stoi(event1[1]);  // Convert event1's time to an integer
        int time2 = stoi(event2[1]);  // Convert event2's time to an integer

        // If times are different, sort by time
        if (time1 != time2) {
            return time1 < time2;
        }

        // If times are the same, "OFFLINE" event comes first
        return event1[0] == "OFFLINE";
    }

    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        // Sort events using the custom comparator
        sort(events.begin(), events.end(), compareEvents);

        // To store the count of mentions for each user
        vector<int> mentionsCount(numberOfUsers, 0);

        // To track whether the user is online or offline
        vector<int> userStatus(numberOfUsers, 1); // 1 means online, 0 means offline
        
        // A map to store the time when each user goes offline
        unordered_map<int, int> offlineTime;

        // Loop over the events
        for (auto& event : events) {
            string type = event[0];  // Event type (MESSAGE or OFFLINE)
            int time = stoi(event[1]);  // Event time
            string target = event[2];  // Target users (either ALL, HERE, or specific users)

            // If the event is "OFFLINE"
            if (type == "OFFLINE") {
                int userId = stoi(target.substr(2));  // Extract user ID (e.g., "id1" -> 1)
                userStatus[userId] = 0;  // Mark user as offline
                offlineTime[userId] = time + 60;  // Record the time when the user goes offline (offline for 60 mins)
            }

            // If the event is "MESSAGE"
            else if (type == "MESSAGE") {
                vector<int> recipients;  // To store the list of recipients for this message

                // If the target is "ALL", send message to all users
                if (target == "ALL") {
                    for (int i = 0; i < numberOfUsers; ++i) {
                        recipients.push_back(i);  // Add all users to recipients
                    }
                }
                // If the target is "HERE", send message to all online users
                else if (target == "HERE") {
                    for (int i = 0; i < numberOfUsers; ++i) {
                        if (userStatus[i] == 1) {  // If user is online
                            recipients.push_back(i);
                        }
                    }
                }
                // If the target contains specific user IDs (e.g., "id1 id0")
                else {
                    stringstream ss(target);  // Stream the target string to extract individual user IDs
                    string userStr;
                    while (ss >> userStr) {
                        int userId = stoi(userStr.substr(2));  // Extract user ID from "id1", "id0"
                        if (userId >= 0 && userId < numberOfUsers) {
                            recipients.push_back(userId);  // Add valid user IDs to recipients
                        }
                    }
                }

                // Increment the message count for each recipient
                for (int recipient : recipients) {
                    mentionsCount[recipient]++;
                }
            }

            // After processing the message, check for offline users
            for (int i = 0; i < numberOfUsers; ++i) {
                if (userStatus[i] == 0 && offlineTime[i] <= time) {
                    userStatus[i] = 1;  // Mark user as online again after the offline duration
                }
            }
        }

        return mentionsCount;  // Return the final count of mentions for each user
    }
};


