class Solution {
public:
    bool traverse(string currentCity, map <string, vector <string> > &graph, int ticketsLeft, vector <string> &path, map <vector <string>, int > &availableTickets){
        if(ticketsLeft == 0){
            return true;
        }
        for(string neighbourCity : graph[currentCity]){
            if(availableTickets[{currentCity, neighbourCity}] == 0){
                continue;
            }
            availableTickets[{currentCity, neighbourCity}]--;
            path.push_back(neighbourCity);
            if(traverse(neighbourCity, graph, ticketsLeft - 1, path, availableTickets)){
                return true;
            }
            else{
                availableTickets[{currentCity, neighbourCity}]++;
                path.pop_back();
            }
        }
        return false;
    }
    
    vector <string> findItinerary(vector <vector <string> > &tickets) {
        map <string, vector <string> > graph;
        map <vector <string>, int> availableTickets;
        for(vector <string> ticket : tickets){
            graph[ticket.front()].push_back(ticket.back());
            availableTickets[ticket]++;
        }
        
        for(map <string, vector <string> > :: iterator it = graph.begin(); it != graph.end(); ++it){
            sort(it -> second.begin(), it -> second.end());
        }
        
        vector <string> path {"JFK"};
        traverse("JFK", graph, (int) tickets.size(), path, availableTickets);
        return path;
    }
};
