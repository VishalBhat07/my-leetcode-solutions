class MyCalendar
{
public:
    vector<pair<int, int>> bookings;

    MyCalendar() {}

    bool book(int start, int end)
    {
        for (auto booking : bookings)
        {
            if (max(booking.first, start) < min(booking.second, end))
            {
                return false;
            }
        }
        bookings.push_back(make_pair(start, end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */