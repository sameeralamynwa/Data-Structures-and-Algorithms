class Meeting{
    int start, end;
    public Meeting(int start, int end){
        this.start = start;
        this.end = end;
    }
}

class ComparatorMeeting implements Comparator<Meeting> {
    public int compare(Meeting a, Meeting b){
        if(a.end > b.end){
            return 1;
        }
        return -1;
    }
}

class Solution {
    public static int maxMeetings(int start[], int end[], int n){
        ArrayList <Meeting> meetings = new ArrayList <>();
        for(int i = 0; i < n; ++i){
            meetings.add(new Meeting(start[i], end[i]));
        }
        Collections.sort(meetings, new ComparatorMeeting());
        int maxMeetings = 0, lastMeeting = 0;
        for(int i = 0; i < n; ++i){
            if(meetings.get(i).start > lastMeeting){
                lastMeeting = meetings.get(i).end;
                maxMeetings++;
            }
        }
        return maxMeetings;
    }
}
