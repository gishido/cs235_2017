class Deque
{
  public:
    // constructors and destructors
    Deque() : data(NULL), max(0), iFront(0), iBack(-1) {}
    Deque(int capacity) throw(const char *);
    Deque(const Deque<T> &rhs) throw(const char *);
    ~Deque()
    {
        if (!empty())
            delete[] data;
    }
    Deque<T> &operator=(const Deque<T> &rhs) throw(const char *);
    // standard container interfaces
    bool empty() const { return size() == 0; }
    int size() const { return iBack - iFront + 1; }
    int capacity() const { return max; }
    void clear()
    {
        iFront = 0;
        iBack = -1;
    }
    // deque-specific interfaces
    void push_back(const T &t) throw(const char *);
    void push_front(const T &t) throw(const char *);
    void pop_back() throw(const char *);
    void pop_front() throw(const char *);
    T &front() throw(const char *);
    T &back() throw(const char *);
    T front() const throw(const char *);
    T back() const throw(const char *);

  private:
    // utility functions
    int iAbsoluteFromIRelative(int i) const
    {
        return (i >= 0) ? (i % max) : (max - ((-1 - i) % max) - 1);
    }
    int getIBack() const { return iAbsoluteFromIRelative(iBack); }
    int getIFront() const { return iAbsoluteFromIRelative(iFront); }
    void resize(int newMax = 0) throw(const char *);
    // member variables
    T *data;    // dynamically allocated data for the deque
    int max;    // the size of the data array
    int iFront; // the index of the first item in the array
    int iBack;  // the index of the last item in the array
};