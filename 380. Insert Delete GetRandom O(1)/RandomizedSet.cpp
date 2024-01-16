class RandomizedSet
{
public:
    /** Initialize your data structure here. */
    vector<int> nums;
    unordered_map<int, int> m;
    RandomizedSet()
    {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {

        if (m.find(val) != m.end())
        { // check if the value is present or not
            return false;
        }

        nums.push_back(val);
        m[val] = nums.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {

        // check if the value is present or not
        // if not return false else delete the element
        if (m.find(val) == m.end())
            return false;

        int ind = m[val]; // access the index of the element which we have to remove
        int lastElement = nums.back();
        nums[ind] = lastElement; // delete the value by storing the last element at it's place
        m[lastElement] = ind;    // update the latest element index
        nums.pop_back();         // pop the last element since we have shifted this element
        m.erase(val);            // erase it from map

        return true;
    }

    /** Get a random element from the set. */
    int getRandom()
    {

        int n = nums.size();

        return nums[rand() % n];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */